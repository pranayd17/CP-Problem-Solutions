int Solution::diffPossible(const vector<int> &A, int B) {

    unordered_map<int,int> m;

    bool flag=false;

    for(int i=0;i<A.size();i++){

        if(m.find(A[i])!=m.end()){

            flag=true;

        }else{

            m[A[i]]=i;

        }

    }

    if(B==0&&flag==true) return 1;

    for(int i=0;i<A.size();i++){

        if(m.find(B+A[i])!=m.end()&&i!=m[B+A[i]]){

            return 1;

        }

    }

    return 0;

}
