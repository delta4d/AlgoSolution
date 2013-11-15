import java.util.*;
import java.math.*;

public class Main {
	public static int p[] = new int[256];
	public static boolean isp[] = new boolean[1024];
	
	public static void init() {
		int k = 0;
//		System.out.println("---");
		for (int i=2; i<1024; ++i) if (!isp[i]) {
			p[k++] = i;
//			System.out.println(p[k-1] + " ");
			for (int j=i<<1; j<1024; j+=i) isp[j] = true;
		}
	}

	public static void main(String []args) {
		int i, j, k;
		int m, n, t;
		int tc, cn;
		boolean xx;
		boolean a[][] = new boolean[128][128];
		Scanner in = new Scanner(System.in);

		init();
		tc = in.nextInt();
		for (cn=0; cn<tc; ++cn) {
			t = in.nextInt();
			m = in.nextInt();
			for (j=0; j<m; ++j) {
				k = in.nextInt();
				for (i=0; i<t; ++i) {
					for (xx=false; k%p[i]==0; k/=p[i], xx=!xx);
					a[i][j] = xx;
				}
			}
			
			int r = 0;
			int c = 0;
			
			while (r < t && c < m) {
				for (i=r; i<t; ++i) if (a[i][c]) break;
				if (i >= t) {
					++c;
				} else {
					int rr = i;
					for (j=0; j<m; ++j) {
						boolean tmp = a[r][j];
						a[r][j] = a[rr][j];
						a[rr][j] = tmp;
					}
					for (i=r+1; i<t; ++i) if (a[i][c]) for (j=c; j<m; ++j) a[i][j] ^= a[r][j];
					++r;
				}
			}
			
			System.out.println(BigInteger.valueOf(2).pow(m-r).subtract(BigInteger.ONE));
			if (cn != tc - 1) System.out.println();
		}
	}
}
