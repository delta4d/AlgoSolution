// 100ms
// basic geo
// points can be dup
// enumerate line [O(n^3)]
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int xmult(Point &p, Point &a, Point &b) {
        return (a.x - p.x) * (b.y - p.y) - (a.y- p.y) * (b.x - p.x);
    }
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;
        sort(begin(points), end(points), [](const Point &a, const Point &b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });
        vector <int> cnt((int)points.size(), 1);
        int n = 1, sz = (int)points.size(), ret = 0;
        for (int i=1; i<sz; ++i) {
            if (points[i].x == points[n-1].x  && points[i].y == points[n-1].y) {
                ++cnt[n-1];
            } else {
                points[n++] = points[i];
            }
        }
		for (int i=0; i<n; ++i) ret = max(ret, cnt[i]);
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int cc = 0;
            for (int k=0; k<n; ++k) {
                cc += (xmult(points[k], points[i], points[j]) == 0) * cnt[k];
            }
            ret = max(ret, cc);
        }
        return ret;
    }
};

// 152ms
// eumerate one end point, can count the different slope
// to avoid float number comparsion, I use fraction to represent slope
// time complexity is O(n^2logn)
// it costs more than O(n^3)
// due to my ugly implementation, and STL map costs
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#define SGN(x) ((x) < 0 ? -1 : 1)
bool operator<(const Point &a, const Point &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = (int)points.size();
        if (n <= 2) return n;
        int ret = 2;
        for (int i=0; i<n; ++i) {
			int dup = 0;
			for (int j=0; j<n; ++j) dup += points[i] == points[j];
			ret = max(ret, dup);
            map<Point, int> cnt;
            for (int j=0; j<n; ++j) if (!(points[i] == points[j])) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                int sgn = SGN(x) * SGN(y), d = 1;
                x = sgn * abs(x), y = abs(y);
                if (x && y) d = __gcd(x, y);
                x /= d, y /= d;
                if (y == 0) x = 1;
                if (x == 0) y = 1;
                Point cc(x, y);
                ++cnt[cc];
                ret = max(ret, cnt[cc]+dup);
            }
        }
        return ret;
    }
};
