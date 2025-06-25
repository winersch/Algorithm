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
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

struct student{
    string name;
    int a, b, c;
};
int n;
vector<student> st;

bool comp(student& a, student& b){
    if (a.a == b.a){
        if (a.b == b.b){
            if (a.c == b.c){
                return a.name < b.name;
            }else{
                return a.c > b.c;
            }
        }else{
            return a.b < b.b;
        }
    }else{
        return a.a > b.a;
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        student s;
        cin >> s.name >> s.a >> s.b >> s.c;
        st.push_back(s);
    }

    std::sort(st.begin(), st.end(), comp);

    for(auto s : st){
        cout << s.name << "\n";
    }

    return 0;
}
