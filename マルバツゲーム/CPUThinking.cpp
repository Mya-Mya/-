#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<Windows.h>
/*
�l�H�m�\�Ŏ��ɒu���ʒu�����߂�
*/
extern int board[9];
int MySide;//�P���Z�B�|�P���~�B*1�Ŏ����A*-1�ő���B
int CPUThought[9];//�l�H�m�\���~��u����Ă��s���]���l�ϐ�

/*
�����_���ɒu���ꏊ���Ă���v�l�G���W��
*/
void PutRnd(){
	Sleep(1);
	srand((unsigned)time(NULL));
	CPUThought[rand() % 9] ++;//�]���l�͂P
}

/*
�������������J���Ă����疄�߂�悤��Ă���v�l�G���W��
*/
void PutCenter() {
	if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 1; }//�]���l�͂P
}

/*
���肪�Q�A�ŕ���������������c��̂Ƃ���ɓ����v�l�G���W��
*/
void PutRestToPreventLose() {
	for (int i = 0; i<3; i++) {//��
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == -2*MySide) {//�����\��
			for (int j = 0; j < 3; j++) {
				if (board[i * 3 + j] == 0) { CPUThought[i * 3 + j] = CPUThought[i * 3 + j] + 10; }//�]���l�͂P�O
			}
		}
	}
	for (int i = 0; i<3; i++) {//�c
		if (board[i] + board[3+i] + board[6+i] == -2 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[j * 3 + i] == 0) { CPUThought[j * 3 + i] = CPUThought[j * 3 + i] + 10; }//�]���l�͂P�O
			}
		}
	}
	if (board[0] + board[4] + board[8] == -2 * MySide) {//�ȂȂ�
		if (board[0] == 0) { CPUThought[0] = CPUThought[0] + 10; }//�]���l�͂P�O
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 10; }//�]���l�͂P�O
		if (board[8] == 0) { CPUThought[8] = CPUThought[8] + 10; }//�]���l�͂P�O
	}
	if (board[2] + board[4] + board[6] == -2 * MySide) {//�ȂȂ�
		if (board[2] == 0) { CPUThought[2] = CPUThought[2] + 10; }//�]���l�͂P�O
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 10; }//�]���l�͂P�O
		if (board[6] == 0) { CPUThought[6] = CPUThought[6] + 10; }//�]���l�͂P�O
	}
}

/*
�������Q�A�ŏ���������������c��̂Ƃ���ɓ����v�l�G���W��
*/
void PutRestToWin() {
	for (int i = 0; i<3; i++) {//��
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 2 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[i * 3 + j] == 0) { CPUThought[i * 3 + j] = CPUThought[i * 3 + j] + 20; }//�]���l�͂Q�O
			}
		}
	}
	for (int i = 0; i<3; i++) {//�c
		if (board[i] + board[3 + i] + board[6 + i] == 2 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[j * 3 + i] == 0) { CPUThought[j * 3 + i] = CPUThought[j * 3 + i] + 20; }//�]���l�͂Q�O
			}
		}
	}
	if (board[0] + board[4] + board[8] == 2 * MySide) {//�ȂȂ�
		if (board[0] == 0) { CPUThought[0] = CPUThought[0] + 20; }//�]���l�͂Q�O
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 20; }//�]���l�͂Q�O
		if (board[8] == 0) { CPUThought[8] = CPUThought[8] + 20; }//�]���l�͂Q�O
	}
	if (board[2] + board[4] + board[6] == 2 * MySide) {//�ȂȂ�
		if (board[2] == 0) { CPUThought[2] = CPUThought[2] + 20; }//�]���l�͂Q�O
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 20; }//�]���l�͂Q�O
		if (board[6] == 0) { CPUThought[6] = CPUThought[6] + 20; }//�]���l�͂Q�O
	}
}

/*
����+�Q�A���܂肾�����炢����̗]��ɓ����
*/
void PutTwoes() {
	for (int i = 0; i<3; i++) {//��
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 1 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[i * 3 + j] == 0) { CPUThought[i * 3 + j] = CPUThought[i * 3 + j] + 2; }//�]���l�͂Q
			}
		}
	}
	for (int i = 0; i<3; i++) {//�c
		if (board[i] + board[3 + i] + board[6 + i] == 1 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[j * 3 + i] == 0) { CPUThought[j * 3 + i] = CPUThought[j * 3 + i] + 2; }//�]���l�͂Q
			}
		}
	}
	if (board[0] + board[4] + board[8] == 1 * MySide) {//�ȂȂ�
		if (board[0] == 0) { CPUThought[0] = CPUThought[0] + 2; }//�]���l�͂Q
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 2; }//�]���l�͂Q
		if (board[8] == 0) { CPUThought[8] = CPUThought[8] + 2; }//�]���l�͂Q
	}
	if (board[2] + board[4] + board[6] == 1 * MySide) {//�ȂȂ�
		if (board[2] == 0) { CPUThought[2] = CPUThought[2] + 2; }//�]���l�͂Q
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 2; }//�]���l�͂Q
		if (board[6] == 0) { CPUThought[6] = CPUThought[6] + 2; }//�]���l�͂Q
	}
}

int max = 0;//�ŏI�I�ȁ~��u���ꏊ��]���l�ƂƂ��ɔ��f����ϐ�
/*
�ǂ��ɒu�������߂�
*/
void DecideWhereToPut() {
	
	for (int i = 0; i < 9; i++) {
		if (CPUThought[max] < CPUThought[i]) {//���Y�]���l���ő傾������
			if(board[i]==0){//�J���Ă�����
				max = i;
			}
		}
	}
	if (board[max] != 0) {
		/*���܂�Ȃ��ꍇ�̓����_���Ŏw��*/
		int randtmp;
		while (1) {
			srand((unsigned)time(NULL));
			randtmp = rand() % 9;
			if (board[randtmp] == 0) { 
				max = randtmp; 
				break;
			}
		}
		return;
	}
	return;
}


void CPU(int inputSide) {
	MySide = inputSide;

	/*�ϐ��̏�����*/
	max = 0;
	for (int i = 0; i < 9; i++) { CPUThought[i] = 0; }

	/*�e��v�l�G���W��*/
	PutRnd();
	PutCenter();
	PutRestToPreventLose();
	PutRestToWin();
	PutTwoes();

	/*�ǂ��ɒu�������߂�*/
	DecideWhereToPut();

	/*�u��*/
	board[max]=MySide;
}