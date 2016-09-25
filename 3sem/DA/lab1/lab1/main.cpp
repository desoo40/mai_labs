#include <iostream>

using namespace std;
using Tloong = unsigned long long;
const int MIN_CAP = 8;

class TElement {
public:
    Tloong key = 0;
    Tloong value = 0;
};

class TParametrs {
public:
    Tloong capacity = MIN_CAP;
    Tloong size_of_arr = 0;
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
        else if (i == 1) {
				return (int)tmp;
        }
		--i;
	}
}

void RarixSort(TElement *arr, TParametrs *par)
{
    if (!par->size_of_arr) {
        return;
    }
    int m = MaxRadix(par->size_of_arr, arr);
    int k = 10;
    int *C = new int[k];
    TElement *B = new TElement[par->capacity];

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= k - 1; ++j) {
            C[j] = 0;
        }

        for (int j = 0; j <= par->size_of_arr - 1; ++j) {
            int d = Digit(arr[j], i);
            ++C[d];
        }

        int count = 0;
    
        for (int j = 0; j <= k - 1; ++j) {
            int tmp = C[j];
            C[j] = count;
            count += tmp;
        }
      
        for (int j = 0; j <= par->size_of_arr - 1; ++j) {
            int d = Digit(arr[j], i);
            B[C[d]] = arr[j];
            ++C[d];
        }

		for (int j = 0; j <= par->size_of_arr - 1; ++j) {
			arr[j] = B[j];
		}
    }

    delete[]C;
    delete[]B;
}

void ArrayFill(TElement *arr, TParametrs *par) {
    TElement tmp;

    for (Tloong i = 0; cin >> tmp.key >> tmp.value; ++i) {
        if (par->size_of_arr == par->capacity) {
            par->capacity *= 2;
            arr = (TElement*)realloc(arr, sizeof(TElement) * par->capacity);
        }

        arr[i] = tmp;
        ++par->size_of_arr;
    }
}

void RadixSortResultPrint(TElement* arr, TParametrs* par)
{
    for (Tloong i = 0; i < par->size_of_arr; ++i) {
        cout << arr[i].key << " " << arr[i].value << endl;
    }
}

int main(int argc, char const **argv) {
    TParametrs *par = new TParametrs;
    TElement *arr = new TElement[par->capacity];

    ArrayFill(arr, par);
	RarixSort(arr, par);
    RadixSortResultPrint(arr, par);

    delete[]par;
    delete[]arr;

    return 0;
}
