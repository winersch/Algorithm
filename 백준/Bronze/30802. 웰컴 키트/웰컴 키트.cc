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

int n, t, p;
int arr[6];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    cin >> t >> p;
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < 6; i++) {
        a += arr[i] / t;
        if (arr[i]%t != 0){
            a++;
        }
    }

    b = n / p;
    c = n % p;

    cout << a << "\n" << b << " " << c;

    return 0;
}