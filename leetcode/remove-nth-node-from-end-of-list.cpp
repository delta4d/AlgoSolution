// 72ms
// basic link list operation
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
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			ListNode *rp = head, *pre = head, *p = head;
			for (int i=0; p!=NULL; ++i) {
			    if (i >= n) pre = rp, rp = rp->next;
			    p = p->next;
			}
			if (rp == head) head = head->next;
			else if (rp == NULL) pre->next = NULL;
			else pre->next = rp->next;
			return head;
		}
};
