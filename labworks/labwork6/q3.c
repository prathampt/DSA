#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the longest common subsequence
const char* longestCommonSubsequence(const char* str1, const char* str2, int* length) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a 2D array to store the length of common subsequences
    int dp[len1 + 1][len2 + 1];

    // Build the dp array
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // Length of the longest common subsequence
    *length = dp[len1][len2];

    // Allocate memory for the longest common subsequence
    char* subsequence = (char*)malloc((*length + 1) * sizeof(char));

    // Build the longest common subsequence
    int i = len1, j = len2, index = *length;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            subsequence[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Null-terminate the subsequence
    subsequence[*length] = '\0';

    return subsequence;
}

int main() {
    const char* str1 = "AGGTAB";
    const char* str2 = "GXTXAYB";

    int length;
    const char* subsequence = longestCommonSubsequence(str1, str2, &length);

    printf("Longest Common Subsequence: %s\n", subsequence);
    printf("Length of LCS: %d\n", length);

    // Free the allocated memory for the subsequence
    free((void*)subsequence);

    return 0;
}
