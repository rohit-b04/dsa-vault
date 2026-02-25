class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<int> setBits;
        for(int i = 0;i <= 255;i++) {
            int num = i ,count = 0;
            while(num > 0) {
                if((num & 1) == 1) {
                    count++;
                }
                num = num >> 1;
            }
            setBits.push_back(count);
        }
        // cout << setBits[255] << endl;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int countSetBits, curnum;
        
        for(int i = 0;i < arr.size();i++) {
            countSetBits = 0;
            curnum = arr[i];
            for(int j = 0;j < 4;j++) {
                
                
                // curnum = (curnum & 255);
        
                // cout << curnum << endl;
        
                countSetBits += setBits[curnum & 255];
                curnum = (curnum >> 8);
            }
            // cout << countSetBits << " " << arr[i] << endl;
            pq.push({countSetBits, arr[i]});
        
            cout << pq.top().first << " " << pq.top().second << endl;
        }
        vector<int> ans;
        while(!pq.empty()) {
            int n = pq.top().second;
            pq.pop();
            ans.push_back(n);
        }
        return ans;
    }
};