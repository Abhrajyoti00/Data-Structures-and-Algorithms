class Solution {
public:

    bool isBipartiteUtil(int sv, vector<vector<int>>& graph, int vertices, vector<int>& color){
        vector<bool> visited(vertices, false); 
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        color[sv] = 0;
        while(!q.empty()){
            int sv = q.front();
            q.pop();
            for(int i = 0; i < graph[sv].size(); i++){ 
                if(graph[sv][i] == 1 && !visited[i] && color[i] == -1){
                    q.push(i);
                    color[i] = 1 - color[sv];
                    visited[i] = true;
                }
                else if(graph[sv][i] == 1 && color[sv] == color[i])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int noOfvertices = graph.size();
        vector<int> color(noOfvertices, -1);
        for(int i=0; i<graph.size(); i++){
            if(color[i]==-1)
                {
                    if(!isBipartiteUtil(i, graph, noOfvertices, color))
                        return false;
                }
        }
        return true;
    }
};
