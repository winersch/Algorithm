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

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vi v;
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        std::sort(v.begin(), v.end(), greater<>());
        cout << "Scenario #" << i+1 << ":\n";
        if (pow(v[0],2) == pow(v[1],2) + pow(v[2],2)){
            cout << "yes\n\n";
        }else{
            cout << "no\n\n";
        }
    }

    return 0;
}

