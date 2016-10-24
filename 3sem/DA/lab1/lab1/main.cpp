#include <iostream>
#include <cstdlib>

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
            else {
                return 0;
            }
        }
        --i;
    }

    return 0;
}

void RarixSortResult(TElement* arr, Tloong size_of_arr) {
	for (Tloong i = 0; i < size_of_arr; ++i) {
		cout << arr[i].key << "\t" << arr[i].value << endl;
	}
}

void Tmpprint(int* p, int size)
{
	for (Tloong i = 0; i < size; ++i) {
		cout << p[i] << endl;
	}
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

		Tmpprint(C, k);

        for (int j = 0; j <= n - 1; ++j) {
            int d = Digit(arr[j], i);
            B[C[d]] = arr[j];
            ++C[d];
			Tmpprint(C, k);
			cout << endl;
			
        }

        for (int j = 0; j <= n - 1; ++j) {
            arr[j] = B[j];
        }

		RarixSortResult(B, n);
		cout << endl;
    }

    delete[]C;
    delete[]B;
}



int main(int argc, char const **argv) {

    TElement elem;
    Tloong capacity = MIN_CAP;
    Tloong size_of_arr = 0;
    TElement *arr = new TElement[capacity];


    for (Tloong i = 0; cin >> elem.key >> elem.value; ++i) {
        if (size_of_arr == capacity) {
            capacity *= 2;
            arr = (TElement*)realloc(arr, sizeof(TElement) * capacity);
        }

        arr[i] = elem;
        ++size_of_arr;
    }

    RarixSort(arr, size_of_arr, capacity);
    RarixSortResult(arr, size_of_arr);

    delete[]arr;

    return 0;
}
