class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        
        val merged = mutableListOf<Int>()
        val n = nums1.size; val m = nums2.size
        var idx1 = 0; var idx2 = 0
        while(idx1 < n && idx2 < m){
            if(nums1[idx1] < nums2[idx2]){
                merged.add(nums1[idx1])
                idx1 += 1
            } else {
                merged.add(nums2[idx2])
                idx2 += 1
            }
        }

        while(idx1 < n){
            merged.add(nums1[idx1])
            idx1 += 1
        }

        while(idx2 < m){
            merged.add(nums2[idx2])
            idx2 += 1
        }

        val idx = (merged.size / 2)
        return if(merged.size % 2 == 0) {
            (merged[idx].toDouble() + merged[idx - 1].toDouble()) / 2.0
        } else {
            merged[idx].toDouble()
        }
    }
}