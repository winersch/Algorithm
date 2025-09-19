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

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    vector<pair<string, int>> v;
    for (int i = n; i <= m; i++) {
        string a, b;
        if (i >= 10){
            b = num[i%10];
            a = num[i/10];
        }else{
            a = num[i];
        }
        v.push_back({a + " " + b, i});
    }

    std::sort(v.begin(), v.end());
    for (int i = 1; i <= v.size(); i++) {
        cout << v[i-1].second << " ";
        if (i%10 == 0){
            cout << "\n";
        }
    }

    return 0;
}
