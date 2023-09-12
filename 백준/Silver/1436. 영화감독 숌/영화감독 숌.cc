#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count = 1, num = 666;
    cin >> n;
    while(count != n+1){
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6' && s[i] == s[i+1] && s[i] == s[i+2]){
                count++;
                break;
            }
        }
        num++;
    }
    cout << num-1;

    return 0;
}
