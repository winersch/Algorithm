#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int one;
int zero;
pair<int, int> memoization[41];

pair<int, int> fibonacci(int n) {
    if (n == 0) {
        memoization[n] = make_pair(1, 0);
    } else if (n == 1) {
        memoization[n] = make_pair(0, 1);
    } else if (memoization[n] == make_pair(0, 0)) {
        memoization[n] = make_pair(fibonacci(n - 1).first + fibonacci(n - 2).first,
                                   fibonacci(n - 1).second + fibonacci(n - 2).second);
    }
    return memoization[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (memoization[a] == make_pair(0, 0)) {
            fibonacci(a);
        }
        cout << memoization[a].first << " " << memoization[a].second << "\n";
    }


    return 0;
}