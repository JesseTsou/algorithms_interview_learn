#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
/*
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 */
int print(string str)
{
    cout << str << endl;
    return 0;
}
int print(vector<int> vec)
{
    for (int e:vec)
        cout << e << " ";
    cout << endl;
    return 0;
}
class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 使用长度为26的数组来存储元素个数
     * 固定长度进行滑动
     * 但是操作还是过于冗余了
     */
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec;
        if (s.size() == 0)
            return vec;
        int a[26] = {0};//用于存储p元素
        int b[26] = {0};//用于存储s元素
        for (char c:p)
            a[c-97]++;
        int l = 0;
        int r = p.size() - 1;
        bool issame = true;
        while(r <= s.size() - 1)
        {
            issame = true;
            memset(b, 0, sizeof(b));
            for (int i = l; i <= r; i ++)
                b[s[i]-97]++;//存储滑动子串元素

            for (int i = 0; i < 26; i ++)//比较
            {
                if(a[i] != b[i])
                {
                    issame = false;
                    break;
                }
            }
            if (issame)
                vec.push_back(l);
            r ++;
            l ++;
        }
        return vec;
    }

    /*
     * 对上述做法进行优化
     * 移动的过程中，对存储s的数组进行元素的添加与删除
     *
     */
    vector<int> findAnagrams2(string s, string p) {
        vector<int> vec;
        if (s.size() == 0 || p.size() > s.size())
            return vec;
        int a[26] = {0};//用于存储p元素
        int b[26] = {0};//用于存储s元素
        for (int i = 0;i < p.size(); i ++)//
        {
            a[p[i] - 'a'] ++;//存储p元素
            b[s[i] - 'a'] ++;//存储初始p长度的s子串
        }
        int l = 0;
        int r = p.size() - 1;
        bool issame = true;
        while(r <= s.size() - 1)
        {
            issame = true;
            for (int i = 0; i < 26; i ++)//比较
            {
                if(a[i] != b[i])
                {
                    issame = false;
                    break;
                }
            }
            if (issame)
                vec.push_back(l);
            if (r + 1 < s.size())//边界判断
                b[s[++r] - 'a'] ++;//存储后一元素
            else
                r++;
            b[s[l++] - 'a'] --;//移除前一元素
        }
        return vec;
    }

    /*
     * 使用vector来存储，方便作比较
     */
    vector<int> findAnagrams3(string s, string p) {
        vector<int> vec;
        if (s.size() == 0 || p.size() > s.size())
            return vec;
        vector<int> a(26);//用于存储p元素
        vector<int> b(26);//用于存储s元素
        for (int i = 0;i < p.size(); i ++)//
        {
            a[p[i] - 'a'] ++;//存储p元素
            b[s[i] - 'a'] ++;//存储初始p长度的s子串
        }
        int l = 0;
        int r = p.size() - 1;
        while(r <= s.size() - 1)
        {
            if (a == b)//比较
                vec.push_back(l);
            if (r + 1 < s.size())//边界判断
                b[s[++r] - 'a'] ++;//存储后一元素
            else
                r++;
            b[s[l++] - 'a'] --;//移除前一元素
        }
        return vec;
    }
};

int main() {
    string str = "aaaaaaaaaa";
    string str1="aaaaaa";
    print(str);
    Solution s;
    vector<int> vec = s.findAnagrams3(str,str1);
    print(vec);
    return 0;
}