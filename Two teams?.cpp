int helper(int src, int color, vector<vector<int> > &G, vector<int> &C) {

    C[src] = color;

    for(int a : G[src]) {

        if(C[a] == -1) {

            if(!helper(a, !color, G, C))

                 return 0;

        }

        else if(C[a] == color)

            return 0;

    }

    return 1;

}


int Solution::solve(int A, vector<vector<int> > &B) {

    vector<vector<int> > G(A);

    vector<int> C(A,-1);

    for(auto a : B) {

        G[a[0]-1].push_back(a[1]-1);

        G[a[1]-1].push_back(a[0]-1);

    }

    for(int i=0;i<A;i++) {

        if(C[i] == -1) {

             if(!helper(i, 1, G, C)) 

                 return 0;

        }

    }

    return 1;

}

