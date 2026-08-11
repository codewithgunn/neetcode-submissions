class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int length1 = s1.size();
        int length2 = s2.size();
        if (length1 > length2) return false;

        vector<int> countS1 (26,0);
        vector<int> countS2 (26,0);

        for(int i = 0 ; i < length1 ; i++){
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }

        for(int i = length1 ; i < length2 ; i++){
            if(countS1 == countS2) return true;
            countS2[s2[i-length1] - 'a']--;
            countS2[s2[i] - 'a']++;
        }
        return countS1 == countS2;
    }
};
