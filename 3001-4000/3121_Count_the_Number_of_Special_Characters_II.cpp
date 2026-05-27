/*
Problem Number: 3121
Problem Name: Count the Number of Special Characters II

Difficulty: Medium

Topics:
String, Hash Table

Approach:
Store:
- last occurrence of lowercase letters
- first occurrence of uppercase letters

A character is special if:
1. it exists in both lowercase and uppercase
2. all lowercase occurrences appear before
   the first uppercase occurrence

Check this condition for all 26 letters.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int numberOfSpecialChars(string word) {

        // Store last occurrence of lowercase letters
        vector<int> lastLower(26, -1);

        // Store first occurrence of uppercase letters
        vector<int> firstUpper(26, -1);

        // Traverse string
        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            // Lowercase character
            if(islower(ch)) {

                lastLower[ch - 'a'] = i;
            }

            // Uppercase character
            else {

                int idx = ch - 'A';

                // Store first occurrence only
                if(firstUpper[idx] == -1) {

                    firstUpper[idx] = i;
                }
            }
        }

        int ans = 0;

        // Check special characters
        for(int i = 0; i < 26; i++) {

            if(lastLower[i] != -1 &&
               firstUpper[i] != -1 &&
               lastLower[i] < firstUpper[i]) {

                ans++;
            }
        }

        return ans;
    }
};
