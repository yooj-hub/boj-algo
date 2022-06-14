#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tmp[256];
    while (1) {
        gets(tmp);
        int ans = 0;
        if (tmp[0] == '#')
            break;
        int pos = 0;
        while (1) {
            if ('\0' == tmp[pos])
                break;
            if ('a' == tmp[pos])
                ans++;
            if ('e' == tmp[pos])
                ans++;
            if ('i' == tmp[pos])
                ans++;
            if ('o' == tmp[pos])
                ans++;
            if ('u' == tmp[pos])
                ans++;
            if ('A' == tmp[pos])
                ans++;
            if ('E' == tmp[pos])
                ans++;
            if ('I' == tmp[pos])
                ans++;
            if ('O' == tmp[pos])
                ans++;
            if ('U' == tmp[pos])
                ans++;
            pos++;
        }
        printf("%d\n", ans);
    }
}