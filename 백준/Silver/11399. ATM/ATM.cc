#include <iostream>
#include <algorithm>


using namespace std;


int main() {
    int num, sum = 0;
    int *time;
    cin >> num;
    time = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> time[i];
    }
    sort(time, time + num);

    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++) {
            sum+= time[j];
        }
    }
    cout << sum;
    return 0;
}
