class StockSpanner {
private:
    vector<pair<int, int>> prices;

public:
    StockSpanner() {}

    int next(int price) {
        int ans = 1;
        while (prices.empty() == false and prices.back().first <= price) {
            ans += prices.back().second;
            prices.pop_back();
        }
        prices.emplace_back(price, ans);
        return ans;
    }
};