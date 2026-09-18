class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int i = 0;
        while (i < tokens.size()) {
            if (tokens[i] == "+") {
                int operand2 = stoi(st.top()); st.pop();
                int operand1 = stoi(st.top()); st.pop();
                st.push(to_string(operand1 + operand2));
            } else 
            if (tokens[i] == "-") {
                int operand2 = stoi(st.top()); st.pop();
                int operand1 = stoi(st.top()); st.pop();
                st.push(to_string(operand1 - operand2));
            } else
            if (tokens[i] == "*") {
                int operand2 = stoi(st.top()); st.pop();
                int operand1 = stoi(st.top()); st.pop();
                st.push(to_string(operand1 * operand2));
            } else
            if (tokens[i] == "/") {
                int operand2 = stoi(st.top()); st.pop();
                int operand1 = stoi(st.top()); st.pop();
                st.push(to_string(operand1 / operand2));
            } else {
                st.push(tokens[i]);
            }
            i++;
        }
        return stoi(st.top());
    }
};
