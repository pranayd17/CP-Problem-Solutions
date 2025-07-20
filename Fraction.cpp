string Solution::fractionToDecimal(int A, int B) {
string ans="";
long long int num=A;
long long int den=B;
if(num>0 && den<0)
{
ans+='-';
}
else if(num<0 && den>0)
{
ans+='-';
}
num=abs(num);
den = abs(den);
if(num==0)
{
return "0";
}
long long int r=num%den;
long long int v=num/den;
    ans+=to_string(v);
    map<long long int,long long int>m;
    if(r!=0)
    {
    ans+='.';
    while(1)
    {
    if(m.find(r)!=m.end())
    {
    return ans.substr(0,m[r])+'('+ans.substr(m[r])+')';
                break;
    }
    if(r==0)
    {
    return ans;
    break;
    }
    m[r]=ans.size();
    long long int d= (r*10)/den;
    ans+=to_string(d);
    r=(r*10)%den;
    }
    }
    return ans;
}
