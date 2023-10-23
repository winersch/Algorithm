#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        priority_queue<int, vector<int>, greater<int>> pqg;
        priority_queue<int, vector<int>, less<int>> pql;
        map<int, int> cnt;

        int num = 0;
        for (int j = 0; j < a; j++) {
            char ch;
            int input;

            cin >> ch >> input;

            if (ch == 'I') {
                pqg.push(input);
                pql.push(input);
                cnt[input]++;
            } else if (ch == 'D') {
                if (input == -1 && !pqg.empty()) {
                    cnt[pqg.top()]--;
                    pqg.pop();
                } else if (input == 1 && !pql.empty()) {
                    cnt[pql.top()]--;
                    pql.pop();
                }
                while (!pqg.empty() && cnt[pqg.top()] == 0) {
                    pqg.pop();
                }
                while (!pql.empty() && cnt[pql.top()] == 0) {
                    pql.pop();
                }
            }

        }
        if (pqg.empty() || pql.empty()) {
            cout << "EMPTY" << "\n";
        } else {
            cout << pql.top() << " " << pqg.top() << "\n";
        }

    }

    return 0;
}