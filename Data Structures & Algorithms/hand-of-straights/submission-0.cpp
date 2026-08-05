class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if ( n % groupSize != 0 ) return false ;
        unordered_map<int,int> freqMap;
        for(int i = 0 ; i < n ; i++){
            freqMap[hand[i]]++;
        }
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(auto& [card,freq] : freqMap){
            minHeap.push(card);
        }
        while(!minHeap.empty()){
            int smallestElement = minHeap.top();
            int frequency = freqMap[smallestElement];

            if(frequency == 0){
                minHeap.pop();
                continue;
            }
            for(int i = 0 ; i < groupSize ; i++){
                int currentElement = smallestElement + i;
                if(freqMap[currentElement] < frequency){
                    return false;
                }
                else{
                    freqMap[currentElement] -= frequency;
                }
            }
        }
        return true;

    }
};
