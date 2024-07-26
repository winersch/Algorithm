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

struct Trie{
    bool finish;
    Trie* next[10];
    Trie() : finish(false){
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for (int i = 0; i < 10; i++) {
            if (next[i]){
                delete next[i];
            }
        }
    }
    void insert(string &s, int idx){
        if (s.length() == idx){
            finish = true;
        }else{
            int curr = s[idx] - '0';
            if (next[curr] == NULL){
                next[curr] = new Trie();
            }
            next[curr]->insert(s, idx+1);
        }
    }

    bool find(string &s, int idx){
        if (s.length() == idx){
            return false;
        }
        if (finish){
            return true;
        }
        int curr = s[idx] - '0';
        if (next[curr] == NULL){
            return false;
        }
        return next[curr]->find(s, idx+1);
    }

};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        Trie* root = new Trie();
        bool b = true;
        cin >> n;
        string s[10001];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            root->insert(s[i],0);
        }

        for (int i = 0; i < n; i++) {
            if(root->find(s[i], 0)){
                b = false;
                break;
            }
        }

        if (b){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }


    }

    return 0;
}