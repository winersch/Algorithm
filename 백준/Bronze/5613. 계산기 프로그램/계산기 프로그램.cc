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

    int result;
    cin >> result;

    while (true) {
        string op;
        cin >> op;

        if (op == "="){
            break;
        }
        int num;
        cin >> num;

        if (op == "+") result += num;
        else if (op == "-") result -= num;
        else if (op == "*") result *= num;
        else if (op == "/") result /= num;  // 정수 나눗셈
    }

    cout << result << "\n";
    return 0;
}

