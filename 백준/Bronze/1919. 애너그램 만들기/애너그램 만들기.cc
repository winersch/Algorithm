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

struct cnt {
    int a[26] = {0};

    int diff(const cnt& other) const {
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += std::abs(a[i] - other.a[i]);
        }
        return diff;
    }
};

int check(string a, string b) {
    cnt ca, cb;
    for (int i = 0; i < a.length(); i++) {
        ca.a[a[i] - 'a']++;
    }
    for (int i = 0; i < b.length(); i++) {
        cb.a[b[i] - 'a']++;
    }
    return ca.diff(cb);
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    cout << check(a,b);

    return 0;
}