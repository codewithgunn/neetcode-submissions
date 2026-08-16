class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> billcount (2,0);
        for(int i = 0 ; i < bills.size() ; i++){
            if(bills[i] == 5){
                billcount[0]++;
            }
            else if(bills[i] == 10){
                billcount[1]++;
                if(billcount[0] == 0){
                    return false;
                }
                billcount[0]--;
            }
            else if(bills[i] == 20){
                if(billcount[1] == 0 && billcount[0] < 3){
                    return false;
                }
                else if(billcount[1] > 0 && billcount[0] == 0){
                    return false;
                }
                else if(billcount[1] > 0){
                    billcount[1]--;
                    billcount[0]--;
                }
                else{
                    billcount[0] -= 3;
                }

            }
        }
        return true;
    }
};