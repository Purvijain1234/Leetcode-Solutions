/*
Problem Number: 0002
Problem Name: Add Two Numbers

Difficulty: Medium

Topics:
Linked List, Math, Recursion

Approach:
Traverse both linked lists simultaneously.

Add corresponding digits along with carry.
Create a new node for each digit of the sum.

If carry remains at the end,
create one final node.

Time Complexity:
O(max(n, m))

Space Complexity:
O(max(n, m))
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node
        ListNode* dummy = new ListNode(0);

        ListNode* temp = dummy;

        int carry = 0;

        // Traverse both linked lists
        while(l1 != NULL || l2 != NULL || carry) {

            int sum = carry;

            // Add value from first list
            if(l1 != NULL) {

                sum += l1->val;

                l1 = l1->next;
            }

            // Add value from second list
            if(l2 != NULL) {

                sum += l2->val;

                l2 = l2->next;
            }

            // Update carry
            carry = sum / 10;

            // Create new node
            temp->next = new ListNode(sum % 10);

            temp = temp->next;
        }

        return dummy->next;
    }
};
