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

int n;

int check(int left, int right, bool erased, string s){

    while(left < right){
        if(s[left] == s[right]){
            left++;
            right--;
            continue;
        }
        if (!erased){
            if (check(left+1, right, true, s) == 0 || check(left, right-1, true, s) == 0){
                return 1;
            }
            return 2;
        }else{
            return 2;
        }
    }

    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << check(0, s.length()-1, false, s) << "\n";
    }

    return 0;
}