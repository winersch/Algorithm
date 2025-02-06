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

map<string, bool> m;
map<string, bool> visited;

bool check(string& s){
    for (int i = 0; i < 3; i++) {
        if (s[i] != '.' && s[i] == s[i+3] && s[i+3] == s[i+6]){
            return true;
        }
        if (s[0 + i*3] != '.' && s[0 + i*3] == s[1 + i*3] && s[1 + i*3] == s[2+i*3]){
            return true;
        }
    }
    if (s[0] != '.' && s[0] == s[4] && s[4] == s[8]){
        return true;
    }
    if (s[2] != '.' && s[2] == s[4] && s[4] == s[6]){
        return true;
    }
    bool check = true;
    for (int i = 0; i < 9; i++) {
        if (s[i] == '.'){
            check = false;
        }
    }
    return check;
}

void bfs(){
    queue<pair<string, int>> q;
    q.push({".........", 0});
    visited["........."] = true;

    while(!q.empty()){
        string curr = q.front().first;
        int turn = q.front().second;
        q.pop();
        char c;
        if (turn){
            c = 'O';
        }else{
            c = 'X';
        }

        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] == '.'){
                curr[i] = c;
                if (!visited[curr]){
                    visited[curr] = true;
                    if (check(curr)){
                        m[curr] = true;
                    }else{
                        q.push({curr,!turn});
                    }
                }
                curr[i] = '.';
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    bfs();


    string s;
    while(true){
        cin >> s;
        if (s == "end"){
            break;
        }
        if (m[s]){
            cout << "valid\n";
        }else{
            cout << "invalid\n";
        }
    }

    return 0;
}

