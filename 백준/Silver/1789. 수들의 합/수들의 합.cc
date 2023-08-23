#include <iostream>

using namespace std;

int main() {
    unsigned int s, count = 0;
    cin >> s;
    long long sum = 0;
    for (unsigned int i = 1; i <= s; i++) {
        count++;
        sum+=i;
        if (sum == s){
            cout << count;
            break;
        }else if (sum > s){
            cout << --count;
            break;
        }
    }
    return 0;
}
