#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define inf 2000000000

using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
int visited[1001];
int start, dest;


void dijkstra() {
    priority_queue<pair<pair<int,int>,pair<string,int>>, vector<pair<pair<int,int>,pair<string,int>>>, greater<pair<pair<int,int>,pair<string,int>>>> pq;
    string s = to_string(start) + " ";

    pq.push({{0,start}, {s, 1}});

    while(!pq.empty()){
        int curr = pq.top().first.first;
        int now = pq.top().first.second;
        string cs = pq.top().second.first;
        int cn = pq.top().second.second;
        pq.pop();
        if (now == dest){
            cout << curr << "\n";
            cout << cn << "\n";
            cout << cs;
            return;
        }
        for (int i = 0; i < v[now].size(); i++) {
            int to = v[now][i].first;
            int cost = v[now][i].second;
            if(visited[to] > curr + cost){
                visited[to] = curr + cost;
                pq.push({{curr + cost, to},{cs + to_string(to) + " ", cn+1}});
            }
        }

    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cin >> start >> dest;
    fill_n(visited, 1001, inf);
    dijkstra();


    return 0;
}