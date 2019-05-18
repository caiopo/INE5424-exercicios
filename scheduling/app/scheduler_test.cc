#include <utility/ostream.h>
#include <process.h>
#include <time.h>

using namespace EPOS;

OStream cout;

Thread* thread_io;
Thread* thread_cpu;

int slow_fibonacci(int i) {
    if (i == 0) return 0;
    if (i == 1) return 1;

    return slow_fibonacci(i - 1) + slow_fibonacci(i - 2);
}

// IO bound thread will not lose priority,
// as it never uses its entire quantum
int io_bound() {
    cout << "IO bound thread at " << thread_io << " with priority = " << thread_io->priority() << endl;

    for (int i = 0; i < 5; i++) {
        Alarm::delay(100000);
    }

    cout << "IO bound thread finished " << endl;

    return 0;
}

// CPU bound thread will lose priority,
// as it always uses its entire quantum
int cpu_bound() {
    cout << "CPU bound thread at " << thread_cpu << " with priority = " << thread_cpu->priority() << endl;

    slow_fibonacci(35);

    cout << "CPU bound thread finished " << endl;

    return 0;
}

int main() {
    thread_io = new Thread(&io_bound);
    thread_cpu = new Thread(&cpu_bound);

    thread_io->join();
    thread_cpu->join();

    cout << "CPU bound thread end priority: " << thread_cpu->priority() << endl;
    cout << "IO bound thread end priority: " << thread_io->priority() << endl;

    delete thread_io;
    delete thread_cpu;

    return 0;
}
