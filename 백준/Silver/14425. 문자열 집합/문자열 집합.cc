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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;

struct Trie{
    bool finish;
    Trie* next[26];
    Trie() : finish(false){
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for (int i = 0; i < 26; i++) {
            if (next[i]){
                delete next[i];
            }
        }
    }

    void insert(string &s, int idx){
        if (s.length() == idx){
            finish = true;
        }else{
            int curr = s[idx] - 'a';
            if (next[curr] == NULL){
                next[curr] = new Trie();
            }
            next[curr]->insert(s, idx+1);
        }
    }

    bool find(string &s, int idx){
        if (s.length() == idx){
            return finish;
        }
        int curr = s[idx] - 'a';
        if (next[curr] == NULL){
            return false;
        }
        return next[curr]->find(s, idx+1);
    }

}trie;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.insert(s,0);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(trie.find(s,0)){
            ans++;
        }
    }

    cout << ans;
    return 0;
}

