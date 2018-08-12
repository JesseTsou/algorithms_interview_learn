#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;
int print(vector<int >vec)
{
    for(int e:vec)
        cout << e << " ";
    cout << endl;
    return 0;
}
class Solution {
public:
    /*
     * 时间复杂度：O(nlogn)
     * 使用快排进行排序，然后返回倒数第k大的值
     */
    int getpoint(vector <int> &nums, int low, int high)
    {
        int key = nums[low];
        while(low < high)
        {
            while(nums[high] >= key && high > low){
                high --;
            }
            swap(nums[high], nums[low]);
            while(nums[low] <= key && low < high){
                low ++;
            }
            swap(nums[low], nums[high]);
        }
        return low;
    }
    int fastSort(vector<int> &nums,int low, int high)
    {
        if (low < high) {
            int point = getpoint(nums, low, high);
            fastSort(nums, low, point - 1);
            fastSort(nums, point + 1, high);
        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()){
            return 0;
        }
        fastSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    /*
     *直接使用stl的排序函数
     */
    int findKthLargest2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    /*
     *利用快排的思路，将获取的point与所要取得的第k大位置进行比较
     * 若相等，则是所要取的位置
     */
    int findKthLargest3(vector<int>& nums, int k) {
        if (k > nums.size()){
            return 0;
        }
        int low = 0;
        int high = nums.size() - 1;
        while (1)
        {
            int point = getpoint(nums, low, high);
            if (point == nums.size() - k)
                return nums[point];
            else if (point > nums.size() - k){
                high = point - 1;
            }else {
                low = point + 1;
            }
        }
    }
};

int main(){
    int nums1[] = {3,2,3,1,2,4,5,5,6};
    vector <int> vec (nums1, nums1 + sizeof(nums1)/sizeof(nums1[0]));
    print(vec);
    Solution s;
    int kth = s.findKthLargest3(vec,1);
    print(vec);
    cout << "kth: "<< kth << endl;
    return 0;
}