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

    while(true){
        int n; cin >> n;
        if (n == 0){
            break;
        }
        vi v;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            v.push_back(a);
        }
        v.erase(std::unique(v.begin(), v.end()), v.end());
        for(const auto& a : v){
            cout << a << " ";
        }
        cout << "$\n";
    }


    return 0;
}
