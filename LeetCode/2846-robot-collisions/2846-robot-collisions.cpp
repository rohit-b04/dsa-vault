class Solution {
public:

    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<Robot> robotObjects;

        for(int i=0; i< n; i++)
        {
            robotObjects.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robotObjects.begin(), robotObjects.end(), [](const Robot& a, const Robot& b){
            return a.position < b.position;
        });

        vector<Robot> eval;
        for(auto& robot : robotObjects) {
            if (robot.direction == 'R') {
                eval.push_back(robot);
                continue;
            }

            bool removeBot = false;
 
            while (!eval.empty() && eval.back().health <= robot.health && eval.back().direction == 'R'){
                if(eval.back().health == robot.health){
                    eval.pop_back();
                    removeBot=true;
                    break;
                }
                robot.health--;
                eval.pop_back();
            }
            
             
            if (!removeBot && !eval.empty() && eval.back().direction == 'R' && eval.back().health > robot.   health){
                eval.back().health--;
                removeBot= true;
            }

            if(!removeBot) {
                eval.push_back(robot);
            }
        }

        sort(eval.begin(), eval.end(), [](const Robot& a, const Robot& b){
            return a.index < b.index;
        });

        vector<int> res;
        for(const auto& robot : eval){ res.push_back(robot.health);}
        
        return res;

            }
        
};