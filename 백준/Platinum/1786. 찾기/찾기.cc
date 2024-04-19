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

string t,p;
int pi[1000001];
vector<int> ans;

void getPi(){
    int j = 0;
    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]){
            j = pi[j-1];
        }
        if (p[i] == p[j]){
            pi[i] = ++j;
        }
    }
}

void kmp(){
    int j = 0;
    for (int i = 0; i < t.length(); i++) {
        while(j > 0 && t[i] != p[j]){
            j = pi[j-1];
        }
        if (t[i] == p[j]){
            if (j == p.length()-1){
                ans.push_back(i-p.length()+2);
                j = pi[j];
            }else{
                j++;
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    getline(cin, t);
    getline(cin, p);

    getPi();
    kmp();
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}