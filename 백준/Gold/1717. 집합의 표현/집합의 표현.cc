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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
int parent[1000001];

int find_parent(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = find_parent(parent[a]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c > b){
            swap(b,c);
        }
        if (a == 0){
            if (find_parent(b) != find_parent(c)){
                parent[parent[c]] = parent[b];
            }
        }else{
            if (find_parent(b) == find_parent(c)){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }
    }



    return 0;
}