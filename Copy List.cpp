RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A) return A;
    RandomListNode* cur=A;
    unordered_map<RandomListNode*,RandomListNode*> mp;
    while(cur)
    {
        RandomListNode* t= new RandomListNode(cur->label);
        mp[cur]=t;
        cur=cur->next;
    }
    cur = A;
    while(cur)
    {
      mp[cur]->next=mp[cur->next];
      mp[cur]->random=mp[cur->random];
      cur=cur->next;  
    }
    return mp[A];
}
