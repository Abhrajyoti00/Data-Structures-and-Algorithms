#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> v;
    while (i < n1 && j < n2 && k < n3)
    {
        if ((A[i] == B[j]) && (B[j] == C[k]))
        {
            v.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
        int prev_A = A[i - 1];
        int prev_B = B[j - 1];
        int prev_C = C[k - 1];
        while (A[i] == prev_A)
            i++;
        while (B[j] == prev_B)
            j++;
        while (C[k] == prev_C)
            k++;
    }
    if (v.size() == 0)
        return {-1};
    return v;
}
int32_t main()
{
    fast

        // ||| Author: Abhrajyoti Kundu |||
        // ||| DS-ALGO Lover |||

        int t = 1;
    vector<int> v;
    int n1 = 6;
    int n2 = 5;
    int n3 = 8;
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    v = commonElements(A, B, C, n1, n2, n3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    return 0;
}
