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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == l2) return l1;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        if(l1->val <= l2->val){
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
        else{
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        
        int len = lists.size();
        while(len > 1){
            for(int i = 0; i < len / 2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            len = (len + 1) / 2;	// 如果是奇数个链表，确保正中间的能被访问
        }
        return lists.front();
    }
};