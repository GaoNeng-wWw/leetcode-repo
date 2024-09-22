#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, const vector<vector<int>>& trust) {
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        for (int i=0;i<trust.size();i++) {
            int from = trust[i][0];
            int to = trust[i][1];
            in[to] +=1;
            out[from] +=1;
        }
        for (int i=1;i<=n;i++) {
            if ( in[i] == n-1 && out[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> vec = {{1,2}};
    std::cout << s.findJudge(2, vec) << std::endl;
    return 0;
}