class Solution {
public:
    int strStr(string haystack, string needle) {
        // LPS function
        int n = needle.size(), i, j;

        if (n == 0) return 0;

        vector<int> lps(n, 0);

        // Compute the lps
        lps[0] = 0;

        for (i = 1; i < n; i++) {
            // Compute the lps[i]
            // First bubble
            j = lps[i - 1];
            // Continue until I find a suitable bubble to extend
            while (j > 0 && needle[j] != needle[i])
                j = lps[j - 1];

            // If bubble not found
            if (needle[j] != needle[i])
                lps[i] = 0;
            else
                lps[i] = j + 1;
        }


        {
            // Actual KMP
            // I have the lps function
            // lps[i] <-- longest proper prefix which is also a suffix for pattern[0..i]
            i = 0, j = 0;

            while (i < haystack.size() && j < n) {
                // Find first mismatch
                if (haystack[i] == needle[j]) {
                    i++; j++;
                    continue;
                }


                // while(j < n && i < haystack.size() && haystack[i] == needle[j]) {
                //     i++; j++;
                // }

                // If pattern found
                if (j == n)
                    return (i - n);

                // Pattern not found
                // Update j
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }

            if (j == n)
                return (i - n);

            return -1;
        }

    }
};