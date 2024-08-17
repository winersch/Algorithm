#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m, tmp;
int duck[200001];
bool tree[2200000];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> duck[i];
    }

    for (int i = 0; i < m; i++) {
        int a = duck[i];
        vector<int> v;
        while(a > 0){
            if (tree[a]){
                v.push_back(a);
            }
            a /= 2;
        }
        if (v.empty()){
            cout << 0 << "\n";
            tree[duck[i]] = true;
        }else{
            cout << v.back() << "\n";
        }

    }


    return 0;
}