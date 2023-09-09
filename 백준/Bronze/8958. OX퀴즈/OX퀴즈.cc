#include <iostream>

using namespace std;

int n;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int score = 0, stack = 0, num = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'O') {
                score += ++stack;
            } else {
                stack = 0;
                num = 0;
            }
        }
        cout << score << endl;
    }


    return 0;
}