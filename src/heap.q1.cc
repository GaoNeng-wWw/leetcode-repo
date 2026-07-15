#include <cstddef>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

class MaxHeap {
  private:
    vector<int> d = vector<int>();
    int parent(int i) {
      return (i-1)/2;
    };
    int left(int i) {
      return 2*i+1;
    }
    int right(int i) {
      return 2*i+2;
    }
    void sink(int i){
      int n = this->d.size();
      while (left(i) < n) {
        int j = left(i);
        if (right(i) < n && d[right(i)] > d[j]) {
          j = right(i);
        }
        if (d[i] >= d[j]) {
          break;
        }
        swap(d[i],d[j]);
        i=j;
      }
    }
    void swim(int i){
      while (
        i > 0 && this->d[parent(i)] < this->d[i]
      ) {
        swap(d[parent(i)], d[i]);
        i = parent(i);
      }
    }
  public:
    MaxHeap() {};
    MaxHeap(const vector<int>& data) {
      this->build(data);
    }
    int top(){
      return this->d[0];
    }
    void push(int val) {
      this->d.push_back(val);
      this->swim(this->d.size()-1);
    }
    int pop(){
      int val = d[0];
      d[0] = d.back();
      d.pop_back();
      if (!d.empty()) {
        sink(0);
      }
      return val;
    }
    void build(
      const vector<int>& arr
    ){
      this->d = arr;
      int n = this->size();
      for (int i = n / 2 - 1; i >= 0; --i) {
        sink(i);
      }
    }
    std::size_t size(){
      return this->d.size();
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      MaxHeap mxHeap(stones);
      while (mxHeap.size()){
        if (mxHeap.size() == 1) {
          return mxHeap.top();
        }
        int x = mxHeap.top();
        mxHeap.pop();
        int y = mxHeap.top();
        mxHeap.pop();
        if (x == y) {
          continue;
        }
        mxHeap.push(abs(y-x));
      }
      return 0;
    }
};