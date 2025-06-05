class Solution {
public:
    vector<int> threeEqualParts(vector<int>& ar) {
        int cnt0 = 0, cnt1 = 0;
        for(auto i: ar){
            if(i)
                cnt1++;
            else
                cnt0++;
        }
        
        if(cnt1 % 3 != 0)
            return {-1, -1};
        else
        {
            if(cnt1 == 0){
                return {0, 2};
            }
            else{
                int k = cnt1 / 3;
                int one = 0, two = 0, three = 0;
                int cnt = 0;
                for(int i = 0; i < ar.size(); i++){
                    if(ar[i]){
                        if(cnt == 0)
                            one = i;
                        cnt++;
                        
                        if(cnt == k + 1)
                            two = i;
                        
                        if(cnt == 2 * k + 1){
                            three = i;
                            break;
                        }
                    }
                }
                
                //now we have 3 indices.......
                //check if each increment in the indices results in similar integer 0/1....
                
                while(1){
                    if(ar[one] != ar[two] or ar[two] != ar[three] or three == ar.size())
                        break;
                    
                    one++;
                    two++;
                    three++;
                }
                
                if(three == ar.size())
                    return {one - 1, two};
                else
                    return {-1, -1};
            }     
        }
    }
};
