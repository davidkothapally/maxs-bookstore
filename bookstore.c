#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct books // used struct to reduce the amount of time and space taken in certain functions
{
	char book_name[100];
	int number_of_books;
	int book_price;
	int total_price;
	int sum;
}books;	

// The function prototypes
void payroll();
void new_payroll();
void view_payroll();
void delete_payroll();
void purchases();
void new_purchase();
void view_purchases();
void delete_purchases();
void sold_books();
void new_sale();
void view_sales();
void delete_sales();
void arrival_dates();
void new_date();
void view_dates();
void delete_dates();
void profits();

int main()
{
system("color F0");	// background and text colour changed for better viewing while making presentation on a white board

	// variable declarations
	char option[150];
	int length;

	printf("\n<---------------------------->|<--------------->|<---------------------------->");
	printf("\n<---------------------------->| MAX's BOOKSTORE |<---------------------------->"); // name of the store
	printf("\n<---------------------------->|<--------------->|<---------------------------->\n\n");

	// text showing main interface
	puts("DATABASE OPTIONS\n");
	puts("Enter 1 for payroll information.");
	puts("Enter 2 for purchases.");
	puts("Enter 3 for sales.");
	puts("Enter 4 for the dates of the arrival of new books.");
	puts("Enter 5 to see profit made by the bookstore.\n");
    puts("If you wish to exit the program enter any other character.\n");
	puts("Enter your option here: ");	// asks the user to choose an option
	scanf("%s", option);	// reads the option chosen by the user

	length = strlen(option);	// used to check the length of the input
	
	// this conditional statement is used to ensure that the user cannot enter more than one input
	if(length > 1){
		system("cls");	// screen cleared to prevent contant scrolling through of program
		printf("You have entered more than one character.\n\n");	// error message to indicate if more than one character is inputted by the user
		system("pause");	// system paused to ensure that the user reads error message
		system("cls");
		main();
	}else{
	system("cls");	// clears the screen to avoid constant scrolling of program
	
	switch(option[0])	// carries out function based on option chosen by the user
	{
		case '1':	// goes to payroll()
			payroll();
		break;
		case '2':	// goes to purchases()
			purchases();
		break;
		case '3':	// goes to sold_books()
			sold_books();
		break;
		case '4':	// goes to arrival_dates()
			arrival_dates();
		break;
		case '5':	// goes to profits()
			profits();
		break;
		default:	// exits program
			system("cls");	// screen is cleared to prevent costant scrolling through of program
			printf("Thank you for trying our program*\n\n\n");	// exit message
			system("pause");	// system paused to indicate to the user that the program is ending
			exit(1);
		break;
	}
	}
	system("cls");	// clears screen to avoid constant scrolling through program
	main();	// calls back main() so that the program can run infinitely
	return 0;
}

void payroll()	// displays payroll information and calls back main() when executed
{
	// variable declarations
	char option2[150];
	int length;
	
	// text showing the user the payroll interface
	puts("PAYROLL OPTIONS");
	puts("Enter 1 to add payroll for new employee.");
	puts("Enter 2 to view current payroll.");
	puts("Enter 3 to delete current payroll.");
	puts("\nEnter 0 to go back to starting page.");
	printf("\nEnter your option here: ");	// allows the user to enter the desired option
	scanf("%s", option2);	// reads the option selected by the user
	
	length = strlen(option2);	// used to check the length of input
	
	// conditional statement used to display error message and restart payroll() when more than one character is entered
	if(length > 1){
		system("cls");	// screen cleared to prevent constant scrolling of program
		printf("You have entered more than one character.\n\n");	// error message
		system("pause");	// paused for user to read error message
		system("cls");
		payroll();	// used to start payroll() until user makes a valid choice
	}else{
	
	switch(option2[0])	// carries out function based on option chosen by user
	{
		case '1':	// goes to new_payroll()
			new_payroll();
		break;
		case '2':	// goes to view_payroll()
			view_payroll();
		break;
		case '3':	// goes to delete_payroll()
			delete_payroll();
		break;
		case '0':	// goes to main()
			main();
		break;
		default:	// restarts payroll() because of wrong input
			system("cls");	// screen cleared to prevent scrolling through program
			puts("You have entered the wrong input. Please try again.\n\n");	// error message
			system("pause");	// paused to allow the user to read error message
			system("cls");
			payroll();	// restarts payroll until valid choice is made by the user
		break;
	}
	}
	printf("\n");
	system("pause");
	return;
}

void new_payroll()	// allows for entry of a new payroll
{
	FILE * ptr;
	ptr = fopen("payroll.txt", "a");

	// variable declarations
	char first_name[50];
	char last_name[50];
	int gross_pay;

	printf("\nType the first name of the new employee:");	// alows for user to type the first name of the new employee
	scanf("%s", first_name);	// reads the first name of the employee
	printf("\nType the last name of the new employee:");	// alows for user to type the last name of the new employee
	scanf("%s", last_name);	// reads the last name of the employee
	fprintf(ptr, "\n\nNAME		:	%s %s", first_name, last_name);	// stores the full name of the new employee in the database

	printf("\nType the gross pay of the new employee: $");	// allows for user to enter the employee's gross pay
	scanf("%d", &gross_pay);	//reads the employee's gross pay
	fprintf(ptr, "\nGROSS PAY	:	$%d", gross_pay);	// stores the gross pay of the employee in the database

	fclose(ptr);
	return;
}

void view_payroll()	// displays appropriate text file containing payroll information
{
	FILE * ptr;
	char singleLine[150];
	
	// conditional statement used to display message (if there are no inputs) or display file
	if((ptr = fopen("payroll.txt", "r"))==NULL) {
		printf("There is no payroll information curently.\n");	// message displayed if file is missing
	}else{
	while(!feof(ptr)) {	// loops until pointer reaches to end of file
	fgets(singleLine, 150, ptr);	// reads every line in the file because of loop
	puts(singleLine);	// prints every line in the file because of loop
	}
	}

	fclose(ptr);
	return;
}

void delete_payroll()	// deletes text file containing the payroll information
{
	remove("payroll.txt");	// deleted payroll.txt
	puts("The payroll has been successfully deleted.");	// message showing the user that the file has been deleted
	return;
}

void purchases()	// displays information on purchased books and calls back main() when executed
{
	// variable declarations
	char option3[150];
	int length;
	
	// text showing the purchases interface
	puts("PURCHASES OPTIONS");
	puts("Enter 1 to add a new purchase.");
	puts("Enter 2 to view current purchases.");
	puts("Enter 3 to delete current purchases");
	puts("Enter 0 to go back to the main page");
	printf("\nEnter your option here: ");	// asks the user to select an option
	scanf("%s", option3);	// reads the option selected by the user

	length = strlen(option3);	// used to check the length of input
	
	// conditional statement used to display error message and restart purchases() when more than one character is used
	if(length > 1){
		system("cls");
		printf("You have entered more than one character.\n\n");	// error message
		system("pause");	// paused in order to read error message
		system("cls");
		purchases();
	}else{
	
	switch(option3[0])	// carries out function based on option chosen
	{
		case '1':	// goes to new_purchase()
			new_purchase();
		break;
		case '2':	// goes to view_purchases()
			view_purchases();
		break;
		case '3':	// goes to delete_purchases()
			delete_purchases();
		break;
		case '0':	// goes to main()
			main();
		break;
		default:	// restarts purchases() because of wrong input
			system("cls");
			puts("You have entered the wrong input. Please try again.\n\n");	// error message
			system("pause");	// system paused to allow user to read error message
			system("cls");
			purchases();	// restarts purchases() until valid choice is made by the user
		break;
	}
	}

	printf("\n");
	system("pause");	// screen paused to allow the user to read what was just entered
	return;
}

void new_purchase()	// allows for entry of a new purchase
{
	FILE * ptr;
	FILE * sumptr;

	// sum_purchases is created with value 0 because the sum of books needs to be initialized before calculations can be assigned to it
	if((sumptr = fopen("sum_purchases.txt", "a")) == NULL){
		fprintf(sumptr, "%d", 0);
		fclose(sumptr);
	}

	sumptr = fopen("sum_purchases.txt", "r");
	ptr = fopen("purchases.txt", "a");

	getchar();
	printf("\nType the name of the book purchased: ");	// collects book name from user
	gets(books.book_name);
	printf("\nType the quantity of the purchased book: ");	// collects quantity purchased from user
	scanf("%d", &books.number_of_books);
	printf("\nType the price for one book: $");	// collects price of book from user
	scanf("%d", &books.book_price);
	
	// calculation for total price of books
	books.total_price = books.number_of_books * books.book_price;
	fscanf(sumptr, "%d", &books.sum);
	books.sum = books.sum + books.total_price;

	fclose(sumptr);
	sumptr = fopen("sum_purchases.txt", "w");

	fprintf(ptr, "\n%d %s @ %d = %d", books.number_of_books, books.book_name, books.book_price, books.total_price);	// input printed to purchases.txt
	fprintf(sumptr, "%d", books.sum);	// input printed to sum_purchases.txt

	fclose(ptr);
	fclose(sumptr);
	return;
}

void view_purchases()	// displays the text files relating to purchases
{
	FILE * ptr;

	// conditional statement to either display a message if file is missing or to display file
	if((ptr = fopen("purchases.txt", "r")) == NULL){
		puts("There is no information on purchases.");	// message that is displayed if there is no file named purchases.txt
	}else{

	char singleLine[150];

	while(!feof(ptr)) {	// loops until pointer reaches end of file
	fgets(singleLine, 150, ptr);	// reads every line in the file because of loop
	puts(singleLine);	// prints every line read because of loop
	}

	fclose(ptr);
	printf("\n");

	int sum;

	ptr = fopen("sum_purchases.txt", "r");
	fscanf(ptr, "%d", &sum);	// reads value in file

	printf("The total spent on purchases is $%d.", sum);	// prints value read from file
	}
	return;
}

void delete_purchases()	// deletes text files on purchases
{
	FILE * sumptr;
	remove("purchases.txt");	// deletes purchases.txt
	sumptr = fopen("sum_purchases.txt", "w");	// opened to assign sum as 0 before deleting
	fprintf(sumptr, "%d", 0);	// assigned to 0 in order to prevent arithmetic errors because of previous value if any
	fclose(sumptr);
	remove("sum_purchases.txt");	// deletes sum_purchases.txt
	puts("Successfully deleted purchases.");
	return;
}

void sold_books()	// displays information on sold books and calls back main() when executed
{
	// variable declarations
	char option4[150];
	int length;
	
	// text showing the sales interface
	puts("SALES OPTIONS");
	puts("Enter 1 to add a new sale.");
	puts("Enter 2 to view current sales.");
	puts("Enter 3 to delete current sales");
	puts("Enter 0 to return to main page");
	printf("\nEnter your option here: ");	// asks the user to choose an option
	scanf("%s", option4);	// reads the option chosen by the user
	
	length = strlen(option4);	// used to find length of input
	
	// conditional statement used to display error message and restart sold_books if more than one character is entered
	if(length > 1){
		system("cls");
		printf("You have entered more than one character.\n\n");	// error message
		system("pause");	// paused to allow for reading of error message
		system("cls");
		sold_books();	// restarts sold_books until vaalid choice is made by the user
	}else{
	
	switch(option4[0])	// carries out a function based on option chosen by the user
	{
		case '1':	// goes to new_sale()
			new_sale();
		break;
		case '2':	// goes to view_sales()
			view_sales();
		break;
		case '3':	// goes to delete_sales()
			delete_sales();
		break;
		case '0':	// goes to main()
			main();
		break;
		default:	// displays error message and restarts sold_books()
			system("cls");
			puts("You have entered the wrong input. Please try again.\n\n");	// error message
			system("pause");	// paused so user can read error message
			system("cls");
			sold_books();	// restarts sold_books() until user enters valid input
		break;
	}
	}
	
	printf("\n");
	system("pause");	// pauses screen to allow user to read what was chosen
	return;
}

void new_sale()	// allows for entry of a new sale to the database
{
	// local variables
	FILE * ptr;
	FILE * sumptr;
		
	// if statement used to input 0 as the starting value for calculation to be correct
	if((sumptr = fopen("sum_sales.txt", "a")) == NULL){
		fprintf(sumptr, "%d", 0);	// 0 is written to sum_sales because there needs to be a value for calculation to be possible
		fclose(sumptr);
	}

	sumptr = fopen("sum_sales.txt", "r");
	ptr = fopen("sales.txt", "a");

	getchar();
	printf("\nType the name of the book sold: ");	// collects book_name
	gets(books.book_name);
	printf("\nType the quantity of the sold book: ");	// collects quantity of books sold
	scanf("%d", &books.number_of_books);
	printf("\nType the price for one book: $");	// collects price of one book
	scanf("%d", &books.book_price);
	
	// calculation for total price for books
	books.total_price = books.number_of_books * books.book_price;
	fscanf(sumptr, "%d", &books.sum);
	books.sum = books.sum + books.total_price;

	fclose(sumptr);
	sumptr = fopen("sum_sales.txt", "w");

	fprintf(ptr, "\n%d %s @ %d = %d", books.number_of_books, books.book_name, books.book_price, books.total_price);	// input printed to sales.txt
	fprintf(sumptr, "%d", books.sum);	// input printed to sum_sales.txt

	fclose(ptr);
	fclose(sumptr);
	return;
}

void view_sales()	// views all text files relating to sales
{
	FILE * ptr; // local variable

	// conditional statement to either display a message if file is missing or to display file
	if((ptr = fopen("sales.txt", "r")) == NULL){
		puts("There is no information on sales.");	// message that is displayed if there is no fie named sales.txt
	}else{

	char singleLine[150]; // local variable

	while(!feof(ptr)) {	// loops until pointer reaches end of file
	fgets(singleLine, 150, ptr);	// reads every line in the file because of loop
	puts(singleLine);	// prints every line read because of loop
	}

	fclose(ptr);
	printf("\n");

	int sum; // local variable

	ptr = fopen("sum_sales.txt", "r");
	fscanf(ptr, "%d", &sum);	// reads value in file
	printf("The total made from sales is $%d.", sum);	// prints value read from file
	}
	return;
}

void delete_sales()	// deletes all text files relating to sales and clears all data stored on sales
{
	FILE * sumptr; // local variable
	remove("sales.txt");
	sumptr = fopen("sum_sales.txt", "w");	// assigning sum as 0 before deleting to clear previous values
	fprintf(sumptr, "%d", 0);	// assigned to 0 in order to prevent arithmetic errors because of previous value if any
	fclose(sumptr);
	remove("sum_sales.txt");	// deletes sum_sales.txt
	puts("Successfully deleted sales.");
	return;
}

void arrival_dates()	// displays information on the dates for the arrival of new books and calls back main() when executed
{
	char option5[150];
	int length;
	
	// text showing dates interface
	puts("DATES OPTIONS");
	puts("Enter 1 to add a new date.");
	puts("Enter 2 to view current dates.");
	puts("Enter 3 to delete current dates.");
	puts("\nEnter 0 to return to main page");
	printf("\nEnter your option here: ");	// asks the user to select the desired option
	scanf("%s", option5);	// reads the option entered by the user
	
	length = strlen(option5);	// used to find the length of input
	
	// this conditional statement is used to ensure the user does not enter more than one character as input
	if(length > 1){
		system("cls");
		printf("You have entered more than one character.\n\n");	// error message
		system("pause");	// system paused in order to be able to read error message
		system("cls");
		arrival_dates();	// restarts arrival_dates until valid input is entered
	}else{

	switch(option5[0])	// carries out option based on option chosen
	{
		case '1':	// goes to new_date()
			new_date();
		break;
		case '2':	// goes to view_dates()
			view_dates();
		break;
		case '3':	// goes to delete_dates()
			delete_dates();
		break;
		case '0':	// goes to main()
			main();
		break;
		default:	// displays error message and restarts arrival_dates()
			system("cls");
			puts("You have entered the wrong input. Please try again.\n\n");	// error message
			system("pause");	// paused in order to view error message
			system("cls");
			arrival_dates();	// restarts arrival_dates() until user enters a valid input
		break;
	}
	}
	
	printf("\n");
	system("pause");	// pauses the screen to allow the user to view and select the desired option
	return;
}

void new_date()	// allows user to enter a new date and stores it in the appropriate text file
{
	FILE * ptr;
	ptr = fopen("dates.txt", "a");

	// local variable declarations
	char book_name[100];
	int number_of_books;
	char date[20];

	printf("\nType the name of the new arriving book: ");	// collects book name
	scanf("%s", book_name);
	printf("\nType the quantity of the new arriving book: ");	// collects quantity of books
	scanf("%d", &number_of_books);
	printf("\nType the date of arrival (dd/mm/yyyy): ");	// collects the date of arrival
	scanf("%s", date);

	fprintf(ptr, "\n%d %s arriving on %s.", number_of_books, book_name, date);	// prints data collected to dates.txt
	fclose(ptr);
	return;
}

void view_dates()	// opens and reads all text files relating to the dates of the arrival of new books
{
	FILE * ptr;
	// conditional statement to either display a message if file is missing or to display file
	if((ptr = fopen("dates.txt", "r")) == NULL){
		puts("There is no information on dates.");	// message that is displayed if there is no file named dates.txt
	}else{

	char singleLine[150];

	while(!feof(ptr)) {	// loops until pointer reaches end of file
	fgets(singleLine, 150, ptr);	// reads every line in the file because of loop
	puts(singleLine);	// prints every line read because of loop
	}
	
	fclose(ptr);
	printf("\n");
	}
	return;
}

void delete_dates()	// deletes all text files relating to dates
{
	remove("dates.txt");	// deletes dates.txt
	puts("Successfully deleted dates.");	// indicates to the user that the files have been deleted
	return;
}

void profits()	// displays information on the profits made by the business and calls back main() when executed
{
	// variable declarations
	int sum_purchases;
	int sum_sales;
	int profit_made;

	FILE * ptr;

	// conditional statement used to display error messages or to display profit
	if((ptr = fopen("sum_purchases.txt", "r")) == NULL){
		puts("There are no purchases so it is not possible to calculate a profit.");
	}else{
	fscanf(ptr, "%d", &sum_purchases);
	fclose(ptr);
	
	// conditional statement used to display error message or diaplay profit
	if((ptr = fopen("sum_sales.txt", "r")) == NULL){
		puts("Purchases found. There are no sales so it is not possible to calculate a profit.");
	}else{
	fscanf(ptr, "%d", &sum_sales);
	fclose(ptr);

	profit_made = sum_sales - sum_purchases;	// calculation for profit made
	printf("\nThe total spent on purchases is $%d.", sum_purchases);
	printf("\nThe total spent on sales is $%d.", sum_sales);
	printf("\nHence the profit made by the business is $%d", profit_made);
	printf("\nNOTE: A negative profit implies a loss.\n");
	}
	}
	system("pause");	// pauses screen to allow the user to read information displayed
	return;
}

