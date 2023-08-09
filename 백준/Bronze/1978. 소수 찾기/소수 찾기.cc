#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num, count = 0;
    cin >> num;
    int *a;
    a = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < num; i++) {
        bool isPrime = true;
        if (a[i] == 1){
            isPrime = false;
        } else{
            for (int j = 2; j < a[i]; j++) {
                if (a[i] % j == 0) {
                    isPrime = false;
                }
            }
        }
        if (isPrime){
            count++;
        }
    }
    cout << count;
    return 0;
}
