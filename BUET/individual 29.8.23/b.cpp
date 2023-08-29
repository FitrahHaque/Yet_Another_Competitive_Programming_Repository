// C++ program to implement
// the above approach
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
#include <bits/stdc++.h>
using namespace std;

// Utility function to find cross product
// of two vectors
int CrossProduct(vector<vector<int> >& A)
{
	// Stores coefficient of X
	// direction of vector A[1]A[0]
	int X1 = (A[1][0] - A[0][0]);

	// Stores coefficient of Y
	// direction of vector A[1]A[0]
	int Y1 = (A[1][1] - A[0][1]);

	// Stores coefficient of X
	// direction of vector A[2]A[0]
	int X2 = (A[2][0] - A[0][0]);

	// Stores coefficient of Y
	// direction of vector A[2]A[0]
	int Y2 = (A[2][1] - A[0][1]);

	// Return cross product
	return (X1 * Y2 - Y1 * X2);
}

// Function to check if the polygon is
// convex polygon or not
bool isConvex(vector<vector<int> >& points)
{
	// Stores count of
	// edges in polygon
	int N = points.size();

	// Stores direction of cross product
	// of previous traversed edges
	int prev = 0;

	// Stores direction of cross product
	// of current traversed edges
	int curr = 0;

	// Traverse the array
	for (int i = 0; i < N; i++) {

		// Stores three adjacent edges
		// of the polygon
		vector<vector<int> > temp
			= { points[i],
				points[(i + 1) % N],
				points[(i + 2) % N] };

		// Update curr
		curr = CrossProduct(temp);

		// If curr is not equal to 0
		if (curr != 0) {

			// If direction of cross product of
			// all adjacent edges are not same
			if (curr * prev < 0) {
				return false;
			}
			else {
				// Update curr
				prev = curr;
			}
		}
	}
	return true;
}

// Driver code
int main()
{
	// vector<vector<int> > points
	// 	= { { 0, 0 }, { 0, 1 },
	// 		{ 1, 1 }, { 1, 0 } };
	while(true) {
		vector<vector<int>> points;
		int n;
		cin >> n;
		if(n == 0){
			return 0;
		}
		for(int i=0;i<n;i++) {
			vector<int> p(2);
			cin >> p[0] >> p[1];
			points.pb(p);
		}
		if (isConvex(points)) {
			cout << "No"
				<< "\n";
		}
		else {
			cout << "Yes"
				<< "\n";
		}
	}
}
