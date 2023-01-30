class Solution {
public:
    ListNode* mergeInBetween(ListNode* h, int a, int b, ListNode* n) {
        ListNode *s,*f;
        auto *p=h;
        int c = 0;
        while(h!=NULL)
        {
            if(c==(a-1)) s=h;
            if(c==(b+1)) f=h;
            c++;
            h=h->next;
        }
        s->next = n;
        while(n->next != NULL)
        {
            n=n->next;
        }
        n->next = f;
        return p;
    }
};