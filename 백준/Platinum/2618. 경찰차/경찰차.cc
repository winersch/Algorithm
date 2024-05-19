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

int n, w;
vector<pii> v;
vector<vector<int>> dp;
vector<vector<pii>> choice;

int dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int i, int j) {
    int k = max(i, j) + 1;
    if (k > w)
        return 0;

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    pii next = v[k];
    pii car1 = (i == 0) ? make_pair(1, 1) : v[i];
    pii car2 = (j == 0) ? make_pair(n, n) : v[j];

    int move1 = solve(k,j) + dist(car1, next);
    int move2 = solve(i,k) + dist(car2, next);

    if (move1 < move2){
        dp[i][j] = move1;
        choice[i][j] = {k, j};
    }else{
        dp[i][j] = move2;
        choice[i][j] = {i, k};
    }

    return dp[i][j];

}

void print_choice(int i, int j) {
    if (max(i, j) + 1 > w) return;
    if (choice[i][j].first == max(i, j) + 1) {
        cout << "1\n";
        print_choice(choice[i][j].first, choice[i][j].second);
    } else {
        cout << "2\n";
        print_choice(choice[i][j].first, choice[i][j].second);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> w;
    v.resize(w+1);
    for (int i = 1; i <= w; i++) {
        cin >> v[i].first >> v[i].second;
    }

    dp.resize(w + 1, vector<int>(w + 1, -1));
    choice.resize(w + 1, vector<pii>(w + 1, {0, 0}));

    cout << solve(0,0)<< "\n";
    print_choice(0,0);

    return 0;
}