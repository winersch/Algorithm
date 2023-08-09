#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    int* a;
    a = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }

    sort(a, a+num);

    for (int i = 0; i < num; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
