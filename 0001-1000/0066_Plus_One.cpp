/*
Problem Number: 0066
Problem Name: Plus One

Difficulty: Easy

Topics:
Array, Math

Approach:
Start from the last digit.

If digit is less than 9:
increment it and return.

If digit is 9:
change it to 0 and carry forward.

If all digits are 9:
insert 1 at the beginning.

Time Complexity:
O(n)

Space Complexity:
O(1)
(Note: O(n) may be considered due to insertion
at the beginning of the vector.)
*/

class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {

            // No carry required
            if(digits[i] < 9) {

                digits[i]++;

                return digits;
            }

            // Carry generated
            digits[i] = 0;
        }

        // Case: all digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
