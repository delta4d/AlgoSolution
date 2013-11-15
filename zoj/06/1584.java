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
		String s = new String();
		String s1, s2;
		int len;
		//BigInteger a, b;
		while (in.hasNext()) {
			s = in.next();
			if (s.length() > 1024) {
				System.out.println(0);
			} else {
				if (s.length() % 2 == 1) s += '0';
				len = s.length();
				s1 = String.valueOf(s.substring(len>>1, len));
				//System.out.println(s1);
				s2 = String.valueOf(s.substring(0, len>>1));
				//System.out.println(s2);
				s2 = reverse(s2);
				BigInteger a = new BigInteger(s1);
				BigInteger b = new BigInteger(s2);
				System.out.println(a.multiply(b));
			}
		}
	}
}