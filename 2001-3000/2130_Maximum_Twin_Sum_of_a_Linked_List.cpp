/*
Problem Number: 2130
Problem Name: Maximum Twin Sum of a Linked List

LeetCode Link:
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

Difficulty: Medium

Topics:
Linked List, Two Pointers

Approach:
1. Find the middle of the linked list using
   Slow and Fast pointers.
2. Reverse the second half of the linked list.
3. Traverse both halves simultaneously.
4. Compute twin sums:
      firstHalfNode + secondHalfNode
5. Keep track of the maximum twin sum.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next)
 *         : val(x), next(next) {}
 * };
 */

class Solution {
public:

    int pairSum(ListNode* head) {

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;

        while(slow) {

            ListNode* nextNode =
                slow->next;

            slow->next = prev;

            prev = slow;

            slow = nextNode;
        }

        // Calculate twin sums
        int maxSum = 0;

        ListNode* first = head;
        ListNode* second = prev;

        while(second) {

            maxSum =
                max(
                    maxSum,
                    first->val + second->val
                );

            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};
