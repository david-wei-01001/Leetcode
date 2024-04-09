class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
        };
        int len = s.length() / 2;
        int a_count = 0;
        int b_count = 0;
        for (int i = 0; i < len; i++){
            a_count += vowels.contains(s[i]);
            b_count += vowels.contains(s[i + len]);
        }
        return a_count == b_count;
    }
};
