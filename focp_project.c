/*
Author : Kamlesh Kumar
CLASS : BSCS-10C
linkedin : https://www.linkedin.com/in/kamlesh-kumar-389847224/ 

//To Create an admin account you must need additional Admin authentication password "Welcome@1:.
					//FEATURE
  You get "30%" disscount. If you buy a ticket after logging in with your account.
  Reserved seats for particular movies will be "remembered" even after program is close.
  Users can cancel their seats and those seats will be made unreserved again
  If you are logged-in you can "return your movie ticket".
  Admin or User can change his password.
  Unlimited movies can be add in the software.
  Once the user or admin logs-in then he can use functionalitites again and again until he logs-out manually

*/

#include<string.h>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

void greeting(void);// this function calls the initial transition runs only once
void Create_account(int);//this create account depending on function arugument either for user and admin, 
void admin_menu();
void user_menu();
int  authentication(int);//this function for login of user or admin depending on argument passed
void line_anim(int);//this function prints a line animation size of line depending on the argument passed
void txt_anim(char*, int);//this function prints the char array passed in a transition
void change_pass(int);//this simpmly changes the password of admin or user
void addMov();//this function is used only for admin to insert moives
void buy_ticket(int);
int seatno(int, int);//to book seat
char name1[20];
int check = 0;
void close(void);//this function exit the program

struct book
{
	int mnum;
	char mname[20];
	char mtime[10];
	char mday[12];
	char mtype[15];
	int fee;
};
int main()
{
	if (check == 0) {
		greeting();//this function runs only once in the begining
		check += 1;
	}
	int choice = 0, auth = 10;
	char title[] = "\n\tLOG-IN, And GET 30% DISSCOUNT";
	txt_anim(&title[0], sizeof(title));
	while (1 == 1) //this loop goes forever untill 3 is pressed in main menu
	{
		line_anim(38);
		//following 3 lines just print main menu.
		printf("\n\t---------------------------------\n\t---------------------------------\n");Sleep(1000);
		printf("\t| \tMAIN MENU ## \t\t|\n \t| 1. Create Account\t\t|\n \t| 2. Log-in\t\t\t|\n \t| 3. Buy Ticket Without-login\t|\n\t| 4. Exit\t\t\t|");Sleep(1500);
		printf("\n\t---------------------------------\n\t---------------------------------\n"); Sleep(1000);
		printf("\tEnter YOUR CHOICE :: ");Sleep(1000);
		scanf("%d", &choice); //choice varaiable will selection from menu
		switch (choice) {//switch to make decision
		case 1:
			system("cls");
			line_anim(38);
			printf("\n\t*********************************\n");Sleep(1000);
			printf("\t| Creater Account As:  \t\t|\n \t| 1. Admin\t\t\t|\n \t| 2. User \t\t\t|\n\t| 3. Go-to Main Menu\t\t|\n\t| 3. Exit\t\t\t|");Sleep(1000);
			printf("\n\t********************************* \n\tEnter your choioce : ");Sleep(1000);
			scanf("%d", &choice); //now choice varaiable will selection either user or admin
			if (choice == 4)
				close();
			else if (choice == 3) {
				system("cls");
				main();
			}
			else
				Create_account(choice);
			break;

		case 2:
			system("cls");
			line_anim(38);
			printf("\n\t*********************************\n");Sleep(500);
			printf("\t| Login-in As:  \t\t|\n \t| 1. Admin\t\t\t|\n \t| 2. User \t\t\t|\n\t| 3. Go-to Main Menu\t\t|\n\t| 4. Exit\t\t\t|");Sleep(500);
			printf("\n\t********************************* \n\tEnter your choioce : ");Sleep(500);
			scanf("%d", &choice); //now choice varaiable will selection either user or admin
				if (choice == 4)
					close();
				if((choice==2) || (choice == 1))
					auth = authentication(choice);
				if (auth == 0) {
					printf("\tYou are logged-In :) \n");
					system("PAUSE");
					system("cls");
					if (choice == 2)
						user_menu();
					else if (choice == 1)
						admin_menu();
				}
				else
					system("cls");
					break;
		case 3:
			buy_ticket(0);
		case 4:
			close();
			break;
		default:
			printf("\t\nBad Selection, select from the list again : ");
			break;
		}
	}
	getchar();
	return 0;
}//end of main function

void greeting(void) {
	int count, i;

	for (int i = 0; i < 9; i++)
	{   // A simple animation to show a moving train.
		printf("       . . . . . . . . o o o o o o o o");
		for (count = i; count > 0;count--)
			printf("o o o o o");
		printf("\n");

		for (count = i; count > 0;count--)
			printf("\t");
		printf("\t\t                _____      o\n");

		for (count = i; count > 0;count--)
			printf("\t");
		printf("\t\t       ____****  ]OO|_n_n__][.\n");

		for (int count = i; count > 0;count--)
			printf("\t");
		printf("\t\t      [________]_|__|________)< \n");

		for (int count = i; count > 0;count--)
			printf("\t");
		printf("\t\t       oo    oo  'oo OOOO-| oo\\_\n");


		if (i != 8) {
			Sleep(190);
			system("cls");
		}
		else
			Sleep(1000);
	}
	line_anim(38);
	printf("\t  ___ ____ _  _ ____ __  __   __      ____ ____ ___ _  _ ____ ____    ___ _  _ ___ ____ ____ __  __ \n"); Sleep(1200);
	printf("\t / __(_  _( \\( ( ___(  \\/  ) /__\\    (_  _(_  _/ __( )/ ( ___(_  _)  / __( \/ / __(_  _( ___(  \\/  )\n"); Sleep(1200);
	printf("\t( (__ _)(_ )  ( )__) )    ( /(__)\\     )(  _)(( (__ )  ( )__)  )(    \\__ \\\\  /\\__ \\ )(  )__) )    ( \n");Sleep(1200);
	printf("\t \\___(____(_)\\_(____(_/\\/\\_(__)(__)   (__)(____\\___(_)\\_(____)(__)   (___/(__)(___/(__)(____(_/\\/\\_)\n");Sleep(1200);

	char subtitle[] = " (: CINEMA TICKET SYSTEM BY KAMLESH KUMAR :). . . .\n ";
	printf("\n \t\t\t\t");
	txt_anim(subtitle, sizeof(subtitle));
	//This prints the tiltle and subtitle

}//end of greeting function

//this function is used for allocating seats and deallocating seats for customers
int seatno(int mov_no, int select) {
	int i = 0, j = 0;
	FILE* ptr;
	int seat_no = 0;
	char file_nm[10];
	sprintf(file_nm, "_%d", mov_no);
	strcat(file_nm, ".txt");
	ptr = fopen(file_nm, "r");
	int array[10][10];
	if (ptr == NULL) {
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++) {
				if (i == 0)
					array[i][j] = j + 1;
				else
					array[i][j] = (10 * i) + (j + 1);
			}
	}
	else {
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++)
				fscanf(ptr, " %7d", &array[i][j]);
			fscanf(ptr, "\n");
		}
		fclose(ptr);
	}
	if (select == 0) {
		printf("\n\t\t\t\t  S C R E E N");Sleep(100);
		printf("\n\t\t\t\t  | | | | | |\n");Sleep(100);
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				if (array[i][j] == 0)
					printf("      **");
				else
					printf(" %7d", array[i][j]);
			}
			printf("\n\n"); Sleep(50);
		}
		char head[] = "\n\tPositions shown with ** are already reserved.\n\tSelect Seat.NO from non-reserved seats: ";
		txt_anim(head, sizeof(head));
	Again:
		scanf("%d", &seat_no);
		i = (seat_no / 10);
		j = (seat_no % 10) - 1;
		if (array[i][j] == 0) {
			printf("\t!! Seat no : %d is alread reserved.\n\tPlease select again : ", seat_no);
			goto Again;
		}
		array[i][j] = 0;
	}
	else {
		i = (select / 10);
		j = (select % 10) - 1;
		array[i][j] = select;
	}
	ptr = fopen(file_nm, "w");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			fprintf(ptr, " %7d ", array[i][j]);
		fprintf(ptr, "\n");
	}
	fclose(ptr);
	return seat_no;
}
//but_ticket function can be called directly from main meny or after login as user.
void buy_ticket(int select) {
	system("cls");
	FILE* ptr;
	char c;
	int num = 0, sno, seat;
	char ch;
	float price = 0.0;
	char head1[] = "\n\n\tChoose From Above Movie S.Numbers : ";
	ptr = fopen("Movies.txt", "a+");
	char head[] = "\nS.No    TYPE OF MOVIE       NAME OF MOVIE        DATE          TIME      PRICE(IN RUPESS).\n";
	txt_anim(head, sizeof(head));
	line_anim(30);
		while ((ch = fgetc(ptr)) != EOF) {
			printf("%c", ch);
			if (ch == '\n')
				Sleep(100);
		}
	line_anim(30);
		if (select == 1) {
			system("PAUSE");
			admin_menu();
		}
	fclose(ptr);
	ptr = fopen("Movies.txt", "r");
	fseek(ptr, 0, SEEK_END);
		if (ftell(ptr) == 0) {
			printf("\n\tTheir is no movie in cinema right-now\n\tPLease ask Admin to ADD Movies.##\n");
			system("PAUSE");
			system("cls");
			main();
		}
		else{
			rewind(ptr);
			txt_anim(head1, sizeof(head1));
			scanf("%d", &sno);
			for (c = getc(ptr); c != EOF; c = getc(ptr)) {
				if (c == '\n') // Increment count if this character is newline 
					num = num + 1;
				if (num == sno - 1)
					break;
			}
			if (select == 0) {//if function is called directly to buy ticket from main menu
				printf("\tENTER YOUR NAME : ");
				getc(stdin);
				fgets(name1, 20, stdin);
			}
		seat = seatno(sno, 0);
		system("PAUSE");
		struct book b;
		fscanf(ptr, "%*5d. %15s %20s ", b.mtype, b.mname);
		fscanf(ptr, "%10s %13s %14d \n", b.mday, b.mtime, &b.fee);
		price = (float)b.fee;
			if (select == 2)//discount if called from user menu
				price = 0.7 * price;
		system("cls");
		printf("\n\n");
		time_t t;
		time(&t);
		printf("\t-----------------TICKET BOOKING RECEIPT----------------\n");
		line_anim(24);
		printf("\n\tTICKET BOOKING DETAILS : %s \n", ctime(&t));Sleep(200);
		printf("\t Movie Name : %20s     Movie No      : %d \n", b.mname, sno);Sleep(200);
		printf("\t Movie Type : %20s     Customer Name : %s\n", b.mtype, name1);Sleep(200);
		printf("\t Movie Time : %20s     Seat Number   : %d\n", b.mtime, seat);Sleep(200);
		printf("\t Movie Date : %20s     \n\n", b.mday);Sleep(200);
			if (select == 0) {
				printf("\t\t\t\t\t       price         : %.2f", price);Sleep(200);
				line_anim(24);
				system("PAUSE");
				system("cls");
				main();
			}
			if (select == 2) {
				printf("\t %s You are logged-in \t   \tPrice 30%% OFF  : %.2f",name1, price);Sleep(200);
				line_anim(24);
				system("PAUSE");
				system("cls");
				user_menu();
			}
		}
}

void addMov()
{
		int num = 1;
		char c;
		struct book b;
		char op;
		FILE* fp;
		char title[] = "\t!! NOTE fill all fields without space.\n";
		txt_anim(title, sizeof(title));
		printf("\n    Enter Name of  Movie          : ");
		scanf("%s", b.mname);
		printf("      Enter type Movie            : ");
		scanf("%s", b.mtype);
		printf("Enter Movie Schedule (DD:MM:YYYY) : ");
		c = getc(stdin);
		scanf("%s", b.mday);
		printf("   Enter Time (eg hh:mm AM )      : ");
		scanf("%s", &b.mtime);
		printf("    Enter Ticket Prize            : ");
		scanf("%d", &b.fee);
		fp = fopen("Movies.txt", "a+");//above lines just input the required ditails for movie
		rewind(fp);
			for (c = getc(fp); c != EOF; c = getc(fp))
				if (c == '\n') // Increment count if this character is newline 
					num = num + 1; //num+1 is the 1 more than the total no of movies already present in data
		fprintf(fp, "%5d. %15s %20s ", num, b.mtype, b.mname);
		fprintf(fp, "%10s %13s %14d \n", b.mday, b.mtime, b.fee);//now inpute fiels are enterd in the file
		printf("\n\tRecord insert sucessful!");
		line_anim(38);
		fclose(fp);
			do {
				printf("\n\tAdd another record (y/n)? : ");
				c = getc(stdin);
				scanf("%c", &op);
				switch (op) {
				case 'y':
					printf("\n");
					addMov();
				case 'n':
					printf("\n");
					admin_menu();
				default:
					printf("Please select (y) or (n)! \n");
				}
			} while (op != 'n');
		admin_menu();
}

int authentication(int select) {
		char  password[20], tempname[30], check_pass[20];
		unsigned int length;
		printf("\tENTER YOUR NAME  : ");
		getc(stdin);
		gets(name1, sizeof(name1), stdin);
		strcpy(tempname, name1);
		length = strlen(tempname);
		if (select == 1)
			strcat(tempname, " admin");
		strcat(tempname, ".txt");

		FILE* ptr;
		if ((ptr = fopen(tempname, "r")) == NULL) { //to check if the account exist
			printf("\t!!This user/admin account does Not exist.\n Press any key to continue");
			getchar();
			return;
		}
		else {//if files exist than it inputs the password
			fclose(ptr);
			printf("\tEnter Password   : ");
		Again:
			scanf("%s", password);
			ptr = fopen(tempname, "a+");
			fseek(ptr, -20, SEEK_END);
			fscanf(ptr, "%s", check_pass);
			if (strcmp(password, check_pass) != 0) {
				printf("\t!!Password does not matche.\n \tENTER AGAIN:\t");
				goto Again;
			}
		}
		rewind(ptr);//this function brings the curser in the file to the start of file
		fclose(ptr);
		return 0;
}

void Create_account(int select) {
		char name[20], password[20], choose, tempname[30];
		char admin_pass[20] = "Welcome@1";
		printf("\tENTER YOUR NAME: ");
		getc(stdin);
		gets(name, sizeof(name), stdin);//this line input name
		strcpy(tempname, name);
			//
			if (select == 1) {				//if account is created for admin
				strcat(tempname, " admin");//then admin is also concatenated with the name 
			pass:							//as admin has to be given more authorites
				printf("\tEnter Admin authentication password: ");
				scanf("%s", password);
				if ((strcmp(password, admin_pass)) != 0) {
					printf("\t!!Admin password not matched.!!\n\tWant to re-enter password (y/n): ");
					getc(stdin);
					scanf("%c", &choose);
					if (choose == 'y')
						goto pass;
					return;
				}
			}
		printf("\tENTER your password: ");
		scanf("%s", password);
		strcat(tempname, ".txt");
		FILE* ptr;
		strcat(name, " ");
		ptr = fopen(tempname, "a+"); //now txt file is created either for for admin or user
		fputs(name, ptr); //in these lines names and password  are saved to file
		fprintf(ptr, " %20s", password);
		fclose(ptr);
		char title[] = "Your Account has been created";
		txt_anim(title, sizeof(title));
		line_anim(38);
		system("cls");
		return;
}
//the logic used is that new password is just written at the last 20 spaces of each respective account file
//and authentication picks the last 20 space of account file as a passowrd.
void change_pass(int select) {
	line_anim(38);
	char file_name[30], new_pass[35];
	strcpy(file_name, name1);
	if (select == 1)
		strcat(file_name, " admin");
	strcat(file_name, ".txt");
	printf("\n\t%s, enter new password :: ", name1);
	scanf("%s", new_pass);
	printf("\n\tPassword changed succesfully\n");
	system("PAUSE");
	FILE* ptr = fopen(file_name, "a+");
	fprintf(ptr, " %20s", new_pass);
	fclose(ptr);
	if (select == 1)
		admin_menu();
	else if (select == 2)
		user_menu();
}
//this menu just decide and direct the control to other functions accordingly
void admin_menu() {
	system("cls");	
	int choice = 0;
	char c;
	char title[25];
	printf("\n\n\t*********************************\n");Sleep(500);
	printf("\t|You are Login-in as admin:  \t|\n \t| 1. Add Movies\t\t\t|\n \t| 2. Show all Movies   \t\t|\n \t| 3. Delete Movies \t\t|\n\t| 4. Log-out \t\t\t|\n\t| 5. Change password\t\t|\n\t| 6. Exit\t\t\t|");Sleep(500);
	printf("\n\t********************************* \n\tEnter your choioce : ");Sleep(500);
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		addMov();
		break;
	case 2:
		buy_ticket(1);//this function only shows administrator movie
		break;
	case 3:
		system("cls");
		char itl[] = "Note :: !!ALL THE MOVIES WILL BE DELETED\n\t Do you stil want to delete (y/n): ";
		txt_anim(itl, sizeof(itl));
		do {
			getc(stdin);
			scanf("%c", &c);
			switch (c) {
			case 'y':
				remove("Movies.txt");
				printf("\tDeleted Movies Successfuly : \n");
				break;
			case 'n':
				break;
			default:
				printf("Please select (y) or (n)! ");
			}
		} while (c != 'n' && c != 'y');
		system("PAUSE");
		admin_menu();
	case 4:
		system("cls");
		char title[] = "YOU ARE LOGGED-OUT SUCCESFULLY";
		txt_anim(title, sizeof(title));
		main();
	case 5:
		change_pass(1);
		break;
	case 6:
		close();
	default:
		printf("\t!!Selection out of list.");Sleep(1500);
		break;
	}
	return;
}

//this menu just decide and direct the control to other functions accordingly
void user_menu() {
	system("cls");
	line_anim(38);
	int choice = 0, seat = 0;
	printf("\n\n\t*********************************\n");Sleep(500);
	printf("\t|You are Login-in as User:  \t|\n \t| 1. Buy Movie ticket\t\t|\n \t| 2. Return Movie ticket  \t|\n \t| 3. Change password \t\t|\n\t| 4. Log-out\t\t\t|\n\t| 5. Exit\t\t\t|");Sleep(500);
	printf("\n\t********************************* \n\tEnter your choioce : ");Sleep(500);
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		buy_ticket(2);
	case 2:
		printf("\t%s Please Enter movie number : ", name1);
		scanf("%d", &choice);
		printf("\t%s Please Enter Seat  number : ", name1, seat);
		scanf("%d", &seat);
		seatno(choice, seat);
		printf("\t%s, your Seat No %d for Movie No: %d has been cancelled. \n", name1, seat, choice);
		system("PAUSE");
		system("cls");
		user_menu();
	case 3:
		change_pass(2);//the control is again directed to the user menu after changing passowrd
	case 4:
		system("cls");
		main();
	case 5:
		close();
	default:
		break;
	}
}

void line_anim(int num) {
	printf("\n");
	for (int i = 0; i < num; i++) {
		printf("+--"); Sleep(80);
	}
	printf("\n");
}

void txt_anim(char* ptr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%c", ptr[i]);
		Sleep(60);
	}
	return;
}

void close(void) {
	printf("\t!!Existing program\n");
	system("PAUSE");
	exit(0);
}
//The End:)