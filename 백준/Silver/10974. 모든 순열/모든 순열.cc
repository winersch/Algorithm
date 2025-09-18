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
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int n;
bool selected[9];

void find(vi& v){
    if (v.size() == n){
        for(int a : v){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!selected[i]){
            selected[i]= true;
            v.push_back(i);
            find(v);
            v.pop_back();
            selected[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    vi v;
    find(v);


    return 0;
}
