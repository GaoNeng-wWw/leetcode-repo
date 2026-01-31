#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      char ans = letters[0];
      for (auto l : letters){
        if (l > target) {
            return l;
        }
      }
      return ans;
    }
};