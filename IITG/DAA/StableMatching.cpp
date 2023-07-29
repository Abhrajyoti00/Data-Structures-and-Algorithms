#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


bool pri(int N, vector<vector<int> > prefer, int w, int m, int mm){
    for(int  i =0; i<N; i++){
        if(prefer[w][i] == mm)
            return true;
        if(prefer[w][i] == m)
            return false;
    }
    return true;
}
void stable_match(int N, vector<vector<int> > prefer){
    vector<int> wPart(N,-1);
    vector<bool> free_men(N,true);
    // memset(wPart, -1, sizeof(wPart));
    // memset(free_men, true, sizeof(free_men));
    
    int freecount = N;
    int m;
    while(freecount>0){
        for(m = 0; m<N; m++){
            if(free_men[m] == true)
                {
                    break;
                }
        }
        for(int i = 0; i< N && free_men[m] == true; i++){
            int w = prefer[m][i];
            if(wPart[w-N] == -1) // means woman w is free
            {
                wPart[w-N] = m;
                freecount--;
                free_men[m] = false;
            }
            else // woomen is not free
            {
                int mm = wPart[w-N]; // the man with wehom the women is with currently
                // to check m or mm
                if(pri(N, prefer, w, m, mm) == false) // w prefers m over mm 
                {
                    wPart[w-N] = m;
                    free_men[mm] = true;
                    free_men[m] = false;   
                }
            }
        }
    }
    for(int i = 0; i<N; i++){
        cout<<"Woman "<<i << " Man"<<wPart[i]<<"\n";
    }
}

void solve() {
    int N;
    cin>>N;
    vector<vector<int> > prefer;
    for(int i=0; i<2*N; i++){
        vector<int>temp;
        for(int j = 0 ; j< N; j++)
            {
                int ele;
                cin>>ele;
                temp.emplace_back(ele);
            }
            prefer.emplace_back(temp);
    }
    stable_match(N, prefer);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}