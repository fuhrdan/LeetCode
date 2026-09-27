#include <stdlib.h>
#include <string.h>
char* minWindow(char* s, char* t) {
    int need[128] = {0}, missing = strlen(t), left = 0, bestL = 0, bestLen = 1 << 30;
    for (int i = 0; t[i]; i++) need[(unsigned char)t[i]]++;
    for (int right = 0; s[right]; right++) {
        unsigned char c = s[right];
        if (need[c] > 0) missing--;
        need[c]--;
        while (missing == 0) {
            if (right - left + 1 < bestLen) { bestLen = right - left + 1; bestL = left; }
            c = (unsigned char)s[left++];
            need[c]++;
            if (need[c] > 0) missing++;
        }
    }
    if (bestLen == (1 << 30)) { char* r = malloc(1); r[0] = 0; return r; }
    char* r = malloc(bestLen + 1); memcpy(r, s + bestL, bestLen); r[bestLen] = 0; return r;
}
