class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        int total_sum = 0;
        stack<int> st;

        for(auto& ele: operations){
            if(ele == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            } else if(ele == "D"){
                int t = st.top();
                st.push(2 * t);
            } else if(ele == "C"){
                st.pop();
            } else{
                st.push(stoi(ele));
            }
        }
        while(!st.empty()){
            total_sum += st.top();
            st.pop();
        }
        return total_sum;
    }
};