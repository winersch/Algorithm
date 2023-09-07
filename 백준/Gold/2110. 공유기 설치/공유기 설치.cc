#include <iostream>
#include <algorithm>


using namespace std;
int n, c, cnt, dist;
vector<int> house;

int main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        house.push_back(tmp);
    }

    sort(house.begin(), house.end());
    int low = 1;
    int high = 1000000001;
    while (low < high) {
        int mid = (high + low) / 2;
        cnt = 1;
        int start = house[0];

        for (int i = 0; i < n; i++) {
            int end = house[i];
            if (end - start >= mid) {
                cnt++;
                start = end;
            }
        }
        if (cnt >= c) {
            dist = max(mid, dist);
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << dist;

    return 0;
}
