#include <bits/stdc++.h>


bool isCharOpeningBracket(char &c){
    return c == '[' || c == '{' || c == '('; 
}

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(auto &c: s){
            if(isCharOpeningBracket(c)){
                st.push(c);
            } else{
                if(st.empty()){
                    return false;
                }

                
                char top = st.top();
                st.pop();

                cout << c << " " << top << endl;

                if(c == ')' && top != '('){
                    return false;
                }
                else if(c == '}' && top != '{'){
                    return false;
                }
                else if(c == ']' && top != '['){
                    return false;
                }
            }
        }

        return st.empty();
    }
};
