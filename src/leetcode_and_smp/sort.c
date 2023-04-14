#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int k = *a;
    *a = *b;
    *b = k;
}

int arr_min_ind(int *arr, int size)
{
    int ind = 0;

    for (int i = 1; i < size; ++i)
        if (arr[i] < arr[ind])
            ind = i;
    return ind;
}

void bubble_sort(int *arr, int size)
{
    int k = 0;

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (arr[i] > arr[j])
                swap(arr + i, arr + j); // swap(&arr[i], &arr[j]);
}

void insertion_sort(int *arr, int size)
{
    int j = 0;

    for (int i = 1; i < size; ++i)
    {
        j = i - 1;
        while (arr[j] > arr[j + 1] && j >= 0)
        {
            swap(arr + j + 1, arr + j);
            --j;
        }
    }
}

void selection_sort(int *arr, int size)
{
    int min_ind = 0;

    for (int i = 0; i < size; ++i)
    {
        min_ind = arr_min_ind(arr + i, size - i);
        swap(arr + i, arr + min_ind);
    }
}

// l     r
// 1 6 9 2 4 7 11
// 1 2 4 6 7 9 11 - merged

// O(size_l + size_r)


// l[i] > r[j] -> swap; ++i;
// l[i] < r[j] -> ++i
// l[i] = r[j] -> swap(l + i + 1, r + j);
void merge_old(int *left, int size_l, int *right, int size_r)
{
    int i = 0;
    int j = 0;

    while (i < size_l && j < size_r)
    {
            if (left[i] > right[j])
            {
                swap(left + i, right + j);
                ++i;
            }
            if (left[i] < right[j])
            {
                ++i;
            }
            if (left[i] == right[j])
            {
                swap(left + i + 1, right + j);
            }
    }
}    

void merge(int *arr, int l, int mid, int r)
{
    int i = 0, j = 0, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
}

//void mergeSort(int *arr, int l, int r)
//{
//    if (l < r)
//    {
//        int m = l + (r - l);
//        mergeSort(arr, l, m);
//        mergeSort(arr, m + 1, 0);    
//        merge(arr, l, m, r);
//    }
//}

void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    printf("Given array is \n");
    printArray(arr, arr_size);   
    //mergeSort(arr, 0, arr_size - 1); 
    printf("\nSorted array is \n");
    merge(arr, 3, 3, 3);
    printArray(arr, arr_size);
    return 0;
}
