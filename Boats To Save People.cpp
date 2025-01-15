class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int count = 0;
        long long sum = 0;
        int i = 0 ;
        int j = n-1;
        while(i<=j){
      if((people[i]+people[j])<=limit) {
            count++;
            i++;
            j--;
         }
         else {
            j--;
            count++;
         }
    
        }
          return count;
    }
};
