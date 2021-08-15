#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    // string inputstr, revstr;
    char str[100001], rev[100001];
    while (gets(str)) {
        int fail[10001] = { -1 };
        int len = strlen(str);
        int i, j;
        reverse_copy(str, str + len, rev);

        //failure
        for (i = 1, j = -1; i < len; ++i) {
            while (j >= 0 && rev[j + 1] != rev[i])
                j = fail[j];
            if (rev[j + 1] == rev[i])
                ++j;
            fail[i] = j;
        }

        for (i = 0, j = -1; i < len; ++i) {
            while (j >= 0 && rev[j + 1] != str[i])
                j = fail[j];
            if (rev[j + 1] == str[i])
                ++j;
        }

        for (i = 0; i < len; ++i)
            cout << str[i];
        for (++j; j < len; ++j)
            cout << rev[j];
        cout << endl;
    }
    return 0;
}
