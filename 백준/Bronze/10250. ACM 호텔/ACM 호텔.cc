#include <iostream>

using namespace std;

int num;


int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        int h, w, n;
        cin >> h >> w >> n;

        int floor = n % h;
        int room = n / h + 1;
        if (floor == 0) {
            room--;
            floor = h;
            cout << floor * 100 + room << endl;
        } else {
            cout << floor * 100 + room << endl;
        }

    }


    return 0;
}