#include<stdio.h>
#include"CPUThinking.h"
#pragma warning(disable:4996)
#include<Windows.h>

/*
”Õ–Ê•Ï”
board[9]
‚O‚P‚Q
‚R‚S‚T
‚U‚V‚W

board[n]
ZF‚P
~F|‚P
@F‚O
 ƒfƒtƒHƒ‹ƒgF‚O
*/
int board[9];

//Ÿ”s@[‚PF~@‚OF‰½‚à‚È‚µ@‚PFZ
int check_winner() {
	for(int i=0;i<3;i++){//‰¡
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 3) { return 1; }
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == -3) { return -1; }
	}
	for(int i=0;i<3;i++){//c
		if (board[0 + i] + board[3 + i] + board[6 + i] == 3) { return 1; }
		if (board[0 + i] + board[3 + i] + board[6 + i] == -3) { return -1; }
	}
	if (board[0] + board[4] + board[8] == 3) { return 1; }//‚È‚È‚ß
	if (board[0] + board[4] + board[8] == -3) { return -1; }//‚È‚È‚ß
	if (board[2] + board[4] + board[6] == 3) { return 1; }//‚È‚È‚ß
	if (board[2] + board[4] + board[6] == -3) { return -1; }//‚È‚È‚ß

	return 0;
}

//ƒ†[ƒU[‚ÍZ
void UserMaru() {
	int input;
	printf("Z‚ğ’u‚­ˆÊ’u‚ğ‚PŸŒ³”z—ñ‚Ì”Õ–Ê“Y‚¦š‚Åw’è‚µ‚Ä‚­‚¾‚³‚¢B\n");
	scanf("%d", &input);
	if(board[input]!=0){//Šù‚É‚»‚ÌêŠ‚ª–„‚Ü‚Á‚Ä‚¢‚½‚ç
		printf("‚»‚ÌêŠ‚ÍŠù‚Ég—p‚³‚ê‚Ä‚¢‚Ü‚·BÄs‚µ‚Ä‚­‚¾‚³‚¢B\n\n");
		UserMaru();
		return;
	}
	board[input] = 1;
	return;
}

//•`‰æ
void Draw() {
	printf("E«««\n");
	for (int i = 0; i < 9; i++) {
		if (i == 0 || i == 3 || i == 6) { printf("¨"); }
		if (board[i] == 0) { printf("@"); }
		if (board[i] == 1) { printf("Z"); }
		if (board[i] == -1) { printf("~"); }

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
	for (int i = 0; i < 9; i++) { board[i] = 0;}//”Õ–Ê‰Šú‰»
	printf("\n------------------------------------------\n------------------------------------------\n              ‘æ%d‰ñí\n------------------------------------------\n------------------------------------------\n", turn);

	for(int i=0;i<9;i++){//ƒƒCƒ“ƒ‹[ƒ`ƒ“
		printf("\n\n%dè–Ú‘Ò‚¿\n------------------------------------------\n", i+1);
		Draw();//•`‰æ
		if (check_winner() != 0) {//Ÿ”s‚ª‚Â‚¢‚½‚ç
			break;
		}
		if(i%2==0){//æè
			CPU(-1);
		}
		if(i%2==1){//Œãè
			//UserMaru();
			CPU(1);
		}
	}

	printf("\n------------------------------------------\n------------------------------------------\n");
	Draw();
	if (check_winner() == 1) { 
		MaruWin++;
		printf("Z‚ÌŸ‚¿I\n");
	}
	if (check_winner() == -1) { 
		BatuWin++;
		printf("~‚ÌŸ‚¿I\n"); 
	}
	if (check_winner() == 0) { 
		Same++;
		printf("ˆø‚«•ª‚¯I\n"); 
	}

	
	turn++;
	if (turn < 1000 && MaruWin==0) { main(); }

	printf("\n------------------------------------------\n");
	printf("\n1000‰ñŸ•‰‚µ‚½A‚à‚µ‚­‚ÍŒãè‚ÌZ‚ªŸ‚Á‚½‚Ì‚Å‚¨’m‚ç‚¹‚µ‚Ü‚·II\n");
	printf("Z‚ÌŸ‚¿I %d‰ñ–Ú\n", MaruWin);
	printf("~‚ÌŸ‚¿I %d‰ñ–Ú\n", BatuWin);
	printf("ˆø‚«•ª‚¯I@%d‰ñ–Ú\n", Same);
	printf("\n‚±‚ê‚É‚Ä‡‚ÍI—¹‚µ‚Ü‚·B\n");
	

	int hoge;
	scanf("%d", &hoge);
}