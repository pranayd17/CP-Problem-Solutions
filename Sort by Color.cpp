void Solution::sortColors(vector<int> &A) {
   
   
   int zero = 0, one = 0, two = 0;
   
   for(int i = 0; i< A.size(); i++){
       if(A[i] == 0)zero++;
       else if(A[i] == 1)one++;
       else two++;
    }
   
    A.clear();
   
    while(zero--){
        A.push_back(0);
    }
    while(one--){
        A.push_back(1);
    }
    while(two--){
        A.push_back(2);
    }
   
}
