#include <iostream>

using namespace std;

int gdc(int a, int b){
    if (b == 0){
        return a;
    }else{
        return gdc(b,a%b);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a = gdc(n , m);

    cout << a << "\n";
    cout << n*m/a << "\n";

    return 0;
}
