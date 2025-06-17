ListNode* Solution::mergeKLists(vector<ListNode*> &arr) {
    ListNode *dummy = new ListNode(-1);
    ListNode *ptr = dummy;
   
    // min heap -> will hold {node->val , node } (int, ListNode)
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
   
    int k = arr.size();
   
    vector<int> ans;
   
    for(int i = 0; i < k ; i++){
        if(arr[i]){ // check to ensure we dont run into NULL node (or mistakenly push NULL node in our PQ)
            pq.push({arr[i]->val, arr[i]});
        }
    }
   
    while(pq.size() > 0){
        auto topp = pq.top();
        pq.pop();
       
        int e = topp.first;
        ListNode *node = topp.second;
       
        ptr->next = node;
        ptr = ptr->next;
       
        if(node && node->next){
            pq.push({node->next->val, node->next});
        }
    }
   
    return dummy->next;;
       
}
