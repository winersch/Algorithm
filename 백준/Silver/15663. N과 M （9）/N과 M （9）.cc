#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, m;
int input[9];
int visited[9];
vector<int> v;

void dfs(int a, int cnt){
    if (cnt == m){
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && input[i] != b){
            visited[i] = 1;
            b = input[i];
            v[cnt] = input[i];
            dfs(i, cnt+1);
            visited[i] = 0;
        }
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    v.resize(m);
    sort(input, input+n);
    

    dfs(0,0);
    /*
    for (int i = 0; i < n; i++) {
        visited[i] = 1;
        v[0] = input[i];
        dfs(i, 1);
        visited[i] = 0;
    }*/


    return 0;
}