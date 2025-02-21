class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> stack;
        for(auto& c : tokens) {
            if(c == "+" || c == "-" || c == "*" || c == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                if(c == "+") stack.push(b + a);
                else if(c == "-") stack.push(b - a);
                else if(c == "*") stack.push(b * a);
                else stack.push(b / a);
            }
            else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};