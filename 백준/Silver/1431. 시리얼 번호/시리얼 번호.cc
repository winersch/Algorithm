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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

vector<string> v;
int n;

bool comp(string& s1, string& s2){
    if (s1.length() != s2.length()){
        return s1.length() < s2.length();
    }else{
        int t1 = 0, t2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] <= '9' && s1[i] >= '0'){
                t1 += s1[i] - '0';
            }
        }
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] <= '9' && s2[i] >= '0'){
                t2 += s2[i] - '0';
            }
        }
        if (t1 != t2){
            return t1 < t2;
        }else{
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i]){
                    return s1[i] < s2[i];
                }
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    std::sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}