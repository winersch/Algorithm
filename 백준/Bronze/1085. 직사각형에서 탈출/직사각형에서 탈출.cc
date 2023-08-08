#include <iostream>

int main() {
    using namespace std;

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int num = 0;

    if(w / 2 >= x) {
        num = x;
    }else{
        num = w - x;
    }

    if(h / 2 >= y){
        num = min(num, y);
    }else{
        num = min(num, h - y);
    }

    cout << num;


    return 0;
}
