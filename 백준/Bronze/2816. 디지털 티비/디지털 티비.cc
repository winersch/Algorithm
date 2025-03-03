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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;
vector<string> v;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int c1, c2;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == "KBS1"){
            c1 = i;
        }
        if (v[i] == "KBS2"){
            c2 = i;
        }
    }
    for (int i = 0; i < c1; i++) {
        cout << 1;
    }

    for (int i = 0; i < c1; i++) {
        cout << 4;
    }
    if (c1 > c2){
        c2++;
    }

    for (int i = 0; i < c2; i++) {
        cout << 1;
    }
    for (int i = 0; i < c2-1; i++) {
        cout << 4;
    }

    return 0;
}

