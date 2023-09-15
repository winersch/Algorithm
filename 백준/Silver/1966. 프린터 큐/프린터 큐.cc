#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int n, m, cnt = 1;
        cin >> n >> m;
        queue<pair<int, int>> q;
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            v.push_back(a);
            q.push(make_pair(a, j));
        }
        sort(v.rbegin(), v.rend());
        while (!q.empty()) {
            if (v[cnt - 1] == q.front().first) {
                if (q.front().second == m) {
                    break;
                }
                cnt++;
                q.pop();
            } else {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                q.push(make_pair(a, b));
            }
        }
        cout << cnt << "\n";
    }


    return 0;
}
