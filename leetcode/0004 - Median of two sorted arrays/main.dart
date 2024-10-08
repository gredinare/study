class Solution {
    double findMedianSortedArrays(List<int> nums1, List<int> nums2) { 
        List<int> sortedArray = nums1 + nums2;
        sortedArray.sort();

        var len = sortedArray.length;
        var median = 0.0;

        if (len % 2 == 0) {
            var midIndexR = (len / 2).round();
            var midIndexL = midIndexR - 1;

            median = (sortedArray[midIndexL] + sortedArray[midIndexR]) / 2;
            print(median);
        } else {
            var mid = (len / 2).truncate();
            median = sortedArray[mid].toDouble();
        }

        return median;
    }
}

void main() {
    var l1 = [1, 3];
    var l2 = [2];

    var sol = Solution();
    var result = sol.findMedianSortedArrays(l1, l2);

    print(result);
}