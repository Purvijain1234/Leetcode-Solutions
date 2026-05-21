/*
Problem Number: 0021
Problem Name: Merge Two Sorted Lists

Difficulty: Easy

Topics:
Linked List, Recursion

Approach:
Use a dummy node and compare nodes
from both linked lists.

Attach the smaller node to the result list
and move forward.

At the end, attach remaining nodes.

Time Complexity:
O(n + m)

n = length of list1
m = length of list2

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        //compare
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // remaining node
        if(list1 != NULL){
            temp->next = list1;
        }
        else{
            temp->next = list2;
        }
        return dummy->next;
    }
};
