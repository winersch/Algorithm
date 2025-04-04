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

    int a, b, c;
    cin>>a>>b>>c;
    if (a+b+c >= 100){
        cout <<"OK";
    }else{
        int tmp = min(a,min(b,c));
        if (tmp == a){
            cout << "Soongsil";
        }else if (tmp == b){
            cout << "Korea";
        }else{
            cout << "Hanyang";
        }
    }
    return 0;
}