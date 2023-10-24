#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int visited[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        queue<pair<int, string>> q;
        q.push({a, ""});
        fill_n(visited, 10001, 0);
        visited[a] = 1;
        while (!q.empty()) {
            int tmp = q.front().first;
            string str = q.front().second;
            q.pop();


            if (tmp == b) {
                cout << str << "\n";
                break;
            }

            if (tmp == 0) {
                int s;
                s = 9999;
                if (!visited[s])
                q.push({s, str + "S"});
                visited[s] = 1;
            } else {
                int d = tmp * 2;
                if (d > 9999) {
                    d %= 10000;
                }
                if (!visited[d])
                q.push({d, str + "D"});
                visited[d] = 1;
                int s;
                s = tmp - 1;
                if (!visited[s])
                q.push({s, str + "S"});
                visited[s] = 1;
                int l;
                if (tmp / 1000 > 0) {
                    l = ((tmp % 1000) * 10) + tmp / 1000;
                } else if (tmp / 100 > 0) {
                    l = tmp * 10;
                } else if (tmp / 10 > 0) {
                    l = tmp * 10;
                } else {
                    l = tmp * 10;
                }
                if (!visited[l])
                q.push({l, str + "L"});
                visited[l] = 1;
                int r;
                if (tmp / 1000 > 0) {
                    r = tmp / 10 + (tmp % 10) * 1000;
                } else if (tmp / 100 > 0) {
                    r = tmp /10 + (tmp%10) * 1000;
                } else if (tmp / 10 > 0) {
                    r = tmp / 10 + (tmp % 10) * 1000;
                } else {
                    r = tmp * 1000;
                }
                if (!visited[r])
                q.push({r, str + "R"});
                visited[r] = 1;
            }
        }

    }
    return 0;
}