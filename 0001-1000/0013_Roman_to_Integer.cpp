/*
Problem Number: 0013
Problem Name: Roman to Integer

Difficulty: Easy

Topics:
Hash Table, String, Math

Approach:
Traverse the string and compare current Roman value
with next Roman value.

If current value is smaller than next value:
subtract it.

Otherwise:
add it.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500},      
            {'M', 1000},       
        };

        int result = 0;
        for(int i=0; i<s.length(); i++){
            if(i+1 < s.length() && value[s[i]] < value[s[i+1]]){
                result -= value[s[i]];
            }
            else{
                result += value[s[i]];
            }
        }
        return result;
    }
};
