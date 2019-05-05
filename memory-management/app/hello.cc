#include <utility/ostream.h>

using namespace EPOS;

OStream cout;

int main()
{
    cout << "Trying to Alloc" << endl;
    int* x = new int;
    cout << "Done" << endl;

    return 0;
}
