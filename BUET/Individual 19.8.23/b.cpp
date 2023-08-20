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
	while(true){
		ll m,c1,c2,n1,n2;
		cin >> m;
		if(m == 0)
			return;
		cin >> c1 >> n1 >> c2 >> n2;
		ll g = __gcd(n1,n2);
		if(m%g){
			cout << "failed" << endl;
			continue;
		}
		if(n1 == 1 && n2 == 1){
			if(c1 < c2){
				cout << m << " " << 0 << endl;
			}
			else{
				cout << 0 << " " << m << endl;
			}
			continue;
		}
		ll ans = INF,x,y;
		if(n1>n2){
			for(ll i=0;i<=m/n1;i++){
				ll left = m - n1*i;
				if(left%n2 == 0 && (i*c1 + (left/n2)*c2) < ans){
					ans = i*c1 + (left/n2)*c2;
					x = i;
					y = left/n2;
				}
			}
		}
		else {
			for(ll i=0;i<=m/n2;i++){
				ll left = m - n2*i;
				if(left%n1 == 0 && (i*c2 + (left/n1)*c1) < ans){
					ans = i*c2 + (left/n1)*c1;
					y = i;
					x = left/n1;
				}
			}
		}
		cout << x << " " << y << endl;
	}
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