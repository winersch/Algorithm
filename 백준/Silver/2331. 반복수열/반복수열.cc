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
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int visited[1000001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a;
    int p, ans = 0;
    cin >> a >> p;
    visited[stoi(a)]++;
    while(true){
        int sum = 0;
        for (int i = 0; i < a.length(); i++) {
            sum += pow(a[i] - '0', p);
        }
        a = to_string(sum);
        visited[sum]++;
        if (visited[sum] > 2){
            break;
        }
    }
    for (int i = 0; i < 1000001; i++) {
        if (visited[i] == 1){
            ans++;
        }
    }
    cout << ans;

    return 0;
}