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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

list<char> text;
int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s >> n;
    text = list<char>(s.begin(), s.end());
    auto cursor = text.end();
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'L'){
            if (cursor != text.begin()){
                cursor--;
            }
        }else if (c == 'D'){
            if (cursor != text.end()){
                cursor++;
            }
        }else if (c == 'B'){
            if (cursor != text.begin()){
                cursor--;
                cursor = text.erase(cursor);
            }
        }else if (c == 'P'){
            char ch;
            cin >> ch;
            text.insert(cursor, ch);
        }
    }

    cout << string(text.begin(), text.end());

    return 0;
}

