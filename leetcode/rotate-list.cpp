// 52ms
// k may be larger than the length of list
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return head;
        if (k == 0) return head;
        ListNode *pk = head, *tail = head, *p;
        int cnt = 0, n = 0;
        for (p=head; p!=NULL; p=p->next,++n);
        k %= n;
        if (k == 0) return head;
        for (p=head; p!=NULL; p=p->next,++cnt) {
            if (cnt > k) pk = pk->next;
            if (p->next != NULL) tail = tail->next;
        }
        tail->next = head;
        head = pk->next;
        pk->next = NULL;
        return head;
    }
};
