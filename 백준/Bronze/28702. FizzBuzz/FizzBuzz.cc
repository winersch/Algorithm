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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s[0] == 'F' || s[0] == 'B') {
            continue;
        }
        int n = stoi(s) + 3 - i;
        if (n % 5 == 0 && n % 3 == 0) {
            cout << "FizzBuzz";
        } else if (n % 5 == 0) {
            cout << "Buzz";
        } else if (n % 3 == 0) {
            cout << "Fizz";
        } else {
            cout << n;
        }
        break;
    }


    return 0;
}