class Solution {
	public:
	int pre(char a) {
		
		if (a == '^')
			return 3;
		if (a == '*' || a == '/')
			return 2;
		if (a == '+' || a == '-')
			return 1;
		
		return 0;
		
	}
	string infixToPostfix(string& s) {
		// code here
		stack<char>st;
		string temp;
		for (char c : s) {
			if (isalnum(c)) {
				temp += c;
			}
			else if (c == '(') {
				st.push(c);
			}
			else if (c == ')') {
				while (!st.empty() && st.top() != '(') {
					temp += st.top();
					st.pop();
				}
				
				if (!st.empty()) {
					st.pop();
				}
				
			}
			else {
				while (!st.empty() &&
				st.top() != '(' &&
				(pre(st.top()) > pre(c) ||
				(pre(st.top()) == pre(c) && c != '^'))) {
					
					temp += st.top();
					st.pop();
				}
				st.push(c);
				
			}
			
		}
		while (!st.empty()) {
			temp += (st.top());
			st.pop();
		}
		return temp;
	}
};
