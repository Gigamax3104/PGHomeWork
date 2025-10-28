#include	<iostream>
#include	<cstdlib>
#include	<ctime>
#include "janken.h"
using namespace std;

static void JankenMove(int size);
static BringOut ExitHand(const char* hand);
static bool HandJudgement(char hand, const char* handkind,int size);
static void ThinkHand(const char* handKind,int size,BringOut& Player, BringOut& CPU);
static Judgement LastJudgement(BringOut& Player, BringOut& CPU);
static bool ShowResult(BringOut& Player, BringOut& CPU,const Judgement judgement);
static void ShowEachOtherHand(const char* handmassage[],BringOut& Player, BringOut& CPU);

static const char HandKind[] = "GgSsPp"; //内部リンケージ + 定数

//回数入力
void LimitInput() {
	int size;
	char enter;

	do {
		enter = '\0';
		cout << "じゃんけんする回数を選択してください。>" << flush;
		cin >> size;

		do {
			cout << size << "回でよろしいですか\?(Yes : Z, No : X)>" << flush;
			cin >> enter;
		} while (!(enter == 'z' || enter == 'x'));

		cout << endl;
	} while (enter == 'x');

	JankenMove(size);
}
//主に動作する関数
static void JankenMove(int size) {

	int size2 = sizeof HandKind / sizeof HandKind[0];

	BringOut Player, CPU;

	for (int i = 0; i < size; i++) {
		cout << i + 1 << "回目" << endl;
		do {
			ThinkHand(HandKind, size2, Player, CPU);

		} while (ShowResult(Player, CPU,LastJudgement(Player, CPU)));
	}

}

//お互いの手を決める関数
static void ThinkHand(const char* handKind,int size,BringOut& Player, BringOut& CPU) {
	srand((unsigned int)time(NULL));

	char PlayerHand;

	do {
		cout << "自分の手を入力してください。(G : グー、S : チョキ、P ; パー)>" << flush;
		cin >> PlayerHand;

	} while (HandJudgement(PlayerHand, handKind, size));

	Player = ExitHand(&PlayerHand);

	int idx = rand() % size;
	CPU = ExitHand(&handKind[idx]);
}

//ThinkHand関数にて、HandKindの中身と自分が入力した文字が一緒であるか判定する関数
static bool HandJudgement(char hand, const char* handkind,int size) {
	int i = 0;

	while (i < size) {
		
		if (hand != handkind[i]) {
			i++;
		}
		else {
			break;
		}
	}

	if (i == size) {
		cout << "もう一度入力してください。" << endl;
		return true;
	}
	else {
		return false;
	}
}

//入力した文字や、ランダムで決められた文字を列挙体で判別する関数
static BringOut ExitHand(const char* hand) {
	return
		*hand == 'G' || *hand == 'g' ? Rock :
		*hand == 'S' || *hand == 's' ? Scissors :
		*hand == 'P' || *hand == 'p' ? Paper : None;
}

//勝敗の判断をする関数
static Judgement LastJudgement(BringOut& Player, BringOut& CPU) {
	return
		(Player == Rock && CPU == Scissors) || (Player == Scissors && CPU == Paper) ||
		(Player == Paper && CPU == Rock) ? Win : Player == CPU ? Draw : Lose;
}

//勝敗メッセージを表示する関数
static bool ShowResult(BringOut& Player, BringOut& CPU,const Judgement judgement) {
	const char* massage[] = {
		"やったね！あなたの勝ち！",
		"あいこなのでもう一回！",
		"残念！あなたの負け！"
	};
	const char* Handmassage[] = {
		"グー",
		"チョキ",
		"パー"
	};

	ShowEachOtherHand(Handmassage,Player, CPU);

	switch (judgement) {
		case Win:
		case Lose:
			cout << massage[judgement % 4] << endl << endl; 
			return false; break;
		case Draw:
			cout << massage[judgement % 4] << endl << endl; 
			return true; break;
	}
}

//自分の手と相手の手を表示する関数
static void ShowEachOtherHand(const char* handmassage[],BringOut& Player, BringOut& CPU) {
	cout << "自分の手:" << flush << handmassage[Player] << endl;
	cout << "相手の手:" << flush << handmassage[CPU] << endl;
}