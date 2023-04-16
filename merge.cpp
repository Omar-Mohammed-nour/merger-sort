#include <iostream>
#include <array>

void merge(int* leftarr, int* rightarr, int* arr) {
    //sizes
    std::size_t length = sizeof(arr) / sizeof(*arr);
    int leftlength = length / 2;
    int rightlength = length - leftlength;// cux the right wants the leftover crumbs
    
    //indices
    int i = 0, l = 0, r = 0; 
    
    //sorting
    while (l < middle && r < arrlength - middle) {
        if (leftarr[l] < rightarr[r]) {
            arr[i] = leftarr[l];
            i++;
            l++;
        }
        else {
            arr[i] = rightarr[r];
            i++;
            r++;
        }
    }

    while (l < leftlength) {
        arr[i] = leftarr[l];
        i++;
        l++;
    }

    while (r < rightlength) {
        arr[i] = rightarr[r];
        i++;
        r++;
    }

}

void mergeSort(int arr[]) {
    
    std::size_t arrlength = sizeof(arr) / sizeof(*arr);
    std::cout << arrlength;

    if (arrlength <= 1) {return;}//base case (will bassically stop the function since this has recursion)

    int middle = arrlength / 2;

    int* leftarr = new int[middle];
    int* rightarr = new int[arrlength - middle]; // the reason its not middle - lenght is because you cant get a negative number in arrays
    
    //int i = 0; for left sub array
    int j = 0; //for right sub array

    for (int i = 0; i < arrlength; i++) {
        if (i < middle) {
            leftarr[i] = arr[i];
            //std::cout << arr[i];
        }
        else {
            rightarr[j] = arr[i];
            j++;
        }
    }
    
    mergeSort(leftarr);
    mergeSort(rightarr);
    merge(leftarr, rightarr, arr);
    
    delete[] leftarr;
    delete[] rightarr;

}


int main () {
    
    int mainarr[8] = {4, 2, 3, 1, 5 ,7 ,8 ,6};
    mergeSort(mainarr);

    for (int i = 0; i < 8; i++) {
        std::cout << mainarr[i] << ' ';
    }
    
}


