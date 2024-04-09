class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        if (size_1 > size_2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        else if (size_1 == 0)
        {
            return size_2 % 2 == 0? (nums2[(size_2 - 1)/ 2] + nums2[(size_2 - 1)/ 2 + 1]) / 2.0: nums2[(size_2 - 1) / 2];
        }
        
        // Idea: only consider partitions in nums1, and since what's needed in merged left is a half, then the partition for nums2 is auto-generated.
        // Thus, converge the partition of nums1, ie l and r to the same value and done the search
        // since number of elements in the left partition of nums1 is at least 0, so l = 0, since it is at most size_1, so r = size_1
        // let l ~ r be the interval of concern, l be the index of the first included element, r be the index of the first excluded element
        int l = 0;
        int r = size_1;
        // Total number of elements in left of merged array
        int total_left = (size_1 + size_2 + 1) / 2;
        
        // what's at and below/above l and r are on the greater and lesser side
        // while the interval is not empty
        int max_left1, min_right1, max_left2, min_right2;
        while (l <= r)
        {
            // partition of nums1, this denote the number of elements in the left partition of nums1, possibly including the median.
            int p1 = (l + r) / 2;
            // nothing in the left partition of nums1
            if (p1 == 0)
            {
                max_left1 = INT_MIN;
            }
            else
            {
                // index = 0 if p1 = 1, index = 1 if p1 = 2, ...
                max_left1 = nums1[p1 - 1];
            }
            // left part of nums1 can have at most size_1 items
            if (p1 == size_1)
            {
                min_right1 = INT_MAX;
            }
            else
            {
                min_right1 = nums1[p1];
            }


            // partition of nums2, this denote the number of elements in the left partition of nums2, possibly including the median.
            int p2 = total_left - p1;
            if (p2 == 0)
            {
                max_left2 = INT_MIN;
            }
            else
            {
                max_left2 = nums2[p2 - 1];
            }
            if (p2 == size_2)
            {
                min_right2 = INT_MAX;
            }
            else
            {
                min_right2 = nums2[p2];
            }
            // By sorted, we already have:
            // max_left1 <= min_right1
            // max_left2 <= min_right2
            if (max_left1 <= min_right2 && max_left2 <= min_right1)
            {
                // so the entire left and right are detatched
                if ((size_1 + size_2) % 2 == 0){
                    // Case even
                    return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;
                }
                else
                {
                        return max(max_left1, max_left2);
                }
            }
            else if (max_left1 > min_right2)
            {
                // too much item in left part of nums1, so what's right of max_left1 can be discarded
                // -1 because p1 denote the start of right of sums1, which should be discarded
                r = p1 - 1;
            }
            else
            {
                // max_left2 > min_right1
                // too much item in left part of nums2, which means too little in right sums1, so left of nums1 can be discarded
                // why + 1? because min_right1 is at p1 and should be put to left
                l = p1 + 1;
            }
            
        }
        throw;


    }

    int min(int a, int b)
    {
        if (a <= b)
        {
            return a;
        }
        return b;
    }

    int max(int a, int b)
    {
        if (a >= b)
        {
            return a;
        }
        return b;
    }
};