/*
Problem Number: 2161
Problem Name: Partition Array According to Given Pivot

LeetCode Link:
https://leetcode.com/problems/partition-array-according-to-given-pivot/

Difficulty: Medium

Topics:
Array, Two Pointers, Simulation

Approach:
Create three separate arrays:

1. Elements smaller than pivot
2. Elements equal to pivot
3. Elements greater than pivot

Traverse the array once and place each
element into its respective group.

Finally concatenate:
less + equal + greater

This preserves the relative order of elements.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:

    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> less;
        vector<int> equal;
        vector<int> greater;

        // Partition elements
        for(int num : nums) {

            if(num < pivot) {

                less.push_back(num);
            }

            else if(num == pivot) {

                equal.push_back(num);
            }

            else {

                greater.push_back(num);
            }
        }

        vector<int> ans;

        // Add smaller elements
        for(int x : less) {

            ans.push_back(x);
        }

        // Add equal elements
        for(int x : equal) {

            ans.push_back(x);
        }

        // Add greater elements
        for(int x : greater) {

            ans.push_back(x);
        }

        return ans;
    }
};
