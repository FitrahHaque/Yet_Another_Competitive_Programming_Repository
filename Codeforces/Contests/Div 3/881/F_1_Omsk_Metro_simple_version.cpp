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
vector<vector<int>> gp;
struct Vertex{
    int x,minSumSoFar,maxSumSoFar,minSumEndingHere,maxSumEndingHere;
    Vertex(){minSumEndingHere = 0,maxSumEndingHere = 0,maxSumSoFar = 0,minSumSoFar = 0;}
    Vertex(int _x) : x(_x) {
        minSumEndingHere = 0,maxSumEndingHere = 0,maxSumSoFar = 0,minSumSoFar = 0;
    }
    
};
vector<Vertex> p;
void inherit(Vertex& u, Vertex &v){
    v.maxSumEndingHere = max(u.maxSumEndingHere + v.x,0);
    v.maxSumSoFar = max(u.maxSumSoFar,v.maxSumEndingHere);
    v.minSumEndingHere = max(u.minSumEndingHere + (-v.x),0);
    v.minSumSoFar = max(u.minSumSoFar, v.minSumEndingHere);
}
void solve(int tc) {
    gp.pb(vector<int>());
    p.pb(Vertex(1));
    p[0].maxSumEndingHere = 1;
    p[0].maxSumSoFar = 1;
    int n=1,q;
    cin >> q;
    while(q--){
        char type;
        cin >> type;
        if(type == '+'){
            int u,x;
            cin >> u >> x;
            u--;
            gp.pb(vector<int>());
            gp[u].pb(n);
            p.pb(Vertex(x));
            inherit(p[u],p[n]);
            n++;
        }
        else{
            int u,v,k;
            cin >> u >> v >> k;
            u--,v--;
            if(k<0){
                k = abs(k);
                if(p[v].minSumSoFar >= k){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            } 
            else{
                if(p[v].maxSumSoFar >= k){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }
    }
    for(auto i=0;i<gp.size();i++){
        gp[i].clear();
    }
    gp.clear();
    p.clear();
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