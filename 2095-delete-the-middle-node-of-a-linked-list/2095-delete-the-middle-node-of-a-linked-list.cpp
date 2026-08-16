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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == nullptr){
            head = nullptr;
            return head ;
            
        };
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prv = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prv = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // now we have value of the mid at the slow
        
        prv->next = slow->next;
        delete slow;

        return head;
    }
};
