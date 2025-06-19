#include <vector>
#include <string>
#include <queue>
using namespace std;

int rc[4] = {1, 0, 0, -1};
int cc[4] = {0, 1, -1, 0};
int n;
int m;

bool dfs(int row, int col, vector<string> &A, string B, int i) {
if (i == B.length()) {
return true;
}
for (int j = 0; j < 4; j++) {
int nr = row + rc[j];
int nc = col + cc[j];
if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
if (A[nr][nc] == B[i]) {
if (dfs(nr, nc, A, B, i + 1)) {
return true;
}
}
}
}
return false;
}

int Solution::exist(vector<string> &A, string B) {
n = A.size();
m = A[0].length();
queue<pair<int, int>> q;
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (B[0] == A[i][j]) {
q.push({i, j});
}
}
}
while (!q.empty()) {
auto it = q.front();
int row = it.first;
int col = it.second;
q.pop();
if (dfs(row, col, A, B, 1)) {
return 1;
}
}
return 0;
}
