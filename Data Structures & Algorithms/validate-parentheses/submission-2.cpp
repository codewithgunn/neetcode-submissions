class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        if(s.size() % 2 == 1) return false;
        for(char b : s ){
            if(b == '(' || b == '{' || b == '['){
                bracketStack.push(b);
            }
            else if (!bracketStack.empty()){
                if(b == ')' && bracketStack.top() == '('){
                    bracketStack.pop();
                }
                else if(b == '}' && bracketStack.top() == '{'){
                    bracketStack.pop();
                }
                else if(b == ']' && bracketStack.top() == '['){
                    bracketStack.pop();
                }
                else{
                    return false;
                }
            }
            else return false;
        } 
        if(bracketStack.empty()){
            return true;
        }
        return false;
    }
};
