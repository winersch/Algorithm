#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;


int v, e, ans;
vector<pair<int,pair<int,int>>> vertex;
int parent[10001];

int findParent(int a){
    if (parent[a] == 0){
        return a;
    }else{
        return findParent(parent[a]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >>c;
        vertex.push_back({c,{a,b}});
    }
    sort(vertex.begin(), vertex.end());

    for (int i = 0; i < vertex.size(); i++) {
        int a = vertex[i].second.first;
        int b = vertex[i].second.second;
        int cost = vertex[i].first;
        if (findParent(a) != findParent(b)){
            parent[findParent(b)] = findParent(a);
            ans += cost;
        }
    }
    cout << ans;
    return 0;
}