#include <utility/ostream.h>
#include <process.h>

using namespace EPOS;

OStream cout;

int main()
{
    int thread = sizeof(Thread);
    int context = sizeof(CPU::Context);
    int stack = Traits<Application>::STACK_SIZE;

    cout << endl << endl << endl << endl << endl;
    cout << "sizeof(Thread) " << thread << endl;
    cout << "sizeof(Context) " << context << endl;
    cout << "Stack size " << stack << endl;

    cout << "Total " << thread + context + stack << endl;

    cout << endl << endl << endl << endl << endl;
    return 0;
}
