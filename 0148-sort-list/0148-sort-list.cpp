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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Put all node values into a vector
        vector<int> values;
        ListNode* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        // Step 2: Sort the vector
        sort(values.begin(), values.end());

        // Step 3: Put the sorted values back into the linked list
        curr = head;
        for (int i = 0; i < values.size(); i++) {
            curr->val = values[i];
            curr = curr->next;
        }

        return head;
    }
};