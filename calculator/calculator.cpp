#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long int num1, num2;
// int sel;
const int MAX_BIT = 32; // 레지스터의 길이만큼
int result = 0;
string result_bin = "";

string binary(int num);
int decimal(string bin);
string adder(int num1, int num2);
string subtractor(int num1, int num2);
int multiplicator(int num1, int num2);
void divider(int num1, int num2);
string euibosu(string input);
void left_shift(string& A, string& Q);
int is_zero(string input);
string reverse_str(string reverse_str);

//main
int main() {
	
	while (1) {
		cout << "첫 번째 수를 입력하세요 : ";
		cin >> num1;

		if (num1 > INT_MAX) {
			cout << "input overflow!" << endl;
			continue;
		}
		else if (num1 < INT_MIN) {
			cout << "input underflow!" << endl;
			continue;
		}

		cout << "두 번째 수를 입력하세요 : ";
		cin >> num2;
		if (num2 > INT_MAX) {
			cout << "input overflow!" << endl;
			continue;
		}
		else if (num2 < INT_MIN) {
			cout << "input underflow!" << endl;
			continue;
		}

		cout << "======================= < 덧셈 > =======================" << endl;
		result_bin = adder(num1, num2);
		if (result_bin == "of") {
			cout << "result.........overflow" << endl << endl;
		}
		else {
			result = decimal(result_bin);
			cout << "result : \t" << result << endl << endl;
		}

		cout << "======================= < 뺄셈 > =======================" << endl;
		result_bin = subtractor(num1, num2);
		if (result_bin == "of") {
			cout << "result.........overflow" << endl << endl;
		}
		else {
			result = decimal(result_bin);
			cout << "result : \t" << result << endl << endl;
		}

		cout << "======================= < 곱셈 > =======================" << endl;
		multiplicator(num1, num2);

		cout << "======================= < 나눗셈 > =======================" << endl;
		divider(num1, num2);
		cout << endl;

		cout << "다시 하시겠습니까?(y/n) : ";
		char input;
		cin >> input;

		if (input == 'n') {
			break;
		}
		else {
			system("cls");
		}
	}
	return 0;
}

string reverse_str(string reverse_str) { // 인자로 입력한 문자열의 reverse 문자열을 return.
	reverse(reverse_str.begin(), reverse_str.end());

	return reverse_str;
}
// decimal -> binary
string binary(int num) {
	string bin_num = "";
	string bin_num2 = "";
	if (num >= 0) {
		while (num > 0) {
			bin_num += to_string(num % 2);
			num /= 2;
		}
		bin_num += "0"; // reverse()시키면 최상위 부호비트가 됨.
		while (bin_num.length() < MAX_BIT) { // 최상위부터 나머지 비트들을 0으로 설정.
			bin_num += "0";
		}
		return bin_num;
	}
	else {
		int num2 = num;
		num++;
		num *= -1;
		while (num > 0) {
			bin_num += to_string(num % 2);
			num /= 2;
		}
		bin_num += "0";
		while (bin_num.length() < MAX_BIT) {
			bin_num += "0";
		}
		for (int i = 0; i < bin_num.length(); i++) {
			if (bin_num.substr(i, 1) == "0") {
				bin_num.replace(i, 1, "1");
			}
			else {
				bin_num.replace(i, 1, "0");
			}


		}
		return bin_num;
	}
}

string euibosu(string input) { // reverse된 input
	string euibosu = input;

	for (int i = 0; i < MAX_BIT; i++) {
		if (euibosu[i] == '0') {
			euibosu[i] = '1';
		}
		else {
			euibosu[i] = '0';
		}
	}

	for (int i = 0; i < MAX_BIT; i++) {
		if (euibosu[i] == '0') {
			euibosu[i] = '1';

			break;
		}
		else {
			euibosu[i] = '0';
		}
	}

	return euibosu;
}

int is_zero(string input) { // Z Flag 판별
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '1') {
			return 0;
		}

		if (i == (input.length() - 1)) {
			return 1;
		}
	}
}

void left_shift(string& A, string& Q) {
	// reverse된 string이 들어옴.
	
	// left_shift A
	for (int i = (MAX_BIT - 1); i > 0; i--) {
		A[i] = A[i - 1];
	}

	A[0] = Q[MAX_BIT - 1];
	// left_shift Q

	for (int i = (MAX_BIT - 1); i > 0; i--) {
		Q[i] = Q[i - 1];
	}
	Q[0] = '0';
}

// binary -> decimal
int decimal(string bin) {
	int result = 0;
	if (bin.substr(bin.length() - 1, 1) == "0") {
		for (int i = 0; i < bin.length(); i++) {

			if (bin.substr(i, 1) == "0") {
				//cout << bin.substr(i, 1) << endl;
				result += 0 * (pow(2, i));
			}
			else {
				//cout << bin.substr(i, 1) << endl;
				result += 1 * (pow(2, i));
			}
		}
		return result;
	}

	else {
		for (int i = 0; i < bin.length(); i++) {
			if (bin.substr(i, 1) == "0") {
				bin.replace(i, 1, "1");
			}
			else {
				bin.replace(i, 1, "0");
			}
		}
		for (int i = 0; i < bin.length(); i++) {
			if (bin.substr(i, 1) == "0") {
				bin.replace(i, 1, "1");
				break;
			}
			else {
				bin.replace(i, 1, "0");
			}
		}
		for (int i = 0; i < bin.length(); i++) {
			if (bin.substr(i, 1) == "0") {
				result += 0 * (pow(2, i));
			}
			else {
				result += 1 * (pow(2, i));
			}
		}
		result *= -1;
		return result;
	}
	//cout << "1" << endl;
	return result;
}

// add two num
string adder(int num1, int num2) {
	int carry = 0;
	int a = 0;
	int b = 0;
	int C = 0, V = 0, S = 0, Z = 0;
	string bin_num1 = binary(num1);
	string bin_num2 = binary(num2);
	
	// tmp는 단순 보여주기용 
	string tmp = bin_num1;
	reverse(tmp.begin(), tmp.end());
	cout << "num1_bin:\t" << tmp << endl;
	tmp = bin_num2;
	reverse(tmp.begin(), tmp.end());
	cout << "num2_bin:\t" << tmp << endl;

	string bin_result = "";
	for (int i = 0; i < bin_num1.length(); i++) {
		// cout << bin_num1.substr(i, 1) << endl;
		if (bin_num1.substr(i, 1) == "1") {
			a = 1;
		}
		else {
			a = 0;
		}
		if (bin_num2.substr(i, 1) == "1") {
			b = 1;
		}
		else {
			b = 0;
		}

		if (a + b + carry == 3) {
			carry = 1;
			bin_result += "1";
		}
		else if (a + b + carry == 2) {
			carry = 1;
			bin_result += "0";
		}
		else if (a + b + carry == 1) {
			carry = 0;
			bin_result += "1";
		}
		else if (a + b + carry == 0) {
			carry = 0;
			bin_result += "0";
		}

		if (i == bin_num1.length() - 2) {
			V = carry;
		}

		if (i == bin_num1.length() - 1) {
			V ^= carry;
		}

	}
	bin_result = bin_result.substr(0, MAX_BIT);
	//cout << bin_result << endl;
	tmp = bin_result;
	reverse(tmp.begin(), tmp.end());
	cout << "result_bin:\t" << tmp << endl;
	S = bin_result[MAX_BIT - 1] - '0';
	Z = is_zero(bin_result);
	C = carry;

	cout << "Flag 값 ==> " << "C : " << C << ", S : " << S <<
		", V : " << V << ", Z : " << Z << endl;

	if (bin_num1.substr(MAX_BIT - 1, 1) == bin_num2.substr(MAX_BIT - 1, 1)
		&& bin_num1.substr(MAX_BIT - 1, 1) != bin_result.substr(MAX_BIT - 1, 1)) {
		return "of";
	}
	return bin_result;
}
// sub two num
string subtractor(int num1, int num2) {
	string bin_result = "";
	string bin_num1 = binary(num1);
	string bin_num2 = binary(num2);
	string tmp = bin_num1;

	reverse(tmp.begin(), tmp.end());
	cout << "num1_bin:\t" << tmp << endl;

	tmp = bin_num2;
	reverse(tmp.begin(), tmp.end());
	cout << "num2_bin:\t" << tmp << endl;

	cout << "send to adder" << endl;
	bin_result = adder(num1, num2 *= -1);
	return bin_result;
}

// mul two num
int multiplicator(int num1, int num2)
{
	bool z_flag[2]; //나중에 계산용 
	bool sign[2]; // 부호 체크용
	z_flag[0] = false;
	z_flag[1] = false;
	bool z_check = true; // true이면 0

	string bin_num1 = binary(num1);
	string bin_num2 = binary(num2);

	reverse(bin_num1.begin(), bin_num1.end());
	// cout << "num1_bin:\t" << bin_num1 << endl;
	reverse(bin_num2.begin(), bin_num2.end());
	// cout << "num2_bin:\t" << bin_num2 << endl;

	/*
	   cout << "피승수 : "; //숫자값을 입력받음
	   cin >> input[0];
	   cout << "승수 : ";
	   cin >> input[1];

	   sign[0] = false; // false면 양수
	   sign[1] = false;

	   while (getchar() != '\n');

	   for (int i = 0; i < 2; i++) {
		  if (input[i].at(0) == '-') { //부호 체크
		  //첫 문자가 -이면..
			 sign[i] = true; //음수라는 뜻
		  }
		  for (int j = 0; j < 32; j++) {
			 mbinary[i][j] = 0; //싹다 0으로 초기화
		  }
	   }
	   int temp = 0; //임시 저장값. (입력한 값이 int형으로 표현된다고 가정, 연산에 사용되는 레지스터 길이가 32비트라고 가정되어 있으므로.)

	   for (int i = 0; i < 2; i++) {
		  if (!sign[i]) { //양수이면, 그대로 변환
			 temp = atoi(input[i].c_str());

		  }
		  else { //음수이면, 부호 빼고 값 받아옴.
			 temp = atoi(input[i].substr(1).c_str());

		  }

		  for (int j = 31; j > 0; j--) { //0번 인덱스는 부호값.
			 mbinary[i][j] = temp % 2;
			 temp /= 2;
		  }

		  if (sign[i]) { //음수이면 보수로 변경
			 bool check_up = true; //2의 보수에서 쓰일 올림수, 참이면 올림


			 for (int j = 31; j >= 0; j--) {
				if (mbinary[i][j] == 0)
				   mbinary[i][j] = 1;
				else
				   mbinary[i][j] = 0;   //일단 1의 보수 취해줌.

				if (check_up) { //만일 뒤에서 올림값이 올라오면 값 증가. 2의 보수로 바꿔주기 위함
				   mbinary[i][j]++;

				   if (mbinary[i][j] != 1) //증가시킨값이 1이 아님.
					  mbinary[i][j] = 0; // 2가 되었단 뜻이므로 0으로 바꾸고 올림유지
				   else //1이라면
					  check_up = false; //false로 유지
				}
			 }
		  }
	   }*/

	int minus_q = 0; //q0용 
	int A[32] = {}; //계산에 활용할 레지스터 A
	int M[32] = {};
	int Q[32] = {};
	int in_carry = 0;
	int out_carry = 0;

	int _M[32]; //계산에 사용할 m의 보수, 위의 방식과 동일.
	bool check_up = true;
	for (int i = 31; i >= 0; i--) {
		if (bin_num1[i] == '0')
			_M[i] = 1;
		else
			_M[i] = 0;

		if (check_up) {
			_M[i]++;
			if (_M[i] != 1)
				_M[i] = 0;
			else
				check_up = false;
		}
	}

	cout << "stage 0 >" << endl;
	cout << "A 레지스터 : ";
	for (int i = 0; i < 32; i++) {
		cout << A[i];
		if (i % 4 == 3)
			cout << " ";
	}

	cout << endl << "Q 레지스터 : ";
	for (int i = 0; i < 32; i++) {
		if (bin_num2[i] == '1')
			Q[i] = 1;
		else
			Q[i] = 0;
		cout << Q[i];
		if (i % 4 == 3)
			cout << " ";
	}

	cout << endl << "Q-1 레지스터 초기값 : 0";

	cout << endl << "M 레지스터 : ";
	for (int i = 0; i < 32; i++) {
		if (bin_num1[i] == '1')
			M[i] = 1;
		else
			M[i] = 0;
		cout << bin_num1[i];
		if (i % 4 == 3)
			cout << " ";
	}

	/*   //M의보수
	   for (int i = 0; i < 32; i++)
		  cout << _M[i] << endl << endl;
	   for (int i = 0; i < 32; i++)    cout<<"Q " << Q[i];
	   cout <<endl<< "q의 첫자리  "<<Q[31] << endl;
	*/
	cout << endl << endl;
	for (int i = 0; i < 32; i++) {

		int* add = NULL;

		cout << "stage " << i + 1 << " >" << endl;

		if (Q[31] == 1 && minus_q == 0) {  //Q의 마지막이랑, Q0가 10 이면 빼기.

			cout << "A <- A - M" << endl;
			add = _M;
		}
		else if (Q[31] == 0 && minus_q == 1) { //Q의 마지막이랑, Q0가 01 이면 더하기.
			cout << "A <- A + M" << endl;
			add = M;
		}
		if (add != NULL) {
			int carry = 0;
			for (int j = 31; j >= 0; j--) { //최하위비트부터 거꾸로 연산
				A[j] += add[j] + carry; //A에 더함 
				if (A[j] > 1) { //더한 결과값이 1보다 크면, 
					carry = 1; //올림수 존재
					A[j] %= 2; //A는 2로 나눈 나머지를 가짐. 0을 가지면 된다고 생각
				}
				else {
					carry = 0;
				}

				if (j == 0) { //최상위비트 캐리값
					in_carry = carry;
				}
				else if (j == 1) { //그다음비트 캐리값. 이따 V플래그 계산때 사용
					out_carry = carry;
				}
			}
			// 덧셈과정 for문 닫기 
			//  

			//cout << i + 1 << "번째 곱셈 계산 : ";
			cout << "A 레지스터 : ";
			for (int k = 0; k < 32; k++) {
				cout << A[k];
				if (k % 4 == 3)
					cout << " ";
			}
			cout << endl;
		}

		// 그 외의 00, 11은 넘기기만 하니까 고려 하지 않는다.

		//shift연산 수행
		for (int j = 31; j >= 0; j--) {
			if (j != 31) { //끝자리가 아니면 
				Q[j + 1] = Q[j]; //현재 자릿수를 뒤로 한칸 미룬다 
			}
			else
				minus_q = Q[j]; //끝자리면 버려지는 값 
		}
		for (int j = 31; j >= 0; j--) {
			if (j != 31) {
				A[j + 1] = A[j]; //A레지스터 값을 우측으로 한칸 이동 
			}
			else
				Q[0] = A[j]; //A의 버려지는 값은 mbinary의 최상단으로 
		}
		//산술적 연산이므로, 0번째 배열 값은 그대로 둔다

		cout << "우측 shift 수행" << endl;

		cout << "A 레지스터  Q 레지스터 : ";
		for (int j = 0; j < 32; j++) {
			cout << A[j];
		}
		cout << " ";
		for (int j = 0; j < 32; j++) {
			cout << Q[j];
		}
		cout << endl << "Q-1 레지스터 : " << minus_q << endl;

		for (int i = 0; i < 32; i++) {
			if (A[0] != 0 && z_check) {
				z_check = false;
				break;
			}
		}
		for (int i = 0; i < 32; i++) {
			if (bin_num2[i] != 0 && z_check) {
				z_check = false;
				break;
			}
		}
		cout << "C 플래그 : " << in_carry << endl; //최상위 캐리값
		cout << "S 플래그 : " << A[0] << endl;
		cout << "Z 플래그 : ";
		if (z_check)
			cout << "1" << endl;
		else
			cout << "0" << endl;

		cout << "V 플래그 : ";
		if (in_carry ^ out_carry) //xor 계산
			cout << "1" << endl;
		else
			cout << "0" << endl;
		cout << endl << endl;

	}

	long long answer = 0; // 최대값이 2^32 * 2^32 일 수 있으므로 long long 사용 

	for (int i = 0; i < 32; i++) {
		answer *= 2;
		answer += A[i];
	}
	for (int i = 0; i < 32; i++) {
		answer *= 2;
		answer += Q[i]; //10진수로 변환 
	}

	cout << "최종 곱셈 10진수 결과값 : " << answer << endl;
	/*
	   for (int i = 0; i < 32; i++) {
		  if (A[0] != 0 && z_check) {
			 z_check = false;
			 break;
		  }
	   }
	   for (int i = 0; i < 32; i++) {
		  if (mbinary[1][i] != 0 && z_check) {
			 z_check = false;
			 break;
		  }
	   }


	   cout << "C 플래그 : " << in_carry << endl; //최상위 캐리값
	   cout << "S 플래그 : " << A[0] << endl;
	   cout << "Z 플래그 : ";
	   if (z_check)
		  cout << "1" << endl;
	   else
		  cout << "0" << endl;

	   cout << "V 플래그 : ";
	   if (in_carry^out_carry) //xor 계산
		  cout << "1" << endl;
	   else
		  cout << "0" << endl;
	*/
}

// divide two num
void divider(int num1, int num2) { // num1 / num2
	if (num2 == 0) {
		cout << "0으로는 나눌 수 없습니다." << endl;
		return;
	}
	string A;
	string Q;
	string M;
	int count = MAX_BIT; // 계수

	string bin_num1 = binary(num1); // reverse된 string이 들어감. 
	string bin_num2 = binary(num2); // reverse된 string이 들어감.
	A = bin_num1;  // 부호비트 ==> A[MAX_BIT - 1]
	Q = bin_num1; // 부호비트 ==> Q[MAX_BIT - 1]
	M = bin_num2; // 부호비트 ==> M[MAX_BIT - 1]

	for (int i = 0; i < MAX_BIT; i++) {
		A[i] = Q[MAX_BIT - 1]; // Q의 부호비트로 A를 Set함.
	}
	cout << "=================== < 초기상태 > ===================" << endl;
	cout << "A 레지스터 : " << reverse_str(A) << endl;
	cout << "Q 레지스터 : " << reverse_str(Q) << endl;
	cout << "M 레지스터 : " << reverse_str(M) << endl << endl;
	
	char A_sign = '0';
	string past_A; // A에 복원할 때 A에 대입하기 위한 값

	while (count > 0) {
		cout << "=================== < " << (MAX_BIT - count + 1) <<
			"번째 loop > ===================" << endl;

		cout << "< Left Shift >" << endl;
		left_shift(A, Q);

		cout << "A 레지스터 : " << reverse_str(A) << endl;
		cout << "Q 레지스터 : " << reverse_str(Q) << endl << endl;

		A_sign = A[MAX_BIT - 1];
		count--;

		if (A[MAX_BIT - 1] == M[MAX_BIT - 1]) { // A의 부호와 M의 부호가 같음. ==> A = A - M
			cout << "< A = A - M >" << endl;
			past_A = A;
			A = subtractor(decimal(A), decimal(M));
			cout << endl;

			cout << "A 레지스터 : " << reverse_str(A) << endl << endl;
		}
		else { // A의 부호와 M의 부호가 다름. ==> A = A + M. 
			cout << "< A = A + M >" << endl;
			past_A = A;
			A = adder(decimal(A), decimal(M));
			cout << endl;

			cout << "A 레지스터 : " << reverse_str(A) << endl << endl;
		}

		if (A_sign == A[MAX_BIT - 1]) {
			cout << "< Q[0] = 1 >" << endl;
			Q[0] = '1';
		}
		else { 
			string temp_Q = Q.substr(MAX_BIT - count);
			if (is_zero(A) && is_zero(temp_Q)) { // A와 Q가 전부 0 ==> Q[0] = 1
				cout << "< Q[0] = 1 >" << endl;
				Q[0] = '1';
			}
			else {
				cout << "< Restore >" << endl;
				A = past_A;
			}
		}
		cout << "A 레지스터 : " << reverse_str(A) << endl;
		cout << "Q 레지스터 : " << reverse_str(Q) << endl << endl;
	}

	string quotient = ""; // 몫
	string remainder = ""; // 나머지
	
	if(bin_num1[MAX_BIT - 1] == bin_num2[MAX_BIT - 1]){
		quotient = Q;
		remainder = A;

		cout << "나머지 : " << reverse_str(remainder) << " ==> " << decimal(remainder) << endl;
		cout << "몫 : " << reverse_str(quotient) << " ==> " << decimal(quotient) << endl;
	}
	else {
		quotient = euibosu(Q);
		remainder = A;

		cout << "나머지 : " << reverse_str(remainder) << " ==> " << decimal(remainder) << endl;
		cout << "몫 : " << reverse_str(quotient) << " ==> " << decimal(quotient) << endl;
	}
}