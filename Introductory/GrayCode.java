import java.util.*;
public class GrayCode {

	public static String[] code (int n) {
		String[] ans;
		if(n == 1) {
			ans = new String[2];
			ans[0] = "0";
			ans[1] = "1";
			return ans;
		}
		else {
			String[] arr = code(n-1);
			int l = arr.length;
			ans = new String[2*l];
			for(int i = 0; i < l; i++) {
				ans[i] = arr[i] + "0";
				ans[2*l-i-1] = arr[i] + "1";
			}
			return ans;
		}
	}

	public static void print(String[] arr) {
		for(int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] arr1 = code(n);
		print(arr1);

	}

}
