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

int n;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, t = 1;
        cin >> a >> b;
        for (int j = 0; j < b; j++) {
            t = (t * a) % 10;
        }
        if (t == 0) {
            t = 10;
        }
        cout << t << "\n";
    }

}