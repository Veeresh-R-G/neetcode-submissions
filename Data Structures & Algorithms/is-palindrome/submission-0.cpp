class Solution {
public:
    bool isPalindrome(string s) {
        
        string newStr = "";
        for(char c: s){
            if(isalnum(c)){
                newStr += tolower(c);
            }
        }
        
        int l = 0;
        int r = newStr.size() - 1;

        while(l < r){
            if(newStr[l++] != newStr[r--]){
                return false;
            }
        }

        return true;
    }
};
