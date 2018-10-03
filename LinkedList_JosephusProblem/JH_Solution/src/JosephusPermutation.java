// 백준 알고리즘 1158번 문제
import java.util.*;

public class JosephusPermutation {

	public static void main(String[] args) {
		int temp =0; // 큐의 값을 저장하는 임시 변수
		int cnt=0; // 결과 배열에 원소값 제어 변수
		int num=0; // 루프 제어 변수
		
		Scanner sc = new Scanner(System.in);
		
		Queue<Integer> que = new LinkedList<Integer>();
		
		int N = sc.nextInt(); int M = sc.nextInt();
	
		int result[] = new int[N]; // 결과를 저장하는 배열
		
		for(int i = 0; i< N; i++)	// 입력 큐 세팅	
			que.offer(i+1);
		
			while(true) {
				num++;	
				
			if(que.isEmpty() == true)	// 큐가 비었으면 결과 출력
				break;
			
			temp = que.poll();	// 값을 빼주고 마지막에 다시 넣어줌
			
			if(num%M == 0) {	// 매 M 번 째마다 값을 큐에 다시 넣지 않고 결과 배열에 저장 
				result[cnt] = temp;
				cnt++;
				continue;
			}
			que.offer(temp);	
		}
			
			System.out.print("<"+result[0]);
		for(int k = 1; k < result.length; k++)
			System.out.print(", " + result[k]);
			System.out.print(">");
	}
}
