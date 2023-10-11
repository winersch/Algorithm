#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    long long int result = 0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int high = arr[n - 1];
    int low = 0;
    long long int mid;

    while (low <= high) {
        long long int sum = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                sum += arr[i] - mid;
            }
        }
        if (sum >= m) {
            low = mid + 1;
            if (mid > result) result = mid;
        } else {
            high = mid - 1;
        }

    }
    cout << result;

    return 0;
}