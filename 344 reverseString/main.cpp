#include <iostream>
#include <string>
using namespace std;
/*
 * 编写一个函数，其作用是将输入的字符串反转过来。
 */
int print(string str)
{
    cout << str << endl;
    return 0;
}

class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 从数组两边向中间遍历，并作交换
     */
    string reverseString(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            swap(s[l++],s[r--]);
        }
        return s;
    }
};

int main() {
    //string str = "A man, a plan, a canal: Panama";
    //string str = "race a car";;
    string str = " ";
    //string str = ",.";
    print(str);
    Solution s;
    string str2 = s.reverseString(str);
    print(str2);
    return 0;
}