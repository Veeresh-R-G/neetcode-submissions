class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int finish = 0;
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto prereq: prerequisites){
            indegree[prereq[0]]++;
            adj[prereq[1]].push_back(prereq[0]);
        }

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            finish++;

            //decrease the indegree of the outgoing node
            for(auto &child: adj[top]){
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }

        return finish == numCourses;
    }
};
