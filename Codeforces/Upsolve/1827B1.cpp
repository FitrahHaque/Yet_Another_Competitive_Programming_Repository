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
vector<int> par,sz;
int seg=0;
int find(int node){
    if(node == par[node])
        return node;
    return par[node] = find(par[node]);
}
void merge(int u,int v){
    int a = find(u);
    int b = find(v);
    if(a == b){
        return;
    }
    if(sz[a] < sz[b])
        swap(a,b);
    sz[a] += sz[b];
    par[b] = a;
    seg++;
}

void solve(int tc) {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	par = vector<int>(n);
	sz = vector<int>(n);
	ll ans = 0;
	for(int l=0;l<n;l++) {
		vector<int> pref(n);
		pref[l] = a[l];
		seg = 0;
		par[l] = l;
		sz[l] = 1;
		for(int i=l+1;i<n;i++) {
			pref[i] = max(pref[i-1],a[i]);
			par[i] = i;
			sz[i] = 1;
		}
		for(int r=l+1;r<n;r++) {
			while(r-sz[find(r)] >= l && a[r] < pref[r-sz[par[r]]]) {
				merge(r,r-sz[par[r]]);
				// cout << "i" << endl;
			}
			ans += seg;
		}
	}
	cout << ans << endl;
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