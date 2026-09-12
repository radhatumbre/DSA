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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* middle(ListNode* head, ListNode* end){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != end && fast->next != end){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* buildTree(ListNode* start, ListNode* end){
        if(start==end) return NULL;
        ListNode* middleNode = middle(start,end);
        if(middleNode == nullptr) return NULL;
        TreeNode* head = new TreeNode(middleNode->val);
        head->left = buildTree(start, middleNode);
        head->right = buildTree(middleNode->next, end);
        return head;
    }
    TreeNode* sortedListToBST(ListNode* head) {
       return buildTree(head,NULL);
    }
};