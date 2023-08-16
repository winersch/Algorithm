#include <iostream>

using namespace std;

/*

*/


int main() {
    int a, count = 0;
    cin >> a;

    if (a<100){
        count = a;
    } else{
        count = 99;
        if (a<1000){
            for (int i = 100; i <= a; i++) {
                int one, ten, hund;
                one = i%10;
                ten = i/10%10;
                hund = i/100;
                if ((one-ten) == (ten - hund)){
                    count++;
                }

            }
        }else{
            count = 144;
            for (int i = 1000; i <= a; i++) {
                int one, ten, hund, thou;
                one = i%10;
                ten = i/10%10;
                hund = i/100%10;
                thou = i/1000;
                if ((one-ten) == (ten - hund) && (ten - hund) == (hund - thou)){
                    count++;
                }


            }
        }

    }
    cout << count;

    return 0;
}