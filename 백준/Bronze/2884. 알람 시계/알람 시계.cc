#include <iostream>

using namespace std;


int main() {
    int hr, mi;
    cin >> hr >> mi;
    mi = mi + hr*60;
    mi -= 45;
    if (mi < 0){
        mi += 1440;
    }
    cout << mi/60 << " " << mi%60;

    return 0;
}
