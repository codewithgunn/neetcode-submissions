class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> frequency (26,0);
        for( char task : tasks){
            frequency[task - 'A']++;
        }
        
        int maxFreq = 0;
        for(int freq : frequency){
            maxFreq = max(freq , maxFreq);
        }

        int maxCount = 0;
        for(int freq : frequency){
            if(freq == maxFreq){
                maxCount++;
            }
        }

        int interval = (maxFreq - 1)*(n+1)+maxCount;
        int leastInt = max(m,interval);
        return leastInt;
    }
};
