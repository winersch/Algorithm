#include <iostream>

using namespace std;


int main() {
    int a, b, v;
    cin >> a >> b >> v;

    int day = (v-a) / (a-b);
    int mod = (v-a) % (a-b);
    if (mod == 0){
        day += 1;
    }else{
        day += 2;
    }
    cout << day;

    return 0;
}

