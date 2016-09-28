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
        }
        --i;
    }

    return 0;
}

void RarixSort(TElement *arr, Tloong n, uint32_t cap)
{
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

        for (Tloong j = 0; j <= n - 1; ++j) {
            int d = Digit(arr[j], i);
            ++C[d];
        }

        int count = 0;
    
        for (int j = 0; j <= k - 1; ++j) {
            int tmp = C[j];
            C[j] = count;
            count += tmp;
        }
      
        for (Tloong j = 0; j <= n - 1; ++j) {
            int d = Digit(arr[j], i);
            B[C[d]] = arr[j];
            ++C[d];
        }

        for (Tloong j = 0; j <= n - 1; ++j) {
            arr[j] = B[j];
        }
    }

    delete[]C;
    delete[]B;
}

void ArrayInsert(TElement *arr, Tloong *size, uint32_t *cap) {
   
    TElement elem;

    for (Tloong i = 0; cin >> elem.key >> elem.value; ++i) {
        if ((*size) == *(cap)) {
            (*cap) *= 2;
            arr = (TElement*)realloc(arr, sizeof(TElement) * (*cap));
        }

        arr[i] = elem;
        ++(*size);
    }
}

void RarixSortResultPrint(TElement *arr, Tloong size) {
    for (Tloong i = 0; i < size; ++i) {
        cout << arr[i].key << "\t" << arr[i].value << endl;
    }
}

int main(int argc, char const **argv) {
    
    uint32_t capacity = MIN_CAP;
    Tloong size_of_arr = 0;
    TElement *arr = new TElement[capacity];
    
    ArrayInsert(arr, &size_of_arr, &capacity);
    RarixSort(arr, size_of_arr, capacity);
    RarixSortResultPrint(arr, size_of_arr);

    delete[]arr;

    return 0;
}