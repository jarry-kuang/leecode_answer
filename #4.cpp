#4.cpp
class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2,int k) { //find 'k'th number
    	int s1 = nums1.size(); 
    	int s2 = nums2.size();
    	int index1 = 0; 
    	int index2 = 0;

    	while(true){
    		if(index1==s1) return nums2[index2+k-1]; //if nums1 length is equal to index
    		if(index2==s2) return nums1[index1+k-1]; //if nums2 length is equal to index
    		if(k==1) return min(nums1[index1],nums2[index2]);

    		int newIndex1 = min(index1+k/2-1,s1-1);//mid 
    		int newIndex2 = min(index2+k/2-1,s2-1);
    		int pivot1 = nums1[newIndex1];
    		int pivot2 = nums2[newIndex2];
    		if(pivot1<=pivot2){
    			k -= newIndex1 -index1 +1;
    			index1 = newIndex1 + 1;
    		}else{
    			k-=newIndex2-index2 +1;
    			index2 = newIndex2 +1;
    		}
    	}
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
