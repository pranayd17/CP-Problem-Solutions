const int INF=1001001001;
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<vector<int>>L,R,Lq,Rq;
        for(int i=0;i<k;i++){
            Lq.push({0,i});
        }
        int need=n,ans=0,tm=0;
        while(need>0||R.size()||Rq.size()){
            while(Lq.size()&&tm>=-Lq.top()[0]){
                auto x=Lq.top();Lq.pop();
                L.push({time[x[1]][0]+time[x[1]][2],x[1]});
            }
            while(Rq.size()&&tm>=-Rq.top()[0]){
                auto x=Rq.top();Rq.pop();
                R.push({time[x[1]][0]+time[x[1]][2],x[1]});
            }
            if(R.size()){
                auto x=R.top();R.pop();
                if(need==0){ans=tm+time[x[1]][2];}
                Lq.push({-(tm+time[x[1]][2]+time[x[1]][3]),x[1]});
                tm+=time[x[1]][2];
            }else if(L.size()&&need>0){
                auto x=L.top();L.pop();
                need--;
                Rq.push({-(tm+time[x[1]][0]+time[x[1]][1]),x[1]});
                tm+=time[x[1]][0];
            }else{
                tm=INF;
                if(Lq.size())tm=min(tm,-Lq.top()[0]);
                if(Rq.size())tm=min(tm,-Rq.top()[0]);
            }
        }
        return ans;
    }
};
