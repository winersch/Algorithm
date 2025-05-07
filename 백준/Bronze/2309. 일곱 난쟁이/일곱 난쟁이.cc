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

int arr[9];
bool selected[9];

void sel(int sum, int idx, int cnt){

    if (sum == 100 && cnt == 7){
        vi v;
        for (int i = 0; i < 9; i++) {
            if (selected[i]){
                v.push_back(arr[i]);
            }
        }
        std::sort(v.begin(), v.end());
        for(int a : v){
            cout << a << "\n";
        }
        exit(0);
    }
    if (cnt > 7 || sum > 100){
        return;
    }

    for (int i = idx+1; i < 9; i++) {
        selected[i] = true;
        sel(sum + arr[i], i, cnt+1);
        selected[i] = false;
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    sel(0,-1,0);


    return 0;
}

