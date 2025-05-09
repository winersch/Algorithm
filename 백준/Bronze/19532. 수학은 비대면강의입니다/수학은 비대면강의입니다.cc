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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int i = -999; i < 1000; i++) {
        for (int j = -999; j < 1000; j++) {
            if (a * i + b * j == c && d * i + e * j == f){
                cout << i << " " << j;
                exit(0);
            }
        }
    }



    return 0;
}

