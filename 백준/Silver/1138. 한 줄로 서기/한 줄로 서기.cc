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
#include <list>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    vi v(n);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        for (int j = 0; j < n; j++) {
            if (a == 0 && v[j] == 0){
                v[j] = i;
                break;
            }
            if (v[j] == 0){
                a--;
            }
        }

    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }


    return 0;
}

