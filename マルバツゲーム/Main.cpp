#include<stdio.h>
#include"CPUThinking.h"
#pragma warning(disable:4996)
#include<Windows.h>

/*
�Ֆʕϐ�
board[9]
�O�P�Q
�R�S�T
�U�V�W

board[n]
�Z�F�P
�~�F�|�P
�@�F�O
 �f�t�H���g�F�O
*/
int board[9];

//���s�@�[�P�F�~�@�O�F�����Ȃ��@�P�F�Z
int check_winner() {
	for(int i=0;i<3;i++){//��
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 3) { return 1; }
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == -3) { return -1; }
	}
	for(int i=0;i<3;i++){//�c
		if (board[0 + i] + board[3 + i] + board[6 + i] == 3) { return 1; }
		if (board[0 + i] + board[3 + i] + board[6 + i] == -3) { return -1; }
	}
	if (board[0] + board[4] + board[8] == 3) { return 1; }//�ȂȂ�
	if (board[0] + board[4] + board[8] == -3) { return -1; }//�ȂȂ�
	if (board[2] + board[4] + board[6] == 3) { return 1; }//�ȂȂ�
	if (board[2] + board[4] + board[6] == -3) { return -1; }//�ȂȂ�

	return 0;
}

//���[�U�[�́Z
void UserMaru() {
	int input;
	printf("�Z��u���ʒu���P�����z��̔ՖʓY�����Ŏw�肵�Ă��������B\n");
	scanf("%d", &input);
	if(board[input]!=0){//���ɂ��̏ꏊ�����܂��Ă�����
		printf("���̏ꏊ�͊��Ɏg�p����Ă��܂��B�Ď��s���Ă��������B\n\n");
		UserMaru();
		return;
	}
	board[input] = 1;
	return;
}

//�`��
void Draw() {
	printf("�E������\n");
	for (int i = 0; i < 9; i++) {
		if (i == 0 || i == 3 || i == 6) { printf("��"); }
		if (board[i] == 0) { printf("�@"); }
		if (board[i] == 1) { printf("�Z"); }
		if (board[i] == -1) { printf("�~"); }

		if (i == 2 || i == 5 || i == 8) { printf("\n"); }
	}
	printf("\n");
	return;
}

int turn = 1;
int MaruWin = 0;
int BatuWin = 0;
int Same = 0;
int main() {
	for (int i = 0; i < 9; i++) { board[i] = 0;}//�Ֆʏ�����
	printf("\n------------------------------------------\n------------------------------------------\n              ��%d���\n------------------------------------------\n------------------------------------------\n", turn);

	for(int i=0;i<9;i++){//���C�����[�`��
		printf("\n\n%d��ڑ҂�\n------------------------------------------\n", i+1);
		Draw();//�`��
		if (check_winner() != 0) {//���s��������
			break;
		}
		if(i%2==0){//���
			CPU(-1);
		}
		if(i%2==1){//���
			//UserMaru();
			CPU(1);
		}
	}

	printf("\n------------------------------------------\n------------------------------------------\n");
	Draw();
	if (check_winner() == 1) { 
		MaruWin++;
		printf("�Z�̏����I\n");
	}
	if (check_winner() == -1) { 
		BatuWin++;
		printf("�~�̏����I\n"); 
	}
	if (check_winner() == 0) { 
		Same++;
		printf("���������I\n"); 
	}

	
	turn++;
	if (turn < 1000 && MaruWin==0) { main(); }

	printf("\n------------------------------------------\n");
	printf("\n1000�񏟕������A�������͌��́Z���������̂ł��m�点���܂��I�I\n");
	printf("�Z�̏����I %d���\n", MaruWin);
	printf("�~�̏����I %d���\n", BatuWin);
	printf("���������I�@%d���\n", Same);
	printf("\n����ɂĎ����͏I�����܂��B\n");
	

	int hoge;
	scanf("%d", &hoge);
}