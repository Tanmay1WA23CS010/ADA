#include <stdio.h>
#include <string.h>

const char* predictPartyVictory(char *senate) {
    int rCount = 0, dCount = 0, rBan = 0, dBan = 0, n = strlen(senate);
    while (1) {
        int remaining = 0;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'X') continue;
            remaining = 1;
            if (senate[i] == 'R') {
                if (rBan) { senate[i] = 'X'; rBan--; } else { dBan++; rCount++; }
            } else {
                if (dBan) { senate[i] = 'X'; dBan--; } else { rBan++; dCount++; }
            }
        }
        if (!remaining || !rCount || !dCount) break;
        rCount = dCount = 0;
    }
    return rCount ? "Radiant" : "Dire";
}

int main() {
    char senate[] = "RDD";
    printf("Winning party: %s\n", predictPartyVictory(senate));
    return 0;
}
