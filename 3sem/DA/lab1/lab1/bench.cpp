#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define Tloong unsigned long long

using namespace std;
const int MIN_CAP = 8;

class TElement {
public:
    Tloong key;
    Tloong value;
};

int MaxRadix(Tloong size, TElement *arr) {
    Tloong max = 0;

    for (Tloong i = 0; i < size; ++i) {
        arr[i].key > max ? max = arr[i].key : max;
    }

    int radix = 0;

    while (max / 10) {
        ++radix;
        max /= 10;
    }

    return radix + 1;
}

int Digit(TElement elem, int i) {

    Tloong tmp = elem.key;

    while (i) {
        if (tmp / 10) {
            if (i == 1) {
                return tmp % 10;
            }
            tmp /= 10;
        }
        else {
            if (i == 1) {
                return (int)tmp;
            }
        }
        --i;
    }

    return 0;
}

void RarixSort(TElement *arr, Tloong n, Tloong cap) {
    if (!n) {
        return;
    }

    int m = MaxRadix(n, arr);
    int k = 10;
    int *C = new int[k];
    TElement *B = new TElement[cap];

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= k - 1; ++j) {
            C[j] = 0;
        }

        for (int j = 0; j <= n - 1; ++j) {
            int d = Digit(arr[j], i);
            ++C[d];
        }

        int count = 0;

        for (int j = 0; j <= k - 1; ++j) {
            int tmp = C[j];
            C[j] = count;
            count += tmp;
        }

        for (int j = 0; j <= n - 1; ++j) {
            int d = Digit(arr[j], i);
            B[C[d]] = arr[j];
            ++C[d];
        }

        for (int j = 0; j <= n - 1; ++j) {
            arr[j] = B[j];
        }
    }

    delete[]C;
    delete[]B;
}

int main(int argc, char const **argv) {

    TElement elem;
    Tloong capacity = MIN_CAP;
    Tloong size_of_arr = 0;
    TElement *arr = new TElement[capacity];
    clock_t start;
    double duration;

    for (Tloong i = 0; cin >> elem.key >> elem.value; ++i) {
        if (size_of_arr == capacity) {
            capacity *= 2;
            arr = (TElement*)realloc(arr, sizeof(TElement) * capacity);
        }

        arr[i] = elem;
        ++size_of_arr;
    }

    vector<Tloong> bench(size_of_arr);

    for (Tloong i = 0; i < size_of_arr; ++i)
    {
    	bench[i] = arr[i].key;
    }

    start = clock();

    RarixSort(arr, size_of_arr, capacity);

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "My radix sort: " << duration << endl;

    start = clock();
    sort(bench.begin(), bench.end());
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "STL sort: " << duration << endl;

    delete[]arr;

    return 0;
}
