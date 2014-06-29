// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *cur = helper, *prev = NULL;
        int i = 0;
        while(i < m) {
            prev = cur;
            cur = cur->next;
            ++i;
        }
        ListNode *midHead = cur;
        while(i < n) {
            cur = cur->next;
            ++i;
        }
        ListNode *next = cur->next;
        cur->next = NULL;
        prev->next = revList(midHead);
        midHead->next = next;
        return helper->next;
    }
    
    ListNode *revList(ListNode *head) {
        ListNode *cur = head, *prev = NULL;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
