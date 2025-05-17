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


vi v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 1;; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (i % v[j] == 0){
                cnt++;
            }
        }
        if (cnt >= 3){
            cout << i;
            break;
        }
    }

    return 0;
}

