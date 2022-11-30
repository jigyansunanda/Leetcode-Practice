class Logger {
public:
    unordered_map<string, int> mp;
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.count(message) == 0) {
            mp[message] = timestamp;
            return true;
        } else {
            if (timestamp >= 10 + mp[message]) {
                mp[message] = timestamp;
                return true;
            } else {
                return false;
            }
        }
    }
};