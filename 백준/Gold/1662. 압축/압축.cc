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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int ans;
int len[50], mul[50];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int depth = 0;
    int tmp = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            len[depth]--;
            depth++;
            mul[depth] = tmp;
        } else if (c == ')') {
            int a = len[depth] * mul[depth];
            len[depth] = 0;
            depth--;
            len[depth] += a;
        } else {
            len[depth]++;
            tmp = c - '0';
        }
    }

    cout << len[0];
    return 0;
}