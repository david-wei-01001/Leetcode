class Solution {
public:
    string removeKdigits(string num, int k) {
        // Admire the unbelievable use of string!!!!!!

        // use stack instead of string to avoid TLE error
        string s = "";
        for (char chr : num)
        {
            // must use while not if to remove all digits that is greater in order to behave correctly, eg. 1333333331, all the 3 must be removed before adding 1.
            while (s.size() && s.back() > chr && k)
            {
                s.pop_back();
                k--;
            }
            // must use s.push_back() instead of s += chr to avoid TLE error
            if (s.size() || chr != '0') s.push_back(chr);
        }
        while (s.size() && k--)
        {
            // Note in our previous while loop, It is already true that the char are ordered from smallest to the biggest, so the last several digits are guaranteed to be the biggest. Thus there is no need to find the max.
            s.pop_back();
        }
        return s.size() == 0 ? "0": s;
    }
};
