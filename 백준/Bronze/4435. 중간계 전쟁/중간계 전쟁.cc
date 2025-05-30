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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int sc1[6] = {1, 2, 3, 3, 4, 10};
int sc2[7] = {1, 2, 2, 2, 3, 5, 10};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a1 = 0, a2 = 0;
        for (int j = 0; j < 6; j++) {
            int a;
            cin >> a;
            a1 += sc1[j] * a;
        }
        for (int j = 0; j < 7; j++) {
            int a;
            cin >> a;
            a2 += sc2[j] * a;
        }
        cout << "Battle " << i << ": ";
        if (a1 > a2){
            cout << "Good triumphs over Evil\n";
        }else if (a2 > a1){
            cout << "Evil eradicates all trace of Good\n";
        }else{
            cout << "No victor on this battle field\n";
        }
    }


    return 0;
}
