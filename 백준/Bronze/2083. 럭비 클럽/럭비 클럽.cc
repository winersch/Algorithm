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
#include <set>


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

    while (true){
        string s;
        cin >> s;
        if (s == "#"){
            break;
        }
        int a, b;
        cin >> a >> b;
        cout << s << " ";
        if (a > 17 || b >= 80){
            cout << "Senior\n";
        }else{
            cout << "Junior\n";
        }
    }

}