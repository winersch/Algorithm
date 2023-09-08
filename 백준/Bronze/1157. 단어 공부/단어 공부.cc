#include <iostream>

using namespace std;
int al[26];

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= 'Z' && s[i] >= 'A'){
            al[s[i]-'A']++;
        }else if (s[i] <= 'z' && s[i] >= 'a'){
            al[s[i]-'a']++;
        }
    }

    int max_num = 0;
    char max_al;

    for (int i = 0; i < 26; i++) {
        if(al[i] >= max_num){
            max_num = al[i];
            max_al = i+'A';
        }
    }
    int count = 0;

    for (int i = 0; i < 26; i++) {
        if (al[i] == max_num){
            count++;
        }
    }

    if (count > 1){
        cout << "?";
    }else{
        cout << max_al;
    }
    return 0;
}
