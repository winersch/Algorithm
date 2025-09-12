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
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi v;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            v.push_back(a);
            sum += a;
        }
        double abg = sum / n;
        int cnt = 0;
        for(int a : v){
            if (a > abg){
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        double ans = ( (double)cnt /(double)n)*100;
        cout << ans << "%\n";
    }


    return 0;
}
