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
struct Dim{
	ll h,w,d;
	Dim(){}
	Dim(int _h,int _w,int _d) : h(_h), w(_w), d(_d) {}
	void sort(){
		ll o = min({h,w,d});
		ll t = max({h,w,d});
		ll s = h+w+d-o-t;
		h = o;
		w = s;
		d = t;
	}
};

//change here
struct Item {
    ll d;
    Item() : d(INFL){}

    Item(ll _d) : d(_d) {}
};

struct SegTree {
    int size;
    vector<Item> value;
    Item NEUTRAL_ELEMENT;

    vector<Item> prop;
    ll NO_PROPAGATION;

    SegTree(int _size) {
        size = _size;
        value = vector<Item>(4 * size);
        NEUTRAL_ELEMENT = Item();//change here, used for merging
        NO_PROPAGATION = INFL;//change here,used for modifying
        prop = vector<Item>(4 * size, Item(NO_PROPAGATION));
    }

    //change here
    Item modify(Item &a, Item &b, ll len) {//operation which is given as an update to each segment; propagation happens only on this operation
        Item ans;
        if (b.d == NO_PROPAGATION) {
           ans.d = a.d;
        } else {
            ans.d = min(a.d,b.d);
        }
        return ans;
    }

    void propagate(int node, int l, int r) {
        if (l == r)
            return;
        int mid = l + (r - l) / 2;
        prop[2 * node + 1] = modify(prop[2 * node + 1], prop[node], 1);
        prop[2 * node + 2] = modify(prop[2 * node + 2], prop[node], 1);
        value[2 * node + 1] = modify(value[2 * node + 1], prop[node], mid - l + 1);
        value[2 * node + 2] = modify(value[2 * node + 2], prop[node], r - mid);
        prop[node] = Item(NO_PROPAGATION);
    }

    //change here
    Item merge(Item &a, Item &b) {//operation for merging two segments at inner nodes 
        Item ans;
        ans.d = min(a.d,b.d);
        return ans;
    }

    //change here
    Item single(ll v) {
        return Item(v);
    }

    void build(vector<int>& a,int node, int l, int r) {
        if (l == r) {
            value[node] = single(a[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(a,2 * node + 1, l, mid);
        build(a,2 * node + 2, mid + 1, r);
        value[node] = merge(value[2 * node + 1], value[2 * node + 2]);
    }

    void build(vector<int>& a) {
        build(a,0, 0, size - 1);
    }

    void update(int ql, int qr, Item v, int node, int l, int r) {
        propagate(node, l, r);
        if (l > qr || r < ql)
            return;
        if (ql <= l && r <= qr) {
            prop[node] = modify(prop[node], v, 1);
            value[node] = modify(value[node], v, r - l + 1);
            return;
        }
        int mid = l + (r - l) / 2;
        update(ql, qr, v, 2 * node + 1, l, mid);
        update(ql, qr, v, 2 * node + 2, mid + 1, r);
        value[node] = merge(value[2 * node + 1], value[2 * node + 2]);
    }


    void update(int l, int r, ll v) {
        update(l, r, single(v), 0, 0, size - 1);
    }

    Item query(int ql, int qr, int node, int l, int r) {
        propagate(node, l, r);
        if (l > qr || r < ql)
            return NEUTRAL_ELEMENT;
        if (ql <= l && r <= qr) {
            return value[node];
        }
        int mid = l + (r - l) / 2;
        Item q1 = query(ql, qr, 2 * node + 1, l, mid);
        Item q2 = query(ql, qr, 2 * node + 2, mid + 1, r);
        return merge(q1, q2);
    }

    Item query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }
};

void solve(int tc) {
	 int n;
	 cin >> n;
	 vector<Dim> a(n);
	 set<ll> s;
	 map<ll,int> idx;
	 for(int i=0;i<n;i++){
	 	cin >> a[i].h >> a[i].w >> a[i].d;
	 	a[i].sort();
	 	s.insert(a[i].w);
	 }
	 sort(all(a),[&](Dim& x,Dim& y){
	 	return x.h < y.h;
	 });
	 int cnt=0;
	 for(auto i:s){
	 	idx[i] = cnt++;
	 }
	 SegTree tree(cnt);
	 queue<int> q;
	 for(int i=0;i<n;i++){
	 	if(!q.empty() && a[q.front()].h < a[i].h){
	 		while(!q.empty()){
	 			int id = q.front();
	 			q.pop();
	 			tree.update(idx[a[id].w], idx[a[id].w], a[id].d);
	 		}
	 	}
	 	auto nin = tree.query(0,idx[a[i].w]-1);
	 	if(nin.d < a[i].d){
	 		cout << "Yes" << endl;
	 		return;
	 	}
	 	q.push(i);
	 }
	 cout << "No" << endl;
	 return;
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