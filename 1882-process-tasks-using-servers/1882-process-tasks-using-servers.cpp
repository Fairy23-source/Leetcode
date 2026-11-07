
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> available;

        priority_queue<pair<long long, pair<int, int>>,
            vector<pair<long long, pair<int, int>>>,
            greater<pair<long long, pair<int, int>>>> busy;

        int n = servers.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while (!busy.empty() && busy.top().first <= time) {
                auto p = busy.top();
                busy.pop();
                available.push(p.second);
            }

            if (available.empty()) {
                time = busy.top().first;

                while (!busy.empty() && busy.top().first <= time) {
                    auto p = busy.top();
                    busy.pop();
                    available.push(p.second);
                }
            }

            auto [weight, id] = available.top();
            available.pop();

            ans.push_back(id);

            busy.push({time + tasks[i], {weight, id}});
        }

        return ans;
    }
};
