import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static int f(int d, int a, int b, int m, int n) {
		int[][] p = new int[m][n];
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
			p[i][j] = i * n + j;
		}
		if (m == n) {
			for (int dd=0; dd<d; ++dd) {
				int[][] t = new int[n][n];
				for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) t[j][n-i-1] = p[i][j];
				for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) p[i][j] = t[i][j];
			}
		} else {
			if (d > 0) {
				int[][] t = new int[m][n];
				for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) t[m-i-1][n-1-j] = p[i][j];
				for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) p[i][j] = t[i][j];
			}
		}
		for (int i=0; i<m; ++i) {
			int[] t = new int[n];
			for (int j=0; j<n; ++j) t[(j+b)%n] = p[i][j];
			for (int j=0; j<n; ++j) p[i][j] = t[j];
		}
		for (int j=0; j<n; ++j) {
			int[] t = new int[m];
			for (int i=0; i<m; ++i) t[(i+a)%m] = p[i][j];
			for (int i=0; i<m; ++i) p[i][j] = t[i];
		}
		boolean[] v = new boolean[m*n];
		int cnt = 0;
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (!v[p[i][j]]) {
			++cnt;
			for (int c=p[i][j]; !v[c]; ) {
				v[c] = true;
				c = p[c/n][c%n];
			}
		}
		return cnt;
	}
	public static void main(String []args) throws IOException {
		Scanner in = new Scanner(new FileInputStream("tickets.in"));
		PrintWriter out = new PrintWriter(new FileOutputStream("tickets.out"));
		int m = in.nextInt(), n = in.nextInt();
		if (m < n) {
			int t = m;
			m = n;
			n = t;
		}
		BigInteger tot = BigInteger.ZERO;
		int cnt = 0;
		for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) for (int k=0; k<4; ++k) {
			if (m != n && k % 2 == 1) continue;
			int e = f(k, i, j, m, n);
			tot = tot.add(BigInteger.valueOf(2).pow(e));
			++cnt;
		}
		tot = tot.divide(BigInteger.valueOf(cnt));
		out.print(tot);
		out.close();
		in.close();
	}
}

// 6970257	 2014-06-27 18:26:29	delta_4d	 H - Tickets	 Java 8	Accepted	498 ms	2996 KB
