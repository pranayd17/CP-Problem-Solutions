#include <iostream>
#include <string>

using namespace std;

class Solution {
    int state_mem[5000][64]; // Memoization table for DP
    int MOD = 1e9 + 7;       // Modulo value to avoid overflow

public:
    // Recursive function to count valid colorings
    int countWays(int& n, int r, int c, int prev_state, int curr_state) {
        // If all rows are painted, return 1 valid way
        if (r == n) return 1;

        // If end of current row, move to next row
        if (c == 3) {
            return countWays(n, r + 1, 0, curr_state, 0);
        }

        // Memoization check for start of row
        if (c == 0 && state_mem[r][prev_state] != -1) {
            return state_mem[r][prev_state];
        }

        // Get color of cell directly above current cell
        int upcolor = (prev_state >> ((2 - c) * 2)) & 3;

        // Get color of left cell in current row (if exists)
        int leftcolor = (c > 0) ? (curr_state & 3) : 0;

        int no_of_ways = 0;

        // Try all 3 colors (encoded as 1, 2, 3)
        for (int color = 1; color <= 3; color++) {
            // Ensure color is different from both up and left neighbors
            if (color != upcolor && color != leftcolor) {
                // Recurse to next column, appending the new color
                no_of_ways = (no_of_ways + countWays(n, r, c + 1, prev_state, (curr_state << 2) + color)) % MOD;
            }
        }

        // Cache the result for the current row and previous state
        if (c == 0) {
            state_mem[r][prev_state] = no_of_ways;
        }

        return no_of_ways;
    }

public:
    int numOfWays(int n) {
        memset(state_mem, -1, sizeof(state_mem)); // Initialize memo table
        return countWays(n, 0, 0, 0, 0);           // Start from row 0 and column 0
    }
};
