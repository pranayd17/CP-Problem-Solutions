int Solution::diffPossible(vector<int> &A, int k) {

    int i = 0, j = 1, n = A.size();

    

    while(j < n) {

        int dif = A[j] - A[i];

        

        if(dif == k) return 1;

        

        if(dif > k) {

            i++;

        }else {

            j++;

        }


       if(i == j) {

           j++;

       }

    }

    

    return 0;

}
