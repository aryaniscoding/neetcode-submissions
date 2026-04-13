class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int second_top = 0;
        int top = 0;
        
        for(auto &i : operations){
            if(i == "C"){
                st.pop();
            }
            else if(i == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                int add = top1+top2;
                st.push(top1);
                st.push(add);
            }
            else if(i == "D"){
                st.push(2*st.top());
            }
            else{
                // st.push(i - "0");
                st.push(stoi(i));
            }
        }
        int ans = 0;
        while(!st.empty()){
            // int topp = st.top();
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};