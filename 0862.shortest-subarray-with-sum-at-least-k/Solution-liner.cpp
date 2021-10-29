class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        unsigned ans = -1;
        deque<pair<long long, size_t>> sumstack; // <position, sum(0...pos-1)>
        sumstack.push_back(make_pair(0ul, 0ll));
        long long sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sumstack.size() && sumstack.front().first + k <= sum)
            {
                // printf("i = %lu, sum - k = %lld, it = (%lld, %lu)\n", i, sum - k, sumstack.front().first, sumstack.front().second);
                ans = min(ans, (unsigned)(i + 1 - sumstack.front().second));
                sumstack.pop_front();
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
