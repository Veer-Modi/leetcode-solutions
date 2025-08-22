class Solution {
public:
    int gcdAll(vector<int>& counts) {
        int g = counts[0];
        for (int c : counts) {
            g = gcd(g, c);
        }
        return g;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2)
            return false;

        unordered_map<int, int> freq;
        for (int num : deck) {
            freq[num]++;
        }

        vector<int> counts;
        for (auto& p : freq) {
            counts.push_back(p.second);
        }

        int g = gcdAll(counts);
        return g >= 2;
    }
};