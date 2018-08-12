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
};

int main(){
    //int nums1[] = {1,2,3,4,5,5,6};
    int nums1[] = {2,7,11,15};
    vector <int> vec (nums1, nums1 + sizeof(nums1)/sizeof(nums1[0]));
    print(vec);
    Solution s;
    vector <int> ret = s.twoSum(vec,9);
    print(ret);
    return 0;
}