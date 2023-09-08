#include <iostream>

using namespace std;


int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++) {
        int num;
        string s;
        cin >> num >> s;
        for (char ch: s) {
            for (int j = 0; j < num; j++) {
                cout << ch;
            }
        }
        cout << "\n";
    }


    return 0;
}
