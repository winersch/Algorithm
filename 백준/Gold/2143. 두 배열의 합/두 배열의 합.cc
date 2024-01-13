#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int t, n, m;
int arr1[1001];
int arr2[1001];
vector<int> v1, v2;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = arr1[i];
        v1.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += arr1[j];
            v1.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = arr2[i];
        v2.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += arr2[j];
            v2.push_back(sum);
        }
    }

    sort(v2.begin(), v2.end());
    long long ans = 0;
    for(int a : v1){
       int b = t - a;
       auto ub = upper_bound(v2.begin(), v2.end(), b);
       auto lb = lower_bound(v2.begin(), v2.end(),b);
       ans += (ub-lb);
    }

    cout << ans;
    return 0;
}