#include <stdio.h>

void show_arr(int arr[], int n);
void sort_arr(int arr[], int n);

int main() {
    const int n = 7;
    int arr[n] = {64, 2, 24, 7, 0, 365, 1};
    printf("\nbefore sorting: ");
    show_arr(arr, n);
    sort_arr(arr, n);
    printf("\nafter sorting: ");
    show_arr(arr, n);
    printf("\n");
    return '0';
}

void show_arr(int arr[], int n){
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
}

void sort_arr(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < (n - 1); i++) {
        for(j = 0; j < (n - 1); j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}