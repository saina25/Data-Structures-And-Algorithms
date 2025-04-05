//geeksforgeeks problem "Rat in a Maze Problem - I"

class Solution{
    
    private:
    
        bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>> &m){
            
            if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0){
                return true;
            }
            else{
                return false;
            }
        }
        
        void solve(vector<vector<int>> &m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path){
            
            //you have reached x,y here
            
            //base case
            if(x==n-1 && y==n-1){
                ans.push_back(path);
                return ;
            }
            
            visited[x][y]=1;
            
            //4 choices - D, L, R, U
            
            //down
            int newx = x+1;
            int newy = y;
            if(isSafe(newx, newy, n, visited, m)){
                path.push_back('D');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();
            }
            
            //Left
            newx = x;
            newy = y-1;
            if(isSafe(newx, newy, n, visited, m)){
                path.push_back('L');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();
            }
            
            //Right
            newx = x;
            newy = y+1;
            if(isSafe(newx, newy, n, visited, m)){
                path.push_back('R');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();
            }
            
           //Up
            newx = x-1;
            newy = y;
            if(isSafe(newx, newy, n, visited, m)){
                path.push_back('U');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();
            }
            
            
            visited[x][y]=0; //backtracking
        }
        
    public:
    
        vector<string> findPath(vector<vector<int>> &m) {
            
            // 0---> not allowed
            // 1--->allowed
            
            vector<string> ans;
            
            //not allowed at starting coordinate
            if(m[0][0]==0){
                return ans;
            }
            
            //starting coordinate
            int srcx =0;
            int srcy =0;
            
            int n = m[0].size();
            
            vector<vector<int>> visited = m;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    visited[i][j]=0;
                }
            }
    
            
            string path="";
            solve(m, n, ans, srcx, srcy, visited, path);
            sort(ans.begin(),ans.end());
            return ans;
            
        }
};
