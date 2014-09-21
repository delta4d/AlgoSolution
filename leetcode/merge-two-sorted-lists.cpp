// 52ms
// same as merge operation in merge sort
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1), *p = head, *p1, *p2;
        for (p1=l1,p2=l2; p1!=NULL&&p2!=NULL; p=p->next) {
            if (p1->val < p2->val) {
                p->next = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                p->next = new ListNode(p2->val);
                p2 = p2->next;
            }
        }
        for ( ; p1!=NULL; p1=p1->next,p=p->next) p->next = new ListNode(p1->val);
        for ( ; p2!=NULL; p2=p2->next,p=p->next) p->next = new ListNode(p2->val);
        return head->next;
    }
};

// splice not create
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(-1), *p1, *p2, *cc=ret;
        for (p1=l1,p2=l2; p1!=nullptr&&p2!=nullptr; ) {
            if (p1->val < p2->val) cc->next = p1, p1 = p1->next;
            else cc->next = p2, p2 = p2->next;
            cc = cc->next;
        }
        for (; p1 != nullptr; p1=p1->next,cc=cc->next) cc->next = p1;
        for (; p2 != nullptr; p2=p2->next,cc=cc->next) cc->next = p2;
        return ret->next;
    }
};
