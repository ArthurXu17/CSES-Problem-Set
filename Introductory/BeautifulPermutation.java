import java.util.*;
public class BeautifulPermutation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n == 1) {
			System.out.print(1);
		}
		else if(n==2 || n == 3) {
			System.out.print("NO SOLUTION");
		}
		else if (n%2 == 0){
			for(int i = n-1; i >= 1; i -=2) {
				System.out.print(i + " ");
			}
			for(int i = n; i >=2; i -=2) {
				System.out.print(i + " ");
			}
		}
		else {
			for(int i = n; i >= 1; i -=2) {
				System.out.print(i + " ");
			}
			for(int i = n-1; i >=2; i -=2) {
				System.out.print(i + " ");
			}
		}
	}

}
