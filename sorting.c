# include <stdio.h>

// Helping Functions
void swap(int *a,int *b);
int partition(int *arr,int lo, int hi);

// Sorting Functions
void insertion_sort(int arr[], int n);      // O(n^2)
void selection_sort(int arr[], int n);      // O(n^2)
void quick_sort(int arr[], int low, int high);    // O(nlogn)


int main(void){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    for(int i=0;i<9;++i) printf("%d ", arr[i]);
    printf("\n");
    //insertion_sort(arr,9);
    quick_sort(arr,0,8);
    for(int i=0;i<9;++i) printf("%d ", arr[i]);

    return 0;
}

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
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
    return;
}

void selection_sort(int arr[], int n)
{
    int i, j, target;
    for (i = 0; i < n-1; i++)
    {
        target = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[target])
            {
                target = j;
            }
        }
        swap(&arr[target], &arr[i]);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
