#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> input[101];
vector<int> graph[1001];
vector<int> ans;
int entry[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            input[i].push_back(b);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < input[i].size(); j++) {
            graph[input[i][j-1]].push_back(input[i][j]);
            entry[input[i][j]]++;
        }
    }

    queue<int> q;
    bool isok = false;
    for (int i = 1; i <= n; i++) {
        if (entry[i] == 0){
            q.push(i);
            isok = true;
        }
    }
    if (!isok){
        cout << 0;
        return 0;
    }



    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            entry[next]--;
            if (entry[next] == 0){
                q.push(next);
            }
        }
    }

    if (ans.size() != n){
        cout << 0;
        return 0;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}