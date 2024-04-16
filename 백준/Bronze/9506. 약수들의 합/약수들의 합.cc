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
#define mod 10007
#define ll long long
using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    while (cin >> a){
        if (a == -1){
            break;
        }
        int tmp = a;
        vector<int> v;
        for (int i = 1; i < a; i++) {
            if (a % i == 0){
                tmp -= i;
                v.push_back(i);
            }
        }
        if (tmp == 0){
            cout << a << " = ";
            cout << v[0];
            for (int i = 1; i < v.size(); i++) {
                cout << " + " << v[i];
            }
            cout << "\n";
        }else{
            cout << a << " is NOT perfect.\n";
        }
    }



    return 0;
}