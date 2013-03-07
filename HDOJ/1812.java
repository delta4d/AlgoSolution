import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static BigInteger pow(int x, int n) {
		BigInteger ret = BigInteger.ONE;
		for (int i=0; i<n; ++i) ret = ret.multiply(BigInteger.valueOf(x));
		return ret;
	}
	
	public static BigInteger gao(int n, int c) {
		int k, x, y;
		BigInteger tot;
		if (n % 2 == 0) {
			k = n >> 1;
			x = k * k;
			y = 2 * k * k;
			tot = pow(c, x).multiply(BigInteger.valueOf(2));
			tot = tot.add(pow(c, n*n));
			tot = tot.add(pow(c, y));
			tot = tot.add(pow(c, n*n>>1).multiply(BigInteger.valueOf(2)));
			tot = tot.add(pow(c, n*(n+1)>>1).multiply(BigInteger.valueOf(2)));
		} else {
			k = n >> 1;
			x = k * (k + 1) + 1;
			y = 2 * k * (k + 1) + 1;
			tot = pow(c, x).multiply(BigInteger.valueOf(2)); 
			tot = tot.add(pow(c, n*n));
			tot = tot.add(pow(c, y));
			tot = tot.add(pow(c, n*(n+1)>>1).multiply(BigInteger.valueOf(2)));
			tot = tot.add(pow(c, n*(n+1)>>1).multiply(BigInteger.valueOf(2)));
		}
		return tot.divide(BigInteger.valueOf(8));
	}
	
	public static void main(String []args) {
		int i, j, k;
		int n, c;
		BigInteger f[][] = new BigInteger[32][32];
		Scanner in = new Scanner(System.in);
		
		for (n=1; n<32; ++n) for (c=1; c<32; ++c) f[n][c] = gao(n, c);
		
	//	System.out.println(f[2][2]);
		
		while (in.hasNext()) {
			n = in.nextInt();
			c = in.nextInt();
			System.out.println(f[n][c]);
		}
	}
}