#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
/*
 * 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
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
     * 滑动窗口
     * 使用count来记录匹配元素的个数
     * 全部匹配时count等于t的size
     */
    string minWindow(string s, string t) {
        if (s.size() == 0)
            return "";
        int a[256] = {0};
        int b[256] = {0};

        for (int i = 0; i < t.size(); i ++)
        {
            a[t[i]] ++;
        }

        int l = 0,r = -1;//[l,r]表示子串
        int count = 0;
        int minlen = s.size()  + 1;
        int start = -1;
        while(l < s.size())
        {
            if (r + 1 < s.size() && count < t.size()){//右边界临界或未匹配完全时
                b[s[r+1]] ++;
                if (a[s[r + 1]] >= b[s[r + 1]])//表示该元素仍未匹配完成时
                    count ++;
                r++;//右边界右移，扩大范围
            } else{
                if (count == t.size()){//表示已经匹配完成时
                    if (r - l + 1 < minlen){
                        minlen = r - l + 1;
                        start = l;
                    }
                }
                b[s[l]] --;
                if(b[s[l]] < a[s[l]])//表示该元素已经缺少
                    count --;
                l ++;
            }
        }
        if (start == -1)
            return "";
        return s.substr(start,minlen);
    }
    /*
     * 自己做的
     * 超时了
     * 但是感觉应该没错
     */
    string minWindow2(string s, string t) {
        if (s.size() == 0)
            return "";
        vector<int> a('z'-'A' + 1);
        vector<int> b('z'-'A' + 1);

        for (int i = 0; i < t.size(); i ++)
        {
            a[t[i] - 'A'] ++;
            b[s[i] - 'A'] ++;
        }

        int l = 0,r = t.size() - 1;//[l,r]表示子串
        string res="";
        string subStr;
        bool isin = true;
        while(l < s.size())
        {
            isin = true;
            for (int j = 0; j < a.size();j ++)//判断是否已经匹配完成（太耗时）
            {
                if (a[j] > b[j])
                {
                    isin = false;
                    break;
                }
            }
            subStr=s.substr(l,r - l + 1);
            if (isin)//匹配完成时，左边界右移
            {
                res = (res.size() != 0 && res.size()<subStr.size()?res:subStr);
                b[s[l] - 'A'] --;
                l++;
            } else{//匹配未完成时，右边界右移
                if (r + 1 < s.size())
                {
                    b[s[++r] - 'A'] ++;
                }else if(r + 1 == s.size()){
                    l ++;
                }
            }
        }
        return res;
    }
};

int main() {
    string str = "wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon";
    string str1="ozgzyywxvtublcl";
    //string str = "ADOBECODEBANC";
    //string str1 = "ABC";
    print(str);
    Solution s;
    string str2 = s.minWindow(str,str1);
    print(str2);
    return 0;
}