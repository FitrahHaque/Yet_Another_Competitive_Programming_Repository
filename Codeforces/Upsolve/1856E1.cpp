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
ll ans;
int dfs(int node=0){
	int sum = 0;
	vector<int> subtree;
	for(auto i:gp[node]) {
		int children = dfs(i);
		sum += children;
		subtree.pb(children);
	}
	int n = subtree.size();
	vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
	for(int i=0;i<n;i++){
		dp[i][0] = true;
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			//not taking i-th subtree
			dp[i][j] = dp[i-1][j];
			
			//taking i-th subtree
			if(subtree[i-1] <= j) {
				dp[i][j] = dp[i][j] | dp[i-1][j-subtree[i-1]];
			}
		}
	}
	//finding out the partition which is almost equal in size
	for(int i=sum/2;i>=0;i--) {
		if(dp[n][i] == true){
			ans += 1ll * (sum-i) * i;
			break;
		}
	}
	return sum+1;
}
void solve(int tc) {
	int n;
	cin >> n;
	gp = vector<vector<int>> (n);
	for(int i=1;i<n;i++) {
		int p;
		cin >> p;
		p--;
		gp[p].pb(i);
	}
	dfs();
	cout << ans << endl;
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