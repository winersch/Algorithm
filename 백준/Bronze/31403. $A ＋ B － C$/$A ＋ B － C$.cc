#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin >> a >> b >> c;
    cout << a + b - c << "\n";
    string s = "";
    s += to_string(a);
    s += to_string(b);
    cout << stoi(s) - c;


}