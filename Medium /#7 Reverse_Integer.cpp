class Solution {
public:
    bool check_size(int x, int y){
        const int low_bound = 1 << 31;
        const int high_bound = ~(low_bound);
        if (y == -1){
            return x <= high_bound / 10. && x >= low_bound / 10.;
        }
        else {
            return x <= high_bound - y;
        }
    }
    int reverse_positive(int x){
        
        int toReturn = 0;
        int digit = x % 10;
        int temp = x / 10;
        try {
          while (temp != 0){
            if (!check_size(toReturn, -1)){
                return 0;
            }
            toReturn *= 10;
            if (!check_size(toReturn, digit)){
                return 0;
            }
            toReturn += digit;
            digit = temp % 10;
            temp /= 10;
          }
        if (!check_size(toReturn, -1)){
            return 0;
        }
          return toReturn * 10 + digit;
        }
        catch (const runtime_error& error) {
          return 0;
        }
        
    }
    int reverse(int x) {
        if (x < 0){
            if (x == 1 << 31){
                return 0;
            }
            return -reverse_positive(-x);
        }
        else{
            return reverse_positive(x);
        }
        
    }
};
