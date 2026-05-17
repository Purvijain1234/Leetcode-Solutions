class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            string prefix = strs[0];

            // compare
            for(int i=0; i<strs.size(); i++){

                // reduce prefix until match
                while(strs[i].find(prefix) != 0){
                    prefix = prefix.substr(0, prefix.length() - 1);

                    // if prefix empty
                    if(prefix.empty()){
                        return "";
                    }
                }
            }
            return prefix;
    }
};
