#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include<mmsystem.h>

void village();
void Battle(int id);
int intro();
int inn();
int shop();
int slime();
int sword();

char playerName[100]; // �÷��̾��� �̸�
int playerMaxhp = 100;
int playerMaxmp = 50;
int playerLv = 1;
int playerHp = 100;
int playerMp = 50;
int playerExp = 0;
int playerMaxExp = 10;
int playerStr = 0;
int playerInt = 0;
int playerDex = 0;
int playerAtk = 5;
int playerDef = 2;
int playerGold = 100; // ������


int floor = 0;// ���� ��

//���� ����� �������� ���� ����� ���� music������ ��ġ�� ������ ���ּ���.

#define BGM_MAIN ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\main.wav"
#define BGM_village ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\village.wav"
#define BGM_shop ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\shop.wav"
#define BGM_dungeon ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\dungeon.wav"
#define BGM_inn ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\inn.wav"

#pragma comment(lib,"winmm.lib")

void main() { //����
	system("mode con: cols=101 lines=30"); // �ܼ�â ����
	while (intro() == 0)
		intro();
}

int intro() //��Ʈ��
{
	char ans; // ���

	system("cls");
	PlaySound(TEXT(BGM_MAIN), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                        1  �� �� �� ��.                                         ��\n");
	printf("��                                         �� �� �� �� !                                          ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                �÷��̾��� �̸��� �Է��Ͻʽÿ�.                                 ��\n");
	printf("��                                  (10���� �̳��� �Է��Ͻÿ�)                                    ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");

	scanf_s("%s", playerName, 100);
	if ( strlen(playerName) > 10 ) {
		system("cls");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                                   10���� �̳��� �Է����ּ���!                                  ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		Sleep(1000);
		return 0;
	}

	else {
		system("cls");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                                         �Է¹޾ҽ��ϴ�.                                        ��\n");
		printf("                                       %s��(��) �³���? (Y/N)                                       \n", playerName);
		printf("����������������������������������������������������������������������������������������������������\n");
		getchar();
		scanf_s("%c", &ans, 1);

		if ( ans == 78 || ans == 110) {
			system("cls");
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("��                                      �ٽ� �Է� ���ּ���!                                       ��\n");
			printf("����������������������������������������������������������������������������������������������������\n");
			Sleep(1000);
			return 0;
		}

		else if( ans == 89 || ans == 121) {
			system("cls");
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("��                                         ������ ���ϴ�.                                         ��\n");
			printf("����������������������������������������������������������������������������������������������������\n");
			Sleep(1000);
			village();
			return 1;
		}
	}
}

void village()
{
	int command;
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT(BGM_village), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");

	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                              ������                                                            ��\n");
	printf("��                             ��������                        ����������������������������       ��\n");
	printf("��                            ����������                       ����������������������������       ��\n");
	printf("��                           ������������                      ��= = = = = = = = = = = = ��       ��\n");
	printf("��                          ��������������                     �������� = = = = = =��������       ��\n");
	printf("��                         ����������������                          ��= = = = = = ��             ��\n");
	printf("��                         ����������������                          �� = = = = = =��             ��\n");
	printf("��                          ��������������                           ��= = = = = = ��             ��\n");
	printf("��                            ����������                             ~~~~~~~SO~~~~~~              ��\n");
	printf("��                               ����                                ~~~~~~MANY~~~~~              ��\n");
	printf("��                                ��                                 ~~~~~~FLOOR~~~~              ��\n");
	printf("��                               ___                                 ��= = = = = = ��             ��\n");
	printf("��                              �� ��                                �� = = = = = =��             ��\n");
	printf("��     =========             ============                            ��= = = = = = ��             ��\n");
	printf("��   �� S H O P ��         +��  I N N   ��+                          �� = = = = = =��             ��\n");
	printf("��  ==============        =================                          ��= = = = = = ��             ��\n");
	printf("��  ��           ��         ��          ��                           �� = = = = = =��             ��\n");
	printf("��  ��  _______  ��         ��  _____   ��                           ��= = = = = = ��             ��\n");
	printf("��  ��  ��*|*��  ��         �� ��*|*��  ��                           �� = = = = = =��             ��\n");
	printf("��   =============          ##############                           ===============              ��\n");
	printf("��     1. ����                 2. ����                                     3. ž                  ��\n");
	printf("��                                                                                                ��\n");
	printf("���ƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǦ�\n");
	printf("���ǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƦ�\n");
	printf("���ƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǦ�\n");
	printf("���ǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƦ�\n");
	printf("���ƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǢƢǦ�\n");
	printf("����������������������������������������������������������������������������������������������������\n");

	getchar();
	scanf_s("%d", &command);
	switch (command) {
	case 1: // ����
		while (shop() == 0) shop();
		break;
	case 2: // ����
		while(inn() == 0) inn();
		break;
	case 3: // ž����
		floor += 1;
		Battle(floor);
		break;

	default: // ����
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                                    �ùٸ� ���� �Է����ּ���.                                   ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		Sleep(1000);
		village();
	}
}

void Battle(int id)
{
	char monsterName[30];
	int monsterHp;
	int monsterAtk;
	int monsterDef;
	int monsterExp;
	int monsterGold;
	int command; //���� Ŀ�ǵ�
	int Bcommand; //���� Ŀ�ǵ�
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT(BGM_dungeon), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	switch (id)
	{
	case 1:
		strcpy_s(monsterName, strlen(monsterName), "������1");
		monsterHp = 30;
		monsterAtk = 5;
		monsterDef = 2;
		monsterExp = 5;
		monsterGold = 25;
		break;

	case 2:
		strcpy_s(monsterName, strlen(monsterName), "������2");
		monsterHp = 35;
		monsterAtk = 7;
		monsterDef = 3;
		monsterExp = 10;
		monsterGold = 40;
		break;

	case 3:
		strcpy_s(monsterName, strlen(monsterName), "������3");
		monsterHp = 40;
		monsterAtk = 9;
		monsterDef = 4;
		monsterExp = 25;
		monsterGold = 85;
		break;

	case 4:
		strcpy_s(monsterName, strlen(monsterName), "������4");
		monsterHp = 45;
		monsterAtk = 12;
		monsterDef = 5;
		monsterExp = 50;
		monsterGold = 150;
		break;

	case 5:
		strcpy_s(monsterName, strlen(monsterName), "������5");
		monsterHp = 50;
		monsterAtk = 15;
		monsterDef = 7;
		monsterExp = 100;
		monsterGold = 350;
		break;

	case 6:
		strcpy_s(monsterName, strlen(monsterName), "������6");
		monsterHp = 60;
		monsterAtk = 18;
		monsterDef = 9;
		monsterExp = 250;
		monsterGold = 600;
		break;

	case 7:
		strcpy_s(monsterName, strlen(monsterName), "������7");
		monsterHp = 80;
		monsterAtk = 21;
		monsterDef = 12;
		monsterExp = 600;
		monsterGold = 900;
		break;

	case 8:
		strcpy_s(monsterName, strlen(monsterName), "������8");
		monsterHp = 110;
		monsterAtk = 25;
		monsterDef = 15;
		monsterExp = 1000;
		monsterGold = 1500;
		break;

	case 9:
		strcpy_s(monsterName, strlen(monsterName), "������9");
		monsterHp = 150;
		monsterAtk = 30;
		monsterDef = 18;
		monsterExp = 2000;
		monsterGold = 2500;
		break;

	case 10:
		strcpy_s(monsterName, strlen(monsterName), "������10");
		monsterHp = 200;
		monsterAtk = 50;
		monsterDef = 25;
		monsterExp = 4000;
		monsterGold = 5000;
		break;

	}
	system("cls");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("                              ����� ž�� ��ο� ����� �ö� %d ���� �����ߴ�.                      \n", floor);
	printf("                                     ����� �հ� ������ �װ����� �����....                         \n");
	printf("����������������������������������������������������������������������������������������������������\n");
	Sleep(1200);
	if (strcmp(monsterName, "������1") == 0 || strcmp(monsterName, "������2") == 0 || strcmp(monsterName, "������3") == 0 || strcmp(monsterName, "������4") == 0 || strcmp(monsterName, "������5") == 0 || strcmp(monsterName, "������6") == 0 || strcmp(monsterName, "������7") == 0 || strcmp(monsterName, "������8") == 0 || strcmp(monsterName, "������9") == 0 || strcmp(monsterName, "������10") ) {
		slime();
	}

	printf("����������������������������������������������������������������������������������������������������\n");
	printf("                                   %s��(��) �����ߴ�! ����� �ൿ��?                                \n", monsterName);
	printf("                                            ��� �ұ�?                                            \n");
	printf("                                      1) �ο��. 2) ���ư���.                                       \n");
	printf("����������������������������������������������������������������������������������������������������\n");

	scanf_s("%d", &command);


	switch (command)
	{
	case 1:
		system("cls");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("                                            ��, %s�� ����                                           \n", playerName);
		printf("                                                Lv. %d                                              \n", playerLv);
		printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
		printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("                                            ��, %s�� ����                                           \n", monsterName);
		printf("                                               [HP:%d]                                              \n", monsterHp);
		printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
		printf("����������������������������������������������������������������������������������������������������\n");

		printf("                        ==//+===+>>  %s���� ������ ��������!!  <<+===+//==                        \n", monsterName);
	Battle:
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("                                           ����� �ൿ�� ?                                          \n");
		printf("                    1)�Ϲݰ��� 2)���(-mp15) 3)��ų��� 4)�����ۻ�� 5)��������                     \n");
		printf("����������������������������������������������������������������������������������������������������\n");
		scanf_s("%d", &Bcommand);

		switch (Bcommand)
		{
		case 1:
			system("cls");
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("                         %s���� �Ϲݰ����� ����� %d ��ŭ�� �������� ������!                        \n", monsterName, playerAtk - monsterDef);
			printf("����������������������������������������������������������������������������������������������������\n");
			monsterHp = monsterHp - (playerAtk - monsterDef);

			if (monsterHp <= 0)
			{

				playerExp = playerExp + monsterExp;
				playerGold = playerGold + monsterGold;
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                �����մϴ� %s, �������� �¸��߽��ϴ�!                               \n", playerName);
				printf("                                             ####����####                                           \n");
				printf("                                          EXP: %d   Gold: %d                                        \n", monsterExp, monsterGold);
				printf("                                            ���, %s�� ����                                         \n", playerName);
				printf("                                                Lv. %d                                              \n", playerLv);
				printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
				printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
				printf("����������������������������������������������������������������������������������������������������\n");

				if (playerExp >= playerMaxExp)
				{
					playerLv += 1;
					playerExp = 0;
					playerMaxExp = playerMaxExp * 2;
					playerMaxhp = playerMaxhp + 10;
					playerMaxmp = playerMaxmp + 5;
					playerHp = playerMaxhp;
					playerMp = playerMaxmp;
					playerAtk += 2;
					playerDef += 1;
					printf("����������������������������������������������������������������������������������������������������\n");
					printf("                                         L E V E L    U P                                           \n");
					printf("                                              Lv. %d                                                \n", playerLv);
					printf("����������������������������������������������������������������������������������������������������\n");
				}

				system("Pause");
				floor++;
				Battle(floor);
				return;

			}

			printf("����������������������������������������������������������������������������������������������������\n");
			printf("                       %s�� %s���� ������ %d��ŭ�� �������� ������!                                 \n", monsterName, playerName, monsterAtk - playerDef);
			printf("����������������������������������������������������������������������������������������������������\n");
			playerHp = playerHp - (monsterAtk - playerDef);
			system("Pause");

			if (playerHp <= 0)
			{
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                 %s, ����� ���� �Ǹ����׾�,,                                       \n", playerName);
				printf("                                    G A M E     O V E R                                             \n");
				printf("����������������������������������������������������������������������������������������������������\n");
				system("Pause");
				return;
			}

			system("cls");
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("                                            ��, %s�� ����                                           \n", playerName);
			printf("                                                Lv. %d                                              \n", playerLv);
			printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
			printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("                                            ��, %s�� ����                                           \n", monsterName);
			printf("                                               [HP:%d]                                              \n", monsterHp);
			printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
			printf("����������������������������������������������������������������������������������������������������\n");
			goto Battle;
			break;

		case 2:
			system("cls");

			if (playerMp > 15) {
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                   mp15�� �Ҹ��� ��� ������ ����Ѵ�!                              \n");
				playerMp = playerMp - 15;
				printf("                                       %s�� %s�� ������ ���Ƴ´�!                                   \n", playerName, monsterName);
				printf("����������������������������������������������������������������������������������������������������\n");

				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                            ��, %s�� ����                                           \n", playerName);
				printf("                                                Lv. %d                                              \n", playerLv);
				printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
				printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                            ��, %s�� ����                                           \n", monsterName);
				printf("                                               [HP:%d]                                              \n", monsterHp);
				printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
				printf("����������������������������������������������������������������������������������������������������\n");
				goto Battle;
				break;
			}
			else {
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                          ������ �����ϴ�!!                                         \n");
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                            ��, %s�� ����                                           \n", playerName);
				printf("                                                Lv. %d                                              \n", playerLv);
				printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
				printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("                                            ��, %s�� ����                                           \n", monsterName);
				printf("                                               [HP:%d]                                              \n", monsterHp);
				printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
				printf("����������������������������������������������������������������������������������������������������\n");
				goto Battle;
			}
		case 3:
			goto Battle;
		case 4:
			goto Battle;
		case 5:
			system("cls");
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("��                                 ���ͷκ��� �����ƴ�! ������ ���ư���.                        ��\n");
			printf("��                                  (�ƹ�Ű�� �Է��ϸ� ������ ���ư���)                           ��\n");
			printf("����������������������������������������������������������������������������������������������������\n");
			floor = 0;
			system("Pause");
			village();
			return;
			break;

		}


	case 2:
		system("cls");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                                       �����ϰ� ������ ���ƿԴ�.                                ��\n");
		printf("��                                  (�ƹ�Ű�� �Է��ϸ� ������ ���ư���)                           ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");
		floor = 0;
		system("Pause");
		village();
		return;
		break;

	}
}


int inn()
{
	int command = 0;
	char ans;
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT(BGM_inn), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("                                              %s�� ����                                             \n", playerName);
	printf("                                   ���� %s�� �������� %d G �Դϴ�.                                  \n", playerName, playerGold);
	printf("��                                                                                                ��\n");
	printf("����������������������������������[HP : %d / %d  MP : %d / %d]��������������������������������������\n", playerHp, playerMaxhp, playerMp, playerMaxmp);
	printf("��                               1. �޽��� ���Ѵ�. 2. ������ ���ư���.                            ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");

	getchar();
	scanf_s("%d", &command);
	switch (command)
	{
	case 1: // �޽��� ���Ѵ�.
		system("cls");
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("                               ���� ���� : �Ϸ�� ���µ� ������ %d G�Դϴ�.                         \n", (playerLv * 100));
		printf("��                                        ���ڽ��ϱ�? (Y/N)                                       ��\n");                                  
		printf("����������������������������������������������������������������������������������������������������\n");


		getchar();
		scanf_s("%c", &ans);
		if (ans == 89 || ans == 121)
		{
			if (playerGold >= (playerLv * 100))
			{
				system("cls");
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("��                                     �̿��� �ּż� �����մϴ�.                                  ��\n");
				printf("��                                  ü�°� ������ ��� ȸ���Ǿ���.                                ��\n"); 
				printf("����������������������������������������������������������������������������������������������������\n");
				playerHp = playerMaxhp;
				playerMp = playerMaxmp;
				playerGold -= playerLv * 100;
				system("Pause");
				village(); // ������
				return 1;
			}
			else
			{
				system("cls");
				printf("����������������������������������������������������������������������������������������������������\n");
				printf("��                                   �̷�! �������� �����Ͻñ���!                                 ��\n");
				printf("����������������������������������������������������������������������������������������������������\n");
				system("Pause");
				return 0;
			}
		}
		else if (ans == 78 || ans == 110)
		{
			village(); // ������
			return 1;
		}
		else
		{
			printf("����������������������������������������������������������������������������������������������������\n");
			printf("��                                      �� �� ���� �Է��Դϴ�.                                    ��\n");
			printf("����������������������������������������������������������������������������������������������������\n");

			system("Pause");
			return 0;
		}
	case 2: // ������ ������.
		village();
		break;
	default: // ������
		printf("����������������������������������������������������������������������������������������������������\n");
		printf("��                                      �� �� ���� �Է��Դϴ�.                                    ��\n");
		printf("����������������������������������������������������������������������������������������������������\n");

		system("Pause");
		return 0;
	}
}

int shop()
{
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT(BGM_shop), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	printf("����������������������������������������������������������������������������������������������������\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("                                    �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�                                \n");
	printf("                                   /    ::                     ::   ;                               \n");
	printf("                                  /     ::       __________    ::    ;                              \n");
	printf("                                 / :____::_______:    o   :____::_____:                             \n");
	printf("                                / /                                  /                              \n");
	printf("                               / /                                  /                               \n");
	printf("                               :/__________________________________/                                \n");
	printf("                              :��                                  ��                               \n");
	printf("                              :**��            �������Դϴ�.         ��                             \n");
	printf("                              :****�� _________________________________��                           \n");
	printf("                              :******:     ::    :    :   :    ::        :                          \n");
	printf("                              ��*****:     ::    :________:    ::        :                          \n");
	printf("                                ��***:     ::                  ::        :                          \n");
	printf("                                  ��*:_____::__________________::________:                          \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("����������������������������������������������������������������������������������������������������\n");
	system("pause");
	system("cls");
	sword();
	village();
}

int slime() {
		printf("����������������������������������������������������������������������������������������������������\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf("                                              .*:==+**#:                                            \n");
		Sleep(50);
		printf("                                            .++:===++**%                                            \n");
		Sleep(50);
		printf("                                        .:=+=:::===++***%+.                                         \n");
		Sleep(50);
		printf("                                    :=++=::::::===++++****##+=.                                     \n");
		Sleep(50);
		printf("                                 :++=::...::::====+++++********#*+=.                                \n");
		Sleep(50);
		printf("                               +*=:::...::::======+++++**************=                              \n");
		Sleep(50);
		printf("                             =*::::...:::==:=====++++++************#*+*:                            \n");
		Sleep(50);
		printf("                            #==:::::::::=::++++**=+++#=::+#**********#*+=                           \n");
		Sleep(50);
		printf("                           #:==::::::::===*     :#++*  +:  #***********+*.                          \n");
		Sleep(50); //31
		printf("                          +==============*  #@@. ++*: @@@: +#********++*=*                          \n");
		Sleep(50);
		printf("                          #==============++  =:  #++#:    =#********+:=*=+                          \n");
		Sleep(50);
		printf("                          *=++============+*===+*++++*#*##*#%%#*****:.++*+                          \n");
		Sleep(50);
		printf("                          :++++++=====+=#%##*+++++++++**##*++#@****=.=+++                           \n");
		Sleep(50);
		printf("                           +++**++++++++@*==+***********====*#***+::=+*=                            \n");
		Sleep(50);
		printf("                            :+++****+++++***+===========+*##****+===++.                             \n");
		Sleep(50);
		printf("                              .=++++**********###*#*####*******+++*=.                               \n");
		Sleep(50);
		printf("                                 .:=+++++++**************++++++==:                                  \n");
		Sleep(50);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("����������������������������������������������������������������������������������������������������\n");
}

int sword() {
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("                                                                                                    \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("                                    C��                              _,-;                           \n");
	printf("                                      /C_____________________,.-'*'^^ .;                            \n");
	printf("                              ,n#:##:#}{------------------ - - - __.-^'                             \n");
	printf("                                       ;/,-'''^^^^^^^^^^^^^^^^^^^^                                  \n");
	printf("                                     c/'                                                            \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("                                         <����� ���� ������ ��>                                    \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("                                                                                                    \n");
	printf("����������������������������������������������������������������������������������������������������\n");
	system("pause");
}
