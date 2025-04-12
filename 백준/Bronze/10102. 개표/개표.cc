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

    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A'){
            a++;
        }else{
            b++;
        }
    }

    if (a == b){
        cout << "Tie";
    }else if (a > b){
        cout << "A";
    }else{
        cout << "B";
    }

    return 0;
}

