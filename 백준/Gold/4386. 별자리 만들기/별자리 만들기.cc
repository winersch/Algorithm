#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

vector<pair<double, double>> star;
vector<pair<double, pair<int,int>>> edge;
double ans;

int parent[101];

int findParent(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = findParent(parent[x]);
}

void select(int a, int b){
    if (findParent(a) != findParent(b)){
        parent[findParent(b)] = findParent(a);
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        star.push_back({a,b});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double dist = sqrt(pow(abs(star[i].first - star[j].first),2) + pow(abs(star[i].second - star[j].second),2));
            edge.push_back({dist,{i,j}});

        }
    }

    sort(edge.begin(), edge.end());

    memset(parent, -1, sizeof(parent));

    for(auto e : edge){
        double cost = e.first;
        int start = e.second.first;
        int end = e.second.second;

        if (findParent(start) != findParent(end)){
            select(start, end);
            ans += cost;
        }
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}