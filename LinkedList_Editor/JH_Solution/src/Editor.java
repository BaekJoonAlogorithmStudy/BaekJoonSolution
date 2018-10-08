// #### 
// 백준 알고리즘 1406 문제
// 결과는 제대로 나오지만, 시간초과 에러로 해결 하지 못함
// 
// 에디터의 커서가 뒤쪽부터 시작하는 것을 힌트로 삼아 스택 자료구조를 활용하여 구현
//


import java.util.Scanner;
import java.util.Stack;


public class Editor {

	public static void main(String[] args) {
		Stack<Character> stk = new Stack<Character>();
		String command = null;
		
		Scanner sc = new Scanner(System.in);
		
		String input = sc.nextLine();
		int N = sc.nextInt();
		
		char C_result[] = new char[N*3]; // 에디터 명령을 담을 배열
		char temp[] = new char[N*3]; // 스택자료 구조를 활용하기 위한 배열
		int cnt=0; // 제어변수
		int ct =0; // 제어변수
		int num=0; // 제어변수
		int sizeTemp=0; // 스택의 크기를 담는 변수
	
		int cursor = input.length();
			
		sc.nextLine();

		for(int i=0;i<input.length();i++) //string으로 들어온 배열을 한 글 자씩 잘라서 배열에 저장
			stk.push(input.charAt(i));
		
	
		for(int i=0;i<N;i++) {	// 커맨드 값을 N번 만큼 입력을 받음
			
			command = sc.nextLine();
			
			for(int j=0; j<command.length(); j++) {
				C_result[cnt] = command.charAt(j);	//문자 하나씩 C_result 배열에 저장
				cnt++;
				
			}		
		}
			while(true) {
				
				if(cursor<0) // 커서 값이 음수가 되지 않게함
			      cursor=0;
				
				sizeTemp = stk.size();
			
				
			switch(C_result[num]) { // 명령이 4개 이기 때문에 가독성이 좋은 스위치문으로 작성
			
				case 'P': {
				
				int a=0; // 스택이 pop된 횟 수를 세기 위한 변수
				num += 2;	// 'P x' 형태로 커맨드 입력이 들어오기때문에 추가해줘야 하는 문자를 알기위해 제어변수에 2를 더해줌
							
				
				if(stk.size()==cursor) { // 커서가 끝에 있을 때
					stk.push(C_result[num]);
					cursor++;
				}
								
				else {
				for(int k=0; k<(sizeTemp-cursor);k++) {	// 커서에 따라 큐를 pop 해줌
					if(stk.empty()==true) // 큐가 비었으면 종료
						break;
					
					temp[a] = stk.pop();
					a++;
					
				}		
				a--;

				stk.push(C_result[num]);	// 커멘드에 있는 문자를 넣어줌
						
				for(int k=a; k>=0; k--) // 스택은 FILO 이기 때문에 배열에 거꾸로 저장하여 다시 스택에 넣어줌
					stk.push(temp[k]);
				
				}
					break;
				} //end of case 'P'
				
				case 'B': {
					
					int a=0;
								
					if(cursor<=0)  // 커서가 맨 끝에 있으면 실행하지 않음	
						break;
						
					for(int k=0; k< (sizeTemp-cursor) +1;k++) {	// 커서에 따라 큐를 pop 해줌
					
						if(stk.empty()==true) // 큐가 비었으면 종료
							break;
						
						temp[a] = stk.pop();
						a++;	
					}		
					a--;
									
					for(int k=a-1; k>=0; k--)
						stk.push(temp[k]);
					
					cursor--;
					
					break;
				} //end of case 'B'
				
				case 'L': {
					
					cursor--;
								
					break;
				} // end of case'L'
				
				case 'D': {
				
					cursor++;
					
					if(cursor>stk.size()) // 커서가 문장 끝으로 넘어가지 않게 해줌
						cursor--;
							
					break;
				} // end of case 'D'
			} // end of switch
			
			num++; 
			ct++;
			if(ct==N)
				break;
			
			} // end of loop
			System.out.println(stk);
	}// end of main method
}
