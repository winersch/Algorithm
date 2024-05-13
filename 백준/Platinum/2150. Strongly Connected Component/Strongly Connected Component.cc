#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;


int v, e;
vector<int> adj[10001];
vector<int> disc;
vector<int> low;
vector<bool> stacked;
stack<int> st;
vector<vector<int>> sccs;
int t;

void tarjanSCC(int u){
    disc[u] = low[u] = ++t;
    st.push(u);
    stacked[u] = true;

    for(int a : adj[u]){
        if (disc[a] == -1){
            tarjanSCC(a);
            low[u] = min(low[u], low[a]);
        }else if (stacked[a]){
            low[u] = min(low[u], disc[a]);
        }
    }

    if (disc[u] == low[u]){
        vector<int> scc;
        int a;
        do{
            a = st.top();
            st.pop();
            stacked[a] = false;
            scc.push_back(a);
        } while (a != u);
        std::sort(scc.begin(), scc.end());
        sccs.push_back(scc);
    }

}

void findSCC(){
    for (int i = 1; i <= v; i++) {
        if (disc[i] == -1){
            tarjanSCC(i);
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    disc.resize(v+1, -1);
    low.resize(v+1, -1);
    stacked.resize(v+1, false);

    findSCC();
    std::sort(sccs.begin(), sccs.end());
    cout << sccs.size() << "\n";
    for (int i = 0; i < sccs.size(); i++) {
        for (int j = 0; j < sccs[i].size(); j++) {
            cout << sccs[i][j] << " ";
        }
        cout << -1 << "\n";
    }


    return 0;
}