#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#include <list>
#include <unordered_set>
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

bool visited[1024];
vi mask;

int bfs(int start){
    queue<pii> q;
    memset(visited,false,sizeof(visited));
    visited[start] = true;
    q.push({start,0});
    while(!q.empty()){
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (curr == 0 || curr == 511){
            return cost;
        }
        for(int m : mask){
            int next = curr ^ m;
            if (!visited[next]){
                visited[next] = true;
                q.push({next, cost+1});
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;

    mask.push_back((1 << 0) | (1 << 1) | (1 << 2));
    mask.push_back((1 << 3) | (1 << 4) | (1 << 5));
    mask.push_back((1 << 6) | (1 << 7) | (1 << 8));

    mask.push_back((1 << 0) | (1 << 3) | (1 << 6));
    mask.push_back((1 << 1) | (1 << 4) | (1 << 7));
    mask.push_back((1 << 2) | (1 << 5) | (1 << 8));

    mask.push_back((1 << 0) | (1 << 4) | (1 << 8));
    mask.push_back((1 << 2) | (1 << 4) | (1 << 6));

    while(t--){
        int bit = 0;
        for (int i = 0; i < 9; i++) {
            char c;
            cin >> c;
            if (c == 'H'){
                bit |= (1 << (i));
            }
        }
        cout << bfs(bit) << "\n";
    }


    return 0;
}