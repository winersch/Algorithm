#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;


int n, k;
int visit[100001];

void bfs(int a) {
    queue<pair<int, int>> q;
    q.push({a, 0});
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == k){
            cout  << y;
            break;
        }
        if (x+1 >= 0 && x+1<100001){
            if (!visit[x+1]){
                visit[x+1] = 1;
                q.push({x+1, y+1});
            }
        }
        if (x-1 >= 0 & x-1 < 100001){
            if (!visit[x-1]){
                visit[x-1] = 1;
                q.push({x-1, y+1});
            }
        }
        if (x*2 >= 0 && x*2 < 100001){
            if (!visit[x*2]){
                visit[x*2] = 1;
                q.push({x*2,y+1});
            }
        }

    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> k;
    visit[n] = 1;
    bfs(n);

    return 0;

}