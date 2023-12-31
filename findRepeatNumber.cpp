import header;

using namespace std;

// url: https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/?favorite=xb9nqhhg

class Solution
{
public:
    int findRepeatNumber(vector<int>& nums)
    {
        set<int> unique;
        for (auto&& v : nums) {
            if (unique.count(v)) {
                return v;
            } else {
                unique.insert(v);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    nums = {2, 3, 1, 0, 2, 5, 3};
    EXPECT_EQ(s.findRepeatNumber(nums), 2);
}
