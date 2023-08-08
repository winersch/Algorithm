#include <iostream>

int main() {
    using namespace std;

    int peopleNum, area, realNum, a, b, c, d, e;

    cin >> peopleNum >> area >> a >> b >> c >> d >> e;
    realNum = peopleNum * area;

    cout << a-realNum << " " << b-realNum << " " << c-realNum << " " << d-realNum << " " << e-realNum << " " << endl;

    return 0;
}
