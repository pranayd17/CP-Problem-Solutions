class Solution {
public:
    int overlap(const string &a , const string &b) {
        int min_len = min(a.size() , b.size());
        for (int len = min_len ; len >= 1; len--) {
            string suffix = a.substr(a.size() - len);
            string preffix = b.substr(0, len);
            if (suffix == preffix) {
                return len;
            }
        }
        // no matching
        return 0;
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlaps(n, vector<int> (n, 0));

        for (int i =0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                overlaps[i][j] = overlap(words[i], words[j]);
            }
        }

        vector<vector<int>> dp((1 << n), vector<int> (n+1, 1e9));
        vector<vector<int>> parent((1 << n), vector<int> (n+1, -1));

        // base case (only one string is there)

        for (int i = 0 ; i < n; i++) {
            dp[1 << i][i] = words[i].size();
        }

        // transition state

        for (int mask = 0; mask < (1 << n) ; mask++) {
            for (int last = 0; last < n; last++) {
                // if last is allready calculated then proced for next or skip
                if (!(mask & (1 << last))) continue;
                for (int next = 0 ; next < n; next++) {
                    if (mask & (1 << next)) continue;
                    int new_mask = (mask | (1 << next));
                    // lenght of last string + current string - overlap
                    int val = dp[mask][last] + words[next].size() - overlaps[last][next];

                    if (val < dp[new_mask][next]) {
                        dp[new_mask][next] = val;
                        // for keep trak of path need to store last in current mask and next;
                        parent[new_mask][next] = last;
                    }
                }
            }
        }

        // finding best solution
        int mask = (1 << n) - 1; // 111111111 dp[mask][i => 0 ,n]
        int last_index = 0;

        // finding the shortes value of string after processing all index so mask = (1 << n) -1;
        for (int i = 1 ; i < n; i++) {
            if(dp[mask][i] < dp[mask][last_index]) {
                last_index = i;
            }
        }

        // path construction
        vector<int>path;
        while (last_index != -1) {
            path.push_back(last_index);
            int next_index = parent[mask][last_index];
            mask = (mask ^ (1 << last_index));
            last_index = next_index;
        }   

        // reverse for getting path in actual order
        reverse(path.begin(), path.end());

        // build the string;

        string result = words[path[0]];

        for (int i = 1 ; i < path.size() ; i++) {
            int current_overlap = overlaps[path[i-1]][path[i]];
            result += words[path[i]].substr(current_overlap);
        }
        return result;
    }   
};
