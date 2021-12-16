class Solution {
public:
    
    void reverse(vector<int>& v, int start, int end) {
        while(start < end) {
            swap(v[start], v[end]);
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int steps = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, steps - 1);
        reverse(nums, steps, n - 1);
    }
};