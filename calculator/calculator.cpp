#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long int num1, num2;
// int sel;
const int MAX_BIT = 32; // ���������� ���̸�ŭ
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
		cout << "ù ��° ���� �Է��ϼ��� : ";
		cin >> num1;

		if (num1 > INT_MAX) {
			cout << "input overflow!" << endl;
			continue;
		}
		else if (num1 < INT_MIN) {
			cout << "input underflow!" << endl;
			continue;
		}

		cout << "�� ��° ���� �Է��ϼ��� : ";
		cin >> num2;
		if (num2 > INT_MAX) {
			cout << "input overflow!" << endl;
			continue;
		}
		else if (num2 < INT_MIN) {
			cout << "input underflow!" << endl;
			continue;
		}

		cout << "======================= < ���� > =======================" << endl;
		result_bin = adder(num1, num2);
		if (result_bin == "of") {
			cout << "result.........overflow" << endl << endl;
		}
		else {
			result = decimal(result_bin);
			cout << "result : \t" << result << endl << endl;
		}

		cout << "======================= < ���� > =======================" << endl;
		result_bin = subtractor(num1, num2);
		if (result_bin == "of") {
			cout << "result.........overflow" << endl << endl;
		}
		else {
			result = decimal(result_bin);
			cout << "result : \t" << result << endl << endl;
		}

		cout << "======================= < ���� > =======================" << endl;
		multiplicator(num1, num2);

		cout << "======================= < ������ > =======================" << endl;
		divider(num1, num2);
		cout << endl;

		cout << "�ٽ� �Ͻðڽ��ϱ�?(y/n) : ";
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

string reverse_str(string reverse_str) { // ���ڷ� �Է��� ���ڿ��� reverse ���ڿ��� return.
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
		bin_num += "0"; // reverse()��Ű�� �ֻ��� ��ȣ��Ʈ�� ��.
		while (bin_num.length() < MAX_BIT) { // �ֻ������� ������ ��Ʈ���� 0���� ����.
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

string euibosu(string input) { // reverse�� input
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

int is_zero(string input) { // Z Flag �Ǻ�
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
	// reverse�� string�� ����.
	
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
	
	// tmp�� �ܼ� �����ֱ�� 
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

	cout << "Flag �� ==> " << "C : " << C << ", S : " << S <<
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
	bool z_flag[2]; //���߿� ���� 
	bool sign[2]; // ��ȣ üũ��
	z_flag[0] = false;
	z_flag[1] = false;
	bool z_check = true; // true�̸� 0

	string bin_num1 = binary(num1);
	string bin_num2 = binary(num2);

	reverse(bin_num1.begin(), bin_num1.end());
	// cout << "num1_bin:\t" << bin_num1 << endl;
	reverse(bin_num2.begin(), bin_num2.end());
	// cout << "num2_bin:\t" << bin_num2 << endl;

	/*
	   cout << "�ǽ¼� : "; //���ڰ��� �Է¹���
	   cin >> input[0];
	   cout << "�¼� : ";
	   cin >> input[1];

	   sign[0] = false; // false�� ���
	   sign[1] = false;

	   while (getchar() != '\n');

	   for (int i = 0; i < 2; i++) {
		  if (input[i].at(0) == '-') { //��ȣ üũ
		  //ù ���ڰ� -�̸�..
			 sign[i] = true; //������� ��
		  }
		  for (int j = 0; j < 32; j++) {
			 mbinary[i][j] = 0; //�ϴ� 0���� �ʱ�ȭ
		  }
	   }
	   int temp = 0; //�ӽ� ���尪. (�Է��� ���� int������ ǥ���ȴٰ� ����, ���꿡 ���Ǵ� �������� ���̰� 32��Ʈ��� �����Ǿ� �����Ƿ�.)

	   for (int i = 0; i < 2; i++) {
		  if (!sign[i]) { //����̸�, �״�� ��ȯ
			 temp = atoi(input[i].c_str());

		  }
		  else { //�����̸�, ��ȣ ���� �� �޾ƿ�.
			 temp = atoi(input[i].substr(1).c_str());

		  }

		  for (int j = 31; j > 0; j--) { //0�� �ε����� ��ȣ��.
			 mbinary[i][j] = temp % 2;
			 temp /= 2;
		  }

		  if (sign[i]) { //�����̸� ������ ����
			 bool check_up = true; //2�� �������� ���� �ø���, ���̸� �ø�


			 for (int j = 31; j >= 0; j--) {
				if (mbinary[i][j] == 0)
				   mbinary[i][j] = 1;
				else
				   mbinary[i][j] = 0;   //�ϴ� 1�� ���� ������.

				if (check_up) { //���� �ڿ��� �ø����� �ö���� �� ����. 2�� ������ �ٲ��ֱ� ����
				   mbinary[i][j]++;

				   if (mbinary[i][j] != 1) //������Ų���� 1�� �ƴ�.
					  mbinary[i][j] = 0; // 2�� �Ǿ��� ���̹Ƿ� 0���� �ٲٰ� �ø�����
				   else //1�̶��
					  check_up = false; //false�� ����
				}
			 }
		  }
	   }*/

	int minus_q = 0; //q0�� 
	int A[32] = {}; //��꿡 Ȱ���� �������� A
	int M[32] = {};
	int Q[32] = {};
	int in_carry = 0;
	int out_carry = 0;

	int _M[32]; //��꿡 ����� m�� ����, ���� ��İ� ����.
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
	cout << "A �������� : ";
	for (int i = 0; i < 32; i++) {
		cout << A[i];
		if (i % 4 == 3)
			cout << " ";
	}

	cout << endl << "Q �������� : ";
	for (int i = 0; i < 32; i++) {
		if (bin_num2[i] == '1')
			Q[i] = 1;
		else
			Q[i] = 0;
		cout << Q[i];
		if (i % 4 == 3)
			cout << " ";
	}

	cout << endl << "Q-1 �������� �ʱⰪ : 0";

	cout << endl << "M �������� : ";
	for (int i = 0; i < 32; i++) {
		if (bin_num1[i] == '1')
			M[i] = 1;
		else
			M[i] = 0;
		cout << bin_num1[i];
		if (i % 4 == 3)
			cout << " ";
	}

	/*   //M�Ǻ���
	   for (int i = 0; i < 32; i++)
		  cout << _M[i] << endl << endl;
	   for (int i = 0; i < 32; i++)    cout<<"Q " << Q[i];
	   cout <<endl<< "q�� ù�ڸ�  "<<Q[31] << endl;
	*/
	cout << endl << endl;
	for (int i = 0; i < 32; i++) {

		int* add = NULL;

		cout << "stage " << i + 1 << " >" << endl;

		if (Q[31] == 1 && minus_q == 0) {  //Q�� �������̶�, Q0�� 10 �̸� ����.

			cout << "A <- A - M" << endl;
			add = _M;
		}
		else if (Q[31] == 0 && minus_q == 1) { //Q�� �������̶�, Q0�� 01 �̸� ���ϱ�.
			cout << "A <- A + M" << endl;
			add = M;
		}
		if (add != NULL) {
			int carry = 0;
			for (int j = 31; j >= 0; j--) { //��������Ʈ���� �Ųٷ� ����
				A[j] += add[j] + carry; //A�� ���� 
				if (A[j] > 1) { //���� ������� 1���� ũ��, 
					carry = 1; //�ø��� ����
					A[j] %= 2; //A�� 2�� ���� �������� ����. 0�� ������ �ȴٰ� ����
				}
				else {
					carry = 0;
				}

				if (j == 0) { //�ֻ�����Ʈ ĳ����
					in_carry = carry;
				}
				else if (j == 1) { //�״�����Ʈ ĳ����. �̵� V�÷��� ��궧 ���
					out_carry = carry;
				}
			}
			// �������� for�� �ݱ� 
			//  

			//cout << i + 1 << "��° ���� ��� : ";
			cout << "A �������� : ";
			for (int k = 0; k < 32; k++) {
				cout << A[k];
				if (k % 4 == 3)
					cout << " ";
			}
			cout << endl;
		}

		// �� ���� 00, 11�� �ѱ�⸸ �ϴϱ� ��� ���� �ʴ´�.

		//shift���� ����
		for (int j = 31; j >= 0; j--) {
			if (j != 31) { //���ڸ��� �ƴϸ� 
				Q[j + 1] = Q[j]; //���� �ڸ����� �ڷ� ��ĭ �̷�� 
			}
			else
				minus_q = Q[j]; //���ڸ��� �������� �� 
		}
		for (int j = 31; j >= 0; j--) {
			if (j != 31) {
				A[j + 1] = A[j]; //A�������� ���� �������� ��ĭ �̵� 
			}
			else
				Q[0] = A[j]; //A�� �������� ���� mbinary�� �ֻ������ 
		}
		//����� �����̹Ƿ�, 0��° �迭 ���� �״�� �д�

		cout << "���� shift ����" << endl;

		cout << "A ��������  Q �������� : ";
		for (int j = 0; j < 32; j++) {
			cout << A[j];
		}
		cout << " ";
		for (int j = 0; j < 32; j++) {
			cout << Q[j];
		}
		cout << endl << "Q-1 �������� : " << minus_q << endl;

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
		cout << "C �÷��� : " << in_carry << endl; //�ֻ��� ĳ����
		cout << "S �÷��� : " << A[0] << endl;
		cout << "Z �÷��� : ";
		if (z_check)
			cout << "1" << endl;
		else
			cout << "0" << endl;

		cout << "V �÷��� : ";
		if (in_carry ^ out_carry) //xor ���
			cout << "1" << endl;
		else
			cout << "0" << endl;
		cout << endl << endl;

	}

	long long answer = 0; // �ִ밪�� 2^32 * 2^32 �� �� �����Ƿ� long long ��� 

	for (int i = 0; i < 32; i++) {
		answer *= 2;
		answer += A[i];
	}
	for (int i = 0; i < 32; i++) {
		answer *= 2;
		answer += Q[i]; //10������ ��ȯ 
	}

	cout << "���� ���� 10���� ����� : " << answer << endl;
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


	   cout << "C �÷��� : " << in_carry << endl; //�ֻ��� ĳ����
	   cout << "S �÷��� : " << A[0] << endl;
	   cout << "Z �÷��� : ";
	   if (z_check)
		  cout << "1" << endl;
	   else
		  cout << "0" << endl;

	   cout << "V �÷��� : ";
	   if (in_carry^out_carry) //xor ���
		  cout << "1" << endl;
	   else
		  cout << "0" << endl;
	*/
}

// divide two num
void divider(int num1, int num2) { // num1 / num2
	if (num2 == 0) {
		cout << "0���δ� ���� �� �����ϴ�." << endl;
		return;
	}
	string A;
	string Q;
	string M;
	int count = MAX_BIT; // ���

	string bin_num1 = binary(num1); // reverse�� string�� ��. 
	string bin_num2 = binary(num2); // reverse�� string�� ��.
	A = bin_num1;  // ��ȣ��Ʈ ==> A[MAX_BIT - 1]
	Q = bin_num1; // ��ȣ��Ʈ ==> Q[MAX_BIT - 1]
	M = bin_num2; // ��ȣ��Ʈ ==> M[MAX_BIT - 1]

	for (int i = 0; i < MAX_BIT; i++) {
		A[i] = Q[MAX_BIT - 1]; // Q�� ��ȣ��Ʈ�� A�� Set��.
	}
	cout << "=================== < �ʱ���� > ===================" << endl;
	cout << "A �������� : " << reverse_str(A) << endl;
	cout << "Q �������� : " << reverse_str(Q) << endl;
	cout << "M �������� : " << reverse_str(M) << endl << endl;
	
	char A_sign = '0';
	string past_A; // A�� ������ �� A�� �����ϱ� ���� ��

	while (count > 0) {
		cout << "=================== < " << (MAX_BIT - count + 1) <<
			"��° loop > ===================" << endl;

		cout << "< Left Shift >" << endl;
		left_shift(A, Q);

		cout << "A �������� : " << reverse_str(A) << endl;
		cout << "Q �������� : " << reverse_str(Q) << endl << endl;

		A_sign = A[MAX_BIT - 1];
		count--;

		if (A[MAX_BIT - 1] == M[MAX_BIT - 1]) { // A�� ��ȣ�� M�� ��ȣ�� ����. ==> A = A - M
			cout << "< A = A - M >" << endl;
			past_A = A;
			A = subtractor(decimal(A), decimal(M));
			cout << endl;

			cout << "A �������� : " << reverse_str(A) << endl << endl;
		}
		else { // A�� ��ȣ�� M�� ��ȣ�� �ٸ�. ==> A = A + M. 
			cout << "< A = A + M >" << endl;
			past_A = A;
			A = adder(decimal(A), decimal(M));
			cout << endl;

			cout << "A �������� : " << reverse_str(A) << endl << endl;
		}

		if (A_sign == A[MAX_BIT - 1]) {
			cout << "< Q[0] = 1 >" << endl;
			Q[0] = '1';
		}
		else { 
			string temp_Q = Q.substr(MAX_BIT - count);
			if (is_zero(A) && is_zero(temp_Q)) { // A�� Q�� ���� 0 ==> Q[0] = 1
				cout << "< Q[0] = 1 >" << endl;
				Q[0] = '1';
			}
			else {
				cout << "< Restore >" << endl;
				A = past_A;
			}
		}
		cout << "A �������� : " << reverse_str(A) << endl;
		cout << "Q �������� : " << reverse_str(Q) << endl << endl;
	}

	string quotient = ""; // ��
	string remainder = ""; // ������
	
	if(bin_num1[MAX_BIT - 1] == bin_num2[MAX_BIT - 1]){
		quotient = Q;
		remainder = A;

		cout << "������ : " << reverse_str(remainder) << " ==> " << decimal(remainder) << endl;
		cout << "�� : " << reverse_str(quotient) << " ==> " << decimal(quotient) << endl;
	}
	else {
		quotient = euibosu(Q);
		remainder = A;

		cout << "������ : " << reverse_str(remainder) << " ==> " << decimal(remainder) << endl;
		cout << "�� : " << reverse_str(quotient) << " ==> " << decimal(quotient) << endl;
	}
}