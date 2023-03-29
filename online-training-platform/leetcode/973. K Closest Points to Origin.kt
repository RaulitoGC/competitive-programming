

class Solution {

    data class Point(
        val x: Int,
        val y: Int,
        val distance: Int = (x * x) + (y * y)
    )

    fun kClosest(points: Array<IntArray>, k: Int): Array<IntArray> {
        val pq = PriorityQueue<Point>(){ p1, p2 ->
            p1.distance - p2.distance
        }

        points.forEach{ p ->
            pq.add(Point(p[0], p[1]))
        }

        val result = Array<IntArray>(k){
            intArrayOf(-1,-1)
        }

        repeat(k){ idx ->
            val point = pq.poll()
            result[idx] = intArrayOf(point.x, point.y)
        }

        return result
    }
}