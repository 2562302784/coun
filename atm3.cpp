#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void InitialPassword();//初始化密码函数
void HomePage();//中文菜单页
void LoadData();//初始化
void SaveData();

void WithdrawMoney();//取款业务
void TransferMoney();//转账业务
void Enquiry();//查询业务
void EnquiryBalance();//查询余额
void EnquiryInformation();//查询个人信息


void ChangeInformation();//修改信息选项页
void ChangeUser();//修改用户名称
void ChangeAccountNum();//修改账户
void Changephone();//修改联系电话
void ChangePassword();//修改密码




int n;




//用户信息
struct Account
{
	char name[100];
	char username[21];
	char phonenum[12];
	char password[7];
	float balance=10000.00;

	struct Account* next;
};

typedef struct Account Account;

Account* head = NULL;
Account* tail = NULL;
Account* curAccount;



int findAccount2(Account A)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->username, A.username) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}



//查找当前账户
int findAccount1(Account a)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->username, a.username) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//初始化密码
void InitialPassword()
{
	strcpy(curAccount->password, "000000");
}

//验证当前账户密码
int findAccount(Account a)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->password, a.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


//取款业务
void WithdrawMoney()
{
	int a;
	printf("请输入你要取出的金额\t");
	printf("金额为100的整数\n");
	scanf("%d", &a);
	if (a % 100)
	{
		printf("金额为100的整数!请重新输入\n");
	}
	else
	{
		printf("取款成功\n");
	}
}

//转账业务
void TransferMoney()
{
	int a;
	printf("请输入你要转账的账户\t");
	printf("金额为100的整数\n");
	scanf("%d", &a);
	if (a%100)
	{
		printf("金额为100的整数!请重新输入\n");
	}
	else
	{
		printf("转账成功\n");
	}
}

//查询业务页
void Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1：查询余额\n");
		printf("\n\t2：查询个人信息\n");
		printf("\n\t3：返回主页\n");
		printf("\n\t0：退出系统\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			EnquiryBalance();
			k == 3;
			break;
		case 2:
			EnquiryInformation();
			k == 3;
			break;
		case 3:
			HomePage();
			k == 3;
			break;
		case 0:
			k == 3;
			SaveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//查询余额
void EnquiryBalance()
{
	printf("\t您的余额为：\n\t\t%lf\n",&curAccount->balance);
	printf("\n");
	int a,k = 0;
	while (k < 3)
	{
		printf("\n\t1：返回上一页\n");
		printf("\n\t2：返回主页\n");
		printf("\n\t0：退出系统\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Enquiry();
			k == 3;
			break;
		case 2:
			HomePage();
			k == 3;
			break;
		case 0:
			k == 3;
			SaveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//查询个人信息
void EnquiryInformation()
{
	printf("\t姓名：\n\t\t%s\n", curAccount->name);
	printf("\t账号：\n\t\t%s\n", curAccount->username);
	printf("\t联系电话：\n\t\t%s\n", curAccount->phonenum);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1：返回上一页\n");
		printf("\n\t2：返回主页\n");
		printf("\n\t0：退出系统\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Enquiry();
			k == 3;
			break;
		case 2:
			HomePage();
			k == 3;
			break;
		case 0:
			k == 3;
			SaveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//修改用户
void ChangeUser()
{
	int a,k = 0;
	char Password[100];
	while (k<3)
	{
		printf("请输入密码：\n");
		scanf("%s", Password);
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新用户名称:\n");
			scanf("%s", curAccount->name);
			printf("\n");
			printf("用户名称修改成功！\n");
			SaveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页\n");
				printf("\n\t2：返回主页\n");
				printf("\n\t0：退出系统\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k == 3;
					break;
				case 2:
					HomePage();
					k == 3;
					break;
				case 0:
					k == 3;
					SaveData();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n",3-k);
		}
	}
}

//修改账户
void ChangeAccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("请输入密码：\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新账户号码:\n");
			scanf("%s", curAccount->username);
			system("cls");
			printf("\n");
			printf("账户号码修改成功！\n");
			SaveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页\n");
				printf("\n\t2：返回主页\n");
				printf("\n\t0：退出系统\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					HomePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					SaveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}


//修改联系电话
void Changephone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("请输入密码：\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新联系电话号码:\n");
			scanf("%s", curAccount->phonenum);
			system("cls");
			printf("\n");
			printf("联系电话修改成功！\n");
			SaveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页\n");
				printf("\n\t2：返回主页\n");
				printf("\n\t0：退出系统\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					HomePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					SaveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}


//修改密码
void ChangePassword()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("请输入密码：\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新密码:\n");
			scanf("%s", curAccount->password);
			system("cls");
			printf("\n");
			printf("密码修改成功！\n");
			SaveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页\n");
				printf("\n\t2：返回主页\n");
				printf("\n\t0：退出系统\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					HomePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					SaveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
		}
	}
}


//修改信息选项页
void ChangeInformation()
{
	system("cls");
	int a, k2 =1;
	while (k2)
	{
		printf("\n\t1.修改用户\n");
		printf("\n\t2.修改账号\n");
		printf("\n\t3.修改联系电话\n");
		printf("\n\t4.修改密码\n");
		printf("\n\t9.返回上一页\n");
		printf("\n\t0.退出系统\n");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			ChangeUser();
			k2 = 0;
			break;
		case 2:
			ChangeAccountNum();
			k2 = 0;
			break;
		case 3:
			Changephone();
			k2 = 0;
			break;
		case 4:
			ChangePassword();
			k2 = 0;
			break;
		case 9:
			HomePage();
			k2 = 0;
			break;
		case 0:
			SaveData();
			exit(0);
		default:
			system("cls");
			printf("输入错误！\t请按照提示重新输入：\n");
			break;
		}
	}
}

//中文菜单页
void HomePage()
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\t1.取款\n");
		printf("\n\t2.转帐\n");
		printf("\n\t3.查询\n");
		printf("\n\t4.修改个人资料\n");
		printf("\n\t0.退出系统\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			WithdrawMoney();
			break;
		case 2:
			TransferMoney();
			break;
		case 3:
			Enquiry();
			break;
		case 4:
			ChangeInformation();
			break;
		case 0:
			SaveData();
			exit(0);
			break;
		default:
			printf("输入错误！\n");
			k1 = 1;
			break;
		}
	}
}

//英语菜单
void EnglishhomePage()
{
	int a, k = 1;
	while (k)
	{
		k = 0;
		printf("====================（没有完善完毕）\n");
		printf("1.Withdraw money.\t");
		printf("2.Transfer money.\n");
		printf("3.Change password.\n");
		printf("==========\n");
		printf("0.Exit program.\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			WithdrawMoney();
			break;
		case 2:
			TransferMoney();
			break;
		case 3:
			ChangePassword();
			break;
		case 0:
			SaveData();
			exit(0);
			break;
		default:
			printf("Error！\n");
			k = 1;
			break;
		}
	}
}

//中文登录
void ChineseSignIn()
{
	system("cls");
	int m=0,n=0;
	while (m < 3)//3次输入错账号将退出系统
	{
		Account a;
		printf("\n\t请输入账号：\n");
		scanf("%s", a.username);
		system("cls");
		if (findAccount1(a))
		{
			while (n<3)//3次输入错密码将退出系统
			{
				printf("\n\t请输入密码：\n");
				scanf("%s", a.password);
				system("cls");

				if (findAccount(a))
				{
					m = 3;
					n = 3;
					printf("\n==========登录成功==========\n");
					HomePage();
					break;
				}
				else
				{
					m++;
					n++;
					if (n==3)
					{
						printf("\n\t该账号已经被冻结，请联系后台找回。\n");
						InitialPassword();
						break;
					}
					else
					{
						printf("\n\t密码错误  %d次机会后账号将会被冻结\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\t没有查找到该用户!  %d  请重新输入：\n",3-m);
			if (m==3)
			{
				printf("\n\t错误，已退出系统\n");
				SaveData();
				exit(0);
			}
		}
	}
}

//打印当前链表
void printAccount(Account* curP)
{
	printf("%s\t%s\n", curP->username, curP->password);
}

/*void printLinkedList()
{
	Account* curP = head;
	while (curP != NULL)
	{
		printf("%s\t%s\t%s\t%s\n", curP->name, curP->username, curP->iphonenum, curP->password);
		curP = curP->next;
	}
}*/

//打印链表
void printLinkedList()
{
	Account* curP = head;
	while (curP != NULL)
	{
		printAccount(curP);
		curP = curP->next;
	}
}

//中文注册
void ChineseSignUp()//中文注册函数
{
	int a,k = 0;
	printf("\n\t欢迎注册\n\n");

	Account* P = (Account*)malloc(sizeof(Account));
	P->next = NULL;
	if (head == NULL)
	{
		head = P;
		tail = P;//如果这是第一个创建的结点，则将头 尾指针指向这个结点
	}
	else
	{
		tail->next = P; //如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		printf("请输入你的姓名\n");
		scanf("%s", P->name);
		Account A;
		printf("请输入你即将注册的账户号码【10位】\n");
		scanf("%s", A.username);

		
		if (findAccount2(A))
		{
			printf("该账号已经被注册不可用\n");
			exit(0);
		}
		else
		{
			strcpy(P->username,A.username);
		}
		printf("请输入你的电话号码【11位】\n");
		scanf("%s", P->phonenum);
		printf("请设置你的账户密码【6位】\n");
		scanf("%s", P->password);
		SaveData();
		while (k<3)
		{
			system("cls");
			printf("\n\t1：返回登录\n");
			printf("\n\t0：退出系统\n");
			scanf("%d", &a);
			if (a == 1)
			{
				ChineseSignIn();
				break;
			}
			else if (a == 0)
			{
				exit(0);
			}
			else
			{
				k++;
				printf("密码输入错误! \t%d\t请按照提示重新输入：\n", 3 - k);
			}
		}
	}
}

//英语注册
void EnglishSignUp()//英语注册函数
{
	printf("Welcome.\n");
	printf("\n");

	Account* P = (Account*)malloc(sizeof(Account));
	P->next = NULL;
	if (head == NULL)
	{
		head = P;
		tail = P;
	}
	else
	{
		tail->next = P;
		printf("please enter your name.\n");
		scanf("%s", P->name);
		printf("please enter your account number.[20 figures]\n");
		scanf("%s", P->username);
		printf("please enter your cell phone number.[11 figures]\n");
		scanf("%s", P->phonenum);
		printf("please setting your account password.[6 figures]\n");
		scanf("%s", P->password);
	}
}

//英语登录
void EnglishSignIn()
{
	int k = 0;
	while (k < 3)
	{
		Account a;
		printf("please enter your account number.[20 figures]：\n");
		scanf("%s", a.username);

		printf("please enter your account password.[6 figures]：\n");
		scanf("%s", a.password);

		if (findAccount(a))
		{
			k = 3;
			printf("Login successful!\n");
			EnglishhomePage();
		}
		else
		{
			k++;
			if (k!=3)
			{
				printf("Login failed. Please try again.\n");
			}
			else
			{
				printf("Login failed.\n");
				printf("\n");
				printf("EXIT PROGRAM...\n");
			}
		}
	}
}

//初始化
void LoadData()//初始化函数
{
	FILE* fp = fopen("D:/atm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\n", newNodeP->name, newNodeP->username, newNodeP->phonenum, newNodeP->password);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

//开始界面
void start()
{
	int n1,k=1;
	while (k)
	{
		printf("\n请选择语言：\t");
		printf("Please choose language：\n");
		printf("\n\t1：中文\n");
		printf("\n\t2：English\n");
		printf("\n\t0：退出 Exit\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			system("cls");
			printf("\n\t1：用户注册\n");
			printf("\n\t2：用户登录\n");
			printf("\n\t其它：返回上一页\n");
			scanf("%d", &n1);
			k = 0;
			if (n1 == 1)
			{
				ChineseSignUp();//中文注册函数
			}
			else if (n1 == 2)
			{
				ChineseSignIn();
			}
			else
				k = 1;
			break;
		case 2:
			system("cls");
			printf("\n\t1：Sign up\n");
			printf("\n\t2：Sign in\n");
			printf("\n\tOthers：Back to previous page\n");
			scanf("%d", &n1);
			k = 0;
			break;
			if (n1 == 1)
			{
				EnglishSignUp();//英语注册函数
			}
			else if (n1 == 2)
			{
				EnglishSignIn();
			}
			else
				k = 1;
		case 0:
			SaveData();
			exit(0);
		default:
			k = 1;
			printf("\n\t输入有误，请按照提示再次输入!\t");
			printf("\t");
			printf("Error,please follow the prompts to enter again!\n");
			break;
		}
	}
}


//保存数据
void SaveData()
{
	FILE* fp = fopen("D:/atm.txt", "w");
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\n", curP->name, curP->username, curP->phonenum, curP->password);
			curP = curP->next;
		}
		fclose(fp);
	}
}

int main()
{
	LoadData();
	start();

	printLinkedList();
	SaveData();
	return 0;
}
