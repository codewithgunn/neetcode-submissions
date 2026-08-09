class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        
        vector<pair<int, int>> track(n);
        for (int i = 0; i < n; i++) {
            track[i] = {position[i], speed[i]};
        }
        
        // 1. Sort ascending by starting position
        sort(track.begin(), track.end());
        
        int count = 0;
        double max_time = 0.0;
        
        // 2. Iterate backward (closest to target down to farthest)
        for (int i = n - 1; i >= 0; i--) {
            double current_time = (double)(target - track[i].first) / track[i].second;
            
            // Only increment fleet count if this car takes STRICTLY LONGER
            // than the slowest fleet leader ahead of it.
            if (current_time > max_time) {
                count++;
                max_time = current_time; // Update current bottleneck time
            }
        }
        
        return count;
    }
};