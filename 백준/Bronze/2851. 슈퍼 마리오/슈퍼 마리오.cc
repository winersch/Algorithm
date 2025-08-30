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

int arr[10];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;
    arr[0] = a;
    for (int i = 1; i < 10; i++) {
        cin >> a;
        arr[i] = arr[i-1] + a;
    }
    int diff = inf, ans;
    for (int i = 9; i >= 0; i--) {
        if (abs(100 - arr[i]) < diff){
            diff = abs(100 - arr[i]);
            ans = arr[i];
        }
    }

    cout << ans;

    return 0;
}