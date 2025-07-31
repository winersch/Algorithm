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

    bool operator==(const cnt &other) const {
        return equal(a, a + 26, other.a);
    }
};

bool check(string a, string b) {
    cnt ca, cb;
    for (int i = 0; i < a.length(); i++) {
        ca.a[a[i] - 'a']++;
    }
    for (int i = 0; i < b.length(); i++) {
        cb.a[b[i] - 'a']++;
    }
    return ca == cb;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (check(a, b)) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }

    }

    return 0;
}