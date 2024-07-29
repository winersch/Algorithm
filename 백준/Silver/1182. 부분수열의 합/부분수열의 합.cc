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

int n, s, ans;
vector<int> v;
int visited[21];

void find(int a, int idx){
    if (a == s){
        ans++;
    }

    for (int i = idx; i < n; i++) {
        find(a + v[i], i+1);
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        find(v[i], i+1);
    }
    cout << ans;


    return 0;
}