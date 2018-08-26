#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /*
     * 时间复杂度：O(n^2)
     * 使用unordered_map保存倾角以及对应的次数
     * 相同的倾角即在同一个直线上
     * 注意：需要加上对相同点的处理
     */
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i ++) {
            int samenum = 0;
            int sameynum = 0;
            unordered_map<double, int> map1;
            for (int j = 0; j < points.size(); j++)
            {
                //对相同点的判断
                if (points[i].y == points[j].y && points[i].x == points[j].x) {
                    samenum ++;
                }
                //对分母相等情况进行判断
                else if (points[i].y != points[j].y){
                    //计算倾角
                    double a = (double)(points[i].x - points[j].x)/(points[i].y - points[j].y);
                    map1[a] ++;
                }
                else{
                    sameynum ++;
                }
            }
            //对只有相同点的情况进行处理
            res = max(res,samenum);
            //对y相同点情况作处理,需要加上相同点
            res = max(res,sameynum + samenum);
            //遍历map，取最大值，需要加上相同点
            for (unordered_map<double, int>::iterator iter = map1.begin(); iter != map1.end(); iter ++)
            {
                res = max(res, iter->second + samenum);
            }
        }
        return res;
    }
};
int main() {
    Point p1(1,1);
    Point p2(3,2);
    Point p3(5,3);
    Point p4(4,1);
    Point p5(2,3);
    Point p6(1,4);
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    points.push_back(p6);
    Solution s;
    int ret = s.maxPoints(points);
    cout << ret << endl;
    return 0;
}