#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int arr[10001];
int ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = arr[i];
        if (sum == m) {
            ans++;
            continue;
        }
        for (int j = i+1; j < n; j++) {
            if (sum > m) {
                break;
            }
            sum += arr[j];
            if (sum == m) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}