import java.util.*;
public class NumberSpiral {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++) {
			long y = sc.nextLong();
			long x = sc.nextLong();
			long ans;
			if(x > y) {
				if(x%2 == 0) {
					ans = (x-1)*(x-1)+y;
				}
				else {
					ans = x*x-y+1;
				}
			}
			else {
				if(y%2 == 0) {
					ans = y*y - x + 1;
				}
				else {
					ans = (y-1)*(y-1) + x;
				}
			}
			System.out.println(ans);
		}
	}

}
