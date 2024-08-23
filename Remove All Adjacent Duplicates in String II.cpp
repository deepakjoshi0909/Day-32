class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>st;

        for(char ch : s){
            if(!st.empty() && st.back().first == ch){
                st.back().second++;
            } else{
                st.push_back({ch,1});
            }

            if(st.back().second == k){
                st.pop_back();
            }
        }

        string ans = "";
        for (auto& p : st) {
            ans.append(p.second, p.first); 
        }
        
        return ans;
    }
};
