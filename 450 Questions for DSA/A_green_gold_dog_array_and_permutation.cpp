#include<bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> perM_b(n);
    
        for (int i = 0; i < n; i++) {
            perM_b[i] = i + 1;
        }
    
        random_shuffle(perM_b.begin(), perM_b.end());

            for (int i = 0; i < n; i++) {
                cout << perM_b[i] << " ";
            }
            cout << endl;
    }

    return 0;
}
