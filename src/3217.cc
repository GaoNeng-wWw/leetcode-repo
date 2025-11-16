#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      unordered_set<int> cnt(nums.begin(),nums.end());
      ListNode* dummy = new ListNode(0, head);
      auto* tail = dummy;
      auto* cur = head;
      while (cur->next != nullptr) {
        if (
          cnt.count(cur->val)
        ) {
          tail->next = cur->next;
        } else {
          tail = cur;
        }
        cur = cur->next;
      }
      return tail;
    }
};