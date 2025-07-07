class Solution {
public:

    vector<long long>par, vis, sum,sizee;
    int find(int x)
    {
        if(par[x]==x)return par[x];
        return par[x]=find(par[x]);
    }

    void unionn(int x,int y)
    {
        int xx = find(x), yy = find(y);
        if(xx!=yy)
        {
            if(sizee[xx]>sizee[yy])
                swap(xx,yy);
        }
        par[xx]=yy;
        sizee[yy]+=sizee[xx];
        sum[yy]+=sum[xx];
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) {


        int n=nums.size();
        par.resize(n);
        sizee.resize(n+1,1);
        vis.resize(n,0);
        sum.resize(n,0);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }

        vector<long long>ans(q.size(),0);
        long long  mx=0;
        for(int i=n-1;i>=1;i--)
        {
            ans[i]=mx;
            int id = q[i];
            
            if(id>0 && vis[id-1]!=0)
            {
                unionn(id-1,id);
            }
            if(id<n-1 && vis[id+1]!=0)
            {
                unionn(id+1,id);
            }
            sum[find(id)]+=nums[id];
            vis[id]=1;
            mx=max(mx,sum[find(id)]);

        }
        ans[0]=mx;

        return ans;

        
        
    }
};
