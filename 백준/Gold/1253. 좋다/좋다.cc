#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define pii pair<int,int>

int n, ans;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while(l < r){
            if (l == i){
                l++;
                continue;
            }
            if (r == i){
                r--;
                continue;
            }
            if (v[l] + v[r] == v[i]){
                ans++;
                break;
            }
            if (v[l] + v[r] < v[i]){
                l++;
            }else{
                r--;
            }
        }
    }


    cout << ans;
    return 0;
}