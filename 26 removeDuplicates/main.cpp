#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    }
};
int print(vector<int> vec, int size)
{
    for (int i = 0; i < size; i ++)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}
int main() {
    int a[] = {1,2,3,4,5,7,3,7,7,7,7,7,7,7,7,4,5,6,7,8};
    vector<int> vecnums(a, a + sizeof(a)/sizeof(a[0]));
    print(vecnums, vecnums.size());
    Solution s;
    int len = s.removeDuplicates(vecnums);
    print(vecnums, len);

    return 0;
}