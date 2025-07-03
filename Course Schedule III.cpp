class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Sort courses by deadline
        sort(courses.begin(), courses.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;
        int time = 0;

        for (auto& course : courses) {
            int dur = course[0];
            int last = course[1];
            time += dur;
            maxHeap.push(dur);

            // If total time exceeds the current deadline, drop the longest duration course
            if (time > last) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();  // Number of courses taken
    }
};
