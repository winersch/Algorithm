#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    int left = 0, right = 0;
    bool check = false;
    cin >> s;
    for(char c : s){
        if (c == '('){
            check = true;
        }
        if (c == '@'){
            if (check){
                right++;
            } else{
                left++;
            }
        }
    }
    cout << left << ' ' << right;
    return 0;
}