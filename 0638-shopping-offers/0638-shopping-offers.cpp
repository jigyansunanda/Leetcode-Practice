class Solution {
private:
    bool canOfferBeUsed(vector<int> &A, vector<int>& B) {
        for (int i = 0; i < (int) B.size(); ++i) {
            if (A[i] > B[i]) return false;
        }
        return true;
    }

    int generate_key(vector<int> &A) {
        int key = 0;
        int power = 1;
        for (int i = (int)A.size() - 1; i >= 0; --i) {
            key += (A[i] * power);
            power *= 11;
        }
        return key;
    }

public:
    int n;
    vector<int> price;
    unordered_map<int, int> dp;

    int shoppingOffers(vector<int>& _price, vector<vector<int>>& special, vector<int>& needs) {
        this->price = _price;
        this->n = price.size();
        return solve(special, needs);
    }

    int solve(vector<vector<int>>& special, vector<int>& needs) {
        if (accumulate(needs.begin(), needs.end(), 0) == 0) return 0;
        int key = generate_key(needs);
        if (dp.find(key) != dp.end()) return dp[key];
        int costWithoutOffers = 0;
        for (int i = 0; i < n; ++i) costWithoutOffers += (price[i] * needs[i]);
        int lowestPrice = costWithoutOffers;
        for (auto &offer : special) {
            if (canOfferBeUsed(offer, needs)) {
                int costWithOffer = offer.back();
                for (int i = 0; i < n; ++i) needs[i] -= offer[i];
                costWithOffer += solve(special, needs);
                lowestPrice = min(lowestPrice, costWithOffer);
                for (int i = 0; i < n; ++i) needs[i] += offer[i];
            }
        }
        return dp[key] = lowestPrice;
    }
};