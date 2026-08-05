#include <iostream>
#include<stack>
using namespace std;
bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
    {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
		else {
            if (st.empty()) return false;   
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) 
                return false;                
        }
    }
   }
    return st.empty();  
};
int main() 
{
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;
    cout << "Is valid: " << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
