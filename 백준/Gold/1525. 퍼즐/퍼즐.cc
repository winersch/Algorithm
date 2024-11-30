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

vi first;
vi correct = {1,2,3,4,5,6,7,8,0};
int ans;
int d[4] = {3,-3,-1,1};
map<vi, bool> visited;

void bfs(){
    queue<pair<vi,int>> q;
    q.push({first, 0});
    visited[first] = true;

    while(!q.empty()){
        vi curr = q.front().first;
        int move = q.front().second;
        q.pop();

        int zero;
        for (int i = 0; i < 9; i++) {
            if (curr[i] == 0){
                zero = i;
            }
        }

        for (int i = 0; i < 4; i++) {
            int n = zero + d[i];
            if ((i == 2 && zero % 3 == 0) || (i == 3 && zero % 3 == 2)){
                continue;
            }
            if (n >= 0 && n < 9){
                vi next = curr;
                swap(next[n], next[zero]);
                if (next == correct){
                    ans = move+1;
                    return;
                }
                if (!visited[next]){
                    visited[next] = true;
                    q.push({next, move+1});
                }
            }
        }
    }
}

bool check(){
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            if (first[i] != 0 && first[j] != 0){
                if (first[i] > first[j]){
                    cnt++;
                }
            }
        }
    }
    return cnt%2 == 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        first.push_back(a);
    }
    if (check()){
        if (first != correct){
            bfs();
        }
    }else{
        ans = -1;
    }

    cout << ans;

    return 0;
}