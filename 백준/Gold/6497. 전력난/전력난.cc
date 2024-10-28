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
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

struct road{
    int a,b,cost;
};

bool comp(road& r1, road& r2){
    return r1.cost < r2.cost;
}


int n, m, ans, total;
vector<road> v;
int parent[200001];

int findParent(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true){
        cin >> n >> m;
        if (n == 0){
            break;
        }
        v.clear();
        ans = 0;
        total = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if (a > b){
                swap(a,b);
            }
            v.push_back({a,b,c});
        }
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        std::sort(v.begin(), v.end(), comp);

        for (int i = 0; i < v.size(); i++) {
            int a = v[i].a;
            int b = v[i].b;
            int cost = v[i].cost;

            if (findParent(a) != findParent(b)){
                parent[findParent(b)] = findParent(a);
                ans += cost;
            }
            total += cost;
        }


        cout << total - ans << "\n";
    }


    return 0;
}