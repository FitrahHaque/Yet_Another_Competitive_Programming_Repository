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

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> L(n),R(n),A(n),B(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> L[i] >> R[i] >> A[i] >> B[i];
        s.insert(L[i]);
        s.insert(R[i]);
        s.insert(A[i]);
        s.insert(B[i]);
    }
    int qq;
    cin >> qq;
    vector<int> X(qq);
    for(int i=0;i<qq;i++){
        cin >> X[i];
        s.insert(X[i]);
    }
    vector<int> rIdx;
    //coordinate compression
    map<int,int> idx;
    int c=0;
    for(int i:s){
        idx[i] = c++;
        rIdx.pb(i);
    }
    int p=0;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++){
        v.pb(mp(idx[R[i]],mp(idx[B[i]],idx[L[i]])));
    }
    sort(all(v));
    reverse(all(v));   
    std::priority_queue<pair<int,int>> q;
    vector<int> ans(c);
    for(int i=0;i<c;i++){
        ans[i] = i;
    }
    for(int i=c-1;i>=0;i--){
        while(p<n && v[p].ff == i){
            q.push(mp(v[p].ss.ff,p));
            p++;
        }
        while(!q.empty() && v[q.top().ss].ss.ss > i){
            q.pop();
        }
        if(!q.empty()) {
            ans[i] = max(ans[i],ans[q.top().ff]);
        }
    }
    // cout << "size: " << rIdx.size() << endl;
    // cout << rIdx[ans[idx[X[0]]]] << endl;
    for(int i=0;i<qq;i++){
        cout << rIdx[ans[idx[X[i]]]] << " ";
    }
    cout << endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//    FileIO
//#endif
    IOS
    cout << setprecision(15) << fixed;

    int tc = 1;
   cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
//    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}
