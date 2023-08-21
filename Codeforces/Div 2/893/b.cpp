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
	int n,m,d;
	cin >> n >> m >> d;
	vector<int> a(m+1);
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	a[m] = n;
	vector<int> pref(m+2),cnt(m+2);
	pref[0] = a[0] != 1;
	for(int i=0;i<=m;i++){
		int dist = i ? a[i] - a[i-1] : a[i] - 1;
		pref[i+1] = pref[i] + dist/d;
		if(i<m && dist%d){
			pref[i+1]++;
		}
		else if(i == 0 && a[i] == 1){
			pref[i+1]++;
		}
	}
	// for(int i=0;i<=m+1;i++){
	// 	cout << i << ":" << pref[i] << endl;
	// }
	// pref[m+1] = pref[m] + (n - a[m-1])/d;
	int nin = INF;
	for(int i=1;i<=m;i++){
		cnt[i] = pref[i-1] + pref[m+1] - pref[i+1];
		if(i == 1 && pref[0] == 0){
			cnt[i]++;
		}
		int dist = i-1 ? a[i] - a[i-2] : a[i] - 1;
		cnt[i] += dist/d;
		if(i<m && dist%d){
			cnt[i]++;
		}
		nin = min(cnt[i],nin);
	}
	// for(int i=1;i<=m;i++){
	// 	cout << i << ":" << cnt[i] << endl;
	// }
	int c = 0;
	for(int i=1;i<=m;i++){
		if(cnt[i] == nin){
			c++;
		}
	}
	cout << nin << " " << c << endl;
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