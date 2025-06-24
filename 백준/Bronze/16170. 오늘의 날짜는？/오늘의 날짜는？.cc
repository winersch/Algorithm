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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    time_t now = time(nullptr);
    tm *utc = gmtime(&now);

    cout << utc->tm_year + 1900 << '\n'
         << setw(2) << setfill('0') << utc->tm_mon + 1 << '\n'
         << setw(2) << setfill('0') << utc->tm_mday << '\n';
    return 0;
    return 0;
}
