#include <iostream>

using namespace std;

int main() {
    int hour, minute, reqMin;

    cin >> hour >> minute >> reqMin;
    minute += reqMin;
    if (minute >= 60) {
        hour += (minute / 60);
        minute %= 60;
        if (hour >= 24) {
            hour %= 24;
        }
    }
    cout << hour << " " << minute << endl;
    return 0;
}
