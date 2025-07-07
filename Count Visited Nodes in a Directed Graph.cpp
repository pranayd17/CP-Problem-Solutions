class Solution {
public:
   int n ; 
   vector <vector <int>> g1 , g2 ;
   vector <int> col; 
   vector <int> cycle ; 
   vector <int> parent ; 

   void dfs(int node , int cnt , vector <int> &ans){
       if(col[node] != 2){
           ans[node] = cnt + 1;  
           cnt ++ ; 
       }
       else if(col[node] == 2){
        ans[node] = cnt ; 
       }
       if(col[node] == 0) col[node] = 1 ; 
       for(int i =0 ; i < (int)g2[node].size() ; i++){
        if(col[g2[node][i]] == 2) continue ;
        dfs(g2[node][i] , cnt , ans) ; 
       }
   }

   void cy(int node  , int par ){
       parent[node] = par ; 
       for(int i =0 ;i < (int)g1[node].size() ; i++){
           if(col[g1[node][i]] == 0){
            col[g1[node][i]] =1 ; 
              cy(g1[node][i] , node) ; 
           }
           else if(col[g1[node][i]] == 1){
            int temp = node ; 
            while(temp != g1[node][i]){
                col[temp] = 2 ; 
                cycle.push_back(temp) ; 
                temp = parent[temp] ; 
            }
            cycle.push_back(g1[node][i]) ; 
            col[g1[node][i]] = 2 ; 
            return ; 
           }
       }
   }


    vector<int> countVisitedNodes(vector<int>& e) {
           n = (int)e.size()  ; 
           g1.resize(n)  ;
           g2.resize(n) ; 
           col.assign(n , 0) ;
           parent.assign(n , -1 ) ;  
           for(int i = 0 ; i < (int)e.size() ; i++){
            int u = i ; 
            int v = e[i] ; 
            g1[u].push_back(v) ;
            g2[v].push_back(u) ;  
           }

           vector <int> ans(n , 0) ;
           for(int i =0 ;i < n ; i++){

            if(col[i] == 0){
               cy(i , -1) ; 
                for(int j =0 ; j < (int)cycle.size() ; j++){
                    dfs(cycle[j] , (int)cycle.size() , ans) ; 
                }
                cycle.clear() ; 
            }
           }
           return ans ; 
    }
};
