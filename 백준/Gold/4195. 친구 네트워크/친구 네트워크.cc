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

map<string, int> idx;
int parent[200001];
int ans[200001];
int n;


int findParent(int s){
    if (parent[s] == s){
        return s;
    }
    return parent[s] = findParent(parent[s]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        idx.clear();
        cin >> n;
        for (int i = 1; i <= n*2; i++) {
            parent[i] = i;
            ans[i] = 1;
        }
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (idx.find(s1) == idx.end()){
                idx[s1] = cnt++;
            }
            if (idx.find(s2) == idx.end()){
                idx[s2] = cnt++;
            }
            if (findParent(idx[s1]) != findParent(idx[s2])){
                if (idx[s1] > idx[s2]){
                    swap(s1,s2);
                }
                ans[parent[idx[s1]]] += ans[parent[idx[s2]]];
                parent[parent[idx[s2]]] = parent[idx[s1]];
            }
            cout << ans[parent[idx[s1]]] << "\n";
        }
    }

    return 0;
}