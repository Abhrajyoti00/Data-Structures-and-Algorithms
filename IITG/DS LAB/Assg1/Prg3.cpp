// Count the number of peaks in a given 2D-array. An element is a peak at index [i][j] if A[i][j] >
// A[i-1][j-1], A[i-1][j+1], A[i+1][j-1], A[i+1][j+1]. Consider 1<= i, j <= M-2 for an MxM matrix [Do
// not consider the elements at the boundary of the matrix, having row or column as 0 or M-1].
// Return -1 if no peak exists.



#include<bits/stdc++.h>
using namespace std;

int noOfPeaks(int* matrix[], int m) {
    int count = 0;
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if ((matrix[i][j] > matrix[i - 1][j - 1] &&
                matrix[i][j] > matrix[i - 1][j + 1] &&
                matrix[i][j] > matrix[i + 1][j - 1] &&
                matrix[i][j] > matrix[i + 1][j + 1]))
                    count++;
        }
    }
    if (count > 0)
        return count;
    else
        return -1;
}

int main() {
    int m;
    cout << "Enter the number for rows and cols: \n";
    cin >> m;
    int** matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }

    cout << "Enter the elements: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int peaks = noOfPeaks(matrix, m);
    if (peaks == -1) {
        cout << "No peak exists.\n";
    } else {
        cout << "Number of peaks: " << peaks << endl;
    }
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
