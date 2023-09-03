#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int x, count = 0;
    cin >> x;

    while (x != 1){
        if (x%2 == 0){
            x /= 2;
        }else{
            x= x-1;
            x /= 2;
            count++;
        }
    }

    cout << count+1;

    return 0;
}
