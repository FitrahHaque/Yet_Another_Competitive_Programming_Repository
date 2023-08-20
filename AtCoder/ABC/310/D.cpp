#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nline "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second
#define repv(i, m) for(auto (i) = (m).begin();(i) != (m).end();(i)++)
#define FileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

string to_string(char x) { return (string) "\'" + x + "\'"; }

string to_string(const string &x) { return '\"' + x + '\"'; }

string to_string(const char *x) { return to_string((string) x); }

string to_string(bool x) { return x ? "true" : "false"; }

template<typename T, typename V>
string to_string(const pair <T, V> &x) { return '(' + to_string(x.first) + ',' + to_string(x.second) + ')'; }

template<typename T>
string to_string(const T &x) {
    int f = 0;
    string r;
    for (auto &i: x) r += (f++ ? "," : "") + to_string(i);
    return '{' + r + '}';
}

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    cerr << to_string(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

template<typename T>
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x...)  cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(...)
#endif
const long long INFL = 4000000000000000000LL;
const int INF = 2047483647;
const long long mod = 1000000007LL;

/********************************************* this is boring *********************************************/
vector<bool> bad;
vector<vector<bool>> foe;
vector<vector<ll>> dp;
void solve(int tc) {
    int n,t,m;
    cin >> n >> t >> m;
    ll fact = 1;
    for(int i=2;i<=t;i++)
        fact *= i;
    int nax = 1<<n;
    foe = vector<vector<bool>> (n,vector<bool>(n));
    bad = vector<bool> (nax);
    bad[0] = true;
    dp = vector<vector<ll>> (t+1,vector<ll>(nax));
    dp[0][0] = 1;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        foe[u][v] = foe[v][u] = true; 
    }
    for(int mask=0;mask<nax;mask++){
        for(int i=0;i<n && !bad[mask];i++){
            if(!(mask&(1<<i)))
                continue;
            for(int j=i+1;j<n;j++){
                if(!(mask&(1<<j)))
                    continue;
                if(foe[i][j]){
                    bad[mask] = true;
                    break;
                }
            }
        }
    }
    for(int k=1;k<=t;k++){
        for(int mask=1;mask<nax;mask++){
            for(int subMask=mask;subMask;subMask = (subMask-1)&mask){
                if(!bad[subMask]){
                    dp[k][mask] += dp[k-1][mask^subMask];
                }
            }
        }
    }
    dp[t][nax-1] /= fact;
    cout << dp[t][nax-1] << endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//    FileIO
//#endif
    IOS
    cout << setprecision(15) << fixed;

    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
//    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}