#include<stdio.h>
#include"CPUThinking.h"
#pragma warning(disable:4996)
#include<Windows.h>

/*
盤面変数
board[9]
０１２
３４５
６７８

board[n]
〇：１
×：−１
　：０
 デフォルト：０
*/
int board[9];

//勝敗　ー１：×　０：何もなし　１：〇
int check_winner() {
	for(int i=0;i<3;i++){//横
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 3) { return 1; }
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == -3) { return -1; }
	}
	for(int i=0;i<3;i++){//縦
		if (board[0 + i] + board[3 + i] + board[6 + i] == 3) { return 1; }
		if (board[0 + i] + board[3 + i] + board[6 + i] == -3) { return -1; }
	}
	if (board[0] + board[4] + board[8] == 3) { return 1; }//ななめ
	if (board[0] + board[4] + board[8] == -3) { return -1; }//ななめ
	if (board[2] + board[4] + board[6] == 3) { return 1; }//ななめ
	if (board[2] + board[4] + board[6] == -3) { return -1; }//ななめ

	return 0;
}

//ユーザーは〇
void UserMaru() {
	int input;
	printf("〇を置く位置を１次元配列の盤面添え字で指定してください。\n");
	scanf("%d", &input);
	if(board[input]!=0){//既にその場所が埋まっていたら
		printf("その場所は既に使用されています。再試行してください。\n\n");
		UserMaru();
		return;
	}
	board[input] = 1;
	return;
}

//描画
void Draw() {
	printf("・↓↓↓\n");
	for (int i = 0; i < 9; i++) {
		if (i == 0 || i == 3 || i == 6) { printf("→"); }
		if (board[i] == 0) { printf("　"); }
		if (board[i] == 1) { printf("〇"); }
		if (board[i] == -1) { printf("×"); }

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
	for (int i = 0; i < 9; i++) { board[i] = 0;}//盤面初期化
	printf("\n------------------------------------------\n------------------------------------------\n              第%d回戦\n------------------------------------------\n------------------------------------------\n", turn);

	for(int i=0;i<9;i++){//メインルーチン
		printf("\n\n%d手目待ち\n------------------------------------------\n", i+1);
		Draw();//描画
		if (check_winner() != 0) {//勝敗がついたら
			break;
		}
		if(i%2==0){//先手
			CPU(-1);
		}
		if(i%2==1){//後手
			//UserMaru();
			CPU(1);
		}
	}

	printf("\n------------------------------------------\n------------------------------------------\n");
	Draw();
	if (check_winner() == 1) { 
		MaruWin++;
		printf("〇の勝ち！\n");
	}
	if (check_winner() == -1) { 
		BatuWin++;
		printf("×の勝ち！\n"); 
	}
	if (check_winner() == 0) { 
		Same++;
		printf("引き分け！\n"); 
	}

	
	turn++;
	if (turn < 1000 && MaruWin==0) { main(); }

	printf("\n------------------------------------------\n");
	printf("\n1000回勝負した、もしくは後手の〇が勝ったのでお知らせします！！\n");
	printf("〇の勝ち！ %d回目\n", MaruWin);
	printf("×の勝ち！ %d回目\n", BatuWin);
	printf("引き分け！　%d回目\n", Same);
	printf("\nこれにて試合は終了します。\n");
	

	int hoge;
	scanf("%d", &hoge);
}