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
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

bool is_prime[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    memset(is_prime, true, sizeof(is_prime));

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            if (is_prime[j]){
                k--;
                is_prime[j] = false;
                if (k == 0){
                    cout << j;
                    return 0;
                }
            }
        }
    }



    return 0;
}