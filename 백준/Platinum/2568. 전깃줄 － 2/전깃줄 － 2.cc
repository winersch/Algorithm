#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> ans, idx;

int binarySearch(int idx) {
    int mid;
    int left = 0, right = ans.size() - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (ans[mid] < idx) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ans.push_back(v[0].second);
    idx.push_back(0);
    for (int i = 1; i < n; i++) {
        if (ans.back() < v[i].second) {
            ans.push_back(v[i].second);
            idx.push_back(ans.size() - 1);
        } else {
            int pos = binarySearch(v[i].second);
            ans[pos] = v[i].second;
            idx.push_back(pos);
        }
    }
    cout << n - ans.size() << "\n";

    int tmp = ans.size()-1;
    vector<int> t;
    for (int i = idx.size()-1; i >=0 ; i--) {
        if (tmp == idx[i]){
            tmp--;
        }else{
            t.push_back(v[i].first);
        }
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << "\n";
    }


    return 0;
}
