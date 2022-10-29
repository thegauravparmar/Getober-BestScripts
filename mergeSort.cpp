#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int si, int mid, int ed)
{
    int c1 = mid - si + 1;
    int c2 = ed - mid;

    int temp1[c1], temp2[c2];

    for (int i = 0; i < c1; i++)
    {
        temp1[i] = arr[i];
    }
    for (int i = c1; i < c2; i++)
    {
        temp2[i] = arr[i];
    }

    int id1 = 0;
    int id2 = 0;

    int idm = si;

    while (id1 < c1 && id2 < c2)
    {
        if (temp1[id1] <= temp2[id2])
        {
            arr[idm] = temp1[id1];
            id1++;
        }
        else
        {
            arr[idm] = temp2[id2];
            id2++;
        }
        idm++;
    }
    while (id1 < c1)
    {
        arr[idm] = temp1[id1];
        id1++;
        idm++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (id2 < c2)
    {
        arr[idm] = temp2[id2];
        id2++;
        idm++;
    }
}

void mergesort(int arr[], int si, int ed)
{
    if (si >= ed)
        return;

    int mid = (si + ed) / 2;

    mergesort(arr, si, mid);
    mergesort(arr, mid + 1, ed);

    merge(arr, si, mid, ed);
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4};
    int n = 6;
    // cout << arr.length();

    mergesort(arr, 0, n - 1);

    printArray(arr, n);
}
