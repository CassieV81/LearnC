#include <stdio.h>

void mergesort();

int main(void) {

    int array[] = {1, 3, 4, 42, 17, 63, 58, 91, 24, 76, 31, 89, 53, 6, 0, 2, 5, 7};
    int N = sizeof(array) / sizeof(int);
    mergesort(array, N);
    for(int i = 0; i < N; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void mergesort(int a[], int N) {

    if (N <= 1) {
        return;
    }
    int i; 
    int pos = N / 2;
    int k1 = 0, k2 = 0;
    int arr1[N - pos], arr2[N - pos];

    for(i = 0; i < N; i++) {
        if(i < pos) {
            arr1[k1++] = a[i];
        } else {
            arr2[k2++] = a[i];
        }
    }
    // for(i = 0; i < k1; i++) {
    //     printf("%d", arr1[i]);
    // }
    // printf("\n");
    // for(i = 0; i < k2; i++) {
    //     printf("%d", arr2[i]);
    // }
    // printf("\n");

    mergesort(arr1, k1);
    mergesort(arr2, k2);

    int l = 0, j = 0, k = 0;

    while(l < k1 && j < k2) {
        if(arr1[l] < arr2[j]) {
            a[k++] = arr1[l++];
        } else {
            a[k++] = arr2[j++];
        }
    }
    while(l < k1) {
        a[k++] = arr1[l++];
    }
    while(j < k2) {
        a[k++] = arr2[j++];
    }
}
