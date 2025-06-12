class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b)
    {
        return a[1] > b[1];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(),rooms.end(),cmp);
        for(int i = 0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),cmp);
        int j = 0;
        set<int>s;
        int n = queries.size();
        vector<int>ans(n);
        for(int i = 0;i<queries.size();i++)
        {
            while(j<rooms.size() && queries[i][1] <= rooms[j][1])
            {
                s.insert(rooms[j][0]);
                j++;
            }
            if(s.size()==0)
            {
                ans[queries[i][2]] = -1;
                continue;
            }
            //cout<<j<<"\n";
            auto it = s.upper_bound(queries[i][0]);
          //  cout<<queries[i][0]<<"\n";
            int val1 = INT_MAX;
            if(it != s.end())
            {
                  val1 = *it;
            }
           
            int val2 = INT_MAX;
            if(it != s.begin())
            {
                it--;
                val2 = *it;
            }
            int diff =  abs(queries[i][0]-val1);
            int id = val1;
         //   cout<<val1<<" "<<val2<<" "<<id<<"\n";
            if( (diff == abs(queries[i][0]-val2) && val2 < val1 ) ||  ( diff > abs(queries[i][0]-val2)) )
            {
                id = val2;
            }
            ans[queries[i][2]] = id;
        }
        return ans;
    }
};
