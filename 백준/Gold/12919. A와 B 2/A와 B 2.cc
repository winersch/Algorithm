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

string s;
string input;
bool result;

void bfs(){
    queue<string> q;
    q.push(input);

    while(!q.empty()){
        string curr = q.front();
        q.pop();
        if (curr == s){
            result = true;
            return;
        }
        if (curr[0] == 'B'){
            string tmp = curr;
            std::reverse(tmp.begin(), tmp.end());
            tmp = tmp.substr(0, tmp.size()-1);
            q.push(tmp);
        }
        if (curr[curr.length()-1] == 'A'){
            string tmp = curr;
            tmp = tmp.substr(0, tmp.size()-1);
            q.push(tmp);
        }

    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s >> input;

    bfs();
    if (result){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}