#include <iostream>
#include <vector>


int main() {
    using namespace std;

    string str;
    vector <string> v;

    while (std::getline(cin, str)){
        if(str.empty()||str == "#"){
            break;
        }
        v.push_back(str);
    }

    for(string s : v){
        int count = 0;
        for(int i = 0; s[i]; i++){
            if(s[i] == 'i' || s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'I' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U'){
                count++;
            }
        }
        cout << count << endl;
    }


    return 0;
}
