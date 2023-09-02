#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char ch[15];
int selected[15];
vector<char> pass;

void make_pass(int index, int count, int vowel, int consonant) {

    if (count == l && (vowel >= 1 && consonant >= 2)) {
        for (char a: pass) {
            cout << a;
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < c; i++) {
        if (selected[i]) {
            continue;
        }
        selected[i] = 1;
        pass.push_back(ch[i]);
        if (ch[i] == 'i' || ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'o' || ch[i] == 'u') {
            make_pass(i, count + 1, vowel + 1, consonant);
        } else {
            make_pass(i, count + 1, vowel, consonant + 1);
        }
        selected[i] = 0;
        pass.pop_back();
    }

    return;
}

int main() {
    cin >> l >> c;

    for (int i = 0; i < c; i++) {
        cin >> ch[i];
    }
    sort(ch, ch + c);
    make_pass(0, 0, 0, 0);
    return 0;
}
