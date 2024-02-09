#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

int n;
vector<pair<int,int>> v;
vector<int> ans;

int binarySearch(int idx){
    int mid;
    int left = 0;
    int right = ans.size()-1;

    while (left < right){
        mid = (left + right)/2;
        if (ans[mid] < idx){
            left = mid + 1;
        } else{
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
        v.push_back({a,b});
    }

    std::sort(v.begin(), v.end());
    
    ans.push_back(v[0].second);
    
    for (int i = 1; i < n; i++) {
        if (ans.back() < v[i].second){
            ans.push_back(v[i].second);
        }else{
            int pos = binarySearch(v[i].second);
            ans[pos] = v[i].second;
        }
    }
    cout << n - ans.size();
    return 0;
}