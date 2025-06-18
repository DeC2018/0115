#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

unsigned int dp[MAX_LEN];

int numDistinct(char* s, char* t) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    int s_len = strlen(s);
    int t_len = strlen(t);
    
    for (int i = 1; i <= s_len; ++i) {
        int end = i < t_len ? i : t_len;
        for (int j = end; j > 0; --j) {
            if (s[i-1] == t[j-1]) {
                dp[j] += dp[j-1];
            }
        }
    }
    
    return dp[t_len];
}

int main() {
    // Test case 1
    char s1[] = "rabbbit";
    char t1[] = "rabbit";
    printf("Input: s = \"%s\", t = \"%s\"\n", s1, t1);
    printf("Output: %d\n", numDistinct(s1, t1));
    
    // Test case 2
    char s2[] = "babgbag";
    char t2[] = "bag";
    printf("Input: s = \"%s\", t = \"%s\"\n", s2, t2);
    printf("Output: %d\n", numDistinct(s2, t2));
    
    return 0;
}
