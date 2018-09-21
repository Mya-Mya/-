#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<Windows.h>
/*
人工知能で次に置く位置を決める
*/
extern int board[9];
int MySide;//１が〇。－１が×。*1で自分、*-1で相手。
int CPUThought[9];//人工知能が×を置く提案を行う評価値変数

/*
ランダムに置く場所を提案する思考エンジン
*/
void PutRnd(){
	Sleep(1);
	srand((unsigned)time(NULL));
	CPUThought[rand() % 9] ++;//評価値は１
}

/*
もしも中央が開いていたら埋めるよう提案する思考エンジン
*/
void PutCenter() {
	if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 1; }//評価値は１
}

/*
相手が２連で負けそうだったら残りのところに入れる思考エンジン
*/
void PutRestToPreventLose() {
	for (int i = 0; i<3; i++) {//横
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == -2*MySide) {//相手を表す
			for (int j = 0; j < 3; j++) {
				if (board[i * 3 + j] == 0) { CPUThought[i * 3 + j] = CPUThought[i * 3 + j] + 10; }//評価値は１０
			}
		}
	}
	for (int i = 0; i<3; i++) {//縦
		if (board[i] + board[3+i] + board[6+i] == -2 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[j * 3 + i] == 0) { CPUThought[j * 3 + i] = CPUThought[j * 3 + i] + 10; }//評価値は１０
			}
		}
	}
	if (board[0] + board[4] + board[8] == -2 * MySide) {//ななめ
		if (board[0] == 0) { CPUThought[0] = CPUThought[0] + 10; }//評価値は１０
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 10; }//評価値は１０
		if (board[8] == 0) { CPUThought[8] = CPUThought[8] + 10; }//評価値は１０
	}
	if (board[2] + board[4] + board[6] == -2 * MySide) {//ななめ
		if (board[2] == 0) { CPUThought[2] = CPUThought[2] + 10; }//評価値は１０
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 10; }//評価値は１０
		if (board[6] == 0) { CPUThought[6] = CPUThought[6] + 10; }//評価値は１０
	}
}

/*
自分が２連で勝ちそうだったら残りのところに入れる思考エンジン
*/
void PutRestToWin() {
	for (int i = 0; i<3; i++) {//横
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 2 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[i * 3 + j] == 0) { CPUThought[i * 3 + j] = CPUThought[i * 3 + j] + 20; }//評価値は２０
			}
		}
	}
	for (int i = 0; i<3; i++) {//縦
		if (board[i] + board[3 + i] + board[6 + i] == 2 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[j * 3 + i] == 0) { CPUThought[j * 3 + i] = CPUThought[j * 3 + i] + 20; }//評価値は２０
			}
		}
	}
	if (board[0] + board[4] + board[8] == 2 * MySide) {//ななめ
		if (board[0] == 0) { CPUThought[0] = CPUThought[0] + 20; }//評価値は２０
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 20; }//評価値は２０
		if (board[8] == 0) { CPUThought[8] = CPUThought[8] + 20; }//評価値は２０
	}
	if (board[2] + board[4] + board[6] == 2 * MySide) {//ななめ
		if (board[2] == 0) { CPUThought[2] = CPUThought[2] + 20; }//評価値は２０
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 20; }//評価値は２０
		if (board[6] == 0) { CPUThought[6] = CPUThought[6] + 20; }//評価値は２０
	}
}

/*
自分+２連あまりだったらいずれの余りに入れる
*/
void PutTwoes() {
	for (int i = 0; i<3; i++) {//横
		if (board[i * 3 + 0] + board[i * 3 + 1] + board[i * 3 + 2] == 1 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[i * 3 + j] == 0) { CPUThought[i * 3 + j] = CPUThought[i * 3 + j] + 2; }//評価値は２
			}
		}
	}
	for (int i = 0; i<3; i++) {//縦
		if (board[i] + board[3 + i] + board[6 + i] == 1 * MySide) {
			for (int j = 0; j < 3; j++) {
				if (board[j * 3 + i] == 0) { CPUThought[j * 3 + i] = CPUThought[j * 3 + i] + 2; }//評価値は２
			}
		}
	}
	if (board[0] + board[4] + board[8] == 1 * MySide) {//ななめ
		if (board[0] == 0) { CPUThought[0] = CPUThought[0] + 2; }//評価値は２
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 2; }//評価値は２
		if (board[8] == 0) { CPUThought[8] = CPUThought[8] + 2; }//評価値は２
	}
	if (board[2] + board[4] + board[6] == 1 * MySide) {//ななめ
		if (board[2] == 0) { CPUThought[2] = CPUThought[2] + 2; }//評価値は２
		if (board[4] == 0) { CPUThought[4] = CPUThought[4] + 2; }//評価値は２
		if (board[6] == 0) { CPUThought[6] = CPUThought[6] + 2; }//評価値は２
	}
}

int max = 0;//最終的な×を置く場所を評価値とともに判断する変数
/*
どこに置くか決める
*/
void DecideWhereToPut() {
	
	for (int i = 0; i < 9; i++) {
		if (CPUThought[max] < CPUThought[i]) {//当該評価値が最大だったら
			if(board[i]==0){//開いていたら
				max = i;
			}
		}
	}
	if (board[max] != 0) {
		/*決まらない場合はランダムで指定*/
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

	/*変数の初期化*/
	max = 0;
	for (int i = 0; i < 9; i++) { CPUThought[i] = 0; }

	/*各種思考エンジン*/
	PutRnd();
	PutCenter();
	PutRestToPreventLose();
	PutRestToWin();
	PutTwoes();

	/*どこに置くか決める*/
	DecideWhereToPut();

	/*置く*/
	board[max]=MySide;
}