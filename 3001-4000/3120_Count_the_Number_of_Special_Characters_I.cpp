/*
Problem Number: 3120
Problem Name: Count the Number of Special Characters I

Difficulty: Easy

Topics:
String, Hash Table

Approach:
Use two boolean arrays:
- one for lowercase letters
- one for uppercase letters

Mark characters present in the string.

Finally,
count characters that appear in both
lowercase and uppercase forms.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    int numberOfSpecialChars(string word) {

        // Track lowercase letters
        vector<bool> lower(26, false);

        // Track uppercase letters
        vector<bool> upper(26, false);

        // Traverse string
        for(char ch : word) {

            if(islower(ch)) {

                lower[ch - 'a'] = true;
            }

            else {

                upper[ch - 'A'] = true;
            }
        }

        int count = 0;

        // Count special characters
        for(int i = 0; i < 26; i++) {

            if(lower[i] && upper[i]) {

                count++;
            }
        }

        return count;
    }
};
