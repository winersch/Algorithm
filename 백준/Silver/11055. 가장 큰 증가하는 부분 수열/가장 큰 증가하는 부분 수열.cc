#include <iostream>

using namespace std;

int main() {
    int n, result = 0;
    int *sequence, *dp;

    cin >> n;

    sequence = new int[n];
    dp = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = sequence[i];
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j]) {
                dp[i] = max(dp[i], dp[j] + sequence[i]);
                result = max(result, dp[i]);
            }
        }
    }
    if (result == 0) {
        for (int i = 0; i < n; i++) {
            result = max(result, sequence[i]);
        }
    }
    cout << result;


    return 0;
}
