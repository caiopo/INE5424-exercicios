// EPOS Heap Utility Declarations

#ifndef __heap_h
#define __heap_h

#include <utility/debug.h>
#include <utility/list.h>
#include <utility/spin.h>

__BEGIN_UTIL

// Heap
class Heap: private Grouping_List<char>
{
protected:
    static const bool typed = Traits<System>::multiheap;

public:
    using Grouping_List<char>::empty;
    using Grouping_List<char>::size;

    Heap() {
        db<Init, Heaps>(TRC) << "Heap() => " << this << endl;
    }

    Heap(void * addr, unsigned int bytes) {
        db<Init, Heaps>(TRC) << "Heap(addr=" << addr << ",bytes=" << bytes << ") => " << this << endl;

        free(addr, bytes);
    }

    void * alloc(unsigned int bytes) {
        db<Heaps>(TRC) << "Heap::alloc(this=" << this << ",bytes=" << bytes;

        if(!bytes)
            return 0;

        if(!Traits<CPU>::unaligned_memory_access)
            while((bytes % sizeof(void *)))
                ++bytes;

        if(typed)
            bytes += sizeof(void *);  // add room for heap pointer
        bytes += sizeof(int);         // add room for size
        if(bytes < sizeof(Element))
            bytes = sizeof(Element);

        char * a = search_decrementing_bottom_up(bytes);
        if(!a) {
            out_of_memory();
            return 0;
        }

        int * addr = reinterpret_cast<int *>(a);

        if(typed)
            *addr++ = reinterpret_cast<int>(this);
        *addr++ = bytes;

        db<Heaps>(TRC) << ") => " << reinterpret_cast<void *>(addr) << endl;

        return addr;
    }

    void free(void * ptr, unsigned int bytes) {
        db<Heaps>(TRC) << "Heap::free(this=" << this << ",ptr=" << ptr << ",bytes=" << bytes << ")" << endl;

        if(ptr && (bytes >= sizeof(Element))) {
            char * p = reinterpret_cast<char *>(ptr);
            // Place the Element at the end of the freed block
            Element * e = new (p + bytes - sizeof(Element)) Element(p, bytes);
            Element * m1, * m2;
            insert_merging(e, &m1, &m2);
        }
    }

    static void typed_free(void * ptr) {
        int * addr = reinterpret_cast<int *>(ptr);
        unsigned int bytes = *--addr;
        Heap * heap = reinterpret_cast<Heap *>(*--addr);
        heap->free(addr, bytes);
    }

    static void untyped_free(Heap * heap, void * ptr) {
        int * addr = reinterpret_cast<int *>(ptr);
        unsigned int bytes = *--addr;
        heap->free(addr, bytes);
    }

private:
    void out_of_memory();
};

__END_UTIL

#endif
