/*
Problem Number: 3751
Problem Name: Total Waviness of Numbers in Range I

LeetCode Link:
https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/

Difficulty: Medium

Topics:
Math, String, Simulation

Approach:
For each number in the range [num1, num2]:

1. Convert the number into a string.
2. Check every middle digit.
3. A digit contributes to waviness if:
   - it is a peak
     (greater than both neighbors)
   OR
   - it is a valley
     (smaller than both neighbors)

Sum the waviness of all numbers in the range.

Time Complexity:
O((num2 - num1 + 1) × d)

d = number of digits

Space Complexity:
O(d)
*/

class Solution {
public:

    int waviness(int x) {

        string s = to_string(x);

        int n = s.size();

        int res = 0;

        for(int i = 1; i < n - 1; i++) {

            // Peak
            if((s[i] > s[i - 1] &&
                s[i] > s[i + 1])

                ||

               // Valley
               (s[i] < s[i - 1] &&
                s[i] < s[i + 1])) {

                res++;
            }
        }

        return res;
    }

    int totalWaviness(int num1, int num2) {

        int ans = 0;

        for(int x = num1; x <= num2; x++) {

            ans += waviness(x);
        }

        return ans;
    }
};
