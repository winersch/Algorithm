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

    stack<int> st;
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a;
        if (a == 1){
            cin >> b;
            st.push(b);
        }
        if (a == 2){
            if (st.empty()){
                cout << -1 << "\n";
            }else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        if (a == 3){
            cout << st.size() << "\n";
        }
        if (a == 4){
            cout << st.empty() << "\n";
        }
        if (a == 5){
            if (st.empty()){
                cout << -1 << "\n";
            }else{
                cout << st.top() << "\n";
            }
        }
    }


    return 0;
}