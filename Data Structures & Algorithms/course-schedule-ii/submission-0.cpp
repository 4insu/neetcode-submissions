class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto &course : prerequisites) {graph[course[1]].push_back(course[0]);}

        vector<int> inDeg(numCourses);

        for (auto &x : graph) {
            for (auto &y : x) {inDeg[y]++;}
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {q.push(i);}
        }

        int count = 0;
        vector<int> courseOrder;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            courseOrder.push_back(curr);
            count++;

            for (auto &x : graph[curr]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {q.push(x);}
            }
        }

        if (count < numCourses) return {};
        return courseOrder;
    }
};

