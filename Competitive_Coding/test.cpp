#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{

    int n1 = mid - low + 1; // Size of low subarray
    int n2 = high - mid;    // Size of r subarray

    // Create temporary subarrays
    int L[n1], R[n2];

    // Copy data to temporary subarrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // // Merge the temporary subarrays back into arr[low..r]
    // int i = 0;  // Initial index of first subarray
    // int j = 0;  // Initial index of second subarray
    // int k = low;  // Initial index of merged subarray

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Recursive function to sort an array using Merge Sort
void mergeSortUsingRecursiveMethod(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSortUsingRecursiveMethod(arr, l, m);
        mergeSortUsingRecursiveMethod(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeSortUsingIterativeMethod(int arr[], int size)
{
    int currentSize;
    int startIndex;

    // Merge subarrays in a bottom-up manner
    for (currentSize = 1; currentSize < size; currentSize *= 2)
    {
        for (startIndex = 0; startIndex < size - 1; startIndex += 2 * currentSize)
        {
            int mid = min(startIndex + currentSize - 1, size - 1);
            int endIndex = min(startIndex + 2 * currentSize - 1, size - 1);
            merge(arr, startIndex, mid, endIndex);
        }
    }
}

int main()
{

    vector<int> v;
    string stin;

    cout << "Enter the array to be sorted with elements separated by comma: ";
    getline(cin, stin);

    // Parse the stin string to populate the array
    istringstream iss(stin);
    string number;
    while (getline(iss, number, ','))
    {
        v.push_back(stoi(number));
    }
    int n = v.size();
    int arr[n];
    int c = 0;
    int array2[n];
    for (auto itr : v)
    {
        arr[c] = v[c];
        array2[c] = v[c];
        c++;
    }

    cout << "The original array is " << endl;

    for (const int &num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "The resultant Sorted array using recursive merge sort: ";
    cout << endl;

    mergeSortUsingRecursiveMethod(arr, 0, n - 1);

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;

    cout << "The resultant Sorted array using iterative merge sort: ";
    mergeSortUsingIterativeMethod(array2, n);

    cout << endl;

    for (int j = 0; j < n; j++)
    {
        cout << array2[j] << " ";
    }

    return 0;
}
