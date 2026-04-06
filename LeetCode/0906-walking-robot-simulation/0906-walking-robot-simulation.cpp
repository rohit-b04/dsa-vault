class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for(auto& o : obstacles)
            obs.insert({o[0], o[1]});

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        long long x = 0, y = 0, ans = 0;
        int dir = 0; // 0=N, 1=E, 2=S, 3=W
        
        for(int cmd : commands) {
            if(cmd == -1) dir = (dir + 1) % 4;
            else if(cmd == -2) dir = (dir + 3) % 4;
            else {
                for(int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(obs.count({nx, ny})) break; // hit obstacle, stop
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};