#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
  public:
    unordered_map<string, Trie*> children{};
    Trie():ref(-1) {};
    int ref;
};

class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    auto split = [](const string& s) -> vector<string> {
        vector<string> ret;
        string cur;
        for (char ch: s) {
            if (ch == '/') {
                ret.push_back(std::move(cur));
                cur.clear();
            }
            else {
                cur.push_back(ch);
            }
        }
        ret.push_back(std::move(cur));
        return ret;
    };
    vector<string> ret;
    Trie* root = new Trie();
    for (int i=0;i<folder.size();i++) {
      string path = folder[i];
      vector<string> p = split(path);
      Trie* cur = root;
      for (const string& name : p) {
        if (!cur->children.count(name)) {
          cur->children[name] = new Trie();
        }
        cur = cur->children[name];
      }
      cur->ref =i;
    }
    function<void (Trie*)> dfs = [&](Trie* trie) {
      if (trie->ref != -1){
        ret.push_back(folder[trie->ref]);
        return;
      }
      for (auto&& [_, child]: trie->children) {
        dfs(child);
      }
    };
    dfs(root);
    return ret;
  }
};