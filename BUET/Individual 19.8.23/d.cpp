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
const int MAX = 5e5+10;
vector<ll> prm;
void sieve(){
	vector<bool> np(MAX);
	for(int i=2;i<MAX;i++){
		if(!np[i])
			prm.pb(i);
		for(int j=0;j<prm.size() && 1LL*prm[j]*i<MAX;j++){
			np[i*prm[j]] = true;
			if(i%prm[j] == 0)
				break;
		}
	}
}
void factorize(int n,vector<int>&f){
	for(int i=0;i<prm.size() && 1LL*prm[i]*prm[i]<=n;i++){
		if(n%prm[i] == 0){
			f.pb(prm[i]);
			while(n%prm[i] == 0){
				n /= prm[i];
			}
		}
	}
	if(n>1){
		f.pb(n);
	}
	
}
void solve(int tc) {
	int n,q;
	cin >> n >> q;
	vector<int> a(n),on(n);
	vector<vector<int>> fact(n);
	map<int,bitset<200005>> p;
	for(int i=0;i<n;i++){
		cin >> a[i];
		factorize(a[i],fact[i]);
	}
	int cnt = 0;
	ll ans = 0;
	bitset<200005> sm;
	while(q--){
		int x;
		cin >> x;
		x--;
		sm = 0;
		if(on[x]){
			cnt--;
			for(int i:fact[x]){
				p[i][x] = 0;
			}
			for(int i:fact[x]){
				sm = sm | p[i];
			}
			ans -= cnt - sm.count();	
			on[x] = false;
		}
		else{
			for(int i:fact[x]){
				sm = sm | p[i];
			}
			ans += cnt - sm.count();
			cnt++;
			for(int i:fact[x]){
				p[i][x] = 1;
			}
			on[x] = true;
		}
		cout << ans << endl;
	}
}

int main() {
//#ifndef ONLINE_JUDGE
//    FileIO
//#endif
    IOS
    cout << setprecision(15) << fixed;
    sieve();
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
//    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}