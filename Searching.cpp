#include <iostream>
#include <algorithm>
using namespace std;

class Sorter {
public:

    void mergeSort(int arr[], int l, int r) {
        if(l < r) {
            int m = (l + r) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }


    void quickSort(int arr[], int low, int high) {
        if(low < high) {
            int p = partition(arr, low, high);

            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }


    void quickSortM3(int arr[], int low, int high) {
        if(low < high) {
            int p = partitionM3(arr, low, high);

            quickSortM3(arr, low, p - 1);
            quickSortM3(arr, p + 1, high);
        }
    }


private:

    void merge(int arr[], int l, int m, int r) {//compare the 2 sorted halves and compare them into an array
        int n1 = m - l + 1;
        int n2 = r - m;

        int left[n1];
        int right[n2];

        for(int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }

        for(int j = 0; j < n2; j++) {
            right[j] = arr[m + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = l;

        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while(j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }


    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;//values smaller than pivot

        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return i + 1;
    }


    int partitionM3(int arr[], int low, int high) {

        int pivotIndex = medianOfThree(arr, low, high);

        swap(arr[pivotIndex], arr[high]);

        return partition(arr, low, high);
    }


    int medianOfThree(int arr[], int low, int high) {//returns median to be used in partition m3
        int mid = (low + high) / 2;

        if(arr[low] > arr[mid]) {
            swap(arr[low], arr[mid]);
        }

        if(arr[low] > arr[high]) {
            swap(arr[low], arr[high]);
        }

        if(arr[mid] > arr[high]) {
            swap(arr[mid], arr[high]);
        }

        return mid;
    }
};


int main() {

    Sorter s;

    int tmp[8];

    int a[] = {64, 25, 12, 22, 11, 90, 45, 34};
    int n = 8;


    // mergeSort
    copy(a, a + n, tmp);
    s.mergeSort(tmp, 0, n - 1);

    cout << "MS: ";
    for(int x : tmp)
        cout << x << " ";
    cout << endl;


    // quickSort
    copy(a, a + n, tmp);
    s.quickSort(tmp, 0, n - 1);

    cout << "QS: ";
    for(int x : tmp)
        cout << x << " ";
    cout << endl;


    // worst-case for quickSort: sorted array
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8};

    copy(sorted, sorted + n, tmp);
    s.quickSort(tmp, 0, n - 1);

    cout << "QS sorted: ";
    for(int x : tmp)
        cout << x << " ";
    cout << endl;


    // quickSortM3 on same sorted array
    copy(sorted, sorted + n, tmp);
    s.quickSortM3(tmp, 0, n - 1);

    cout << "QSM3 sorted: ";
    for(int x : tmp)
        cout << x << " ";
    cout << endl;


    return 0;
}