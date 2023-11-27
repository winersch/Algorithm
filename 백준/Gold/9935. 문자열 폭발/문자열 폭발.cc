#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

string a, b, tmp;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        tmp+=a[i];
        if (tmp.length() >= b.length()){
            bool is = true;
            for (int j = 0; j < b.length(); j++) {
                if (tmp[tmp.length() - b.length()+j] != b[j]){
                    is = false;
                    break;
                }
            }
            if (is){
                tmp.erase(tmp.end() - b.length(), tmp.end());
            }
        }
    }

    if (tmp.empty()){
        cout << "FRULA";
    } else{
        cout << tmp;
    }

    return 0;
}