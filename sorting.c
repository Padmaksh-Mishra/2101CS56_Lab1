# include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(void){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    for(int i=0;i<9;++i) printf("%d ", arr[i]);
    printf("\n");
    insertion_sort(arr,9);
    for(int i=0;i<9;++i) printf("%d ", arr[i]);
}
