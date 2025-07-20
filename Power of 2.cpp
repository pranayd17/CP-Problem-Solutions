int Solution::power(string A) {

    if(A=="2")

        return 1;

        

    

    if((A.back()-'0')&1) //odd number then return 0

        return 0;

        

    string quotient;

    

    int carry=0;

        

    for(int i=0;i<A.size();++i) {

        int num=carry*10+A[i]-'0';

    

        //avoid leading zeros

        if(num/2!=0 || !quotient.empty())

            quotient.push_back('0'+num/2);

            

        carry=num%2;

    }

        

    return power(quotient);

}
