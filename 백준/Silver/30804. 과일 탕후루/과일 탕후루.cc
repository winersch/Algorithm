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

int n, ans;
int cnt[11];

int check(){
    int t = 0, m = 0;
    for (int i = 1; i < 10; i++) {
        if (cnt[i] > 0){
            t++;
            m += cnt[i];
        }
    }
    if (t <= 2){
        return m;
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
        cnt[a]++;

        while(!check()){
            cnt[q.front()]--;
            q.pop();
        }

        ans = max(ans,check());

    }

    cout << ans;

    return 0;
}