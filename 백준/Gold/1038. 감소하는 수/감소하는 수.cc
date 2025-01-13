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

vector<ll> v;

void find_reducing(){
    queue<ll> q;
    for (int i = 0; i <= 9; i++) {
        q.push(i);
        v.push_back(i);
    }
    while(!q.empty()){
        ll n = q.front();
        q.pop();
        int last = n % 10;

        for (int i = 0; i < last; i++) {
            ll next = n * 10 + i;
            q.push(next);
            v.push_back(next);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    find_reducing();

    int n;
    cin >> n;
    if (n >= v.size()){
        cout << -1;
    }else{
        cout << v[n];
    }

    return 0;
}