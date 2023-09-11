#include <iostream>

using namespace std;


int main() {

    int a, sum = 0;
    string s;
    cin >> a >> s;
    for (int i = 0; i < a; i++) {
        sum += (s[i]-'0');
    }
    cout << sum;

    return 0;
}