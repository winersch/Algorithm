#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int e,s,m;
    cin >> e >> s >> m;

    int e1, s1, m1;
    e1 = 1;
    s1 = 1;
    m1 = 1;
    n = 1;
    while(true){
        if (e1 > 15){
            e1 = 1;
        }
        if (s1 > 28){
            s1 = 1;
        }
        if (m1 > 19){
            m1 = 1;
        }
        if (e1 == e && s1 == s && m1 == m){
            cout << n;
            break;
        }
        e1++;
        s1++;
        m1++;
        n++;
    }


    return 0;
}