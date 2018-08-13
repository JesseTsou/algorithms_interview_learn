#include <iostream>
#include <string>
using namespace std;
/*
 * 给定一个字符串，找出不含有重复字符的最长子串的长度。
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
     * 使用滑动窗口方法
     * 设置字符数组来记录是否有重复元素
     */
    int lengthOfLongestSubstring(string s) {
        char szchar[256] = {0};
        int l = 0, r = -1;//[l,r]为子串
        int len = 0;
        int max = 0;

        while (r + 1 < s.size())
        {
            if(szchar[s[r + 1]] == 0)
            {
                szchar[s[++r]] ++;
                len ++;
                max = (max > len?max:len);
            }else{
                szchar[s[l]] --;
                len --;
                l ++;
            }
        }
        return max;
    }
};

int main() {
    string str="abcabcbb";
    print(str);
    Solution s;
    int len = s.lengthOfLongestSubstring(str);
    cout << len << endl;
    return 0;
}