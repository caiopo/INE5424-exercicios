#include <utility/ostream.h>

using namespace EPOS;

OStream cout;

const int arr_size = 100;

bool is_sorted(int** arr, int s) {
    for (int i = 0; i < (s - 1); i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    auto arr = new int*[arr_size];

    for (int i = 0; i < arr_size; i++) {
        arr[i] = new int[1000];
    }

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << endl;
    }

    cout << endl << is_sorted(arr, arr_size) << endl << endl;

    return 0;
}
