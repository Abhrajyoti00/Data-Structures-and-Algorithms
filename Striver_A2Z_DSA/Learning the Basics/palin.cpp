#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    int k, r, s = 0;
    k = x;
    if (k != 0 && (k < 0 || k % 10 == 0))
        return false;
    while (s < x)
    {
        r = x % 10;
        s = s * 10 + r;
        x /= 10;
    }
    if (s == x || x == s / 10)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    cout << isPalindrome(n);
}