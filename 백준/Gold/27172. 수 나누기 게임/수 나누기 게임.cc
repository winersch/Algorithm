#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;


int player[1000001];
int input[1000001];
int ans[1000001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        player[a]++;
        input[i] = a;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; input[i] * j < 1000001; j++) {
            if (player[input[i] * j] != 0) {
                ans[input[i]]++;
                ans[input[i]*j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[input[i]] << " ";
    }

    return 0;
}