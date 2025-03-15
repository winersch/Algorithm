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

int n, ans = -inf;
vi num;
vector<char> operators;

int calc(int a, char op, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
    return 0;
}

void dfs(int idx, int curr){
    if (idx >= operators.size()){
        ans = max(ans, curr);
        return;
    }

    int next = calc(curr, operators[idx], num[idx+1]);
    dfs(idx+1, next);

    if (idx+1 < operators.size()){
        int bracket = calc(num[idx+1], operators[idx+1], num[idx+2]);
        next = calc(curr, operators[idx], bracket);
        dfs(idx+2, next);
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        if (i%2 == 0){
            num.push_back(s[i] - '0');
        }else{
            operators.push_back(s[i]);
        }
    }

    dfs(0, num[0]);
    cout << ans;

    return 0;
}

