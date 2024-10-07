#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int team[501];
bool adj[501][501];
int entry[501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        memset(team, 0, sizeof(team));
        memset(adj, false, sizeof(adj));
        memset(entry, 0, sizeof(entry));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> team[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                adj[team[i]][team[j]] = true;
                entry[team[j]]++;
            }
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b]){
                adj[a][b] = false;
                adj[b][a] = true;
                entry[b]--;
                entry[a]++;
            }else{
                adj[b][a] = false;
                adj[a][b] = true;
                entry[a]--;
                entry[b]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (entry[i] == 0){
                q.push(i);
            }
        }
        vi ans;
        bool check = false;
        while(!q.empty()){
            if (q.size() >= 2){
                check = true;
                break;
            }
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (int i = 1; i <= n; i++) {
                if (adj[curr][i]){
                    entry[i]--;
                    if (entry[i] == 0){
                        q.push(i);
                    }
                }
            }
        }
        if (check){
            cout << "?";
        }else{
            if (ans.size() != n){
                cout << "IMPOSSIBLE";
            }else{
                for(int a : ans){
                    cout << a << " ";
                }
            }
        }

        cout << endl;

    }

    return 0;
}