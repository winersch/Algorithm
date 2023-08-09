#include <iostream>
using namespace std;

int main() {
    int num, count = 6;
    cin >> num;

    if (num == 1){
        cout << 1;
        return 0;
    }

    for (int i = 2;; i++) {
        if (num <= count+1){
            cout << i;
            return 0;
        }
        count += 6*i;
    }
}
