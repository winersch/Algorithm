#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a = 1,b = 1,m = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int c;
            cin >> c;
            if (c > m){
                a = i;
                b = j;
                m = c;
            }
        }
    }

    cout << m << "\n" << a << " " << b;


    return 0;
}