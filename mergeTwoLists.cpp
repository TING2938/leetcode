//import header;

//using namespace std;

// https://leetcode.cn/problems/merge-two-sorted-lists/


// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1->val < list2->val) {
            list1->next = mergeTwoLists2(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists2(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* ret = new ListNode();
        ListNode* ret_header = ret;

        while (p1 && p2) {
            int v1 = p1->val;
            int v2 = p2->val;
            if (v1 < v2) {
                ret->next = p1;
                p1        = p1->next;
                ret       = ret->next;
            } else {
                ret->next = p2;
                p2        = p2->next;
                ret       = ret->next;
            }
        }
        ret->next = p1 ? p1 : p2;
        return ret_header->next;
    }
};


int main()
{
    Solution s;
    // EXPECT_TRUE(s.isValid("[]{}"));
}