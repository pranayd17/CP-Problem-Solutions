class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> Count(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> EndTime;
        priority_queue<int,vector<int>,greater<int>> FreeRoom;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++)FreeRoom.push(i);

        for(int i=0;i<meetings.size();i++){
            int start=meetings[i][0];
            while(!EndTime.empty() && start>=EndTime.top().first){
                FreeRoom.push(EndTime.top().second);
                EndTime.pop();
            }
            if(!FreeRoom.empty()){
                int TopRoom=FreeRoom.top();
                FreeRoom.pop();
                Count[TopRoom]++;
                EndTime.push({meetings[i][1],TopRoom});
            }
            else{
                if(!EndTime.empty()){
                    long long end=EndTime.top().first;
                    int RoomNo=EndTime.top().second;
                    EndTime.pop();
                    Count[RoomNo]++;
                    EndTime.push({end+(meetings[i][1]-meetings[i][0]),RoomNo});
                }
            }
            
        }



        int max=-1,ans;
        for(int k=0;k<n;k++){
            cout<<Count[k]<<" ";
            if(Count[k]>max){
                ans=k;
                max=Count[k];
            }
        }
        return ans;
    }
};
