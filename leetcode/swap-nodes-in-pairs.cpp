// 8ms
// update p->pa->pb
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
	bool hasNodePair(ListNode *p) {
		return p != NULL && p->next != NULL && p->next->next != NULL;
	}
	void swapNodePair(ListNode **p, ListNode **pa, ListNode **pb) {
		(*pa)->next = (*pb)->next;
		(*pb)->next = *pa;
		(*p)->next = *pb;
	}
	ListNode *swapPairs(ListNode *head) {
		ListNode *p = new ListNode(-1), *ret = p, *pa, *pb;
		p->next = head;
		while (hasNodePair(p)) {
			pa = p->next, pb = pa->next;
			swapNodePair(&p, &pa, &pb);
			p = pa;
		}
		return ret->next;
	}
};
