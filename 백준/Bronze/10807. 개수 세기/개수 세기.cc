#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int arr[201];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a+100]++;
    }

    int t;
    cin >> t;
    cout << arr[t+100];

    return 0;
}