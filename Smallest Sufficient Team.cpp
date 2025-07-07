int m, n;
vector<int> pmask;
vector<vector<int>> selected;
int dp[1 << 20];

class Solution {
public:
    int get_mask(vector<string>& req, vector<string>& person_skill) {
        int mask = 0;
        for (auto skill : person_skill) {
            for (int i = 0; i < req.size(); i++) {
                if (skill == req[i]) {
                    mask |= (1 << i);
                    break;
                }
            }
        }
        return mask;
    }

    int rec(int mask) {
        if (mask == (1 << n) - 1) {
            selected[mask] = {};  // All skills covered
            return 0;
        }
        if (dp[mask] != -1) return dp[mask];

        int ans = 1e9;
        vector<int> best;

        for (int i = 0; i < m; i++) {
            int b_mask = pmask[i];
            int include = b_mask | mask;
            if (include == mask) continue;  

            int curr = 1 + rec(include);
            if (curr < ans) {
                ans = curr;
                best = selected[include];  
                best.push_back(i);         
            }
        }

        selected[mask] = best;
        return dp[mask] = ans;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();
        pmask.resize(m);
        memset(dp, -1, sizeof(dp));
        selected.assign(1 << n, vector<int>());

        for (int i = 0; i < m; i++) {
            pmask[i] = get_mask(req_skills, people[i]);
        }

        rec(0);
        return selected[0];
    }
};
