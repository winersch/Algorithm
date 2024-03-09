#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

int n, m, k;
vector<int> v;
int parent[4000001];

int findParent(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

void unionParents(int a, int b){
    int pa = parent[a];
    int pb = parent[b];

    if (pa > pb){
        parent[pb] = pa;
    }else{
        parent[pa] = pb;
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        parent[i]= i;
    }
    std::sort(v.begin(), v.end());


    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;

        int idx = lower_bound(v.begin(), v.end(), a+1) - v.begin();
        cout << v[findParent(idx)] << "\n";

        if (idx < m){
            unionParents(findParent(idx), findParent(idx) +1);
        }

    }


    return 0;
}