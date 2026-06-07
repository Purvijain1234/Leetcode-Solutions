/*
Problem Number: 2196
Problem Name: Create Binary Tree From Descriptions

LeetCode Link:
https://leetcode.com/problems/create-binary-tree-from-descriptions/

Difficulty: Medium

Topics:
Tree, Hash Table, Binary Tree

Approach:
1. Create TreeNode objects for every unique value.
2. Connect parent and child nodes based on descriptions.
3. Store every child node value in a set.
4. The root is the node that never appears as a child.
5. Return the root node.

Time Complexity:
O(n)

Space Complexity:
O(n)

where n = number of descriptions
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* createBinaryTree(
        vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> nodes;

        unordered_set<int> children;

        for(auto &d : descriptions) {

            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // Create parent node if absent
            if(!nodes.count(parent)) {
                nodes[parent] =
                    new TreeNode(parent);
            }

            // Create child node if absent
            if(!nodes.count(child)) {
                nodes[child] =
                    new TreeNode(child);
            }

            // Connect nodes
            if(isLeft) {
                nodes[parent]->left =
                    nodes[child];
            }

            else {
                nodes[parent]->right =
                    nodes[child];
            }

            children.insert(child);
        }

        // Root never appears as child
        for(auto &d : descriptions) {

            int parent = d[0];

            if(!children.count(parent)) {

                return nodes[parent];
            }
        }

        return nullptr;
    }
};
