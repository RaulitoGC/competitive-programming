class Solution {
public:
    
    void moveVertex( int vertex, unordered_set<int>& source, unordered_set<int>& dest){
        source.erase(vertex);
        dest.insert(vertex);
    }
    
    bool dfs(int vertex, unordered_map<int, vector<int>>& um, unordered_set<int>& white, unordered_set<int>& gray, unordered_set<int>& black){
        moveVertex(vertex, white, gray);
        for(int i = 0; i < um[vertex].size() ; i++){
            if(black.count(um[vertex][i]) > 0){
                continue;
            }
            
            if (gray.count(um[vertex][i]) > 0) {
                return true;
            }
            if(dfs(um[vertex][i], um, white, gray, black)) {
                return true;
            }
        }
        moveVertex(vertex, gray, black);
        return false;
    }
    
    
    bool hasCycle(unordered_map<int,vector<int>>& um){
        unordered_set<int> white, gray, black;
        unordered_map<int,vector<int>>::iterator it;
        for(it = um.begin() ; it != um.end() ; it++){
            white.insert(it->first);
        }
        
        unordered_set<int>::iterator it1;
        
        while(!white.empty()){
            it1 = white.begin();
            int vertex = *it1;
            if(dfs(vertex, um, white, gray, black)){
                return true;
            }
        }
        
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> um;
        
        for(int i = 0 ; i < prerequisites.size() ; i++){
            um[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        return !hasCycle(um);
    }
};
