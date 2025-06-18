#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    unsigned int dp[1001] = {0};
    int numDistinct(string s, string t) {
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = min(i, (int)t.size()); j > 0; --j) {
                if (s[i-1] == t[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[t.size()];
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Output: " << solution.numDistinct(s1, t1) << endl;
    
    // Reset dp array
    fill(begin(solution.dp), end(solution.dp), 0);
    
    // Test case 2
    string s2 = "babgbag";
    string t2 = "bag";
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Output: " << solution.numDistinct(s2, t2) << endl;
    
    return 0;
}
