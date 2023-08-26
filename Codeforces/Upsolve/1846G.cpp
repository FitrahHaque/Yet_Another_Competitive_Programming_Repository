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
vector<vector<ll>> dp,gp;
vector<int> d,heal,side;
int n,m,nax;
int stringToInt(string s) {
	reverse(all(s));
	int ans=0;
	for(int i=0;i<s.size();i++) {
		if(s[i] == '1'){
			ans += 1<<i;
		}
	}
	return ans;
}
void init() {
	for(int mask=0;mask<nax;mask++) {
		for(int i=0;i<m;i++) {
			int nask = mask ^ heal[i];
			nask &= mask;
			nask = nask | side[i];
			gp[mask][nask] = min(gp[mask][nask], (ll)d[i]);
		}
	}
}
ll getwell(int src) {
	std::priority_queue<pair<ll,int>> q;//(days so far, current submask)
	dp[src][src] = 0;
	q.push(mp(0,src));
	while(!q.empty()) {
		ll days = -q.top().ff;
		ll mask = q.top().ss;
		q.pop();
		if(mask == 0){
			return days;
		}
		for(int i=0;i<m;i++) {
			int nask = mask ^ heal[i];
			nask &= mask;
			nask = nask | side[i];
			ll w = gp[mask][nask];
			ll tmp = days + w;
			if(dp[mask][nask] > tmp) {
				dp[mask][nask] = tmp;
				q.push(mp(-tmp,nask));
			}
		}
	}
	return -1;
}
void solve(int tc) {
	cin >> n >> m;
	string _;
	cin >> _;
	int initialSymptom = stringToInt(_);
	d = vector<int> (m);
	heal = vector<int> (m);
	side = vector<int> (m);
	for(int i=0;i<m;i++) {
		string a,b;
		cin >> d[i] >> a >> b;
		heal[i] = stringToInt(a);
		side[i] = stringToInt(b);
	}
	nax = 1<<n;
	dp = vector<vector<ll>> (nax,vector<ll>(nax,INFL));
	gp = vector<vector<ll>> (nax,vector<ll>(nax,INFL));
	init();
	cout << getwell(initialSymptom) << endl;
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