#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 10007
#define ll long long
using namespace std;

int cnt[10];

void count(int n, int t){
    while(n){
        cnt[n%10] += t;
        n /= 10;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int start = 1;
    int base = 1;

    while(start <= n){
        while(start % 10 != 0 && start <= n){
            count(start, base);
            start++;
        }
        if (n < start){
            break;
        }

        while(n%10 != 9 && start <= n){
            count(n,base);
            n--;
        }

        start /= 10;
        n /= 10;

        for (int i = 0; i < 10; i++) {
            cnt[i] += (n-start +1)*base;
        }
        base *= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << " ";
    }
}