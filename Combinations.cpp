
void generate(int currentElement, vector<vector<int>> &result, vector<int> &current, int A, int B){

    if(current.size() == B){

        result.push_back(current);

        return;

    }

    

    for(int i = currentElement; i <= A; i++){

        current.push_back(i);

        generate(i + 1, result, current, A, B);

        current.pop_back();

    }

}


vector<vector<int> > Solution::combine(int A, int B) {

    vector<vector<int>> result;

    vector<int> current;

    generate(1, result, current, A, B);

    return result;

}
