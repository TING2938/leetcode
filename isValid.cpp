import header;

using namespace std;

// https://leetcode.cn/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s) {
        stack<int> stk;
        for (auto c : s)
        {
            int b = isBegin(c); 
            int e = isEnd(c);
            if (b) {
                stk.push(b);
            } else if (e) {
                if (stk.empty())
                    return false;
                if (stk.top() != e) 
                    return false;
                stk.pop();
            }
        }
        if (stk.empty())
            return true;
        else
            return false;

    }

private:
    int isBegin(char c) {
        switch (c) {
            case '(':
                return 1;
            case '[':
                return 2;
            case '{':
                return 3;
            default: 
                return 0;
        }
    }

    int isEnd(char c)
    {
        switch (c) {
            case ')':
                return 1;
            case ']':
                return 2;
            case '}':
                return 3;
            default:
                return 0;
        }
    }
};

int main()
{
    Solution s;
    EXPECT_TRUE(s.isValid("[]{}"));
}