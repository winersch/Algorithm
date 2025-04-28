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

    int a, b;
    cin >> a >> b;
    vi v;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j < i; j++) {
            v.push_back(i);
        }
    }
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum+=v[i-1];
    }
    cout<<sum;
    return 0;
}

