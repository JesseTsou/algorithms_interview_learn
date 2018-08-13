#include <iostream>
#include <string>
#include <cstring>
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
    /*
     * 更简洁的写法
     */
    int lengthOfLongestSubstrin2(string s) {
        char szchar[256] = {0};
        int l = 0, r = -1;//[l,r]为子串
        int max = 0;

        while (r + 1 < s.size())
        {
            if(szchar[s[r + 1]] == 0)
            {
                szchar[s[++r]] ++;
            }else{
                szchar[s[l++]] --;
            }

            max = (max > r - l + 1?max:r - l + 1);
        }
        return max;
    }
    /*
     *设置数组记录右值点的位置，可使左边界快速跳跃到重复点右侧
     */
    int lengthOfLongestSubstring3(string s) {
        int szchar[256] = {0};
        int l = 0, r = -1;//[l,r]为子串
        int max = 0;
        memset(szchar, -1,sizeof(szchar));
        while (r + 1 < s.size())
        {
            r ++;
            if(szchar[s[r]] != -1)
            {
                l = (l > szchar[s[r]] + 1?l:szchar[s[r]]+1);
            }

            szchar[s[r]] = r;//记录位置

            max = (max > r - l + 1?max:r - l + 1);
        }
        return max;
    }
};

int main() {
    string str=" ";
    print(str);
    Solution s;
    int len = s.lengthOfLongestSubstring3(str);
    cout << len << endl;
    return 0;
}