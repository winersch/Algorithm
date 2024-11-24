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

int n;
int t[10001];
int ans[10001];
int entry[10001];
vi pre[10001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t[i] = a;
        if (b == 0){
            q.push(i);
            ans[i] = a;
        }
        for (int j = 0; j < b; j++) {
            int c;
            cin >> c;
            pre[c-1].push_back(i);
            entry[i]++;
        }
    }

    while(!q.empty()){
        int c = q.front();
        q.pop();
        for (int i = 0; i < pre[c].size(); i++) {
            int next = pre[c][i];
            entry[next]--;
            ans[next] = max(ans[next], ans[c] + t[next]);
            if (entry[next] == 0){
                q.push(next);
            }
        }
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
        m = max(m, ans[i]);
    }

    cout << m;
    return 0;
}