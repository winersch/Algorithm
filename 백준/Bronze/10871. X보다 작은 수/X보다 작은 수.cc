#include <iostream>

using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (x > a){
            cout << a << " ";
        }
    }



    return 0;
}