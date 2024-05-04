#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 1234567
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    vector<int> v;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= l){
            l++;
        }else{
            break;
        }
    }
    cout << l;
    return 0;

}