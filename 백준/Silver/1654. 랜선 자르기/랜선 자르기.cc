#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long int k, n, cnt, max_length;
vector<long long int> length;

int find() {
    long long int low = 1;
    long long int high = length[k - 1] + 1;
    long long int mid = (low + high) / 2;
    while (low < high) {
        mid = (low + high) / 2;

        if (low == mid || high == mid) {
            break;
        }
        for (int i = 0; i < k; i++) {
            cnt += length[i] / mid;
        }
        if (cnt >= n) {
            low = mid ;
        } else {
            high = mid;
        }
        cnt = 0;
    }
    return mid;
}

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        long long int a;
        cin >> a;
        length.push_back(a);
    }

    sort(length.begin(), length.end());
    max_length = find();
    cout << max_length;


    return 0;
}