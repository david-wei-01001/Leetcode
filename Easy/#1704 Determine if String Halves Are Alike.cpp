class Solution {
public:
    int isVowel(const char chr){
        char vowellst[] = "aeiouAEIOU";
        for (int i = 0; i < strlen(vowellst); i++){
            if (chr == vowellst[i]){
                return 1;
            }
        }
        return 0;
    }
    bool halvesAreAlike(string s) {
        int len = s.length() / 2;
        int a_count = 0;
        int b_count = 0;
        for (int i = 0; i < len; i++){
            a_count += isVowel(s[i]);
            b_count += isVowel(s[i + len]);
        }
        return a_count == b_count;
    }
};