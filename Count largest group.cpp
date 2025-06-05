class Solution {
public:

    int sum(int n){
        int s=0;
        while(n){
            s+=n%10;
            n/=10;
        }
        return s;
    }

    int countLargestGroup(int n) {
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            int x=sum(i);
            mp[x]++;
        }

    int maxi=INT_MIN;
    for(auto p: mp){
        maxi=max(maxi,p.second);
    }

    int c=0;
    for(auto p:mp){
        if(p.second==maxi) c++;
    }

    return c;
    }
};
