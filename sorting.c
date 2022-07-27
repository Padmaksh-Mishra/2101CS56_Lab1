# include <stdio.h>

// Helping Functions
void swap(int *a,int *b);
void merge(int arr[], int l, int m, int r);
int partition(int *arr,int lo, int hi);

// Sorting Functions
void insertion_sort(int arr[], int n);              // O(n^2)
void selection_sort(int arr[], int n);              // O(n^2)
void bubbleSort(int arr[], int n);                  // O(n^2)
void mergeSort(int arr[], int l, int r);            // O(nlogn)
void quick_sort(int arr[], int low, int high);      // O(nlogn)


int main(void){
    printf("Welcome to the sorts\n");

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

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
