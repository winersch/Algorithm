#include <iostream>

using namespace std;

int num[10];
int leftover[42];

int main() {

    for (int i = 0; i < 10; i++) {
        cin >> num[i];
        leftover[num[i]%42]++;
    }

    int count = 0;
    for (int i = 0; i < 42; i++) {
        if (leftover[i] > 0){
            count++;
        }
    }
    cout << count;

    return 0;
}