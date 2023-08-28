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
string l,r;
ll ans,diff;
int digitDP(vector<vector<vector<vector<vector<int>>>>> &dp,int n,int node=0,ll num=0,int currentMin=9,int currentMax=0,bool smaller=false,bool bigger=false) {
	if(node == n) {
		if(currentMax - currentMin < diff) {
			ans = num;
			// cout << num << endl;
			diff = currentMax - currentMin;
			return 1;
		}
		return 0;
	}
	if(dp[node][currentMin][currentMax][smaller][bigger] != -1) {
		return dp[node][currentMin][currentMax][smaller][bigger];
	}
	int top = smaller ? 9 : r[node] - '0';
	int bottom = bigger ? 0 : l[node] - '0';
	dp[node][currentMin][currentMax][smaller][bigger] = 0;
	for(int i=bottom;i<=top;i++) {
		dp[node][currentMin][currentMax][smaller][bigger] += digitDP(dp,n,node+1,num*10+i,(num || i) ? min(currentMin,i):currentMin,(num || i) ? max(currentMax,i):currentMax,smaller || (i<top),bigger || (i>bottom));
	}
	// for(int i=top;i>=bottom;i--) {
	// 	dp[node][smaller][bigger] += digitDP(dp,n,mini,maxi,node+1,num*10+i,min(currentMin,i),max(currentMax,i),smaller || (i<top),bigger || (i>bottom));
	// }
	return dp[node][currentMin][currentMax][smaller][bigger];
}
void check(int n) {
	ans = -1,diff = 11;
	vector<vector<vector<vector<vector<int>>>>> dp(n,vector<vector<vector<vector<int>>>>(10,vector<vector<vector<int>>>(10,vector<vector<int>>(2,vector<int>(2,-1)))));
	int res = digitDP(dp,n);
}
int process() {
	int n = r.length();
	int z = n - l.length();
	string add;
	while(z--){
		add += "0";
	}
	l = add + l;
	return n;
}
void solve(int tc) {
	cin >> l >> r;
	int n = process();
	check(n);
	cout << diff << endl;
}

int main() {
//#ifndef ONLINE_JUDGE
   // FileIO
//#endif
    IOS
    // freopen("output.txt", "w", stdout);
    cout << setprecision(15) << fixed;

    int tc = 1;
   cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
//    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}