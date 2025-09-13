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

unordered_set<int> s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n = 1;
    s.insert(n);
    for (int i = 0; i < 30; i++) {
        n *= 2;
        s.insert(n);
    }

    int a; cin >> a;
    if (s.find(a) != s.end()){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}
