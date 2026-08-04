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
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slowNode = head;
        ListNode* fastNode = head;
        while(fastNode->next != NULL && fastNode->next->next != NULL){
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
            if(fastNode->next == slowNode || fastNode == slowNode){
                return true;
            }
        }
        return false;
    }
};
