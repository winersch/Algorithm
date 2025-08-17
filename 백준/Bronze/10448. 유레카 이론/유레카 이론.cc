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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vi v;
    for (int i = 1; i*(i+1)/2 < 1001; i++) {
        v.push_back(i*(i+1)/2);
    }

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        bool find = false;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                for (int k = 0; k < v.size(); k++) {
                    if (v[i] + v[j] + v[k] == n){
                        find = true;
                    }
                }
            }
        }
        if (find){
            cout << 1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }


    return 0;
}