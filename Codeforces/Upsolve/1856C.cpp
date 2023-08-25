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
vector<ll> a;
ll n,k;
ll f(int i,ll x) {
	if(x <= a[i])
		return 0;
	if(i == n-1) {
		return INFL;
	}
	return x - a[i] + f(i+1,x-1);
}
bool good(ll x) {
	ll res = INFL;
	for(int i=0;i<n;i++) {
		ll steps = f(i,x);
		res = min(res,steps);
	}
	return res <= k;
}
ll binSearch(ll r) {
	ll l = 0;
	while(r>l+1) {
		ll mid = (l+r)/2;
		if(good(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return l;
}
void solve(int tc) {
	cin >> n >> k;
	a = vector<ll> (n);
	ll mx = 0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	ll ans = binSearch(mx+k+1);
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
