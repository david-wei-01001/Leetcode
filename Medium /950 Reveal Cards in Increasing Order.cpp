class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), less<int>());
        vector<int> to_return(deck.size(), 0);
        vector<int> indecies(deck.size(), 0);
        for (int i = 0; i< deck.size(); i++)
        {
            indecies[i] = i;
        }
        int count = 0;
        int ind;
        while (indecies.size() > 1)
        {
            ind  = indecies[0];
            indecies.erase(indecies.begin());
            to_return[ind] = deck[count];
            ind  = indecies[0];
            indecies.erase(indecies.begin());
            indecies.push_back(ind);
            count++;
        }
        ind  = indecies[0];
        to_return[ind] = deck[count];
        return to_return;
    }
};
