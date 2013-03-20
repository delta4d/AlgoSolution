import java.util.*;
import java.math.*;

public class Main {	
	public static String reverse(String name) {
		String res = "";
		for(int i=name.length()-1;i>=0;i--) {
			res += String.valueOf(name.charAt(i));
		}
		return res;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s, temp, n;
		BigInteger x, rem;
		BigInteger mul = BigInteger.valueOf(26);
		int i, j, k;
		int len;
		s = in.next();
		while (!s.equals("*")) {
			if (s.charAt(0) <= '9' && s.charAt(0) >= '0') {
				temp = "";
				x = new BigInteger(s);
				while (!x.equals(BigInteger.ZERO)) {
					rem = x.mod(mul);
					x = x.divide(mul);
					if (rem.equals(BigInteger.ZERO)) x = x.subtract(BigInteger.ONE);
					k = rem.intValue() + 'a' - 1;
					if (rem.equals(BigInteger.ZERO)) {
						temp = temp + "z";
					} else {
						temp = temp + (char)k;
					}
					//System.out.println(String.format("%s", temp));
				}
				n = s;
				s = reverse(temp);
				//System.out.println(n);
			} else {
				x = BigInteger.ZERO;
				len = s.length();
				for (i=0; i<len; ++i) {
					x = x.multiply(mul);
					x = x.add(BigInteger.valueOf(s.charAt(i)-'a'+1));
				}
				//x = new BigInteger("12345");
				n = x.toString();
			}
			System.out.print(String.format("%-22s", s));
			len = n.length();
			k = len % 3;
			if (k == 0) k = 3;
			for (i=0; i<len; ) {
				for (j=0; j<k; ++j) {
					System.out.print(n.charAt(i));
					++i;
				}
				if (i < len - 1) System.out.print(',');
				k = 3;
			}
			System.out.println();
			s = in.next();
		}
	}
}