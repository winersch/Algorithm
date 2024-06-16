#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n;
vector<pair<int,pii>> v;
int ans[200001];
int colorWeight[200001];
int sameWeight[200001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b,{a,i}});
    }
    sort(v.begin(), v.end());
    int t = 0;
    for (int i = 0; i < n; i++) {
        int weight = v[i].first;
        int color = v[i].second.first;
        int idx = v[i].second.second;

        colorWeight[color] += weight;
        sameWeight[weight] += weight;
        t += weight;

        ans[idx] = t - colorWeight[color] - sameWeight[weight] + weight;
        if (i == 0){
            continue;
        }
        if ((v[i-1].second.first == color) && (v[i-1].first == weight)){
            ans[idx] = ans[v[i-1].second.second];
        }

    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}