class Solution {
public:
    // Time O(n)
    // Space O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int idxToInsert = nums1.size() - 1;
        int i = m-1, j = n - 1;
        
        cout << idxToInsert << endl;
        while(idxToInsert >= 0){
            
            int nums2Value = (j > -1) ? nums2[j] : INT_MIN;
            int nums1Value = (i > -1) ? nums1[i] : INT_MIN;
            cout << nums2Value << " - " << nums1Value << endl;
            if(nums2Value > nums1Value){
                nums1[idxToInsert] = nums2Value;
                j--;
            }else{
                nums1[idxToInsert] = nums1Value;
                i--;
            }
            idxToInsert--;
        }
        
    }
};
