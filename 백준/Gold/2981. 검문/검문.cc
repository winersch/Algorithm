#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int n;
vector<int> ans, arr;

int getGCD(int a, int b){
    return a % b ? getGCD(b, a%b) : b;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int gcd = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        gcd = getGCD(gcd, arr[i] - arr[i-1]);
    }

    for (int i = 2; i * i <= gcd; i++) {
        if (gcd%i == 0){
            ans.push_back(i);
            ans.push_back(gcd/i);
        }
    }
    ans.push_back(gcd);
    std::sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),ans.end()), ans.end());

    for(int a : ans){
        cout << a << " ";
    }

    return 0;
}