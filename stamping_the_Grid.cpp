using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;

const int OCCUPIED = 1;
const int EMPTY = 0;

class Solution {

    vvi updateNearestCross(const vvi& grid, int n, int m) {
        vvi updatedDistances(n, vi(m, 1));
        for (int i=n-1; i>=0; i--)
            for (int j=m-1; j>=0; j--)
                if (grid[i][j] == OCCUPIED) {
                    updatedDistances[i][j] = 0;
                } else if (j<m-1) {
                    updatedDistances[i][j] = updatedDistances[i][j+1]+1;
                }
        return updatedDistances;
    }

    vvb matrixBuildChecker(const vvi& value, int n, int m, int threshold, int windowSize) {
        vvb updatedMatrix(n, vb(m, false));
        for (int j=0; j<m; j++) {
            int containAllMaximums = 0;
            for (int i=0; i<windowSize; i++)
                if (value[i][j] >= threshold) containAllMaximums++;
            updatedMatrix[0][j] = containAllMaximums == windowSize;
            for (int i=windowSize; i<n; i++) {
                if (value[i-windowSize][j] >= threshold) containAllMaximums--;
                if (value[i][j] >= threshold) containAllMaximums++;
                updatedMatrix[i-windowSize+1][j] = containAllMaximums == windowSize;
            }
        } 
        return updatedMatrix;
    } 

    vvb matrixFlattener(const vvb& cell, int n, int m, int height, int width) {
        vvb flattenerOneDimension(n, vb(m, false));
        for (int i=0; i<n; i++) {
            int countPossibles = 0;
            for (int j=0; j<m; j++) {
                if (j>=width && cell[i][j-width]) countPossibles--;
                if (cell[i][j]) countPossibles++;
                flattenerOneDimension[i][j] = countPossibles > 0; 
            }
        }
        vvb flattenerTwoDimension(n, vb(m, false));
        for (int j=0; j<m; j++) {
            int countPossibles = 0;
            for (int i=0; i<n; i++) {
                if (i>=height && flattenerOneDimension[i-height][j]) countPossibles--;
                if (flattenerOneDimension[i][j]) countPossibles++;
                flattenerTwoDimension[i][j] = countPossibles > 0;
            }
        }
        return flattenerTwoDimension;
    }

public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {

        const int gridHeight = grid.size(), gridWidth = grid[0].size();
        bool allOccupied = true;
        for (int i=0; i<gridHeight; i++)
            for (int j=0; j<gridWidth; j++)
                if (grid[i][j] == EMPTY) {
                    allOccupied = false;
                    break;
                } 
        if (allOccupied) return true;
        if (gridHeight < stampHeight || gridWidth < stampWidth) return false;
        
        
        //For each cell, find its nearest right cross
        vvi rightCrossDistance = updateNearestCross(grid, gridHeight, gridWidth);
        
        //For each cell as top-left corner of the sub-matrix, check if matrix-building is possible
        vvb canSubmatrixBeBuilt = matrixBuildChecker(rightCrossDistance, gridHeight, gridWidth, stampWidth, stampHeight);
        
        //For each cell, check whether any stamp with top-left corner relatively North-West to current can consume it
        vvb isCellConsumptionPossible = matrixFlattener(canSubmatrixBeBuilt, gridHeight, gridWidth, stampHeight, stampWidth);


        for (int i=0; i<gridHeight; i++)
            for (int j=0; j<gridWidth; j++)
                if (grid[i][j] == OCCUPIED) continue;
                else if (isCellConsumptionPossible[i][j] == false) return false;
        return true; 
    }
};
