class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // trustScore tracks: (in-degree - out-degree) for each person 1 to n
        vector<int> trustScore(n + 1, 0);

        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];

            trustScore[a]--; // a trusts someone, so a cannot be judge
            trustScore[b]++; // b receives trust
        }

        // Search for person with net score equal to n - 1
        for (int i = 1; i <= n; i++) {
            if (trustScore[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};