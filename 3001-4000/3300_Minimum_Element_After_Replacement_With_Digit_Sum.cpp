/*
Problem Number: 3300
Problem Name: Minimum Element After Replacement With Digit Sum

Difficulty: Easy

Topics:
Array, Math

Approach:
For each number:
1. Calculate the sum of its digits.
2. Keep track of the minimum digit sum.

Return the smallest digit sum found.

Time Complexity:
O(n × d)

n = number of elements
d = number of digits in each number

Space Complexity:
O(1)
*/

class Solution {
public:

    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for(int num : nums) {

            int digitSum = 0;

            // Calculate digit sum
            while(num > 0) {

                digitSum += num % 10;

                num /= 10;
            }

            ans = min(ans, digitSum);
        }

        return ans;
    }
};
