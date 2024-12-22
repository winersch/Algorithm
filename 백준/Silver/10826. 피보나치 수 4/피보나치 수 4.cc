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

string fibo[10001];

string sum(string a, string b){
    int carry = 0;
    string res = "";

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    while(a.length() < b.length()){
        a += "0";
    }

    while(b.length() < a.length()){
        b += "0";
    }

    for (int i = 0; i < a.length(); i++) {
        int t = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
        res += to_string(t);
        carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
    }
    if (carry != 0){
        res += to_string(carry);
    }
    std::reverse(res.begin(), res.end());

    return res;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    fibo[0] = "0";
    fibo[1] = "1";

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        fibo[i] = sum(fibo[i-1], fibo[i-2]);
    }

    cout << fibo[n];


    return 0;
}