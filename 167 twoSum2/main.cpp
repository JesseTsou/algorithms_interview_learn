#include <iostream>
#include <vector>
using namespace std;

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
     * 时间复杂度：O(n)
     * 左右两个索引，向中间进行对撞
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                vector<int> ret;
                ret.push_back(low + 1);
                ret.push_back(high + 1);
                return ret;
            } else if (numbers[low] + numbers[high] > target) {
                high--;
            } else {
                low++;
            }
        }

    }
    /*
    *时间复杂度：O(nlogn)
    *遍历数组，对于每个元素，使用二分查找法，查找其对应和为target的元素是否存在
    */
    vector<int> twoSum2(vector<int>& numbers, int target) {
        int key = 0;
        for (int i = 0; i < numbers.size(); i ++)
        {
            key = target - numbers[i];
            int j = binarySearch(numbers,key,i);
            if (j > 0)
            {
                vector<int> ret;
                ret.push_back(i + 1);
                ret.push_back(j + 1);
                return ret;
            }
        }
    }
private:
    int binarySearch(vector<int> &num, int key,int i)
    {
        int l = i + 1;
        int r = num.size() - 1;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l)/2;
            if (num[mid] == key)
                return mid;
            else if (num[mid] > key){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    //int nums1[] = {1,2,3,4,5,5,6};
    int nums1[] = {1,2,3,4,4,9,56,90};
    vector <int> vec (nums1, nums1 + sizeof(nums1)/sizeof(nums1[0]));
    print(vec);
    Solution s;
    vector <int> ret = s.twoSum2(vec,8);
    print(ret);
    return 0;
}