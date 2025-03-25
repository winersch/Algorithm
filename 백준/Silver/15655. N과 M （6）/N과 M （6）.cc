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
#include <list>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n,m;
vi v;
bool visited[1000];

void find(int idx, int cnt, vi& v1, int selected){
    if (cnt == m){
        if (!visited[selected]){
            visited[selected] = true;
            for(int a : v1){
                cout << a << " ";
            }
            cout << "\n";
        }
    }
    for (int i = idx; i < v.size(); i++) {
        v1.push_back(v[i]);
        int sel = selected;
        sel |= 1 << i;
        find(i+1, cnt+1, v1, sel);
        v1.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    std::sort(v.begin(), v.end());
    vi v1;
    find(0, 0, v1, 0);


}

