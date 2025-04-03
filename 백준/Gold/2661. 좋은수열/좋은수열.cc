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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;

void find(string s) {
    int len = s.length();
    for (int i = 1; i <= len; i++) {
        if (len -2 *i < 0){
            continue;
        }
        if (s.substr(len - i, i) == s.substr(len - 2 * i, i)){
            return;
        }
    }
    if (len == n){
        cout << s;
        exit(0);
    }

    find(s+'1');
    find(s+'2');
    find(s+'3');


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    find("");
}

