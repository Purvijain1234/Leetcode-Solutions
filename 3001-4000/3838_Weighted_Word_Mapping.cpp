/*
Problem Number: 3838
Problem Name: Weighted Word Mapping

LeetCode Link:
https://leetcode.com/problems/weighted-word-mapping/

Difficulty: Easy

Topics:
Array, String, Simulation, Math

Approach:
For each word:

1. Calculate the total weight of the word
   using the given character weights.

2. Compute:
      remainder = weight % 26

3. Map the remainder using reverse
   alphabetical order:

      0 -> 'z'
      1 -> 'y'
      ...
      25 -> 'a'

4. Append the mapped character to
   the answer string.

Return the final generated string.

Time Complexity:
O(total_characters)

Space Complexity:
O(1)
(excluding output string)
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            int sum = 0;

            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int rem = sum % 26;
            ans.push_back('z' - rem);
        }

        return ans;
    }
};
