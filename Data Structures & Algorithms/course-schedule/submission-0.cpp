class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;

            for (auto &x : graph[curr]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {q.push(x);}
            }
        }

        return !(count < numCourses);
    }
};
