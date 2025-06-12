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
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int n, ans;
vs v;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void eat(){

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (v[i][j] == v[i][j-1]){
                cnt++;
                ans = max(ans, cnt);
            }else{
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (v[j][i] == v[j-1][i]){
                cnt++;
                ans = max(ans, cnt);
            }else{
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
    }
}

void switch_candy(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= 0 && ny < n && nx >= 0 && nx < n && v[i][j] != v[ny][nx]){
                    swap(v[i][j], v[ny][nx]);
                    eat();
                    swap(v[i][j], v[ny][nx]);
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
        string s;
        cin >> s;
        v.push_back(s);
    }
    switch_candy();
    cout << ans;


    return 0;
}
