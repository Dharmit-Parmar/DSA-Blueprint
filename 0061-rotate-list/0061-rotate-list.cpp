class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        int length = 0;
        ListNode* trv = head;
        while (trv != nullptr) {
            length++;
            trv = trv->next;
        }

        k = k % length;
        if (k == 0) return head;

        vector<int> s;
        trv = head; 
        for (int i = 0; i < length - k; i++) {
            trv = trv->next;
        }
 
        ListNode* element = trv;
        while (element != nullptr) {
            s.push_back(element->val);
            element = element->next;
        }
 
        trv = head;
        for (int i = 0; i < length - k - 1; i++) {
            trv = trv->next;
        }
        trv->next = nullptr; 
        for (int i = s.size() - 1; i >= 0; i--) {
            ListNode* newnode = new ListNode(s[i], head);
            head = newnode;
        }

        return head;
    }
};