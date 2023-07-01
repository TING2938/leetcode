import header;

using namespace std;

// url:

class Solution
{
public:
    string replaceSpace(string s)
    {
        string ret;
        for (auto&& c : s) {
            if (c == ' ') {
                ret += "%20";
            } else {
                ret += c;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> v1, v2;
    EXPECT_EQ(s.replaceSpace("hello, world"), "hello,%20world");
}
