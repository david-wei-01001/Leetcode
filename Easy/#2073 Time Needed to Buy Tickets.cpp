class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int len = tickets.size();
        int amount = tickets[k];
        int i = 0;
        int acc = 0;
        while (true)
        {
            if (tickets[i] != 0)
            {
                acc++;
                tickets[i]--;
                if (i == k && tickets[k] == 0)
                {
                    return acc;
                }
            }
            i++;
            if (i == len)
            {
                i = 0;
            }
        }
    }
};
