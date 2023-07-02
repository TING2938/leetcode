import header;

// #include <vector>
// #include <algorithm>

using namespace std;

// https://leetcode.cn/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target)
    {
        sort(nums.begin(), nums.end());
        int k1 = 0;
        int k2 = nums.size() - 1;

        vector<vector<int>> ret;
        for (; k1 < k2 - 2; increace(nums, k1, k2)) {
            auto ts = threeSum(nums, k1 + 1, k2, target - nums[k1]);
            if (not ts.empty()) {
                for (auto&& n : ts) {
                    n.push_back(nums[k1]);
                    ret.push_back(std::move(n));
                }
            }
        }
        return ret;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int k1, int k2, long long target) {
        vector<vector<int>> ret;
        for (; k1 < k2 - 1; increace(nums, k1, k2)) {
            auto ts = twoSum(nums, k1 + 1, k2, target - nums[k1]);
            if (not ts.empty()) {
                for (auto&& n : ts) {
                    n.push_back(nums[k1]);
                    ret.push_back(std::move(n));
                }
            }
        }
        return ret;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int k1, int k2, long long target) {
        vector<vector<int>> ret;
        while (k1 < k2)  {
            long long s = nums[k1] + nums[k2];
            if (s == target) {
                ret.push_back({nums[k1], nums[k2]});
                increace(nums, k1, k2);
                decreace(nums, k2, k1);
            } else if (s > target) {
                decreace(nums, k2, k1);
            } else {
                increace(nums, k1, k2);
            }
        }
        return ret;
    }

    void increace(vector<int>& nums, int& k, int k_end) {
        int init = nums[k];
        for (k = k+1 ; k < k_end; k++)
        {
            if (nums[k] != init) {
                return;
            }
        }
        k = k_end;
        return;
    }

    void decreace(vector<int>& nums, int& k, int k_end)
    {
        int init = nums[k];
        for (k = k - 1; k > k_end; k--) {
            if (nums[k] != init) {
                return;
            }
        }
        k = k_end;
        return;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
    EXPECT_EQ(s.fourSum(nums, -294967296), vector<vector<int>>{});
}