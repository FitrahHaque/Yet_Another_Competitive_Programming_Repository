#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		map<int, ll> leftRange;
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll r = n - i;
			ans += leftRange[a[i]] * r;
			leftRange[a[i]] += i + 1;
		}
		cout << ans << endl;
	}
}