#include <bits/stdc++.h>
using namespace std;

void rotate(int a[], int n)
{
    int i, t, d;
    t = a[n-1];
    for (i = n-1; i > 0; i--)
    {   
        a[i] = a[i-1];
    }
    a[0] = t;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], i;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}