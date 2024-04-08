#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 10007
#define ll long long
using namespace std;

map<int, int> map1;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        map1.clear();
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            map1[a]++;
        }
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (map1[a] == 0){
                cout << 0 << "\n";
            }else{
                cout << 1 << "\n";
            }
        }
    }

    return 0;
}