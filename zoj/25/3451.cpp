#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;

#define debug 0

const double g = 9.80665;
const double glx = 34 + 7.32 / 2.0;
const double grx = 34 - 7.32 / 2.0;
const double h = 2.44;
char res[2][5] = {"no", "yes"};

int main(void) {
   double dx;
   double dy;
   double dz;
   double vx;
   double vy;
   double vz;
   double gx;
   double gy;
   double gz;
   double v;
   double x;
   double y;
   double s;
   double total;
   double dec;
   double rem;
   double t;
   int i;
   int j;
   int k;
   int n;
   int case_num(0);
   int test_case;
      
   while (scanf("%lf %lf", &x, &y) != EOF) {
      assert(x >= 0 && x <= 68);
      assert(y > 0 && y <= 105);
      scanf("%d", &test_case);
      assert(test_case >= 1 && test_case <= 100);
      printf("Case #%d:\n", ++case_num);
      
      for (k=1; k<=test_case; ++k) {
         scanf("%lf %lf %lf %lf", &v, &dx, &dy, &dz);
         assert(v > 0 && v <= 60);
         assert(dx >= -100 && dx <= 100);
         assert(dy >= -100 && dy <= 100);
         assert(dz >= 0 && dz <= 100);
         vx = v * dx / sqrt(dx*dx + dy*dy + dz*dz);
         vy = v * dy / sqrt(dx*dx + dy*dy + dz*dz);
         vz = v * dz / sqrt(dx*dx + dy*dy + dz*dz);
         
         //wrong dirction
         if (dy >= 0) {
            printf("Shot %d: %s\n", k, res[0]);
            continue;
         }
         //no vertical motion
         if (dz == 0) {
            if (x - y * dx / dy >= glx || x - y * dx / dy <= grx) {
               printf("Shot %d: %s\n", k, res[0]);
               continue;
            }
            printf("Shot %d: %s\n", k, res[1]);
            continue;
         }
         s = fabs(8.0 * vy * vz / 3.0 / g);
         //cannot reach the goal
         if (s < y) {
            printf("Shot %d: %s\n", k, res[0]);
            continue;
         }
         //out of goal
         if (x - y * dx / dy >= glx || x - y * dx / dy <= grx) {
            printf("Shot %d: %s\n", k, res[0]);
            continue;
         }
         
         s = fabs(-2.0 * vz * vy / g);
         n = -log(1.0 - 3.0 * y / 4.0 / s) / log(4.0);
         dec = pow(2, (double)n);
         total = s * 4.0 * (1.0 - 1.0 / dec / dec) / 3.0;
         rem = y - total;
         vx /= dec;
         vy /= dec;
         vz /= dec;
         
         t = -rem / vy;
         gz = vz * t - 0.5 * g * t * t;
         //beyond goal
         if (gz >= h) {
            printf("Shot %d: %s\n", k, res[0]);
            continue;
         }
         printf("Shot %d: %s\n", k, res[1]);
         //fprintf(fp, "%lf %lf\n%lf %lf %lf %lf\n", x, y, v, dx, dy, dz);
      }
   }
   
   return 0;
}
