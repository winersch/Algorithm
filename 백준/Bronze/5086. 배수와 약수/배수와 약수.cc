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
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    while(true){
        cin >> a >> b;
        if (a == 0 && b == 0){
            break;
        }
        if (b%a == 0){
            cout << "factor" << "\n";
        }else if(a%b == 0){
            cout << "multiple" << "\n";
        }else{
            cout << "neither" << "\n";
        }
    }


    return 0;
}