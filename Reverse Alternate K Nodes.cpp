ListNode* Solution::solve(ListNode* A, int B) {
    stack<int> st;
   
    ListNode* temp=A;
   
    while(temp&&temp->next){
        int k=B;
       
        ListNode* temp2=temp;
       
        while(k--&& temp){
           
            st.push(temp->val);
           
            temp=temp->next;
        }
        k=B;
        while(k-- && temp2){
           
            temp2->val=st.top();
            st.pop();
           
            temp2=temp2->next;
        }
       
        k=B;
        while(k-- && temp){
            temp=temp->next;
        }
    }
   
    return  A;
}
