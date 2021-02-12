#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<time.h>
#include<iomanip>
using namespace std;
int countA = 0, countB;
int checker = 0;
fstream fin, fout, fturndoc, ftemp, fadmin, fcross, fsum;
class issues;
class SecuredLogin;
class heartAttack
{
	int id;
	char name[200];
	int age;
	float height;
	float weight;
	char sex;
	long long int phn;
public:
	friend class doctor;
	friend class issues;
	friend class SecuredLogin;
	friend class adminstration;
	friend class client;
	void twist();
	void welcome();
	void enterdata();
	void doctorlist();
	void test();
	void totaltest();
	void search();
	void deldata();
	void prereport();
	void aboutme();
	void admin();
	void reply();
	void setlock();
	void inquiries();
	int report();
	int display(int, int);
	void showqu();
	void update();
	void adminre();
	void clientSecuredLogin();
	void treatrecord();//left
}mainobj;


class SecuredLogin
{
public:
	friend class doctors;
	friend class issues;
	friend class heartAttack;
	void password();
}passo;


class doctor
{
public:
	friend class heartAttack;
	int id;
	int idofdoc;
	struct date
	{
		int d, m, y;
	}st;
}docp;


class issues
{
public:
	friend class heartAttack;
	int id, vision, chestDiscomfit, bodyWeakness, breathShortness;
	char bg[2];
	int dizziness, fatigue;
	char fam, weight;
	char Nutrition;
	float troponinLevel;
	float bloodPressureNum, blpressuredem;
	float bloodcount;
	float levelOfGlucose;
	float glucose1;
}objp;
class bill
{
	friend class doctor;
	friend class issues;
	friend class SecuredLogin;
	friend class adminstration;
	friend class client;
public:
	int id;
	int billid;
	int sum;
	enum fee { Philip = 600, Ben = 500, Sarah = 700, Esther = 900, Joseph = 550 };
	void total();

}bobj;
class client
{
public:
	friend class issues;
	friend class heartAttack;
	friend class quick;
	friend class doctor;
	int buyid;
	void updatemine();
	void buy();
	void medicare();
	void diseaselevel();
	void seem();
	void complaints();
	void docchange();
	char comp[2000];
	char send[2000];
}pa;

class adminstration
{
private:
	int clientId;
	int staffId;
	char staffName[30];
	char doctorName[30];
	int  doctorId;
	long long int phna;
	char staffUserId[30];
	char password[30];         //password staff
public:
	int medicineId;
	char medicines[300];       //Name of medicine
	float medicinePrice;
	char re[200];
	friend class issues;
	friend class heartAttack;
	friend class doctor;
	friend class paitent;
	void stpassword();
	void medi();               //medicine name provider along price
	void calcbill();           //along with medicines and doctor fees if no medicine then only that
	void adddoc();             //junior doctors
	void adminsi();
	void count();
	void duty();
	void complains();
	void msgs();
	//class risk
	//{
	//	public:




	//};
}admino;
class discuss
{
public:
	friend class heartAttack;
	friend class doctors;
	friend class client;
	friend class issues;
	friend class adminstration;
	int id;
	char name[20];
	char reply[200000];
	char input[200000];
}q;
class finalreport

{
public:
	friend class heartAttack;
	friend class doctors;
	friend class client;
	friend class issues;
	int id;                         // to detect
	char dbresult;                  //level
}freport;
class quick
{
	char name[300];
	int gid;
	int age;
	float troponin;
	float weight;
	float bodytemp;
	int moption;
	void buy();
public:
	friend class heartAttack;
	friend class client;
	quick()
	{
		char ch;
		system("cls");
		char chwer[] = { "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n" };
		int l = strlen(chwer);
		int kk;
		for (kk = 0; kk < l; kk++)
		{
			Sleep(10);
			cout << chwer[kk];
		}
		char chwer1[] = { "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n" };
		l = strlen(chwer1);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(10);
			cout << chwer1[kk];
		}

		char chwer2[] = { "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n" };
		l = strlen(chwer2);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(10);
			cout << chwer2[kk];
		}
		cout << "\n\n Enter the name : ";
		fflush(stdin);
		gets(name);
		srand((time(NULL)));
		gid = rand() % 1161400 + 200000;
		cout << "\n\n ID Generated : ";
		cout << gid;
		cout << "\n\n Enter Age : ";
		cin >> age;
		cout << "\n\n Do you experience symptoms like becoming//having :\n\n 1>Chest Discomfit 2>Dizziness 3>Fatigueness 4>Vision Problem 5>Shortness of Breath 6>Body Weakness??\n\n";
		cout << " Enter Y for Yes : ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			cout << "\n\n You may be at risk of getting heart attack, as these are some of the key symptoms!!";
		else
			cout << "\n\n You may not at risk of getting heart attack  but it is still not sure!!";
		cout << "\n\n Let the nurse take your blood sample  ";
		sleep(2);
		cout << "\n\n Please Wait Taking Blood Sample  ";
		sleep(2);
		cout << "\n\n Analyzing Blood Samples  ";
		sleep(2);
		cout << "\n\n Thanks for being patient ";
		sleep(2);
		cout << "\n\n TEST INITIALIZED : ";
		cout << "\n\n Enter the weight : ";
		cin >> weight;
		cout << "\n\n Enter the The AQT90 FLEX immunoassay analyzer  and the Glucometer readings  : ";
		cin >> troponin;
		cout << "\n\n Enter the body temperature : ";
		cin >> bodytemp;
		cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
		cout << "\t\t\t\t\t\t\t\t\t Generating Report ";
		cout << "\n\n Analyzing Symptoms ";
		sleep(1);
		cout << "\n\n Analyzing Blood Sample ";
		sleep(1);
		cout << "\n\n Analyzing Body temperature ";
		sleep(1);
		cout << "\n\n Getting things done ";
		sleep(2);
		system("cls");
		cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n";
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
		cout << "\t\t\t\t\t\t\t\t\t\tREPORT";
		cout << "\n\n Name : " << name;
		cout << "\n\n Age : " << age;
		cout << "\n\n Weight : " << weight;
		cout << "\n\n Body Temp : " << bodytemp;
		cout << "\n\n";
		int blood;
		srand(time(NULL));
		blood = rand() % 1 + 7;
		if (blood == 1)
		{
			cout << " Blood Group : " << " A+ ";
		}
		else if (blood == 2)
		{
			cout << " Blood Group : " << " A-";
		}
		else if (blood == 3)
		{
			cout << " Blood Group : " << " B+";
		}
		else if (blood == 4)
		{
			cout << " Blood Group : " << " B-";
		}
		else if (blood == 5)
		{
			cout << " Blood Group : " << " O+";
		}
		else if (blood == 6)
		{
			cout << " Blood Group : " << " O-";
		}
		else if (blood == 7)
		{
			cout << " Blood Group : " << " AB+";
		}
		else if (blood == 8)
		{
			cout << " Blood Group : " << " AB-";
		}
		else
		{
			cout << " Blood Group : " << " O+";
		}
		float bloodcount;
		srand(time(NULL));
		bloodcount = rand() % 4000 + 10000;
		if (bloodcount < 4500)
		{
			cout << "\n\n Blood Count : Low -> " << bloodcount;
		}
		else if (bloodcount >= 4500 && bloodcount < 10000)
		{
			cout << "\n\n Blood Count : High -> " << bloodcount;
		}
		float hemoglobin;
		srand(time(NULL));
		hemoglobin = rand() % 10 + 9;
		if (hemoglobin >= 12 && hemoglobin < 16)
			cout << "\n\n Hemoglobin level -> Normal : " << hemoglobin << " grams per deciliter";
		if (hemoglobin < 12)
			cout << "\n\n Hemoglobin level -> LOW : " << hemoglobin << " grams per deciliter";
		if (hemoglobin > 16)
			cout << "\n\n Hemoglobin level ->  : " << hemoglobin << " grams per deciliter";


		float cholesterol;
		srand(time(NULL));
		cholesterol = rand() % 25 + 100;
		if (cholesterol <= 100)
			cout << "\n\n Cholesterol -> IDEAL ->  " << cholesterol << " mg/dl";
		else if (cholesterol > 100 && cholesterol <= 129)
			cout << "\n\n Cholesterol -> Close to Ideal -> " << cholesterol << " mg/dl";
		else if (cholesterol >= 130 && cholesterol <= 159)
			cout << "\n\n Cholesterol -> Borderline ->  " << cholesterol << " mg/dl";
		else if (cholesterol >= 160 && cholesterol <= 189)
			cout << "\n\n Cholesterol ->  High ->  " << cholesterol << " mg/dl";
		else if (cholesterol >= 190 && cholesterol <= 240)
			cout << "\n\n Cholesterol ->  Highly Dangerous ->  " << cholesterol << " mg/dl";

		if (troponin < 0.04)
			cout << "\n\n Normal Troponin Level : ->No signs of heart attack till now ";
		else if (troponin >= 0.04 && troponin <= 0.39)
			cout << "\n\n High Troponin Level : Probably Problem with the heart 1 :->May lead to heart attack ";
		else if (troponin >= 0.40)
			cout << "\n\n High Troponin Level : Problem with the heart 2 :->Probably heart attack ";
        else
            cout <<"You are fine : ";

		cout << "\n\n This is on the basis of a simple test only please take appointment from doctor for much more and clear understanding and for complete treatment\n\n";
		cout << "\n\n Generating Medicine Suggestions ";
		sleep(5);
		if (troponin >= 0.04 && troponin <= 0.39)
		{
			system("cls");
			cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n";
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
			cout << "\t\t\t\t\t\t\t\t\t\tMedicines";
			cout << "\n\n 1. Apixaban \n\n 2. Clopidogel \n\n 3. Benazepril \n\n 4. Azilsartan \n\n 5. Atenolol \n\n";
			srand(time(NULL));
			moption = rand() % 4 + 1;
			cout << "\n\n YOU CAN TAKE ANY OF THESE BUT ITS BETTER IF YOU TAKE OPTION : " << moption;
			cout << "\n\n Suggested Medicine : ";
			if (moption == 1)
				cout << "Apixaban";
			else if (moption == 2)
				cout << "Clopidogel";
			else if (moption == 3)
				cout << "Benazepril";
			else if (moption == 4)
				cout << "Azilsartan";
			else if (moption == 5)
				cout << "Atenolol";
			cout << "\n\n Take 2 tablets Per day after meal";
			cout << " \n\n Before Buying We would like you to take full test ";
			cout << " If you want to buy you can buy Press Y ";
			cout << " Your Preference : ";
			char ch2;
			cin >> ch2;
			if (ch2 == 'Y' || ch == 'y')
				buy();
			else
				mainobj.twist();
		}
		else if (troponin >= 0.40)
		{
			system("cls");
			cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S CHRONIC DISEASE DIAGNOSTIC CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n";
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
			cout << "\t\t\t\t\t\t\t\t\t\tMedicines";
			cout << "\n\n 1. Statins \n\n 2. Aspirin\n\n 3. Warfarin \n\n 4. Beta-blockers \n\n 5. ACE inhibitors \n\n";
			srand(time(NULL));
			moption = rand() % 4 + 1;
			cout << "\n\n YOU CAN TAKE ANY OF THESE BUT ITS BETTER IF YOU TAKE OPTION : " << moption;
			cout << "\n\n Suggested Medicine : ";
			if (moption == 1)
				cout << "Statins";
			else if (moption == 2)
				cout << "Aspirin";
			else if (moption == 3)
				cout << "Warfarin";
			else if (moption == 4)
				cout << "Beta-blockers";
			else if (moption == 5)
				cout << "ACE inhibitors";
			cout << "\n\n Take 2 tablets Per day after meal";
			cout << " \n\n Before Buying We would like you to take full test ";
			cout << " If you want to buy you can buy Press Y ";
			cout << " Your Preference : ";
			char ch2;
			cin >> ch2;
			if (ch2 == 'Y' || ch == 'y')
				buy();
			else
				mainobj.twist();
		}
		else
		{
			cout << " No Medicine Required But keep Good Health, Diet and do some exercises";
		}
	}
};

class diet
{
public:
	diet()
	{
		system("cls");
		char chwer[] = { "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n" };
		int l = strlen(chwer);
		int kk;
		for (kk = 0; kk < l; kk++)
		{
			Sleep(10);
			cout << chwer[kk];
		}
		char chwer1[] = { "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n" };
		l = strlen(chwer1);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(10);
			cout << chwer1[kk];
		}

		char chwer2[] = { "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n" };
		l = strlen(chwer2);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(10);
			cout << chwer2[kk];
		}
		char name[300], ch;
		cout << "\n\n Enter Your Name Please : ";
		fflush(stdin);
		gets(name);
		cout << "\n\n Enter weather you have heart diseases or not(Y/N) ? ";
		cout << "\n\n Your Preference : ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << " Special Diet is to be followed !!";
			cout << "\n\n Here We Go";
			sleep(1); cout << "\n\n1\t\t"; sleep(1); cout << "2\t\t"; sleep(1); cout << "3\t\t";
			system("cls");
			char chwer[] = { "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n" };
			l = strlen(chwer);
			int kk;
			for (kk = 0; kk < l; kk++)
			{
				Sleep(10);
				cout << chwer[kk];
			}
			char chwer1[] = { "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n" };
			l = strlen(chwer1);
			for (kk = 0; kk < l; kk++)
			{
				Sleep(10);
				cout << chwer1[kk];
			}

			char chwer2[] = { "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n" };
			l = strlen(chwer2);
			for (kk = 0; kk < l; kk++)
			{
				Sleep(10);
				cout << chwer2[kk];
			}

			cout << "\n\n Healthy fats from fish oils, olive oil, coconut oils\n\n flax seeds, or avocados Fruits and vegetables�ideally fresh\n\n the more colorful the better\n\n whole fruit rather than juices High-fiber cereals and breads made from whole grains or legumes Fish and shellfish\n\n organic chicken or turkey\n\n High-quality protein such as eggs, beans, low-fat dairy, and unsweetened yogurt";
			cout << "\n\n";
			cout << " Brown or wild rice, riced cauliflower\n\n Sweet potatoes, cauliflower mash \n\n Whole-wheat pasta, spaghetti squash \n\n High-fiber, low-sugar cereal \n\n Steel-cut or rolled oats";
			cout << "\n\n";
		}
		else
		{
			cout << "\n\n You can continue your normal diet : ";
		}
		sleep(8);
		mainobj.twist();
	}
};

void SecuredLogin::password()
{
	system("cls");
	int i;
	char asecuredlogin[9], apassword[12];
	char secured_login[] = "software1";
	char pass[] = "software2050";
	char iot;
	iot = getch();
	system("cls");
	char chwer[] = { "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n" };
	int l = strlen(chwer);
	int kk;
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer[kk];
	}
	char chwer1[] = { "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n" };
	l = strlen(chwer1);
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer1[kk];
	}

	char chwer2[] = { "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n" };
	l = strlen(chwer2);
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer2[kk];
	}
	char take[] = { "\n\n Enter SecuredLogin_id: " };
	int d1 = strlen(take);
	for (kk = 0; kk < d1; kk++)
	{
		Sleep(15);
		cout << take[kk];
	}
	char a;
	cin >> asecuredlogin;
	if (strcmp(asecuredlogin, secured_login) == 0)
	{

		char take1[] = { "\n\n Enter Password: " };
		d1 = strlen(take1);
		for (kk = 0; kk <= d1; kk++)
		{
			Sleep(15);
			cout << take1[kk];
		}
		for (i = 0; i < 13; i++)
		{
			a = getch();
			if (a == 13)
				break;
			else if (a == 8)
			{
				if (i > 0)
					cout << "\b \b";
				i = i - 2;
				continue;
			}
			if (i < 0)
				i = 0;
			else
				putchar('*');
			apassword[i] = a;
		}
		apassword[i] = '\0';
		if (strcmp(apassword, pass) == 0)
		{
			char re[] = { "\n\n\n SecuredLogin Successfull\n\n " };
			int rp = strlen(re);
			int u;
			for (u = 0; u < rp; u++)
			{
				Sleep(14);
				cout << re[u];
			}
			sleep(2);
			checker = 1;
		}
		else
		{
			checker = 2;
			cout << "\n\n Incorrect password";
		}
	}
	else
	{
		cout << "\n\n Invalid SecuredLogin_id\\Username\n\n";
	}
}
void heartAttack::twist()
{
	system("cls");
	int ch;
	char chwer[] = { "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER \t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority!\n" };
	int l = strlen(chwer);
	int kk;
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer[kk];
	}
	char chwer1[] = { "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n" };
	l = strlen(chwer1);
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer1[kk];
	}

	char chwer2[] = { "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n" };
	l = strlen(chwer2);
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer2[kk];
	}
	cout << "\t\t\t\t\t\t\t\t\tChoose the operation \n\n\n 1-> CLIENT \n\n 2-> ADMIN \n\n 3-> INQUIRIES \n\n 4-> INQUIRIES REPLY \n\n 5-> Quick Checkup\n\n 6-> Diet Planner \n\n 7-> Log Out\n\n 8-> Exit";
	cout << "\n\n Your Preference-> ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		welcome();
		break;

	case 2:
		setlock();
		if (countA != 0)
			admin();
		else
			cout << "\n\n\n Access Denied!! Terminating ";
		sleep(3);
		twist();
		break;
	case 3:
		inquiries();
		break;
	case 4:
		showqu();
		break;
	case 5:
		quick();
		break;
	case 6:
		diet();
		break;
	case 7:
		cout << "\n Logging Out.....\n\n";
		sleep(2);
		passo.password();
		break;
	case 8:
		cout << "\n\n Exiting...\n\n";
		sleep(2);
		exit(0);
		break;
	default:
		cout << " You have entered wrong key \n\n";
		break;
	}
}
void heartAttack::welcome()
{
	system("cls");

	cout << "\n";
	int ch;
	char check;
A:
	char chwer[] = { "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\Your Health, Our Priority!\n" };
	int l = strlen(chwer);
	int kk;
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer[kk];
	}
	char chwer1[] = { "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n" };
	l = strlen(chwer1);
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer1[kk];
	}

	char chwer2[] = { "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n" };
	l = strlen(chwer2);
	for (kk = 0; kk < l; kk++)
	{
		Sleep(10);
		cout << chwer2[kk];
	}
	cout << "\t\t\t\t\t\t\t\t   CHOOSE THE OPTIONS FROM MENU\n\n 1: ENTER DATA\n\n 2: GET\\TAKE APPOINTMENT\n\n 3: LIST OF PAITENTS\n\n 4: TEST\n\n 5: Pre-Report\n\n 6: FINAL REPORT\n\n 7: CLIENT-SecuredLOGIN\n\n 8: ABOUT DEVELOPER OF THIS CODE\n\n 9: EXIT\n\n";
	cout << "\n YOUR PREFERENCE : ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		enterdata();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 2:
		doctorlist();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 3:
		display(10, 20);
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 4:
		test();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 5:
		prereport();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 6:
		report();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 7:
		clientSecuredLogin();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}

	case 8:
		aboutme();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto A;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 9:
		cout << " Exiting.... \n\n ";
		sleep(2);
		twist();
		exit(0);
	}
}
main()
{
	int i = 3;
	heartAttack o;
d:
	system("cls");
	passo.password();
	if (checker == 1)
	{
		mainobj.twist();
	}
	else if (checker == 2)
	{
		cout << "\n\n Server Crashed due to heavy traffic or You Entered Incorrect Password\n";
		cout << "\n\n Try Again in few seconds\n\n";
		char ch12[] = { "\n\n Reloading in 5 seconds\n\n" };
		int kk, l;
		for (kk = 0; kk < l; kk++)
		{
			Sleep(15);
			cout << ch12[kk];
		}
		char ch13[] = { "\n\n Reloading in 4 seconds\n\n" };
		l = strlen(ch13);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(15);
			cout << ch13[kk];
		}
		char ch14[] = { "\n\n Reloading in 3 seconds\n\n" };
		l = strlen(ch14);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(15);
			cout << ch14[kk];
		}
		char ch15[] = { "\n\n Reloading in 2 seconds\n\n" };
		l = strlen(ch15);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(15);
			cout << ch15[kk];
		}
		char ch16[] = { "\n\n Reloading in 1 seconds\n\n" };
		l = strlen(ch16);
		for (kk = 0; kk < l; kk++)
		{
			Sleep(15);
			cout << ch16[kk];
		}
		if (i >= 1)
		{
			goto d;
			i--;
		}
		else
			cout << "\n\n Interface Locked due to many invalid tries\n\n";
	}
}
void heartAttack::enterdata()
{
	int i, num = 0;
	fout.open("HEARTATTACTDATA.txt", ios::app);
	system("cls");
	cout << "\t\t\t\t\tWelcome!\n";
	cout << "\n\t\t\tPLEASE FILL ALL THE REQUIRED DATA\n";
	cout << "\n\n ";
	cout << " Enter The no. of paitents : ";
	cin >> num;
	cout << "\n\n ";
	for (i = 0; i < num; i++)
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
		cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
		cout << "\n\n ";
		cout << " PLEASE ASK THE ID number AND ENTER IT : ";
		cin >> id;
		cout << "\n\n";
		cout << " 1 : ENTER NAME : ";
		scanf("%s", name);
		fflush(stdin);
		cout << "\n\n 2 : AGE : ";
		cin >> age;
		cout << "\n\n 3 : SEX(M/F) : ";
		cin >> sex;
		cout << "\n\n 4 : Height : ";
		cin >> height;
		cout << "\n\n 5 : Weight : ";
		cin >> weight;
		cout << "\n\n 6 : Phone number : ";
		cin >> phn;
		fout.write((char*)&mainobj, sizeof(mainobj));
	}
	fout.close();
}
int heartAttack::display(int a, int b)
{
	fin.open("HEARTATTACKDATA.txt", ios::in);
	system("cls");
	cout << "\t\t\t\tHere's the Data of all paitents\n\n\n";


	cout << "|\t ID\t   |             NAME                 |  AGE    |   SEX   |   HEIGHT    |   WEIGHT      |\n";
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		cout << "|" << setw(9) << id << setw(10) << "|" << setw(15) << name << setw(20) << "|" << setw(5) << age << setw(5) << "|" << setw(5) << sex << setw(5) << "|" << setw(7) << height << setw(7) << "|" << setw(7) << weight << setw(7) << "\t|\n\n";
	}
	fin.close();
}
void heartAttack::search()
{
	system("cls");
	fin.open("HEARTATTACKDATA.txt", ios::in | ios::out);
	int tempid, k = 0;
	char check;
	cout << "\t\t\t\tHeart Diseases Health Care\t\n";
	cout << "\n Enter the id no. of client : ";
	cin >> tempid;
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
		{
			k++;
			break;
		}
	}
	if (mainobj.id == tempid)
	{
		cout << "|\t ID\t   |             NAME                 |  AGE    |   SEX   |   HEIGHT    |   WEIGHT      |\n";
		cout << "|" << setw(9) << id << setw(10) << "|" << setw(15) << name << setw(20) << "|" << setw(5) << age << setw(5) << "|" << setw(5) << sex << setw(5) << "|" << setw(7) << height << setw(7) << "|" << setw(7) << weight << setw(7) << "\t|\n\n";
		cout << "\n ";
	}
	else
	{
		cout << " YOU HAVE ENTERED THE INVALID ID PLEASE TRY AGAIN \n";
	}
	fin.close();
}
void heartAttack::test()
{
	system("cls");
	int dd, mm, yyyy;
	cout << "\t\t\t\tHEART DISEASES HEALTH CARE!\n\n\n";
	fin.open("HEARTATTACKDATA.txt", ios::in | ios::out);
	fout.open("issues.txt", ios::app);
	fturndoc.open("Doctors1.txt", ios::in);
	int tempid, k = 0, count = 0;
	char check;
	cout << "\t\t\t\tHeart Diseases Health Care\t\n";
	cout << "\n\n Enter the id no. of client : ";
	cin >> tempid;
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
		{
			k++;
			break;
		}
	}
	if (mainobj.id == tempid)
	{
		cout << "\n\n Enter today's date(dd/mm/yyyy) : ";
		cin >> dd >> mm >> yyyy;
		while (fturndoc.read((char*)&docp, sizeof(docp)))
		{
			if (dd == docp.st.d && docp.st.m == mm && docp.st.y == yyyy && tempid == docp.id)
			{
				count = 1;
				break;
			}
			else
				count = 0;
		}
		if (dd == docp.st.d && docp.st.m == mm && docp.st.y == yyyy && tempid == docp.id)
		{
			objp.id = tempid;
			cout << "\n\n Please Answer The following Questions\n\n\n";
			cout << " Client name: ";
			cout << mainobj.name;
			cout << "\n\n\n";
			cout << " 1:Do you experience discomfit in the center of left side of the chest that lasts for more than a few minutes or that goes away and comes back.Enter the data accordingly(3-highly yes||2-medium yes||1-low yes||0-no)? -> ";
			cin >> objp.chestDiscomfit;
			cout << "\n\n\n";
			cout << " 2:Are you getting hungry fast.Enter the data accordingly(3-highly yes||2-medium yes||1-low yes||0-no)? -> ";
			cin >> objp.bodyWeakness;
			cout << "\n\n\n";
			cout << " 3:Are you getting urine frequently.Enter the data accordingly(3-highly yes||2-medium yes||1-low yes||0-no)? -> ";
			cin >> objp.breathShortness;
			cout << "\n\n\n";
			cout << " 4:Do you get dizziness?Enter the level(3-high||2-medium||1-low||0-no)? -> ";
			cin >> objp.dizziness;
			cout << "\n\n\n";
			cout << " 5:Do you feel fatiguness?Enter the level(3-high||2-medium||1-low||0-no)? -> ";
			cin >> objp.fatigue;
			cout << "\n\n\n";
			cout << " 6:How is your vision?Enter the level(3-highly Blurred||2-Partially Blurred||1-Sometimes Blurred||0-no)? -> ";
			cin >> objp.vision;
			cout << "\n\n 7.Was there anyy weight loss in your body in few days(y/n)?->";
			cin >> objp.weight;
			cout << "\n\n\n";
			cout << " 8.Has any body in your family had heart attack before?(y/n)?->";
			cin >> objp.fam;
			cout << "\n\n";
			sleep(2);
			system("cls");
			cout << "\n\n\n\t\t\t Thanks! Please Take the Test from doctor ";
			cout << "\n\n Taking Blood Sample : ";
			cout << "\n ";
			sleep(2);
			cout << "\n\n Wait for some time \n ";
			sleep(2);
			cout << "\n\n TESTING BLOOD \n ";
			sleep(2);
			cout << "\n\n Please be client and steady!! \n ";
			sleep(2);
			cout << "\n\n Blood Test Complete\n ";
			sleep(2);
			cout << "\n\n";
			cout << " Had a Meal or not(y/n) for past three hours? : ";
			cin >> objp.Nutrition;
			cout << "\n\n Enter Readings of AQT90 FLEX immunoassay analyzer and glucometer: ";
			cin >> objp.troponinLevel;
			cout << "\n\n\n";
			cout << " Enter the blood pressure(num) : ";
			cin >> objp.bloodPressureNum;
			cout << " Enter the blood pressure(den) : ";
			cin >> objp.blpressuredem;
			cout << "\n\n\n";
			cout << "\n\n Enter the level of Glucose(mg/dl)[This is Fasting Plasma Test(FPG)] -> : ";
			cin >> objp.levelOfGlucose;
			cout << "\n\n Enter the level of Glucose((mg/dl)[This is Oral Glucose Tolerance Test(OGTT)] -> : ";
			cin >> objp.glucose1;
			sleep(2);
			cout << "\n\n Test complete you may take the report at evening from reception.";
			cout << "\n\n\n";
			fout.write((char*)&objp, sizeof(objp));
		}
		else
		{
			cout << "\n\n There's no appointment Booked for such person";
		}
	}
	else
	{
		cout << "\n\n Invalid id Please Check and try again ";
	}
	fout.close();
	fin.close();
	fturndoc.close();
}
int heartAttack::report()
{
	float checkdb1 = 0, checkdb2 = 0, checkdb3 = 0;
	system("cls");
	cout << "\t\t\t\tHEART DISEASES HEALTH CARE!\n\n\n";
	fin.open("HEARTATTACKDATA.txt", ios::in);
	fout.open("issues.txt", ios::in);
	int tempid, k = 0;
	char check;
	cout << "\t\t\t\tHeart Diseases Health Care\t\n";
	cout << "\n Enter the id no. of client : ";
	cin >> tempid;
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
		{
			while (fout.read((char*)&objp, sizeof(objp)))
			{
				if (objp.id == tempid)
				{
					k++;
					break;
				}
			}
			break;
		}
	}
	if (mainobj.id == tempid)
	{
		cout << "|\t ID\t   |             NAME                 |  AGE    |   SEX   |   HEIGHT    |   WEIGHT      |\n";
		cout << "|" << setw(9) << id << setw(10) << "|" << setw(15) << name << setw(20) << "|" << setw(5) << age << setw(5) << "|" << setw(5) << sex << setw(5) << "|" << setw(7) << height << setw(7) << "|" << setw(7) << weight << setw(7) << "\t|\n\n";
		cout << "\n\n";
		cout << " 1.Chest Discomfit Level : ";
		if (objp.chestDiscomfit == 0)
			cout << " NO PROBLEM";
		else if (objp.chestDiscomfit == 1)
			cout << " LOW";
		else if (objp.chestDiscomfit == 2)
			cout << " MEDIUM";
		else if (objp.chestDiscomfit == 3)
			cout << " HIGH";
		cout << "\n\n";



		cout << " 2.Body Weakness Level: ";
		if (objp.bodyWeakness == 0)
			cout << " NO PROBLEM";
		else if (objp.bodyWeakness == 1)
			cout << " LOW";
		else if (objp.bodyWeakness == 2)
			cout << " MEDIUM";
		else if (objp.bodyWeakness == 3)
			cout << " HIGH";
		cout << "\n\n";



		cout << " 3.Dizziness Level: ";
		if (objp.dizziness == 0)
			cout << " NO PROBLEM";
		else if (objp.dizziness == 1)
			cout << " LOW";
		else if (objp.dizziness == 2)
			cout << " MEDIUM";
		else if (objp.dizziness == 3)
			cout << " HIGH";
		cout << "\n\n";



		cout << " 4.Fatigue Level: ";
		if (objp.fatigue == 0)
			cout << " NO PROBLEM";
		else if (objp.fatigue == 1)
			cout << " LOW";
		else if (objp.fatigue == 2)
			cout << " MEDIUM";
		else if (objp.fatigue == 3)
			cout << " HIGH";
		cout << "\n\n";



		cout << " 5.Breathing rate: ";
		if (objp.breathShortness == 0)
			cout << " NO PROBLEM";
		else if (objp.breathShortness == 1)
			cout << " LOW";
		else if (objp.breathShortness == 2)
			cout << " MEDIUM";
		else if (objp.breathShortness == 3)
			cout << " HIGH";
		cout << "\n\n";



		cout << " 6.Vision: ";
		if (objp.breathShortness == 0)
			cout << " NO PROBLEM";
		else if (objp.breathShortness == 1)
			cout << " LOW PROBLEM";
		else if (objp.breathShortness == 2)
			cout << " MEDIUM PROBLEM";
		else if (objp.breathShortness == 3)
			cout << " HIGH PROBLEM";
		cout << "\n\n";



		cout << " 7.BloodPressure :";
		if (objp.bloodPressureNum > 140)
		{
			if (objp.blpressuredem > 80)
			{
				cout << "High Blood Pressure\n";
			}
			else
				cout << "High Blood Pressure(cond(II))\n";
		}
		else if (objp.bloodPressureNum <= 140 && objp.bloodPressureNum >= 120)
		{
			if (objp.blpressuredem >= 80 && objp.blpressuredem <= 100)
				cout << " Normal Blood Pressure";
			else
				cout << " Normal Blood Pressure(II)";
		}
		else
		{
			cout << " Low Blood Pressure ";
		}
		cout << "\n\n\t\t\t\t\t\t\t\t Blood Report";
		cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
		int blood;
		srand(time(NULL));
		blood = rand() % 1 + 8;
		if (blood == 1)
		{
			cout << " Blood Group : " << " A+ ";
		}
		else if (blood == 2)
		{
			cout << " Blood Group : " << " A-";
		}
		else if (blood == 3)
		{
			cout << " Blood Group : " << " B+";
		}
		else if (blood == 4)
		{
			cout << " Blood Group : " << " B-";
		}
		else if (blood == 5)
		{
			cout << " Blood Group : " << " O+";
		}
		else if (blood == 6)
		{
			cout << " Blood Group : " << " O-";
		}
		else if (blood == 7)
		{
			cout << " Blood Group : " << " AB+";
		}
		else if (blood == 8)
		{
			cout << " Blood Group : " << " AB-";
		}
		else
		{
			cout << " Blood Group : " << " O+";
		}
		float bloodcount;
		srand(time(NULL));
		bloodcount = rand() % 4000 + 10000;
		if (bloodcount < 4500)
		{
			cout << "\n Blood Count : Low -> " << bloodcount;
		}
		else if (bloodcount >= 4500 && bloodcount < 10000)
		{
			cout << "\n Blood Count : High -> " << bloodcount;
		}
		float ha;
		srand(time(NULL));
		ha = rand() % 10 + 9;
		if (ha >= 12 && ha < 16)
			cout << "\n\n Hameogloblin level -> Normal : " << ha << " grams per deciliter";
		if (ha < 12)
			cout << "\n\n Hameogloblin level -> LOW : " << ha << " grams per deciliter";
		if (ha > 16)
			cout << "\n\n Hameogloblin level ->  : " << ha << " grams per deciliter";


		float cholestrol;
		srand(time(NULL));
		cholestrol = rand() % 90 + 200;
		if (cholestrol <= 100)
			cout << "\n\n Cholesrtrol -> Normal ->  " << cholestrol << " mg/dl";
		else if (cholestrol > 100 && cholestrol <= 129)
			cout << "\n\n Cholestrol -> Close to Normal -> " << cholestrol << " mg/dl";
		else if (cholestrol >= 130 && cholestrol <= 159)
			cout << "\n\n Cholesrtrol -> Borderline ->  " << cholestrol << " mg/dl";
		else if (cholestrol >= 160 && cholestrol <= 189)
			cout << "\n\n Cholesrtrol ->  High ->  " << cholestrol << " mg/dl";
		else if (cholestrol >= 190 && cholestrol <= 240)
			cout << "\n\n Cholesrtrol ->  Highly Risky ->  " << cholestrol << " mg/dl";

		cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
		cout << "\n\n 8.Fasting Plasma Glucose Test(FPG) : ";
		if (objp.levelOfGlucose < 100.00)
		{
			cout << " The Level Of Glucose : Normal -> " << objp.levelOfGlucose << " mg/dl";
			checkdb1++;
		}
		else if (objp.levelOfGlucose >= 100.00 && objp.levelOfGlucose <= 125.00)
		{
			cout << " The Level Of Glucose : Pre-Diabetes(Silent heart attack may be)-> " << objp.levelOfGlucose << " mg/dl";
			checkdb2++;
		}
		else if (objp.levelOfGlucose >= 126.00)
		{
			cout << " The level of Glucose : High -> Diabetes II(Silent heart attack possible " << objp.levelOfGlucose << " mg/dl";
			checkdb2++;
			checkdb3++;
		}
		cout << "\n\n 9.Oral Glucose Tolerance Test(OGTT) :- ";
		if (objp.glucose1 < 140.00)
		{
			cout << " Glucose Level : Normal -> " << objp.glucose1 << " mg/dl";
			checkdb1++;
		}
		else if (objp.glucose1 >= 140.00 && objp.glucose1 <= 199.00)
		{
			cout << " Glucose Level : Higher than Normal (PRE-Diabetes which may lead to silent heart attack)-> " << objp.glucose1 << " mg/dl";
			checkdb2++;
		}
		else if (objp.glucose1 >= 200.00)
		{
			cout << " Glucose Level : High -> Diabetes II which can lead to silent heart attack" << objp.glucose1 << " mg/dl";
			checkdb2++;
			checkdb3++;
		}


		cout << "\n\n 10.Troponin Level (AQT90 FLEX immunoassay analyzer): ";
		if (objp.Nutrition == 'y' || objp.Nutrition == 'Y')
		{
			if (objp.troponinLevel >= 0.40)
			{
				cout << " Very High Troponin Level \n";
				checkdb2++;
				checkdb3++;
			}
			else if (objp.troponinLevel >=0.04 && objp.troponinLevel <=0.39)
			{
				cout << " High Troponin Level\n";
				checkdb2++;
			}
			else if (objp.troponinLevel < 0.04)
			{
				cout << " Normal Troponin Level\n";
				checkdb1++;
			}
			else
				cout << " You are fine.\n";
		}
		else if (objp.Nutrition == 'n' || objp.Nutrition == 'N')
		{
			if (objp.troponinLevel >= 0.04 && objp.troponinLevel <= 0.39)
			{
				cout << " High Troponin Level\n";
				checkdb2++;
			}
			else if (objp.troponinLevel < 0.04)
			{
				cout << " Normal Troponin Level\n\n";
				checkdb1++;
			}
			else
			{
				cout << " You are fine\n\n";
			}
			cout << "\n\n During Taking test we have found that you hadn't ate something from last 2 - 3 hrs so here's a tip \n\n";
			cout << " Health Tip 1 :";
			cout << " You should eat something in every 2 hours as it is important for the body\n\n";
			sleep(1);
		}
		cout << "\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
		if (checkdb1 == 3 && checkdb2 <= 1 && checkdb3 == 0)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t Consult Doctor: For further Detailed Explanation!.";
			cout << "\n\n\t\t\t\t\t\t\t\t Heart Attack Test : Negative \n";
		}
		if (checkdb2 == 2 && checkdb3 <= 1)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t Consult Doctor: For further Detailed Explanation!.";
			cout << "\n\n\t\t\t\t\t\t\t\t Heart Attack Test : Positive \n\t\t\t\t\t\t\t\t Heart Attack Type : Intermediate \n";
		}
		if (checkdb2 < 2 && checkdb3>1)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t Consult Doctor: For further Detailed Explanation!.";
			cout << "\n\n\t\t\t\t\t\t\t\t Heart Attack Test : Positive \n\t\t\t\t\t\t\t\t Heart Attack Type : Intense\n";
		}
		if (checkdb3 == 2 || checkdb3 == 3)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t Consult Doctor: For further Detailed Explanation!.";
			cout << "\n\n\t\t\t\t\t\t\t\t Heart Attack Test : Positive \n\t\t\t\t\t\t\t\t Heart Attack Type : Intense\n";
		}
		if (checkdb3 == 2 && checkdb2 == 2)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t Consult Doctor: For further Detailed Explanation!.";
			cout << "\n\n\t\t\t\t\t\t\t\t Heart Attack Test : Positive \n\t\t\t\t\t\t\t\t Heart Attack Type : Intermediate\n";
		}
		else if (checkdb2 == 1 && checkdb1 == 1 && checkdb2 == 1)
		{
			cout << "\n\n\t\t\t\t\t\t\t Meet Doctor Again due to some complications in test";
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\t\t Consult Doctor for More Help";
		}
		cout << "\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
		cout << "\n\n\n\t\t\t\t\t\t\t\t Final Result :- ";
		if (objp.glucose1 < 140.00)
		{
			cout << "Normal";
		}
		else if (objp.glucose1 >= 140.00 && objp.glucose1 <= 199.00)
		{
			cout << "PRE-Diabetes(May lead to heart attack)";
		}
		else if (objp.glucose1 >= 200.00)
		{
			cout << "Diabetes (Probably can lead to heart attack";
		}
	}
	else
	{
		cout << "\n\n Test Report has not been made\n\n";
	}
	fout.close();
	fin.close();
}

void heartAttack::doctorlist()
{
	system("cls");
	int date, month, year;
	cout << "\t\t\tHeart Attack Health Care!\n\n\n";
	fin.open("HEARTATTACKDATA.txt", ios::in);
	fout.open("Temp.txt", ios::in);
	fturndoc.open("Doctors1.txt", ios::app | ios::in);
	while (fturndoc.read((char*)&docp, sizeof(docp)))
	{
		fout.write((char*)&docp, sizeof(docp));
	}
	fout.close();
	fturndoc.close();
	fout.open("Temp.txt", ios::in);
	fturndoc.open("Doctors1.txt", ios::app | ios::in);
	int option;
	int tempid;
	cout << "\n\n Enter the paitent id : ";
	cin >> tempid;
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
		{
			break;
		}
	}
	if (tempid == mainobj.id)
	{
		cout << "\n\n Paitent Name : " << mainobj.name;
		cout << "\n\n";
	B:
		int tt = 0;
		if (tt = 1)
		{
			system("cls");
		}
		cout << "\n\n\t\t\t\t\t\t\t\tDoctor's List\n\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\tId\t|\t\tDoctor Name\t\t|   \t\tTimings\t\t\t |\tDays\t|\t\tFees\t\t|\n\n";
		cout << "\t1\t|\t\tDr. Philip\t\t|\t\t10:00am-12:00pm\t\t|\t Mon \t|\t\t$ 600\t\t|\n\n";
		cout << "\t2\t|\t\tDr. Ben\t\t|\t\t05:00pm-07:00pm\t\t|\t Tue \t|\t\t$ 500\t\t|\n\n";
		cout << "\t3\t|\t\tDr. Sarah\t\t|\t\t11:00am-01:00pm\t\t|\t Wed \t|\t\t$ 700\t\t|\n\n";
		cout << "\t4\t|\t\tDr.Esther    \t\t|\t\t11:00am-02:00pm\t\t|\t Thurs\t|\t\t$ 900\t\t|\n\n";
		cout << "\t5\t|\t\tDr. Joseph    \t\t|\t\t05:00pm-08:00pm\t\t|\t Fri \t|\t\t$ 550\t\t|\n\n";
		cout << " Enter your Preference of Doctor to Book your Appointment\n\n";
		cout << "\n Your Preference : ";
		cin >> option;
		docp.id = tempid;
		docp.idofdoc = option;
		cout << "\n\n Enter Date to Fix appointment(dd/mm/yyyy)\n\n";
		cout << " Your input : ";
		cin >> date;
		cin >> month;
		cin >> year;
		cout << "\n\n Wait! Checking For Appointments ";
		cout << "\n\n ";
		fout.read((char*)&docp, sizeof(docp));
		{
			if (docp.st.d == date && docp.st.m == month && docp.st.y == year)
			{
				char check;
				cout << "\n\n Sorry for inconvenience The date you selected is not available for appointment ";
				cout << "\n\n Press Y to try again \n ";
				cout << "Your Preference: "; cin >> check;
				if (check == 'y' || check == 'Y')
				{
					tt = 1;
					goto B;
				}
			}
			else
			{
				docp.st.d = date;
				docp.st.m = month;
				docp.st.y = year;
				cout << "\n ";
				sleep(3);
				cout << "\n\n Thanks! Appointment Fixed on " << date << "/" << month << "/" << year;
				fturndoc.write((char*)&docp, sizeof(docp));
			}
		}
	}
	else
		cout << "\n\n Appointment Not Fixed";
	cout << "\n\n";
	fout.close();
	fturndoc.close();
	fin.close();
	remove("Temp.txt");
}





void heartAttack::prereport()
{
	int tempid, c = 0;
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CARE\t\t\n\t\t\t\t\t\t\t\t\tWe judge we understand!\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	fin.open("HEARTATTACKDATA.txt", ios::in);
	fturndoc.open("Doctors1.txt", ios::in);
	cout << " Enter The Id of paitent: ";
	cin >> tempid;
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
		{
			break;
		}
	}
	while (fturndoc.read((char*)&docp, sizeof(docp)))
	{
		if (docp.id == tempid)
			break;
	}
	if (tempid == mainobj.id && tempid == docp.id)
	{
		cout << "\n\n NAME: " << mainobj.name;
		cout << "\n\n Age: " << mainobj.age;
		cout << "\n\n Sex: " << mainobj.sex;
		cout << "\n\n Appointment date: " << docp.st.d << "/" << docp.st.m << "/" << docp.st.y << "\n";
		cout << "\n\n Mobile number: " << mainobj.phn;
		cout << " \n\n Doctor Name: ";
		if (docp.idofdoc == 1)
		{
			cout << "Dr. Philip";
		}
		if (docp.idofdoc == 2)
		{
			cout << "Dr. Ben";
		}
		if (docp.idofdoc == 3)
		{
			cout << "Dr. Sarah";
		}
		if (docp.idofdoc == 4)
		{
			cout << "Dr. Esther";
		}
		if (docp.idofdoc == 5)
		{
			cout << "Dr. Joseph";
		}
		cout << "\n\n\n";
	}
	else
		cout << "\n\n Invalid Id or Appointment has Not been Taken\n\n";
	fin.close();
	fturndoc.close();
}
void heartAttack::aboutme()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME TO THE HEART DISEASES HEALTH CARE\t\t\n\t\t\t\t\t\t\t\t\tWe judge we understand!\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\t\tNAME:AMIT SINGH SANSOYA\n";
	cout << "\t\tSECTION:1656\n";
	cout << "\t\tAND THIS IS AWESOME\n";
	cout << " \t\tSizeof class aminstration : " << sizeof(adminstration);
	cout << "\n\n\t\tSizeof class heart Attack : " << sizeof(heartAttack);
	cout << "\n\n\t\tSizeof class fianlreport : " << sizeof(finalreport);
	cout << "\n\n\t\tSizeof class Secured_login : " << sizeof(SecuredLogin);
	cout << "\n\n\t\tSizeof class issues : " << sizeof(issues);
	cout << "\n\n\t\tSizeof class doctors : " << sizeof(doctor);
	cout << "\n\n\t\tSizeof class discuss : " << sizeof(discuss);
	cout << "\n\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	exit(1);
}
void heartAttack::deldata()
{
	int tempid, k = 0;
	system("cls");
	fin.open("HEARTATTACKDATA.txt", ios::in);
	fout.open("Temp.txt", ios::out);
	fturndoc.open("Doctor1.txt", ios::in);
	ftemp.open("Tempdoc.txt", ios::out);
	cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CARE\t\t\n\t\t\t\t\t\t\t\t\tWe judge we understand!\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\t\t\t\tHere's the Data of all paitents\n\n\n";


	cout << "|\t ID\t   |             NAME                 |  AGE    |   SEX   |   HEIGHT    |   WEIGHT      |\n";
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		cout << "|" << setw(9) << id << setw(10) << "|" << setw(15) << name << setw(20) << "|" << setw(5) << age << setw(5) << "|" << setw(5) << sex << setw(5) << "|" << setw(7) << height << setw(7) << "|" << setw(7) << weight << setw(7) << "\t|\n\n";
	}
	fin.close();
	fin.open("HEARTATTACKDATA.txt", ios::in);
	cout << "\n Enter the id no. of client : ";
	cin >> tempid;

	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
		{
			k++;
		}
		else
		{
			fout.write((char*)&mainobj, sizeof(mainobj));
		}
	}
	fin.close();
	fout.close();
	fin.open("HEARTATTACKDATA.txt", ios::out);
	fout.open("Temp.txt", ios::in);
	while (fout.read((char*)&mainobj, sizeof(mainobj)))
	{
		fin.write((char*)&mainobj, sizeof(mainobj));
	}
	cout << "\n\n Deleted Record";
	cout << "\n\n";
	fin.close();
	fout.close();
	cout << "\n\n UPDATED RECORDS";
	cout << "\n\n";
	fin.open("HEARTATTACKDATA.txt", ios::in);
	cout << "|\t ID\t   |             NAME                 |  AGE    |   SEX   |   HEIGHT    |   WEIGHT      |\n";
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		cout << "|" << setw(9) << id << setw(10) << "|" << setw(15) << name << setw(20) << "|" << setw(5) << age << setw(5) << "|" << setw(5) << sex << setw(5) << "|" << setw(7) << height << setw(7) << "|" << setw(7) << weight << setw(7) << "\t|\n\n";
	}
	fin.close();
}





void heartAttack::clientSecuredLogin()
{
	int tempid, tempotp, co;
	long long int tempno;
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tWe judge we understand!\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n Enter Your user ID : ";
	cin >> tempid;
	cout << "\n\n Enter Your phn No.: ";
	cin >> tempno;
	cout << "\n\n OTP has been sent Wait for 5-10 secs\n\n ";
	srand(time(NULL));
	tempotp = rand() % 80000 + 10300;
	sleep(4);
	cout << " ";
	cout << "\n\n Your 5 digit OTP is : " << tempotp << " Valid for 10 seconds or the screen will go off with in next 5 seconds\n\n";
	cout << "\n\n Enter The 5-digit OTP: ";
	cin >> co;
	cout << "\n\n ";
	fin.open("HEARTATTACKDATA.txt", ios::in);
	if (tempotp == co)
	{
		while (fin.read((char*)&mainobj, sizeof(mainobj)))
		{
			if (tempid == mainobj.id && tempno == mainobj.phn)
			{
				break;
			}
		}
		if (tempid == mainobj.id && tempno == mainobj.phn)
		{
			system("cls");
			cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Wellbeing, Our priority!\n";
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
			cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
			cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
			cout << "\n\n NAME: " << mainobj.name;
			cout << "\n\n Age: " << mainobj.age;
			cout << "\n\n Sex: " << mainobj.sex;
			cout << "\n\n 1. Update Data \n\n 2. Change Doctor \n\n 3. Disease Level \n\n 4. Check Medicines \n\n 5. Buy\\Order Medicines \n\n 6. Register Complaints\n\n 7.See Messages//Complaint status\n\n 8.Exit";
			cout << "\n Enter Preference : ";
			int lc;
			cin >> lc;
			switch (lc)
			{
			case 1:
				pa.updatemine();
				break;
			case 2:
				pa.docchange();
				break;
			case 3:
				pa.diseaselevel();
				break;
			case 4:
				pa.medicare();
				break;
			case 5:
				pa.buy();
				break;
			case 6:
				pa.complaints();
				break;
			case 7:
				pa.seem();
				break;
				//case 8:
				//bobj.totalbill();
				//break;
			case 8:
				cout << "Exiting....";
				sleep(2);
				mainobj.twist();
			default:
				exit(0);
			}
		}
		fin.close();
	}
	else
	{
		cout << "\n\n	Error While Logging...\n";
		sleep(3);
		cout << "\n\n SecuredLogin Failed \n\n";
		fin.close();

	}
}







void heartAttack::admin()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n";
	int ch;
	char check;
BD:
	cout << "\t\t\t\t\t\t\t\t  WE ARE ALWAYS HERE TO HELP YOU \n\n\t\t\t\t\t\t\t\t   CHOOSE THE OPTIONS FROM MENU\n\n 1: List All data(Paitents)\n\n 2: Search for Paitent\n\n 3: Delete Record(Paitents) \n\n 4: Update Records(Paitents)\n\n 5: Count Paitents\n\n 6: Admin Records\n\n 7: Admin Signup\n\n 8: Admin Duties\n\n 9: Logout";
	cout << "\n\n YOUR PREFERENCE FROM LIST : ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		display(10, 20);
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 2:
		search();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 3:
		deldata();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 4:
		update();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 5:
		admino.count();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 6:
		mainobj.adminre();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 7:
		admino.adminsi();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 8:
		admino.duty();
		cout << "\n Do You Want To Continue(y/n)\n";
		cout << " YOUR PREFERENCE: ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			system("cls");
			goto BD;
		}
		else
		{
			cout << "\n\n\t\t\tThank You! Visit us Again\n";
			break;
		}
	case 9:
		cout << "\n\n Loging out......... \n\n";
		sleep(2);
		cout << "\n\n Logged Out Successfully.....\n";

		mainobj.twist();
	default:
		cout << "\n\n Terminated due to wrong key press\n";
	}
}



void adminstration::adminsi()
{
	int c = 0;
	system("cls");
	fadmin.open("admin.txt", ios::app);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t  WE ARE ALWAYS HERE TO HELP YOU \n\n\n";
	cout << " Enter Name : ";
	cin >> admino.staffName;
	cout << "\n\n Enter the Staff Useer Id : ";
	cin >> admino.staffUserId;
	cout << "\n\n Enter the password : ";
	cin >> admino.password;
	cout << "\n\n Enter the phone no.: ";
	cin >> admino.phna;
	cout << "\n\n Enter The ID GENERATED : ";
	cin >> admino.staffId;
	sleep(1);
	cout << "\n\n Logging in in 3 seconds \n\n";
	sleep(1);
	cout << "\n\n Logging in in 2 seconds \n\n";
	sleep(1);
	cout << "\n\n Logging in in 1 seconds \n\n";
	sleep(1);
	fadmin.write((char*)&admino, sizeof(admino));
	fadmin.close();
	mainobj.admin();
}


void adminstration::count()
{
	int c = 0;
	system("cls");
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t  WE ARE ALWAYS HERE TO HELP YOU \n\n\n";
	fadmin.open("admin.txt", ios::in);
	fin.open("HEARTATTACKDATA.txt", ios::in);
	cout << " Select : \n\n 1-> Paitents \n\n 2-> Staff \n\n ";
	int option;
	cout << "\n Your Preference : ";
	cin >> option;
	switch (option)
	{
	case 1:
		while (fin.read((char*)&mainobj, sizeof(mainobj)))
		{
			c++;
		}
		cout << "\n\n The Total Count is: ";
		cout << c;
		countB = c;
		c = 0;
		cout << "\n\n\n";
		break;
	case 2:
		while (fadmin.read((char*)&admino, sizeof(admino)))
		{
			c++;
		}
		cout << "\n\n The Total Count is: ";
		cout << c;
		countB = c;
		cout << "\n\n\n";
		c = 0;
		break;
	}
}



void heartAttack::setlock()
{
	int i, c = 0;
	char a[20], p[13];
	system("cls");
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t  WE ARE ALWAYS HERE TO HELP YOU \n\n\n";
	fadmin.open("admin.txt", ios::in);
	fout.open("admintmp.txt", ios::out);
	fadmin.seekg(0, ios::beg);
	fout.seekp(0, ios::beg);
	while (fadmin.read((char*)&admino, sizeof(admino)))
	{
		fout.write((char*)&admino, sizeof(admino));
	}
	fout.close();
	fadmin.close();
	fout.open("admintmp.txt", ios::in);
	while (fout.read((char*)&admino, sizeof(admino)))
	{
		c++;
	}
	fout.close();
	fadmin.open("admin.txt", ios::in);
	if (c == 0)
	{
		cout << "\n\n No id existed So please Signup to do so\n\n";
		sleep(3);
		admino.adminsi();
	}
	else
	{
		cout << "\n\n Enter the userid : ";
		cin >> a;
		cout << "\n\n Enter The Password : ";
		for (i = 0; i < 12; i++)
		{
			p[i] = getch();
			if (p[i] == 13)
				break;
			else if (p[i] == 8)
			{
				cout << "\b \b";
				i = i - 2;
			}
			else
				putchar('*');
		}
		p[i] = '\0';
		while (fadmin.read((char*)&admino, sizeof(&admino)) && !fadmin.eof())
		{
			if (strcmp(a, admino.staffUserId) == 0 && strcmp(p, admino.password) == 0)
			{
				sleep(2);
				cout << "\n\n Wait for sometime\n\n";
				break;
			}
		}
		fadmin.close();
		if (strcmp(a, admino.staffUserId) == 0 && strcmp(p, admino.password) == 0)
		{
			cout << "\n\n SecuredLogin Successfull \n\n";
			sleep(1);
			cout << " Redirecting \n\n";
			sleep(2);
			mainobj.admin();
		}
		else
		{
			cout << "\n\n Invalid UserId or Password \n\n";
			countA = 0;
		}
	}
}



void adminstration::duty()
{
	int option;
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\n";
	cout << " 1 > Give Replies\n\n";
	cout << " 2 > Take Complains\n\n";
	cout << " 3 > Add Medicines\n\n";
	cout << " 4 > Logout\n\n";
	cout << " Choose preference : \n ";
	cin >> option;
	switch (option)
	{
	case 1:
		mainobj.reply();
		break;
	case 2:
		admino.complains();
		break;
	case 3:
		admino.medi();
		break;
	case 4:
		exit(0);
		cout << " \n\nSecured_Loging Out ....";
		sleep(2);
		mainobj.twist();
	}
}


void heartAttack::reply()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\n";
	fin.open("inquiry.txt", ios::in);
	fout.open("reply.txt", ios::app);
	while (fin.read((char*)&q, sizeof(q)))
	{
		cout << "\n\n Inquiry Id No --> " << q.id;
		cout << "\n\n Inquiry --> " << q.input;
		cout << "\n\n Asked By --> " << q.name;
	}
	int tempid, k = 0;
	fin.seekg(0, ios::beg);
	cout << " \n\n ";
	cout << " Enter The id Whom You want to give reply : ";
	cin >> tempid;
	cout << "\n\n ";
	while (fin.read((char*)&q, sizeof(q)))
	{
		if (tempid == q.id)
		{
			break;
		}
		else
			k = 1;
	}
	if (k == 1)
		cout << "Invalid Id \n\n";
	else if (tempid == q.id)
	{
		cout << "Inquiry Reply : ";
		fflush(stdin);
		gets(q.reply);
		fout.write((char*)&q, sizeof(q));
	}
	fout.close();
	fin.close();
}


void heartAttack::inquiries()
{
	system("cls");
	fout.open("inquiry.txt", ios::app);
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "______________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\n";
	cout << "\n\n Enter The Name --> ";
	cin >> q.name;
	cout << "\n\n Enter the inquiry --> ";
	fflush(stdin);
	gets(q.input);
	cout << "\n ";
	sleep(1);
	cout << "\n\n Your Inquiry id no. Generated --> ";
	srand(time(NULL));
	q.id = rand() % 1200 + 9999;
	cout << q.id;
	fout.write((char*)&q, sizeof(q));
	sleep(2);
	cout << "\n\n Your Inquiry Registered\n ";
	sleep(1);
	cout << "\n\n Press Y to logout ";
	char ch;
	cout << "\n\n Enter The Key : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		fout.close();
		sleep(2);
		mainobj.twist();
	}
	else
	{
		cout << " Exit\n\n";
		mainobj.welcome();
		fout.close();
		exit(0);
	}
}

void heartAttack::showqu()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_______________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n\n";
	fin.open("inquiry.txt", ios::in);
	fout.open("reply.txt", ios::in);
	while (fin.read((char*)&q, sizeof(q)))
	{
		cout << " Inquiry Id : " << q.id;
		cout << "\n\n INQUIRY ASKED BY : " << q.name;
		cout << "\n\n Inquiry : " << q.input;
		cout << "\n\n";
	}
	cout << "-----------------------------------------------------------------------------Replies---------------------------------------------------------------------------------------\n\n\n";
	while (fout.read((char*)&q, sizeof(q)))
	{
		cout << " Inquiry Id : " << q.id;
		cout << "\n\n Inquiries Solved : " << q.reply;
		cout << "\n\n";
	}
	sleep(2);
	fout.close();
	fin.close();
	cout << "\n Press Y to Logout \n ";
	char ch;
	cout << "\n\n Enter The Key : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		mainobj.twist();

	}
	else
		exit(0);
}



void adminstration::medi()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_______________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	int n, i;
	fin.open("Medicines.txt", ios::app);
	cout << " Enter The Number of Medicines to Enter : ";
	cin >> n; cout << "\n\n ";
	for (i = 0; i < n; i++)
	{
		cout << "\n\n Enter The Medicine Id : ";
		cin >> medicineId; cout << "\n\n";
		cout << " Enter The Medicine Name : ";
		fflush(stdin);
		gets(medicines);
		cout << "\n\n Enter The Price : ";
		cin >> medicinePrice;
		fin.write((char*)&admino, sizeof(admino));
	}
	fin.close();
}

void client::medicare()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_______________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	fout.open("Medicines.txt", ios::in);
	cout << " Here's the medicines list \n\n ";
	cout << setw(10) << "Medicine ID" << setw(10) << "|" << setw(15) << "MEDICINE NAMES" << setw(15) << "|" << setw(10) << "PRICE" << "|";
	cout << "\n\n________________________________________________________________________________________________________________________________________________________________________________\n\n";
	while (fout.read((char*)&admino, sizeof(admino)))
	{
		cout << "|" << setw(9) << admino.medicineId << setw(10) << "|" << setw(15) << admino.medicines << setw(15) << "|" << setw(10) << admino.medicinePrice << "|\n\n";
	}
	fout.close();
}
void client::buy()
{
	system("cls");
	int temp, localid, qty, i, tempid;
	float sum = 0;
	char ch;
	cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S HEALTH CARE\t\t\n\t\t\t\t\t\t\t\t\tWe judge we understand!\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_______________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	fcross.open("HEARTATTACKDATA.txt", ios::in);
	fout.open("Medicines.txt", ios::in);
	fin.open("Medbuy.txt", ios::out);
	ftemp.open("empty.txt", ios::in);
	cout << "\n\n Enter your id : ";
	cin >> tempid;
	while (fcross.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
			break;
	}
	while (ftemp.read((char*)&admino, sizeof(admino)))
	{
		fin.write((char*)&admino, sizeof(admino));
	}
	fout.close();
	ftemp.close();
	fin.close();
	fout.open("Medicines.txt", ios::in);
	cout << " Here's the medicines list \n\n ";
	cout << setw(10) << "Medicine ID" << setw(10) << "|" << setw(15) << "MEDICINE NAMES" << setw(15) << "|" << setw(10) << "PRICE" << "|";
	cout << "\n\n_____________________________________________________________________________________________________________________________________________________________________________\n\n";
	while (fout.read((char*)&admino, sizeof(admino)))
	{
		cout << "|" << setw(9) << admino.medicineId << setw(10) << "|" << setw(15) << admino.medicines << setw(15) << "|" << setw(10) << admino.medicinePrice << "|\n\n";
	}
	fout.close();
	fout.open("Medicines.txt", ios::in);
T:
	cout << "\n\n Enter the id of medicine you want to Buy?\n\n ";
	cin >> temp;
	cout << "\n\n Enter the quantity of medicine bought?\n\n ";
	cin >> qty;
	while (fout.read((char*)&admino, sizeof(admino)))
	{
		for (i = 0; i < qty; i++)
		{
			if (temp == admino.medicineId)
			{
				sum = sum + admino.medicinePrice;
			}
		}
	}
	fout.seekg(0, ios::beg);
	fout.close();
	fout.open("Medicines.txt", ios::in);
	while (fout.read((char*)&admino, sizeof(admino)))
	{
		if (temp == admino.medicineId)
		{
			fin.open("Medbuy.txt", ios::app);
			fin.write((char*)&admino, sizeof(admino));
			fin.close();
		}
	}
	fout.close();
	fout.open("Medicines.txt", ios::in);
	cout << "\n\n \t\t\t\tFOR MORE PRESS Y or FOR BILL PRESS ANY OTHER KEY\n\n ";
	cout << "Your preference : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		goto T;
	}
	else
	{
		system("cls");
		int billid;
		srand(time(NULL));
		billid == rand() % 1000000 + 2000000;
		fin.open("Medbuy.txt", ios::in);
		fsum.open("Bill.txt", ios::app);
		cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
		cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
		cout << "\n\n ";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Bill id : " << billid;
		cout << setw(20) << "Medicine ID" << setw(20) << "|" << setw(25) << "MEDICINE NAMES" << setw(25) << "|" << setw(20) << "PRICE" << "|";
		cout << "____________________________________________________________________________________________________________________________________________________________________________\n\n";
		while (fin.read((char*)&admino, sizeof(admino)))
		{
			cout << "|" << setw(19) << admino.medicineId << setw(20) << "|" << setw(25) << admino.medicines << setw(25) << "|" << setw(20) << admino.medicinePrice << "|\n\n";
			cout << "_____________________________________________________________________________________________________________________________________________________________________________\n\n";
		}
		cout << "\n\n\t\t\t\t\t\t\t Total Bill of Medicine is : " << sum;
		cout << "\n________________________________________________________________________________________________________________________________________________________________________________\n\n";
		bobj.billid = billid;
		bobj.sum = sum;
		bobj.id = tempid;
		fin.close();
		fsum.write((char*)&bobj, sizeof(bobj));
		fsum.close();
	}
	fout.close();
	fcross.close();
	remove("Medbuy.txt");
}
void heartAttack::update()
{
	ftemp.open("send1.txt", ios::in);
	fout.open("HEARTATTACKDATA.txt", ios::in);
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME TO THE  HEALTH CARE\t\t\n\t\t\t\t\t\t\t\t\tWe judge we understand!\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	int tempid;
	fin.open("update.txt", ios::out);
	cout << "\n\n You may have requests to update record ";
	cout << "\n\n Press Y to see them ";
	char tp;
	cin >> tp;
	if (tp == 'y' || tp == 'Y')
	{
		cout << "\n\n Requests : ";
		while (ftemp.read((char*)&pa, sizeof(pa)))
		{
			cout << " " << pa.send;
		}
	}
	else
		cout << "\n\n You may be suspended for illegal access or change in data";
	cout << "\n\n Enter The ID to be updated \n";
	cin >> tempid;
	while (fout.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (mainobj.id == tempid)
		{
			cout << "\n\n Enter the new name : ";
			fflush(stdin);
			gets(mainobj.name);
			cout << "\n\n Enter the new age : ";
			cin >> mainobj.age;
			cout << "\n\n Enter the new height : ";
			cin >> mainobj.height;
			cout << "\n\n Enter the new weight : ";
			cin >> mainobj.weight;
			fin.write((char*)&mainobj, sizeof(mainobj));
		}
		else if (mainobj.id != tempid)
			fin.write((char*)&mainobj, sizeof(mainobj));
	}
	fout.close();
	fin.close();
	fin.open("update.txt", ios::in);
	fout.open("HEARTATTACKDATA.txt", ios::out);
	fout.seekg(0, ios::beg);
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		fout.write((char*)&mainobj, sizeof(mainobj));
	}
	fin.close();
	fout.close();
	cout << "\n\n Updating...";
	sleep(2);
	cout << "\n\n UPDATED...";
	sleep(1);
}

void client::updatemine()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEART CARE CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	ftemp.open("send.txt", ios::app);
	cout << "\n\n Write the msg to admin to update and what to update and give reason for it : ";
	fflush(stdin);
	gets(pa.send);
	ftemp.write((char*)&pa, sizeof(pa));
	ftemp.close();
	cout << "\n\n WAIT";
	sleep(2);
	cout << "\n\n Request for change submitted\n";
}

void client::complaints()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	ftemp.open("comp.txt", ios::app);
	cout << "\n\n Write the complaint to admin : ";
	fflush(stdin);
	gets(pa.comp);
	ftemp.write((char*)&pa, sizeof(pa));
	ftemp.close();
	sleep(2);
	cout << "\n\n Mail sent !!";
}
void adminstration::complains()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEART CARE CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	fout.open("recomp.txt", ios::app);
	fin.open("comp.txt", ios::in);
	cout << "\n\n Complains : ";
	while (fin.read((char*)&pa, sizeof(pa)))
	{
		cout << " " << pa.comp;
		cout << "\n\n Write a Reply ";
		cout << "\n\n " << admino.re;
	}
	fflush(stdin);
	gets(admino.re);
	fout.write((char*)&pa, sizeof(pa));
	fin.close();
	fout.close();
}
void client::seem()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	fin.open("recomp.txt", ios::in);
	while (fin.read((char*)&pa, sizeof(pa)))
	{
		cout << " " << admino.re;
	}
	cout << "\n\n Only latest Replies are Available \n";
	fin.close();
}
void heartAttack::adminre()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	fadmin.open("admin.txt", ios::in);
	while (fadmin.read((char*)&admino, sizeof(admino)))
	{
		cout << "\n\n ";
		cout << "Name : " << admino.staffName;
		cout << "\n\n ";
		cout << "User Id : " << admino.staffUserId;
		cout << "\n\n ";
		cout << "ID no. : " << admino.staffId;
		cout << "\n\n";
		fadmin.close();
	}
}


void client::diseaselevel()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEART CARE CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	fin.open("HEARTATTACKDATA.txt", ios::in);
	fout.open("issues.txt", ios::in);
	cout << "Enter Your Id : ";
	int tempid;
	cin >> tempid;
	int check = 0;
	while (fin.read((char*)&mainobj, sizeof(mainobj)))
	{
		if (tempid == mainobj.id)
			break;
	}
	while (fout.read((char*)&objp, sizeof(objp)))
	{
		if (tempid == objp.id)
			break;
	}
	if (tempid == mainobj.id)
	{
		cout << "\n\n Troponin Level : " << objp.troponinLevel;
		if (objp.troponinLevel >= 0.40)
		{
			check = 1;
			cout << " High Troponin Level-II\n";
		}
		else if (objp.troponinLevel >=0.04 && objp.troponinLevel <= 0.39)
		{
			check = 2;
			cout << " High Troponin Level\n";
		}
		else if (objp.troponinLevel < 0.04)
		{
			check = 3;
			cout << " Normal Sugar Level\n";
		}
		else
			cout << " You are fine\n";
	}
	if (check == 1)
		cout << "\n\n\n\t\t\t\t\t\t Probably Heart Attack \n\n";
	else if (check == 2)
		cout << "\n\n\n\t\t\t\t\t\t Problem with the heart-1\n\n";
	else if (check == 3)
		cout << "\n\n\n\t\t\t\t\t\t Normal Troponin Level\n\n";
	else
		cout << "\n\n\n\t\t\t\t\t\t Your are fine\n\n";
	cout << " Loading\n\n";
	sleep(2);
	cout << " Health tip 2: Take medicines on time \n";
	sleep(4);
	fin.close();
	fout.close();
	mainobj.twist();
}

void client::docchange()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S CHRONIC DISEASES DIAGNOSTIC CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	cout << " Sorry for the inconvenience caused Currently this interface is disabeled by admin\n\n";
	sleep(4);
	mainobj.twist();
}

void quick::buy()
{
	int sum;
	int billid;
	int mid;
	int qty;
	char ch1;
	int mod;
B:
	system("cls");
	cout << "\t\t\t\t\t\t\t\t WELCOME MICHAEL'S HEALTH CENTER CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
	cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
	cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
	cout << "\n\n ";
	cout << "\t\t\t\t\t\t\t\t Medicines\n\n";
	static int j = 0;
	cout << setw(5) << "ID" << setw(5) << "|" << setw(20) << "Name" << setw(20) << "|" << setw(5) << "Price/package" << setw(5) << "|\n\n";
	cout << setw(5) << "1" << setw(5) << "|" << setw(20) << "APIXABAN" << setw(20) << "|" << setw(5) << "$ 550" << setw(5) << "|\n\n";
	cout << setw(5) << "2" << setw(5) << "|" << setw(20) << "CLOPIDOGREL" << setw(20) << "|" << setw(5) << "$ 160" << setw(5) << "|\n\n";
	cout << setw(5) << "3" << setw(5) << "|" << setw(20) << "BENAZEPRIL" << setw(20) << "|" << setw(5) << "$ 80" << setw(5) << "|\n\n";
	cout << setw(5) << "4" << setw(5) << "|" << setw(20) << "AZILSARTAN" << setw(20) << "|" << setw(5) << "$150" << setw(5) << "|\n\n";
	cout << setw(5) << "5" << setw(5) << "|" << setw(20) << "ATENOLOL" << setw(20) << "|" << setw(5) << "$ 90" << setw(5) << "|\n\n";
	cout << setw(5) << "6" << setw(5) << "|" << setw(20) << "STATINS" << setw(20) << "|" << setw(5) << "$ 105" << setw(5) << "|\n\n";
	cout << setw(5) << "7" << setw(5) << "|" << setw(20) << "ASPIRIN" << setw(20) << "|" << setw(5) << "$ 70" << setw(5) << "|\n\n";
	cout << setw(5) << "8" << setw(5) << "|" << setw(20) << "WARFARIN" << setw(20) << "|" << setw(5) << "$ 600" << setw(5) << "|\n\n";
	cout << setw(5) << "9" << setw(5) << "|" << setw(20) << "BETA-BLOCKERS" << setw(20) << "|" << setw(5) << "$ 200" << setw(5) << "|\n\n";
	cout << setw(5) << "10" << setw(5) << "|" << setw(20) << "ACE INHIBITORS" << setw(20) << "|" << setw(5) << "$ 250" << setw(5) << "|\n\n";
	cout << "\n\n Enter the id you want to buy : ";
	cin >> mid;
	if (mid == 1)
	{
		sum = sum + 1200;
	}
	if (mid == 2)
	{
		sum = sum + 1100;
	}
	if (mid == 3)
	{
		sum = sum + 1500;
	}
	if (mid == 4)
	{
		sum = sum + 1400;
	}
	if (mid == 5)
	{
		sum = sum + 2000;
	}
	if (mid == 6)
	{
		sum = sum + 2500;
	}
	if (mid == 7)
	{
		sum = sum + 3500;
	}
	if (mid == 8)
	{
		sum = sum + 4500;
	}
	if (mid == 9)
	{
		sum = sum + 5500;
	}
	if (mid == 10)
	{
		sum = sum + 6000;
	}
	cout << "\n\n You can buy only 2 medicines at a time as per Medical Department Rules: ";
	cout << "\n\n Do you want more?(Y/N) ";
	cin >> ch1;
	if (ch1 == 'Y' || ch1 == 'y')
	{
		j++;
		mod = mid;
		goto B;
	}
	else
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t WELCOME TO MICHAEL'S CHRONIC DISEASES DIAGNOSTIC CENTER\t\t\n\t\t\t\t\t\t\t\t\tYour Health, Our Priority\n";
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
		cout << "\t\t\t\t\t\t\t\t   ....MICHAEL'S HEALTH CENTER....\n\n";
		cout << "_________________________________________________________________________________________________________________________________________________________________________\n\n\n";
		cout << setw(5) << "ID" << setw(5) << "|" << setw(20) << "Name" << setw(20) << "|" << setw(5) << "Price/package" << setw(5) << "|\n\n";


		if (mid == 1 || mod == 1)
		{
			cout << setw(5) << "1" << setw(5) << "|" << setw(20) << "APIXABAN" << setw(20) << "|" << setw(5) << "$ 550" << setw(5) << "|\n\n";
		}
		if (mid == 2 || mod == 2)
		{
			cout << setw(5) << "2" << setw(5) << "|" << setw(20) << "CLOPIDOGREL" << setw(20) << "|" << setw(5) << "$ 160" << setw(5) << "|\n\n";
		}
		if (mid == 3 || mod == 3)
		{
			cout << setw(5) << "3" << setw(5) << "|" << setw(20) << "BENAZEPRIL" << setw(20) << "|" << setw(5) << "$ 80" << setw(5) << "|\n\n";
		}
		if (mid == 4 || mod == 4)
		{
			cout << setw(5) << "4" << setw(5) << "|" << setw(20) << "AZILSARTAN" << setw(20) << "|" << setw(5) << "$ 150" << setw(5) << "|\n\n";
		}
		if (mid == 5 || mod == 5)
		{
			cout << setw(5) << "5" << setw(5) << "|" << setw(20) << "ATENOLOL" << setw(20) << "|" << setw(5) << "$ 90" << setw(5) << "|\n\n";
		}
		if (mid == 6 || mod == 6)
		{
			cout << setw(5) << "1" << setw(5) << "|" << setw(20) << "STATINS" << setw(20) << "|" << setw(5) << "$  105" << setw(5) << "|\n\n";
		}
		if (mid == 7 || mod == 7)
		{
			cout << setw(5) << "2" << setw(5) << "|" << setw(20) << "ASPIRIN" << setw(20) << "|" << setw(5) << "$ 70" << setw(5) << "|\n\n";
		}
		if (mid == 8 || mod == 8)
		{
			cout << setw(5) << "3" << setw(5) << "|" << setw(20) << "WARFARIN" << setw(20) << "|" << setw(5) << "$ 600" << setw(5) << "|\n\n";
		}
		if (mid == 9 || mod == 9)
		{
			cout << setw(5) << "4" << setw(5) << "|" << setw(20) << "BETA-BLOCKER" << setw(20) << "|" << setw(5) << "$ 200" << setw(5) << "|\n\n";
		}
		if (mid == 10 || mod == 10)
		{
			cout << setw(5) << "5" << setw(5) << "|" << setw(20) << "ACE INHIBITORS" << setw(20) << "|" << setw(5) << "$ 250" << setw(5) << "|\n\n";
		}
		cout << "\t\t\t\t\t\t\t\t Total Bill : " << sum;
		sleep(5);
		cout << "\t\t\t\t\t\t\t Thanks!for taking Quick test and buying  medicines";
		sleep(3);
		mainobj.twist();
	}
}
