class Solution {
public:
    struct Point {
        int x;
        int y;
    };

    static bool comparePoints(Point &a, Point &b) {
        return a.x < b.x;
    }
    
    int calculateDistance(Point p1, Point p2, Point p) {
        return abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
    }
  
    int crossProduct(Point a, Point b, Point c) {
        float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    
        if (area < 0)
            return -1; // clockwise
    
        if (area > 0)
            return 1; // counter-clockwise
    
        return 0; // collinear
    }

    bool tryAddToSet(vector<Point> &pointsSet, Point &p1, Point &p2, Point& p) {
        int crossProd = crossProduct(p1, p2, p);
        if (crossProd >= 0)
            pointsSet.push_back(p);
        
        return crossProd >= 0;
    }
    
    void findConvexHull(vector<Point> &points, vector<Point> &hull, Point &left, Point &right) {
        if (points.empty())
            return;
        
        int farthestIdx = 0;
        int maxDist = calculateDistance(left, right, points[0]);
        for (int i = 1; i < points.size(); i++) {
            double currentDist = calculateDistance(left, right, points[i]);
            if (currentDist > maxDist) {
                maxDist = currentDist;
                farthestIdx = i;
            }
        }
        hull.push_back(points[farthestIdx]);
        
        vector<Point> leftSet, rightSet;
        for (int i = 0; i < points.size(); i++) {
            if (i == farthestIdx)
                continue;

            if(!tryAddToSet(leftSet, left, points[farthestIdx], points[i]))
                tryAddToSet(rightSet, points[farthestIdx], right, points[i]);
            
        }

        findConvexHull(leftSet, hull, left, points[farthestIdx]);
        findConvexHull(rightSet, hull, points[farthestIdx], right);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& inputPoints) {
        vector<Point> points;
        for (auto &point : inputPoints) {
            points.push_back({point[0], point[1]});
        }

        // Edge case: No hull to form if the number of points is 1 or less
        if (points.size() <= 1)
            return inputPoints;

        vector<Point> hull;
        
        // Find the leftmost and rightmost points
        sort(points.begin(), points.end(), comparePoints);
        hull.push_back(points[0]);
        hull.push_back(points.back());
        
        vector<Point> leftSet, rightSet, collinearPoints;
        for (int i = 1; i < points.size() - 1; i++) {
            int crossProd = crossProduct(points[0], points.back(), points[i]);
            if (crossProd < 0)
                rightSet.push_back(points[i]);
            else if (crossProd > 0)
                leftSet.push_back(points[i]);
            else
                collinearPoints.push_back(points[i]);
        }

        // If one of the sides is empty, add collinear points to the hull
        if (leftSet.empty() || rightSet.empty())
            for (const auto &point : collinearPoints)
                hull.push_back(point);

        findConvexHull(leftSet, hull, points[0], points.back());
        findConvexHull(rightSet, hull, points.back(), points[0]);
        
        vector<vector<int>> outputPoints;
        for (const auto &point : hull) {
            outputPoints.push_back({point.x, point.y});
        }

        return outputPoints;
    }
};
