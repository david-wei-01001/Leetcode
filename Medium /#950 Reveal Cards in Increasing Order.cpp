class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), less<int>());
        int size = deck.size();
        vector<int> to_return(size);
        deque<int> indecies;
        for (int i = 0; i < size; i++)
        {
            indecies.push_back(i);
        }
        int count = 0;
        int ind;
        while (indecies.size() > 1)
        {
            ind = indecies.front();
            indecies.pop_front();
            to_return[ind] = deck[count];
            indecies.push_back(indecies.front());
            indecies.pop_front();
            count++;
        }
        to_return[indecies.front()] = deck[count];
        return to_return;
    }
};
