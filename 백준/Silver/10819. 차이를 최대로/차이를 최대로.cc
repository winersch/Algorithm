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
vi v;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    int ans = 0;

    do{
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(v[i] - v[i+1]);
        }
        ans = max(ans, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;
    return 0;
}

