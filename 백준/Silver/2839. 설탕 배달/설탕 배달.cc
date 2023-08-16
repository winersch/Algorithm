#include <iostream>

using namespace std;

/*
 5킬로, 3킬로
 input%5
 1 = + 1
 2 = + 2
 3 = + 1
 4 = + 2
*/


int main() {
    int input;

    cin >> input;

    int count = input / 5;
    int left = input % 5;


    switch (left) {
        case 0:
            if (input / 5 == 0) {
                cout << -1;
                return 0;
            }
            cout << count;
            break;
        case 1:
            if (input / 5 == 0) {
                cout << -1;
                return 0;
            }
            cout << count + 1;
            break;
        case 2:
            if (input / 5 <= 1) {
                cout << -1;
                return 0;
            }
            cout << count + 2;
            break;
        case 3:
            cout << count + 1;
            break;
        case 4:
            if (input / 5 == 0) {
                cout << -1;
                return 0;
            }
            cout << count + 2;
            break;
    }


    return 0;
}