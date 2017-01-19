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

char playerName[100]; // Ы溯檜橫曖 檜葷
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
int playerGold = 100; // 模雖旎


int floor = 0;// ⑷營 類

//啪歜 褒ч衛 薑鼻瞳檣 擠學 轎溘擊 嬪п musicィ渦曖 嬪纂蒂 營薑曖 п輿撮蹂.

#define BGM_MAIN ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\main.wav"
#define BGM_village ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\village.wav"
#define BGM_shop ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\shop.wav"
#define BGM_dungeon ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\dungeon.wav"
#define BGM_inn ".\\D:\\2.Study\\4.Projects\\ProjectGaming\\Hackathon\\CONSOL~1\\ConsoleApplication3\\resource\\inn.wav"

#pragma comment(lib,"winmm.lib")

void main() { //詭檣
	system("mode con: cols=101 lines=30"); // 夔樂璽 撲薑
	while (intro() == 0)
		intro();
}

int intro() //檣お煎
{
	char ans; // 渠港

	system("cls");
	PlaySound(TEXT(BGM_MAIN), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("早                                        1  橫 釭 撮 蹂.                                         早\n");
	printf("早                                         辨 餌 椒 嬴 !                                          早\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("早                                Ы溯檜橫曖 檜葷擊 殮溘ж褊衛螃.                                 早\n");
	printf("早                                  (10旋濠 檜頂煎 殮溘ж衛螃)                                    早\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("早                                                                                                早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	scanf_s("%s", playerName, 100);
	if ( strlen(playerName) > 10 ) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                   10旋濠 檜頂煎 殮溘п輿撮蹂!                                  早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		Sleep(1000);
		return 0;
	}

	else {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                         殮溘嫡懊蝗棲棻.                                        早\n");
		printf("                                       %s檜(陛) 蜃釭蹂? (Y/N)                                       \n", playerName);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		getchar();
		scanf_s("%c", &ans, 1);

		if ( ans == 78 || ans == 110) {
			system("cls");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早                                      棻衛 殮溘 п輿撮蹂!                                       早\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			Sleep(1000);
			return 0;
		}

		else if( ans == 89 || ans == 121) {
			system("cls");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早                                         葆擊煎 骨棲棻.                                         早\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                              仄仄仄                                                            早\n");
	printf("早                             仄仄仄仄                        旨旬旨旬旨旬旨旬旨旬旨旬旨旬       早\n");
	printf("早                            仄仄仄仄仄                       早曲旭曲旭曲旭曲旭曲旭曲旭早       早\n");
	printf("早                           仄仄仄仄仄仄                      早= = = = = = = = = = = = 早       早\n");
	printf("早                          仄仄仄仄仄仄仄                     曲收收旬 = = = = = =旨收收旭       早\n");
	printf("早                         仄仄仄仄仄仄仄仄                          早= = = = = = 早             早\n");
	printf("早                         仄仄仄仄仄仄仄仄                          早 = = = = = =早             早\n");
	printf("早                          仄仄仄仄仄仄仄                           早= = = = = = 早             早\n");
	printf("早                            仄仄仄仄仄                             ~~~~~~~SO~~~~~~              早\n");
	printf("早                               仄仄                                ~~~~~~MANY~~~~~              早\n");
	printf("早                                仄                                 ~~~~~~FLOOR~~~~              早\n");
	printf("早                               ___                                 早= = = = = = 早             早\n");
	printf("早                              早 早                                早 = = = = = =早             早\n");
	printf("早     =========             ============                            早= = = = = = 早             早\n");
	printf("早   Ｉ S H O P Ｋ         +早  I N N   早+                          早 = = = = = =早             早\n");
	printf("早  ==============        =================                          早= = = = = = 早             早\n");
	printf("早  早           早         早          早                           早 = = = = = =早             早\n");
	printf("早  早  _______  早         早  _____   早                           早= = = = = = 早             早\n");
	printf("早  早  早*|*早  早         早 早*|*早  早                           早 = = = = = =早             早\n");
	printf("早   =============          ##############                           ===============              早\n");
	printf("早     1. 鼻薄                 2. 罹婦                                     3. 鱉                  早\n");
	printf("早                                                                                                早\n");
	printf("早〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥早\n");
	printf("早〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤早\n");
	printf("早〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥早\n");
	printf("早〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤早\n");
	printf("早〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥〤〥早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	getchar();
	scanf_s("%d", &command);
	switch (command) {
	case 1: // 鼻薄
		while (shop() == 0) shop();
		break;
	case 2: // 罹婦
		while(inn() == 0) inn();
		break;
	case 3: // 鱉戲煎
		floor += 1;
		Battle(floor);
		break;

	default: // 螃盟
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                    螢夥艇 高擊 殮溘п輿撮蹂.                                   早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
	int command; //唸薑 醴裔萄
	int Bcommand; //瞪癱 醴裔萄
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT(BGM_dungeon), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	switch (id)
	{
	case 1:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜1");
		monsterHp = 30;
		monsterAtk = 5;
		monsterDef = 2;
		monsterExp = 5;
		monsterGold = 25;
		break;

	case 2:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜2");
		monsterHp = 35;
		monsterAtk = 7;
		monsterDef = 3;
		monsterExp = 10;
		monsterGold = 40;
		break;

	case 3:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜3");
		monsterHp = 40;
		monsterAtk = 9;
		monsterDef = 4;
		monsterExp = 25;
		monsterGold = 85;
		break;

	case 4:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜4");
		monsterHp = 45;
		monsterAtk = 12;
		monsterDef = 5;
		monsterExp = 50;
		monsterGold = 150;
		break;

	case 5:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜5");
		monsterHp = 50;
		monsterAtk = 15;
		monsterDef = 7;
		monsterExp = 100;
		monsterGold = 350;
		break;

	case 6:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜6");
		monsterHp = 60;
		monsterAtk = 18;
		monsterDef = 9;
		monsterExp = 250;
		monsterGold = 600;
		break;

	case 7:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜7");
		monsterHp = 80;
		monsterAtk = 21;
		monsterDef = 12;
		monsterExp = 600;
		monsterGold = 900;
		break;

	case 8:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜8");
		monsterHp = 110;
		monsterAtk = 25;
		monsterDef = 15;
		monsterExp = 1000;
		monsterGold = 1500;
		break;

	case 9:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜9");
		monsterHp = 150;
		monsterAtk = 30;
		monsterDef = 18;
		monsterExp = 2000;
		monsterGold = 2500;
		break;

	case 10:
		strcpy_s(monsterName, strlen(monsterName), "蝸塭歜10");
		monsterHp = 200;
		monsterAtk = 50;
		monsterDef = 25;
		monsterExp = 4000;
		monsterGold = 5000;
		break;

	}
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("                              渡褐擎 鱉曖 橫舒遴 啗欽擊 螢塭 %d 類縑 紫殖ц棻.                      \n", floor);
	printf("                                     橫菸擊 勢堅 紫殖и 斜夠縑憮 渡褐擎....                         \n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	Sleep(1200);
	if (strcmp(monsterName, "蝸塭歜1") == 0 || strcmp(monsterName, "蝸塭歜2") == 0 || strcmp(monsterName, "蝸塭歜3") == 0 || strcmp(monsterName, "蝸塭歜4") == 0 || strcmp(monsterName, "蝸塭歜5") == 0 || strcmp(monsterName, "蝸塭歜6") == 0 || strcmp(monsterName, "蝸塭歜7") == 0 || strcmp(monsterName, "蝸塭歜8") == 0 || strcmp(monsterName, "蝸塭歜9") == 0 || strcmp(monsterName, "蝸塭歜10") ) {
		slime();
	}

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("                                   %s擊(蒂) 葆輿ц棻! 渡褐曖 ч翕擎?                                \n", monsterName);
	printf("                                            橫飩啪 й梱?                                            \n");
	printf("                                      1) 諄遴棻. 2) 給嬴除棻.                                       \n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	scanf_s("%d", &command);


	switch (command)
	{
	case 1:
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("                                            釭, %s曖 鼻鷓                                           \n", playerName);
		printf("                                                Lv. %d                                              \n", playerLv);
		printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
		printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("                                            瞳, %s曖 鼻鷓                                           \n", monsterName);
		printf("                                               [HP:%d]                                              \n", monsterHp);
		printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

		printf("                        ==//+===+>>  %s諦曖 瞪癱縑 蕾橫菟歷棻!!  <<+===+//==                        \n", monsterName);
	Battle:
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("                                           渡褐曖 ч翕擎 ?                                          \n");
		printf("                    1)橾奩奢問 2)寞橫(-mp15) 3)蝶鑒餌辨 4)嬴檜蠱餌辨 5)紫蜂除棻                     \n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		scanf_s("%d", &Bcommand);

		switch (Bcommand)
		{
		case 1:
			system("cls");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("                         %s縑啪 橾奩奢問擊 餌辨п %d 虜躑曖 等嘐雖蒂 殮⑼棻!                        \n", monsterName, playerAtk - monsterDef);
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			monsterHp = monsterHp - (playerAtk - monsterDef);

			if (monsterHp <= 0)
			{

				playerExp = playerExp + monsterExp;
				playerGold = playerGold + monsterGold;
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("                                蹴жм棲棻 %s, 瞪癱縑憮 蝓葬ц蝗棲棻!                               \n", playerName);
				printf("                                             ####爾鼻####                                           \n");
				printf("                                          EXP: %d   Gold: %d                                        \n", monsterExp, monsterGold);
				printf("                                            渡褐, %s曖 鼻鷓                                         \n", playerName);
				printf("                                                Lv. %d                                              \n", playerLv);
				printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
				printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
					printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
					printf("                                         L E V E L    U P                                           \n");
					printf("                                              Lv. %d                                                \n", playerLv);
					printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				}

				system("Pause");
				floor++;
				Battle(floor);
				return;

			}

			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("                       %s陛 %s縑啪 奢問п %d虜躑曖 等嘐雖蒂 殮⑼棻!                                 \n", monsterName, playerName, monsterAtk - playerDef);
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			playerHp = playerHp - (monsterAtk - playerDef);
			system("Pause");

			if (playerHp <= 0)
			{
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("                                 %s, 渡褐擎 釭蒂 褒蜂衛儷橫,,                                       \n", playerName);
				printf("                                    G A M E     O V E R                                             \n");
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				system("Pause");
				return;
			}

			system("cls");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("                                            釭, %s曖 鼻鷓                                           \n", playerName);
			printf("                                                Lv. %d                                              \n", playerLv);
			printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
			printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
			printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
			printf("                                            瞳, %s曖 鼻鷓                                           \n", monsterName);
			printf("                                               [HP:%d]                                              \n", monsterHp);
			printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			goto Battle;
			break;

		case 2:
			system("cls");

			if (playerMp > 15) {
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("                                   mp15蒂 模賅п 賅萇 奢問擊 寞橫и棻!                              \n");
				playerMp = playerMp - 15;
				printf("                                       %s陛 %s曖 奢問擊 虞嬴麻棻!                                   \n", playerName, monsterName);
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("                                            釭, %s曖 鼻鷓                                           \n", playerName);
				printf("                                                Lv. %d                                              \n", playerLv);
				printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
				printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
				printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
				printf("                                            瞳, %s曖 鼻鷓                                           \n", monsterName);
				printf("                                               [HP:%d]                                              \n", monsterHp);
				printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				goto Battle;
				break;
			}
			else {
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("                                          葆釭陛 睡褶ж棻!!                                         \n");
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("                                            釭, %s曖 鼻鷓                                           \n", playerName);
				printf("                                                Lv. %d                                              \n", playerLv);
				printf("                               [HP:%d / %d] [MP:%d / %d] [EXP: %d / %d]                             \n", playerHp, playerMaxhp, playerMp, playerMaxmp, playerExp, playerMaxExp);
				printf("                                          [ATK:%d] [DEF: %d]                                        \n", playerAtk, playerDef);
				printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
				printf("                                            瞳, %s曖 鼻鷓                                           \n", monsterName);
				printf("                                               [HP:%d]                                              \n", monsterHp);
				printf("                                         [ATK:%d]  [DEF: %d]                                        \n", monsterAtk, monsterDef);
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				goto Battle;
			}
		case 3:
			goto Battle;
		case 4:
			goto Battle;
		case 5:
			system("cls");
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早                                 跨蝶攪煎睡攪 紫蜂蟻棻! 葆擊煎 給嬴除棻.                        早\n");
			printf("早                                  (嬴鼠酈釭 殮溘ж賊 葆擊煎 給嬴除棻)                           早\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			floor = 0;
			system("Pause");
			village();
			return;
			break;

		}


	case 2:
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                       寰瞪ж啪 葆擊煎 給嬴諮棻.                                早\n");
		printf("早                                  (嬴鼠酈釭 殮溘ж賊 葆擊煎 給嬴除棻)                           早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("                                              %s曖 鼻鷓                                             \n", playerName);
	printf("                                   ⑷營 %s曖 模雖旎擎 %d G 殮棲棻.                                  \n", playerName, playerGold);
	printf("早                                                                                                早\n");
	printf("曳收收收收收收收收收收收收收收收收[HP : %d / %d  MP : %d / %d]收收收收收收收收收收收收收收收收收收朽\n", playerHp, playerMaxhp, playerMp, playerMaxmp);
	printf("早                               1. �瑍釋� 鏃и棻. 2. 葆擊煎 給嬴除棻.                            早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	getchar();
	scanf_s("%d", &command);
	switch (command)
	{
	case 1: // �瑍釋� 鏃и棻.
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("                               罹婦 輿檣 : ж當嫘 僧朝等 陛問擎 %d G殮棲棻.                         \n", (playerLv * 100));
		printf("早                                        僧啊蝗棲梱? (Y/N)                                       早\n");                                  
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");


		getchar();
		scanf_s("%c", &ans);
		if (ans == 89 || ans == 121)
		{
			if (playerGold >= (playerLv * 100))
			{
				system("cls");
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("早                                     檜辨п 輿敷憮 馬餌м棲棻.                                  早\n");
				printf("早                                  羹溘婁 葆溘檜 賅舒 �蛹僱Ц�棻.                                早\n"); 
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				playerHp = playerMaxhp;
				playerMp = playerMaxmp;
				playerGold -= playerLv * 100;
				system("Pause");
				village(); // 葆擊煎
				return 1;
			}
			else
			{
				system("cls");
				printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
				printf("早                                   檜楛! 模雖旎檜 睡褶ж衛捱蹂!                                 早\n");
				printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				system("Pause");
				return 0;
			}
		}
		else if (ans == 78 || ans == 110)
		{
			village(); // 葆擊煎
			return 1;
		}
		else
		{
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早                                      憲 熱 橈朝 殮溘殮棲棻.                                    早\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

			system("Pause");
			return 0;
		}
	case 2: // 葆擊煎 釭除棻.
		village();
		break;
	default: // 螃盟高
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                      憲 熱 橈朝 殮溘殮棲棻.                                    早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

		system("Pause");
		return 0;
	}
}

int shop()
{
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT(BGM_shop), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("                                    天天天天天天天天天天天天天天天天                                \n");
	printf("                                   /    ::                     ::   ;                               \n");
	printf("                                  /     ::       __________    ::    ;                              \n");
	printf("                                 / :____::_______:    o   :____::_____:                             \n");
	printf("                                / /                                  /                              \n");
	printf("                               / /                                  /                               \n");
	printf("                               :/__________________________________/                                \n");
	printf("                              :′                                  ′                               \n");
	printf("                              :**′            偃嫦醞殮棲棻.         ′                             \n");
	printf("                              :****′ _________________________________′                           \n");
	printf("                              :******:     ::    :    :   :    ::        :                          \n");
	printf("                              ′*****:     ::    :________:    ::        :                          \n");
	printf("                                ′***:     ::                  ::        :                          \n");
	printf("                                  ′*:_____::__________________::________:                          \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	system("pause");
	system("cls");
	sword();
	village();
}

int slime() {
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
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
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

int sword() {
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("                                                                                                    \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("                                    C′                              _,-;                           \n");
	printf("                                      /C_____________________,.-'*'^^ .;                            \n");
	printf("                              ,n#:##:#}{------------------ - - - __.-^'                             \n");
	printf("                                       ;/,-'''^^^^^^^^^^^^^^^^^^^^                                  \n");
	printf("                                     c/'                                                            \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("                                         <綠彰и 濠曖 螃膩脹 匐>                                    \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("                                                                                                    \n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	system("pause");
}
