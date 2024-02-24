#include <iostream>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >>n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << s[0]-'0' + s[2]-'0' << "\n";
    }

    return 0;
}
