#include <iostream>
#include <vector>

using namespace std;

#define newline cout << "\n"

void merge(vector<int> &arr, int l, int m, int r) {
    int s1 = m - l + 1;
    int s2 = r - m;
    
    if (s1 <= 0 || s2 <= 0) {
        return;
    }

    int* L = new int[s1];
    int* R = new int[s2];
    
    for (int i = 0; i < s1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < s2; j++) {
        R[j] = arr[m + 1 + j]; 
    }

    int i = 0, j = 0, k = l;

    while (i < s1 && j < s2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < s2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergesort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergesort(arr, l, m);

        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr = {10, 7, 3, 1, 9, 7, 4, 3, 23, 16, 89, 63, 42, 75, 87, 94, 23, 57, 67, 98, 10, 36, 48, 79, 80, 91, 38, 67, 73, 54, 67, 24, 71, 84, 83, 92, 62, 56, 68, 58, 2, 46, 20, 32, 19, 56, 3, 9, 11, 15, 36, 29, 87, 16, 40, 54, 1, 19, 63, 35, 26, 57, 48, 63, 39, 50, 60, 7, 17, 70, 87, 99, 73, 71, 8, 20, 30, 84, 79, 78, 72, 91, 92, 41, 49, 45, 37, 51, 84, 69, 16, 68, 66, 58, 68, 8, 22, 18, 97, 40, 95, 12, 36, 38, 13, 36, 24, 80, 68, 5, 38, 18, 50, 43, 99, 88, 95, 39, 33, 43, 3, 17, 71, 93, 75, 53, 60, 93, 93, 31, 12, 5, 53, 35, 80, 26, 15, 83, 1, 0, 51};
    int n = arr.size();

    mergesort(arr, 0, n - 1);

    cout << "Sorted array:" << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}
