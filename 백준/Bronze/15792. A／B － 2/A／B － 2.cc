#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 10007
#define ll long long
using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    cout << int(a / b) << ".";
    a = a % b;
    for (int i = 0; i <= 1000; i++)
    {
        a *= 10;
        cout << a / b;
        a = a - (a / b) * b;
    }


    return 0;
}