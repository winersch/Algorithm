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

    string s;
    cin >> s;
    stack<char> st;
    vector<int> v(30,0);
    int depth = 0;
    for(char c : s){

        if (st.empty()){
            depth++;
            st.push(c);
        }

        if (c == '(' || c == '['){
            depth++;
            st.push(c);
        }

        if (c == ')'){
            if (st.top() != '('){
                cout << 0;
                return 0;
            }

            depth--;
            if (v[depth+1] == 0){
                v[depth] += 2;
            }else{
                v[depth] += v[depth+1]*2;
                v[depth+1] = 0;
            }
            st.pop();
        }

        if (c == ']'){
            if (st.top() != '['){
                cout << 0;
                return 0;
            }

            depth--;
            if (v[depth+1] == 0){
                v[depth] += 3;
            }else{
                v[depth] += v[depth+1]*3;
                v[depth+1] = 0;
            }
            st.pop();
        }
    }
    cout << v[1];
    return 0;
}