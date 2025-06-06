class Solution {
public:
	int superEggDrop(int k, int N) {
		if (k == 1 || N<3) return N;
		double n = log(N) / log(2);
		if (k < n++) 
		    while (fun(k, n) < N) ++n;
		return n;
	}
private: 
	int fun(int k, int n) {
		int i=1,temp = 1, maxNumOfF = 0;
		while (i <= k) {
			temp = temp*(n--) / (i++);
			maxNumOfF += temp;
		}
		return maxNumOfF;
	}
};
