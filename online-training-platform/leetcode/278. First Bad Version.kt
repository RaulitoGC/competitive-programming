/* The isBadVersion API is defined in the parent class VersionControl.
      fun isBadVersion(version: Int) : Boolean {} */

      class Solution: VersionControl() {
        override fun firstBadVersion(n: Int) : Int {
            var low = 1; var high = n
            while(low < high) {
                val mid = low + (high - low) / 2
                if(isBadVersion(mid).not()) {
                    low = mid + 1
                } else {
                    high = mid
                }
            }
    
            return low
        }
    }