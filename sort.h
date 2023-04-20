#include "iostream"

namespace sort {
    using namespace std;

//    强行一波运算符重载
    std::ostream &operator<<(std::ostream &os, int *tem) {
        for (int i = 0; i < 7; ++i) {
            os << tem[i] << " ";
        }
        os << std::endl;
        return os;
    }

    class SortNum {
    private:
        int *arr;
        int n;

        int *Copy() {
            int *result = new int[n];
            for (int i = 0; i < n; ++i) {
                result[i] = arr[i];
            }
            return result;
        }

        static bool del(const int *tem) {
            delete[] tem;
            return true;
        }

    public:
        SortNum(int arr[], int n) {
            this->arr = new int[n];
            for (int i = 0; i < n; ++i) {
                this->arr[i] = arr[i];
            }
            this->n = n;
        }

        ~SortNum() {
            delete[] arr;
        }

        int *getArr() const {
            return arr;
        }

        bool bubbleSort() {
            int *res = Copy();
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (res[j] > res[j + 1]) {
                        int temp = res[j];
                        res[j] = res[j + 1];
                        res[j + 1] = temp;
                    }
                }
            }
            cout << res;
            del(res);
        }

        bool insertionSort() {
            int i, key, j;
            int *res = Copy();
            for (i = 1; i < n; ++i) {
                key = res[i];
                j = i - 1;
                while (j >= 0 && res[j] > key) {
                    res[j + 1] = res[j];
                    j--;
                }
                res[j + 1] = key;
            }
            cout << res;
            del(res);
        }

        bool selectionSort() {
            int i, j, min_index;
            int *res = Copy();
            for (i = 0; i < n - 1; i++) {
                min_index = i;
                for (j = i + 1; j < n; j++) {
                    if (res[j] < res[min_index])
                        min_index = j;
                }
                int temp = res[min_index];
                res[min_index] = res[i];
                res[i] = temp;
            }
            cout << res;
            del(res);
        }

        // Merge Sort
        bool merge(int mArr[], int l, int m, int r) {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 = r - m;
            int L[n1], R[n2];
            for (i = 0; i < n1; i++) {
                L[i] = mArr[l + i];
            }
            for (j = 0; j < n2; j++) {
                R[j] = mArr[m + 1 + j];
            }
            i = 0;
            j = 0;
            k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    mArr[k] = L[i];
                    i++;
                } else {
                    mArr[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                mArr[k] = L[i];
                i++;
                k++;
            }
            while (j < n2) {
                mArr[k] = R[j];
                j++;
                k++;
            }
        }

        bool mergeSort(int mArr[], int l, int r) {
            if (l < r) {
                int m = l + (r - l) / 2;
                mergeSort(mArr, l, m);
                mergeSort(mArr, m + 1, r);
                merge(mArr, l, m, r);
            }
        }

        int partition(int pInt[], int low, int high) {
            int pivot = pInt[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {
                if (pInt[j] < pivot) {
                    i++;
                    int temp = pInt[i];
                    pInt[i] = pInt[j];
                    pInt[j] = temp;
                }
            }
            int temp = pInt[i + 1];
            pInt[i + 1] = pInt[high];
            pInt[high] = temp;
            return (i + 1);
        }

        bool quickSort(int pInt[], int low, int high) {
            if (low < high) {
                int pi = partition(pInt, low, high);
                quickSort(pInt, low, pi - 1);
                quickSort(pInt, pi + 1, high);
            }
        }

        // Heap Sort
        bool heapify(int pInt[], int m, int i) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < m && pInt[l] > pInt[largest]) {
                largest = l;
            }
            if (r < m && pInt[r] > pInt[largest]) {
                largest = r;
            }
            if (largest != i) {
                int temp = pInt[i];
                pInt[i] = pInt[largest];
                pInt[largest] = temp;
                heapify(pInt, m, largest);
            }
        }

        bool heapSort() {
            int *res = Copy();
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(res, n, i);
            }
            for (int i = n - 1; i >= 0; i--) {
                int temp = res[0];
                res[0] = res[i];
                res[i] = temp;
                heapify(res, i, 0);
            }
            cout << res;
            del(res);
        }

        // Radix Sort
        int getMax(int pInt[], int p) {
            int mx = pInt[0];
            for (int i = 1; i < p; i++) {
                if (pInt[i] > mx) {
                    mx = pInt[i];
                }
            }
            return mx;
        }

        void countSort(int pInt[], int p, int exp) {
            int output[p];
            int i, count[10] = {0};
            for (i = 0; i < p; i++) {
                count[(pInt[i] / exp) % 10]++;
            }
            for (i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
            for (i = p - 1; i >= 0; i--) {
                output[count[(pInt[i] / exp) % 10] - 1] = pInt[i];
                count[(pInt[i] / exp) % 10]--;
            }
            for (i = 0; i < p; i++) {
                pInt[i] = output[i];
            }
        }

        void radixSort() {
            int *res = Copy();
            int m = getMax(res, n);
            for (int exp = 1; m / exp > 0; exp *= 10) {
                countSort(res, n, exp);
            }
            cout << res;
            del(res);
        }

        void countingSort() {
            int *res = Copy();
            int output[n];
            int max = res[0];
            for (int i = 1; i < n; i++) {
                if (res[i] > max) {
                    max = res[i];
                }
            }
            int count[max + 1];
            for (int i = 0; i <= max; i++) {
                count[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                count[res[i]]++;
            }
            for (int i = 1; i <= max; i++) {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                output[count[res[i]] - 1] = res[i];
                count[res[i]]--;
            }
            for (int i = 0; i < n; i++) {
                res[i] = output[i];
            }
            cout << res;
            del(res);
        }
    };
}