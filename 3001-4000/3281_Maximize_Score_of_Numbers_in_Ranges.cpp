/*
Problem Number: 3281
Problem Name: Maximize Score of Numbers in Ranges

LeetCode Link:
https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/

Difficulty: Medium

Topics:
Array, Greedy, Math

Approach:
The maximum total value is obtained by
choosing the largest element and the
smallest element.

Difference:

max(nums) - min(nums)

This difference contributes to each
of the k operations.

Therefore:

Answer = k × (max(nums) - min(nums))

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:

    long long maxTotalValue(vector<int>& nums, int k) {

        long long mx =
            *max_element(
                nums.begin(),
                nums.end());

        long long mn =
            *min_element(
                nums.begin(),
                nums.end());

        return 1LL * k * (mx - mn);
    }
};
