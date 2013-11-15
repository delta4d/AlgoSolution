import java.util.*;
import java.math.*;

public class Main {
	private static Exception done;

	public static void main(String[] args) {
		BigInteger ten = BigInteger.ONE;
		BigInteger x, f, t, temp, msb;
		Scanner in = new Scanner(System.in);
		int i, j, k;
		int tc, A;
		int n, xn;
		boolean done;
		tc = in.nextInt();
		while (tc >= 0) {
			--tc;
			A = in.nextInt();
			ten = BigInteger.ONE;
			f = BigInteger.valueOf(A);
			f = f.multiply(BigInteger.valueOf(10));
			f = f.subtract(BigInteger.valueOf(1));
			done = false;
			x = BigInteger.ZERO;
			for (n=1; true; ++n) {
				ten = ten.multiply(BigInteger.valueOf(10));
				for (xn=1; xn<10; ++xn) {
					t = ten.subtract(BigInteger.valueOf(A));
					t = t.multiply(BigInteger.valueOf(xn));
					x = t.divide(f);
					temp = x.multiply(f);
					if (temp.equals(t)) {
						done = true;
						break;
					}
				}
				if (done) break;
			}
			//System.out.println("x:"+x+" "+"xn:"+xn+" "+"ten:"+ten);
			msb = ten.multiply(BigInteger.valueOf(xn));
			x = msb.add(x);
			System.out.println(x);
		}
	}
}

