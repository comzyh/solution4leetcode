class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        unsigned ans = -1;
        vector<pair<long long, size_t>> sumstack; // <position, sum(0...pos-1)>
        sumstack.push_back(make_pair(0ul, 0ll));
        long long sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            auto it = lower_bound(sumstack.rbegin(), sumstack.rend(), make_pair(sum - k, nums.size()), greater<pair<long long, size_t>>());
            // auto it = lower_bound(sumstack.rbegin(), sumstack.rend(), make_pair(sum - k, 0ul), [](const pair<long long, size_t> &v, const pair<long long, size_t> &t) -> bool
            //                       { return v.first > t.first; });
            if (it != sumstack.rend())
            {
                // printf("i = %lu, sum - k = %lld, it = (%lld, %lu)\n", i, sum - k, it->first, it->second);
                ans = min(ans, (unsigned)(i + 1 - it->second));
            }
            // insert this sum
            while (sumstack.size() && sumstack.rbegin()->first >= sum)
            {
                sumstack.pop_back();
            }
            sumstack.push_back(make_pair(sum, i + 1));
        }
        return ans;
    }
};
