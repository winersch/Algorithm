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

using namespace std;

int n;
char m[5][5];
vector<int> ans;
int dy[2] = {1, 0};
int dx[2] = {0,1};

void bfs(){
    queue<pair<pii,pii>> q;
    q.push({{0,0},{m[0][0] - '0', 0}});

    while (!q.empty()){
        pii curr = q.front().first;
        int val = q.front().second.first;
        int type = q.front().second.second;
        q.pop();
        if (curr == make_pair(n-1,n-1)){
            ans.push_back(val);
        }

        for (int i = 0; i < 2; i++) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            int t = 0;
            switch (m[ny][nx]) {
                case '+':
                    t = 1;
                    break;
                case '-':
                    t = 2;
                    break;
                case '*':
                    t = 3;
                    break;
                default :
                    break;
            }
            if (ny >= 0 && ny < n && nx >= 0 && nx < n){
                if (type == 0){
                    q.push({{ny,nx}, {val, t}});
                }else{
                    int nval = 0;
                    int num = m[ny][nx] - '0';
                    switch (type) {
                        case 1:
                            nval = val + num;
                            q.push({{ny,nx}, {nval, t}});
                            break;
                        case 2:
                            nval = val - num;
                            q.push({{ny,nx}, {nval, t}});
                            break;
                        case 3:
                            nval = val * num;
                            q.push({{ny,nx}, {nval, t}});
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    bfs();

    int minAns, maxAns;
    std::sort(ans.begin(), ans.end());
    minAns = ans.front();
    maxAns = ans.back();

    cout << maxAns << " " << minAns;


    return 0;
}