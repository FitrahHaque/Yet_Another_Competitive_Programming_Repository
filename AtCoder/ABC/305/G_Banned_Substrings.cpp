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
const long long mod = 998244353;

/********************************************* this is boring *********************************************/
ll add(ll a,ll b){
	return (a+b)%mod;
}
ll mul(ll a,ll b){
	return (a*b)%mod;
}
ll sub(ll a,ll b){
	return ((a - b)%mod + mod)%mod;
}
struct Matrix{
	vector<vector<ll>> mat;
	int params;
	Matrix(){
		params = 2;
		mat = vector<vector<ll>> (2,vector<ll>(2));
	}
	Matrix(int _params){
		params = _params;
		mat = vector<vector<ll>> (params,vector<ll> (params));
	}
	Matrix operator*(const Matrix& other) const{
		Matrix prod(params);
		for(int i=0;i<params;i++){
			for(int j=0;j<params;j++){
				for(int k=0;k<params;k++){
					prod.mat[i][k] = add(prod.mat[i][k],mul(mat[i][j], other.mat[j][k]));
				}
			}
		}
		return prod;
	}
};
bool isValid(const string& pattern,vector<string> &a){
	for(const string& s:a){
		for(int i=0;i<(int)pattern.length()-(int)s.length()+1;i++){
			string temp = pattern.substr(i,(int)s.length());
			if(s == temp){
				return false;
			}
		}
	}
	return true;
}
Matrix Pow(Matrix x,ll n){
	Matrix ans(x.params);
	for(int i=0;i<ans.params;i++){
		ans.mat[i][i] = 1;
	}
	while(n){
		if(n&1){
			ans = ans * x;
		}
		x = x * x;
		n >>= 1;
	}
	return ans;
}
void solve(int tc) {
	ll n;
	int m;
	cin >> n >> m;
	vector<string> a(m);
	for(int i=0;i<m;i++){
		cin >> a[i];
	}

	int use = min(n,6LL);
	vector<string> valid;
	int nax = 1<<use;
	for(int mask=0;mask<nax;mask++){
		string s;
		for(int i=use-1;i>=0;i--){
			s += (mask & (1<<i)) ? "b" : "a";
		}
		if(isValid(s,a)){
			valid.pb(s);
		}
	}
	map<string,int> idx;
	for(int i=0;i<(int)valid.size();i++){
		idx[valid[i]] = i;
	}
	if(n<6){
		cout << (int)valid.size() << endl;
		return;
	}
	Matrix trans((int)valid.size());
	for(int i=0;i<(int)valid.size();i++){
		string next = valid[i].substr(1);
		if(idx.find(next+"a") != idx.end()){
			trans.mat[i][idx[next+"a"]] = 1;
		}
		if(idx.find(next+"b") != idx.end()){
			trans.mat[i][idx[next+"b"]] = 1;
		}
	}
	Matrix total = Pow(trans,n-6);
	ll ans = 0;
	for(int i=0;i<total.params;i++){
		for(int j=0;j<total.params;j++){
			ans = add(ans,total.mat[i][j]);
		}
	}
	cout << ans << endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//    FileIO
//#endif
    IOS
    // cout << setprecision(15) << fixed;

    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
//    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}