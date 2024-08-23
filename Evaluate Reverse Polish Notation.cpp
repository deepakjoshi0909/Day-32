#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s; 
        
        for (std::string token : tokens) {
            if (token == "*" || token == "/" || token == "+" || token == "-") {
                int temp2 = s.top();  
                s.pop();
                int temp1 = s.top(); 
                s.pop();
                
                if (token == "*") {
                    s.push(temp1 * temp2);
                } else if (token == "/") {
                    s.push(temp1 / temp2);
                } else if (token == "+") {
                    s.push(temp1 + temp2);
                } else if (token == "-") {
                    s.push(temp1 - temp2);
                }
            } else {
                s.push(std::stoi(token));  
            }
        }
        
        return s.top();  
    }
};
