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

int ans = inf;
int arr[10][10];
int cnt[5];

bool check(int y, int x, int size){
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (i == 10 || j == 10){
                return false;
            }
            if (arr[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void place(int y, int x, int size, int val){
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            arr[i][j] = val;
        }
    }
}

void solve(int y, int x, int count){
    if (count >= ans){
        return;
    }
    if (x == 10){
        solve(y+1,0,count);
        return;
    }
    if (y == 10){
        ans = min(ans, count);
        return;
    }

    if (arr[y][x] == 0){
        solve(y, x+1, count);
        return;
    }

    for (int i = 5; i >= 1; i--) {
        if (cnt[i-1] < 5 && check(y,x,i)){
            place(y,x,i,0);
            cnt[i-1]++;
            solve(y,x+1,count+1);
            place(y,x,i,1);
            cnt[i-1]--;
        }
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }

    solve(0,0,0);
    if (ans == inf){
        ans = -1;
    }
    cout << ans;

}

