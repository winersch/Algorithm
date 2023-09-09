#include <iostream>
#include <cstring>

using namespace std;

int al[26];


int main() {
    string s;
    cin >> s;
    memset(al, -1, sizeof(al));

    for (int i = 0; i < s.size(); i++) {
        if (al[s[i] - 'a'] == -1) {
            al[s[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << al[i] << " ";
    }
    return 0;
}