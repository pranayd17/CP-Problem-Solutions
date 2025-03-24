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


ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* a=list1;
        ListNode* b=list2;
        ListNode* t=new ListNode(100);
        ListNode* head=t;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                t->next=a;
                a=a->next;
                t=t->next;
            }
            else{
                t->next=b;
                b=b->next;
                t=t->next;
            }
        }
        if(a==NULL) t->next=b;
        else t->next=a;
        return head->next;
    }

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a=lists[0];
            ListNode* b=lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(merge(a,b));
        }
        return lists[0];
    }
};
