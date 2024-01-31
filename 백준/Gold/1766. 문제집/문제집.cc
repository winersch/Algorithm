#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n, m;
int entry[32001];
vector<int> prob[32001];
vector<int> ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >>a >> b;
        entry[b]++;
        prob[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 1; i <= n; i++) {
        if (entry[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.top();
        q.pop();
        ans.push_back(curr);
        for (int i = 0; i < prob[curr].size(); i++) {
            int next = prob[curr][i];
            entry[next]--;
            if (entry[next] == 0){
                q.push(next);
            }
        }
    }

    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}
