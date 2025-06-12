class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans=0;
        for(int i=1;n>0;i++){
            long long start=pow(10,i-1);
            long long end=pow(10,i);
            for(long long j=start;j<end;j++){
                long long odd=create1(j);
                if(n>0 && kpal(odd,k)){
                    n--;
                    ans+=odd;
                }
                else if (n==0) break;
            }
            for(long long j=start;j<end;j++){
                long long even=create2(j);
                if(n>0 && kpal(even,k)){
                    n--;
                    ans+=even;
                }
                else if(n==0) break;
            }
        }
        return ans;
    }
    long long create1(long long n){
        long long pal=n;
        long long y=n/10;
        while(y>0){
            pal=pal*10+y%10;
            y/=10;
        }
        return pal;
    }
    long long create2(long long n){
        long long pal=n;
        long long y=n;
        while(y>0){
            pal=pal*10+y%10;
            y/=10;
        }
        return pal;
    }
    bool kpal(long long n,int k){
        string s="";
        while(n>0){
            s+=('0'+n%k);
            n/=k;
        }
        string t=s;
        reverse(t.begin(),t.end());
        return t==s;
    }
};
