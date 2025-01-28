#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        vector<int> v;
        cin >> n;
        for (int i = 0; i < 20; i++) {
            int a;
            cin >> a;
            v.push_back(a);
            for (int j = 0; j < v.size()-1; j++) {
                if (v[j] > a){
                    for (int k = v.size()-1; k > j; k--) {
                        v[k] = v[k-1];
                        ans++;
                    }
                    v[j] = a;
                    break;
                }
            }
        }
        cout << n << " " << ans << "\n";
    }


    return 0;
}