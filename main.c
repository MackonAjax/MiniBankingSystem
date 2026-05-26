// A MINI BANKING SYSTEM FROM GROUP TWO

#include <stdio.h>
<<<<<<< Updated upstream
// this is the mini banking system 

int main(){
    printf("Hello Mini Baking.");
=======
#include <string.h>


// THESE ARE THE FUNCTION PROTOTYPES

// AUTHENTICATION FUNCTIONS
void sign_up();
int validate_sign_up_details(char name[30], char phone_number[11], char password[30]);
void write_user_to_file(char name[30], char phone_number[11], char password[30], int account_balance);
void log_in();
void delete_account();
void change_account_information();

void users_dashboard(char name[30], char phone_number[11], char password[30], int account_balance);
float deposit();
float withdraw();
float send_money();

int entry_menu();


int main(){

    while(1){
        // entry_menu() is the very first function to be called
        int return_value = entry_menu();
        if(return_value == 10){
            break;
        }
    }

>>>>>>> Stashed changes
    return 0;
}

// FUNCTION DEFINITIONS

int entry_menu(){
    // this is the very first function that calls when someone runs the application.
    // if this function returns 10, the main application loop will break

    printf("\nHELLO, WELCOME TO SIMBA MINI BANK. PLEASE SELECT AN OPTION TO CONTINUE\n");
    printf("\t1. Create a Simba Account.\n");
    printf("\t2. Log in to my Simba Account\n");
    printf("\t3. View Help Page\n");
    printf("\t4. Quit \n");
    printf("ENTER A NUMBER: ");
    int option;
    scanf("%d", &option);

    if(option == 1){

        sign_up();  // option for craeting a SIMBA account

    }else if(option == 2){

        printf(" 2 selected");

    }else if(option == 3){

        printf(" 3 selected");

    }else if(option == 4){

        printf("#####QUITING SIMBA MINI BANKING.#####");
        return 10; // return of 10

    }else{

        printf("\n\n#####PLEASE SELECT A VALID INTEGER.#####\n\n");
        entry_menu();

    }

    return 0;

}

void sign_up(){
    // this is the account creration function. It runs when option 1 is called from the entry_menu()
    char name[30];
    char phone_number[12];
    char password[30];

    // FLUSHING THE \n FROM THE BUFFER
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    // the chaotic \n left by scanf() has been flushed

    printf("\n\nWELCOME TO SIMBA ACCOUNT CREATION. PLEASE FILL IN THE FOLLOWING OPTIONS.\n");
    printf("\n\tName: ");
    fgets(name, sizeof(name), stdin);

    printf("\n\tPhone Number: ");
    fgets(phone_number, sizeof(phone_number), stdin);

    printf("\n\tPassword: ");
    fgets(password, sizeof(password), stdin);

    // the validate_sign_up_details function is called to validate the details.
    // if it returns 0 - sign up credentials are okay
    //              1 - an error with name  2 - error with phone_number   3 - error with password
    int validity = validate_sign_up_details(name, phone_number, password);
    if(validity == 0){
        // this setcion of the if ststement runs when the sign up details have been verified.

        printf("\nValidated credentials, account creation proceeding.");

        account_creation:
        int initial_deposit;
        printf("\nWHAT INITIAL DEPOSIT DO YOU WANT(Above 10,000): ");
        scanf("%d", &initial_deposit);
        if(initial_deposit >= 10000){
            // everything is set, the account can be registered now.

            write_user_to_file(name, phone_number, password, initial_deposit);  // registering the user now
            users_dashboard(name, phone_number, password, initial_deposit);

            printf("\n########################################################################################");
            printf("\t\tCONGRATULATIONS, YOUR SIMBA ACCOUNT HAS SUCCESSFULLY BEEN REGISTERED.");
            printf("\n#######################################################################################");
        }else{
            printf("\n####PLEASE ENTER A PROPER INITIAL DEPOSIT VALUE.\n");
            goto account_creation;
        }

    }else if(validity == 1){

        printf("\n\n####THERE IS AN ERROR WITH YOUR NAME####\n\n");
        sign_up();

    }else if(validity == 2){
        printf("\n\n####YOUR PHONE NUMBER IS INCORRECT####\n\n");
        sign_up();

    }else if(validity == 3){

        printf("\n\n####YOUR PASSWORD SHOULD BE BETWEEN 6 AND 30 CHARACTERS.####\n\n");
        sign_up();

    }else{

        printf("\n\n####AN UNKNOWN ERROR OCCURED DURING ACCOUNT CREATION. PLEASE TRY AGAIN.####\n\n");
        sign_up();

    }

}

int validate_sign_up_details(char name[30], char phone_number[11], char password[30]){
    // this validates the sign up details.
    // return: 0 - okay; 1 - name error; 2 - phone number error; 3 - password error
    if(1==0){
        return 1;
    }
    if(1==0){
        return 2;
    }
    if(1==0){
        return 3;
    }
    return 0;
}

void write_user_to_file(char name[30], char phone_number[11], char password[30], int account_balance){
    FILE *file_ptr = fopen("./simba_users.db", "a");
    // first strip away the \n before writing to file.
    name[strcspn(name, "\n")] = '\0';
    phone_number[strcspn(phone_number, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';
    fprintf(file_ptr, "%s | %s | %s | %d\n", phone_number, name, password, account_balance);
    fclose(file_ptr);
}

void users_dashboard(char name[30], char phone_number[11], char password[30], int account_balance){
    // this function prints the users dashboard after sign up or login
    
    // this loops you as a signed in user till you break
    while(1){
        printf("\n\n######################################################################");
        printf("\n######################################################################");
        printf("\nHELLO %s, WELCOME TO SIMBA MINI BANK.", name);
        printf("\nPHONE NUMBER: %s    :::    ACCOUNT BALANCE: %d", phone_number, account_balance);
        if(account_balance <= 15000){
            printf("\nYour Account Balance is a bit low. Please Consider depositing Money.");
        }
        my_menu:
        printf("\n\t1. Deposit Money");
        printf("\n\t2. Send Money");
        printf("\n\t3. Withdraw Money");
        printf("\n\t4. View Transaction History");
        printf("\n\t5. Log out");
        printf("\n\t6. Delete My Account.");

        printf("\nYou Can select an Option: ");
        int option;
        scanf("%d", &option);

        if(option == 1){

        }else if(option == 2){

        }else if(option == 3){

        }else if(option == 4){

        }else if(option == 5){
            break;
        }else if(option == 6){
            
        }else{
            printf("\n########## PLEASE SELECT A VALID INTEGER OPTION ############");
            goto my_menu;
        }
    }

}

void log_in(){

    char phone_number[12];
    char password[30];
    printf("\n\nHELLO, PLEASE LOGIN TO YOUR SIMBA ACCOUNT.");
    printf("\nEnter q to quit here.");
    printf("\n\tName: ")
    scanf("%s", phone_number);
    
    if(phone_number == "q"){return;}

    printf("\n\tPassword: ");
    scanf("%s", password);

    // this compares phone_number and password to existing account details

}