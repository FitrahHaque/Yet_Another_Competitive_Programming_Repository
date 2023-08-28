#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 mt(time(nullptr)); 
    freopen("input.txt", "w", stdout);

    int testcases = 100;
    cout << testcases << endl;
    for(int i=0;i<testcases;i++) {
        int n1 = 1 + mt() % 10000;
        int n2 = 1 + n1 + mt() % (10000 - n1);
        cout << n1 << " " << n2 << endl;
    }
}