#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define pii pair<int,int>

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            pq.push(a);
            if (pq.size() > n){
                pq.pop();
            }
        }
    }
    cout << pq.top();
    return 0;
}