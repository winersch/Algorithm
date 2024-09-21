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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;


struct bottle {
    int a, b, c;
};

int amx, bmx, cmx;
bool visited[201][201][201];
vi ans;

void bfs(bottle bt) {
    queue<bottle> q;
    q.push(bt);

    while (!q.empty()) {
        bottle c = q.front();
        q.pop();
        if (visited[c.a][c.b][c.c]) {
            continue;
        } else {
            visited[c.a][c.b][c.c] = true;
        }
        if (c.a == 0){
            ans.push_back(c.c);
        }
        // a to b
        if (c.a + c.b > bmx) {
            q.push({c.a + c.b - bmx, bmx, c.c});
        } else {
            q.push({0, c.a + c.b, c.c});
        }
        // a to c
        if (c.a + c.c > cmx) {
            q.push({c.a + c.c - cmx, c.b, cmx});
        } else {
            q.push({0, c.b, c.a + c.c});
        }
        // b to a
        if (c.b + c.a > amx) {
            q.push({amx, c.b + c.a - amx, c.c});
        } else {
            q.push({c.a + c.b, 0, c.c});
        }
        // b to c
        if (c.c + c.b > cmx) {
            q.push({c.a, c.b + c.c - cmx, cmx});
        } else {
            q.push({c.a, 0, c.b + c.c});
        }
        // c to a
        if (c.c + c.a > amx) {
            q.push({amx, c.b, c.c + c.a - amx});
        } else {
            q.push({c.a + c.c, c.b, 0});
        }
        // c to b
        if (c.c + c.b > bmx) {
            q.push({c.a, bmx, c.c + c.b - bmx});
        } else {
            q.push({c.a, c.c + c.b, 0});
        }


    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> amx >> bmx >> cmx;
    bottle bt = {0, 0, cmx};

    bfs(bt);
    std::sort(ans.begin(), ans.end());
    for(int a : ans){
        cout << a << " ";
    }

    return 0;
}