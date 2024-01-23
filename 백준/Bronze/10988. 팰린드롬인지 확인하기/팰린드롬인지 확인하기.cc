#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    bool isfelindrom = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length()-1-i]){
            isfelindrom = false;
            break;
        }
    }

    if (isfelindrom){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}