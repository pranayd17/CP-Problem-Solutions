int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
  unordered_map<int, int>ladder;
  for(auto it : A){
    ladder[it[0]] = it[1];
  }
  unordered_map<int, int>snake;
  for(auto it : B){
    snake[it[0]] = it[1];
  }
  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
  q.push({0, 1});
  vector<int>vis(101, 0);
  vis[1] = 1;
  while(!q.empty()){
    int step = q.top().first;
    int node = q.top().second;
    q.pop();
   
    if(node==100){
      return step;
    }
   
    for(int i=1; i<=6; i++){
      int newNode = node+i;
      if(!vis[newNode]){
        if(newNode<=100 && ladder[newNode]>0){
          q.push({step+1, ladder[newNode]});
          vis[ladder[newNode]]=1;
        }else if(newNode<=100 && snake[newNode]>0){
          q.push({step+1, snake[newNode]});
          vis[snake[newNode]]=1;
        }else{
          if(newNode<=100){
            q.push({step+1, newNode});
            vis[newNode]=1;
          }
        }
      }
    }
  }
  return -1;
}
