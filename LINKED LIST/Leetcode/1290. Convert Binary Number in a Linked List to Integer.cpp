class Solution {
public:
    int i = 1;
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        while(head != NULL)
        {
            sum=(sum*2)+head->val;
            head = head->next;
        }
        return sum;
    }
};
// class Solution {
// public:
//     int i = 1;
//     int getDecimalValue(ListNode* head) {
//         if(head->next==NULL) return head->val;
//         int y = getDecimalValue(head->next) + head->val * pow(2,i);
//         i++;
//         return y;
//     }
// };