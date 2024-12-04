import java.util.Scanner;
public class Repetitions {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		long max = 1;
		long currentL = 1;
		for(int i = 1; i < str.length();i++) {
			
			
			if(str.charAt(i) == str.charAt(i-1)) {
				currentL++;
				if(currentL > max) {
					max = currentL;
				}
			}
			else {
				currentL = 1;
			}
			
		}
		System.out.print(max);
	}

}
