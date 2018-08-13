#include <iostream>
#include <string>
#include <vector>
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
    vector<int> findAnagrams(string s, string p) {

    }
};

int main() {
    string str="cbaebabacd ";
    string str1="abc ";
    print(str);
    Solution s;
    vector<int> vec = s.findAnagrams(str,str1);;
    print(vec);
    return 0;
}