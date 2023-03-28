class Solution {
    fun findKthLargest(nums: IntArray, k: Int): Int {
        val priorityQueue = PriorityQueue<Int>(){ a, b ->
            b - a
        }

        nums.forEach{
            priorityQueue.add(it)
        }

        var result = -1
        repeat(k){
            result = priorityQueue.poll()
        }

        return result
    }
}