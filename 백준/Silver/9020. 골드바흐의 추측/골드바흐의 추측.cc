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

bool is_prime[10001];
vector<int> num;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    memset(is_prime, true, sizeof(is_prime));

    for (int i = 2; i < sqrt(10001); i++) {
        for (int j = i * 2; j < 10001; j+=i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i < 10001; i++) {
        if (is_prime[i]){
            num.push_back(i);
        }
    }

    int t;
    cin >> t;


    while(t--){
        int n;
        cin >> n;
        int a, b;
        for (int i = 0; i < num.size(); i++) {
            int t = num[i];
            if (t > n/2){
                break;
            }
            if (binary_search(num.begin(), num.end(), n-t)){
                a = t;
                b = n-t;
            }
        }
        cout << a << " " << b << "\n";
    }

    return 0;
}