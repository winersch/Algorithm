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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a, b;
    char c;
    cin >> a >> c >> b;
    if (c == '*'){
        cout << 1;
        for (int i = 0; i < a.length() + b.length() -2; i++) {
            cout << 0;
        }
    }else{
        if (a.length() == b.length()){
            cout << 2;
            for (int i = 0; i < a.length() - 1; i++) {
                cout << 0;
            }
        }else{
            int llen = max(a.length(), b.length());
            int slen = min(a.length(), b.length());

            for (int i = llen; i > 0; i--) {
                if (i == llen || i == slen){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
        }
    }
    return 0;
}

