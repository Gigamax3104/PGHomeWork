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

static const char HandKind[] = "GgSsPp"; //���������P�[�W + �萔

//�񐔓���
void LimitInput() {
	int size;
	char enter;

	do {
		enter = '\0';
		cout << "����񂯂񂷂�񐔂�I�����Ă��������B>" << flush;
		cin >> size;

		do {
			cout << size << "��ł�낵���ł���\?(Yes : Z, No : X)>" << flush;
			cin >> enter;
		} while (!(enter == 'z' || enter == 'x'));

		cout << endl;
	} while (enter == 'x');

	JankenMove(size);
}
//��ɓ��삷��֐�
static void JankenMove(int size) {

	int size2 = sizeof HandKind / sizeof HandKind[0];

	BringOut Player, CPU;

	for (int i = 0; i < size; i++) {
		cout << i + 1 << "���" << endl;
		do {
			ThinkHand(HandKind, size2, Player, CPU);

		} while (ShowResult(Player, CPU,LastJudgement(Player, CPU)));
	}

}

//���݂��̎�����߂�֐�
static void ThinkHand(const char* handKind,int size,BringOut& Player, BringOut& CPU) {
	srand((unsigned int)time(NULL));

	char PlayerHand;

	do {
		cout << "�����̎����͂��Ă��������B(G : �O�[�AS : �`���L�AP ; �p�[)>" << flush;
		cin >> PlayerHand;

	} while (HandJudgement(PlayerHand, handKind, size));

	Player = ExitHand(&PlayerHand);

	int idx = rand() % size;
	CPU = ExitHand(&handKind[idx]);
}

//ThinkHand�֐��ɂāAHandKind�̒��g�Ǝ��������͂����������ꏏ�ł��邩���肷��֐�
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
		cout << "������x���͂��Ă��������B" << endl;
		return true;
	}
	else {
		return false;
	}
}

//���͂���������A�����_���Ō��߂�ꂽ������񋓑̂Ŕ��ʂ���֐�
static BringOut ExitHand(const char* hand) {
	return
		*hand == 'G' || *hand == 'g' ? Rock :
		*hand == 'S' || *hand == 's' ? Scissors :
		*hand == 'P' || *hand == 'p' ? Paper : None;
}

//���s�̔��f������֐�
static Judgement LastJudgement(BringOut& Player, BringOut& CPU) {
	return
		(Player == Rock && CPU == Scissors) || (Player == Scissors && CPU == Paper) ||
		(Player == Paper && CPU == Rock) ? Win : Player == CPU ? Draw : Lose;
}

//���s���b�Z�[�W��\������֐�
static bool ShowResult(BringOut& Player, BringOut& CPU,const Judgement judgement) {
	const char* massage[] = {
		"������ˁI���Ȃ��̏����I",
		"�������Ȃ̂ł������I",
		"�c�O�I���Ȃ��̕����I"
	};
	const char* Handmassage[] = {
		"�O�[",
		"�`���L",
		"�p�["
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

//�����̎�Ƒ���̎��\������֐�
static void ShowEachOtherHand(const char* handmassage[],BringOut& Player, BringOut& CPU) {
	cout << "�����̎�:" << flush << handmassage[Player] << endl;
	cout << "����̎�:" << flush << handmassage[CPU] << endl;
}