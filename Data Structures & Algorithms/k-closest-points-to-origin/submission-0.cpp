class Solution {
private:
    int squaredDistance (int x , int y){
        return (pow(x,2)+pow(y,2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxHeap;
        for(const auto point : points){
            int dist = squaredDistance(point[0],point[1]);
            maxHeap.push({dist,point});

            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
