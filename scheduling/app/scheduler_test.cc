#include <utility/ostream.h>
#include <process.h>
#include <time.h>

using namespace EPOS;

OStream cout;

Thread* thread_io;
Thread* thread_cpu;

// IO bound thread will not lose priority,
// as it never uses its entire quantum
int io_bound() {
    cout << "IO bound thread at " << thread_io << endl;

    while (1) {
        Alarm::delay(100000);
    }

    return 0;
}

// CPU bound thread will lose priority,
// as it always uses its entire quantum
int cpu_bound() {
    cout << "CPU bound thread at " << thread_cpu << endl;

    while (1);

    return 0;
}

int main() {
    thread_io = new Thread(&io_bound);
    thread_cpu = new Thread(&cpu_bound);

    thread_io->join();
    thread_cpu->join();

    delete thread_io;
    delete thread_cpu;

    return 0;
}
