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

int n;
int grid[65][65];

string find(pii lt, pii rb){
    if (lt == rb){
        return to_string(grid[lt.first][lt.second]);
    }
    int t = grid[lt.first][lt.second];
    bool is_compressable = true;
    for (int i = lt.first; i <= rb.first; i++) {
        if (!is_compressable){
            break;
        }
        for (int j = lt.second; j <= rb.second; j++) {
            if (grid[i][j] != t){
                is_compressable = false;
                break;
            }
        }
    }
    if (is_compressable){
        return to_string(t);
    }

    string s = "(";

    int mid_row = (lt.first + rb.first) / 2;
    int mid_col = (lt.second + rb.second) / 2;


    s += find({lt.first, lt.second}, {mid_row, mid_col});
    s += find({lt.first, mid_col + 1}, {mid_row, rb.second});
    s += find({mid_row + 1, lt.second}, {rb.first, mid_col});
    s += find({mid_row + 1, mid_col + 1}, {rb.first, rb.second});

    s += ")";
    return s;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    string s = find({0,0}, {n-1,n-1});
    cout << s;
    return 0;
}