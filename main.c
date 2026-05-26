// A MINI BANKING SYSTEM FROM GROUP TWO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// THESE ARE THE FUNCTION PROTOTYPES

// AUTHENTICATION FUNCTIONS
void sign_up();
int validate_sign_up_details(char name[30], char phone_number[12], char password[30]);
void write_user_to_file(char name[30], char phone_number[12], char password[30], int account_balance);
void log_in();
int read_user_from_file(char phone[12], char password[30], char *name, int *account_balance);

int update_account_details(char phone_number[12], char password[30], char new_name[30], char new_password[30]);
void view_help_page();

void users_dashboard(char name[30], char phone_number[12], char password[30], int account_balance);
int deposit(int amount, int token, char phone_number[12], char password[30]);
int withdraw(int amount, int t_token, char phone_number[12], char password[30]);
int send_money();
void view_my_transaction_history();
int delete_my_account(char phone_number[12], char password[30]);

int entry_menu();


int main(){

    while(1){
        // entry_menu() is the very first function to be called
        int return_value = entry_menu();
        if(return_value == 10){
            break;
        }
    }

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

       log_in(); // login to an existing account

    }else if(option == 3){

        view_help_page(); // this shows the help page to the user

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

            printf("\n########################################################################################");
            printf("\t\t\nCONGRATULATIONS, YOUR SIMBA ACCOUNT HAS SUCCESSFULLY BEEN REGISTERED.");
            printf("\n#######################################################################################");

            users_dashboard(name, phone_number, password, initial_deposit);
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

int validate_sign_up_details(char name[30], char phone_number[12], char password[30]){
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

void write_user_to_file(char name[30], char phone_number[12], char password[30], int account_balance){
    FILE *file_ptr = fopen("./simba_users.db", "a");
    // first strip away the \n before writing to file.
    name[strcspn(name, "\n")] = '\0';
    phone_number[strcspn(phone_number, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';
    fprintf(file_ptr, "%s|%s|%s|%d\n", phone_number, name, password, account_balance);
    fclose(file_ptr);
}

void users_dashboard(char name[30], char phone_number[12], char password[30], int account_balance){
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
        printf("\n\t2. Update Account Details (You can only change name and password)");
        printf("\n\t3. Withdraw Money");
        printf("\n\t4. View Transaction History");
        printf("\n\t5. Log out");
        printf("\n\t6. Delete My Account.");

        printf("\nYou Can select an Option: ");
        int option;
        scanf("%d", &option);

        if(option == 1){
            // depositing money
            deposit_money:
            int amount, t_token;
            printf("\n\tEnter Amount to deposit: ");
            scanf("%d", &amount);
            printf("\n\tEnter agents transaction token: ");
            scanf("%d", &t_token);
            if(amount <= 0){
                printf("\n\n####PLEASE ENTER A VALID AMOUNT TO DEPOSIT.####\n\n");
                goto deposit_money;
            }

            int deposit_result = deposit(amount, t_token, phone_number, password);
            if(deposit_result == 1){
                printf("\n\n####DEPOSIT SUCCESSFUL. YOUR ACCOUNT HAS BEEN CREDITED WITH %d.####\n\n", amount);
                account_balance += amount; // update the account balance in the dashboard
            }else if(deposit_result == 0){
                printf("\n\n####DEPOSIT FAILED. INVALID TRANSACTION TOKEN.####\n\n");

            }

        }else if(option == 2){
            // updating account details
            update_account_details:
            char new_name[30];
            char new_password[30];
            printf("\n\tEnter New Name: ");
            scanf("%s", new_name);
            printf("\n\tEnter New Password: ");
            scanf("%s", new_password);

            int update_result = update_account_details(phone_number, password, new_name, new_password);
            if(update_result == 1){
                printf("\n\n####ACCOUNT DETAILS UPDATED SUCCESSFULLY.####\n\n");
                // update the name and password in the dashboard
                strcpy(name, new_name);
                strcpy(password, new_password);
            }else{
                printf("\n\n####UPDATE FAILED. INVALID CREDENTIALS.####\n\n");
                goto update_account_details;
            }
        }else if(option == 3){
            // withdrawing money
            withdraw_money:
            int amount, t_token;
            printf("\n\tEnter Amount to withdraw: ");
            scanf("%d", &amount);
            printf("\n\tEnter agents transaction token: ");
            scanf("%d", &t_token);
            if(amount <= 0){
                printf("\n\n####PLEASE ENTER A VALID AMOUNT TO WITHDRAW.####\n\n");
                goto withdraw_money;
            }

            int withdraw_result = withdraw(amount, t_token, phone_number, password);
            if(withdraw_result == 1){
                printf("\n\n####WITHDRAWAL SUCCESSFUL. YOUR ACCOUNT HAS BEEN DEBITED BY %d.####\n\n", amount);
                account_balance -= amount; // update the account balance in the dashboard
            }else if(withdraw_result == 0){
                printf("\n\n####WITHDRAWAL FAILED. INVALID TRANSACTION TOKEN OR INSUFFICIENT FUNDS.####\n\n");
            }
        }else if(option == 4){
            printf("\n\n####THIS OPTION IS NOT AVAILABLE YET. IT WILL BE IN A FUTURE RELEASE.####\n\n");
        }else if(option == 5){
            break;
        }else if(option == 6){
            int delete_result = delete_my_account(phone_number, password);
            if(delete_result == 1){
                printf("\n\n####YOUR ACCOUNT HAS BEEN SUCCESSFULLY DELETED. GOODBYE FRIEND.####\n\n");
                break;
            }
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
    printf("\n\tPhone Number: ");
    scanf("%s", phone_number);
    
    if(strcmp(phone_number, "q") == 0){return;}

    printf("\n\tPassword: ");
    scanf("%s", password);

    // this compares phone_number and password to existing account details
    char name[30];
    int account_balance;
    int result = read_user_from_file(phone_number, password, name, &account_balance);
    printf("\nResult of read_user_from_file: %d", result);
    if(result == 1){
        users_dashboard(name, phone_number, password, account_balance);
    }else{
        printf("\n\n####INVALID CREDENTIALS. PASSWORD AND PHONE NUMBER DO NOT MATCH ####\n\n");
        log_in();
    }
}

int read_user_from_file(char phone_number[12], char password[30], char *name, int *account_balance){

    FILE *file_ptr = fopen("./simba_users.db", "r");
    if(file_ptr == NULL){
        return 2; // this returns 2 if the file is not found
    }

    char user_data[256]; 
    char credential_holder[4][30];
    
    int state = 0;
    // printf("\n%s", fgets(user_data, sizeof(user_data), file_ptr));
    while(fgets(user_data, sizeof(user_data), file_ptr) != NULL){

        int i = 0;
        char *token = strtok(user_data, "|");
        while(token != NULL && i < 4){
            // this loop splits the user data into phone number, name, password and account balance
            // and stores them in the credential_holder array
            token[strcspn(token, "\n")] = '\0'; // remove newline character
            credential_holder[i][0] = '\0'; // clear the string before copying new data
            strncpy(credential_holder[i], token, sizeof(credential_holder[i]) - 1);
            i++;
            token = strtok(NULL, "|");
        }

        // printf("\nCurrent line phone number: %s, password: %s", credential_holder[0], credential_holder[2]);

        if(strcmp(credential_holder[0], phone_number) == 0 && strcmp(credential_holder[2], password) == 0){
            // this checks if the phone number and password match the current line in the file
            state = 1; // this means the credentials are correct
            strncpy(name, credential_holder[1], 30); // copy the name to the name pointer
            *account_balance = atoi(credential_holder[3]); // copy the account balance to the pointer
            break;
        }
    }

    fclose(file_ptr);
    return state;
}

void view_help_page(){
    FILE *file_ptr = fopen("./simba_help.db", "r");
    char line[256];
    while(fgets(line, sizeof(line), file_ptr) != NULL){
        printf("%s", line);
    }
    fclose(file_ptr);
}

int deposit(int amount, int t_token, char phone_number[12], char password[30]){
    // this function handles depositing of money to the users account
    // it takes in the amount to be deposited and the agents transaction token as parameters
    // it returns 1 if the deposit is successful and 0 if it fails

    // for testing purposes, we will use 123456
    if(t_token == 123456){

        FILE *file_ptr = fopen("./simba_users.db", "r");
        if(file_ptr == NULL){
            return 2; // this returns 2 if the file is not found
        }

        FILE *temp_file_ptr = fopen("./temp.db", "a");

        char user_data[256]; 
        char credential_holder[4][30];
        
        int state = 0;
        while(fgets(user_data, sizeof(user_data), file_ptr) != NULL){

            int i = 0;
            char *token = strtok(user_data, "|");
            while(token != NULL && i < 4){
                // this loop splits the user data into phone number, name, password and account balance
                // and stores them in the credential_holder array
                token[strcspn(token, "\n")] = '\0'; // remove newline character
                credential_holder[i][0] = '\0'; // clear the string before copying new data
                strncpy(credential_holder[i], token, sizeof(credential_holder[i]) - 1);
                i++;
                token = strtok(NULL, "|");
            }

            // printf("\nCurrent line phone number: %s, password: %s", credential_holder[0], credential_holder[2]);

            if(strcmp(credential_holder[0], phone_number) == 0 && strcmp(credential_holder[2], password) == 0){
                // this checks if the phone number and password match the current line in the file
                int current_balance = atoi(credential_holder[3]);
                int new_balance = current_balance + amount;
                snprintf(credential_holder[3], sizeof(credential_holder[3]), "%d", new_balance); // update the balance in the credential holder
            }
            fprintf(temp_file_ptr, "%s|%s|%s|%s\n", credential_holder[0], credential_holder[1], credential_holder[2], credential_holder[3]);
        }
        fclose(file_ptr);
        fclose(temp_file_ptr);
        remove("./simba_users.db"); // remove the old file
        rename("./temp.db", "./simba_users.db"); // rename the temp file to the old databse file name

        
    

        return 1;
    }else{
        return 0;  // unsuccesful
    }
}

int withdraw(int amount, int t_token, char phone_number[12], char password[30]){
    // this one is for withdrawing money from the users account. 

    // we shall still use  123456
    if(t_token == 123456){

        FILE *file_ptr = fopen("./simba_users.db", "r");
        if(file_ptr == NULL){
            return 2; // this returns 2 if the file is not found
        }

        FILE *temp_file_ptr = fopen("./temp.db", "a");

        char user_data[256]; 
        char credential_holder[4][30];
        
        int state = 0;
        while(fgets(user_data, sizeof(user_data), file_ptr) != NULL){

            int i = 0;
            char *token = strtok(user_data, "|");
            while(token != NULL && i < 4){
                // this loop splits the user data into phone number, name, password and account balance
                // and stores them in the credential_holder array
                token[strcspn(token, "\n")] = '\0'; // remove newline character
                credential_holder[i][0] = '\0'; // clear the string before copying new data
                strncpy(credential_holder[i], token, sizeof(credential_holder[i]) - 1);
                i++;
                token = strtok(NULL, "|");
            }

            // printf("\nCurrent line phone number: %s, password: %s", credential_holder[0], credential_holder[2]);

            if(strcmp(credential_holder[0], phone_number) == 0 && strcmp(credential_holder[2], password) == 0){
                // this checks if the phone number and password match the current line in the file
                int current_balance = atoi(credential_holder[3]);

                // check if the user has sufficient balance to withdraw
                if(current_balance >= amount){
                    int new_balance = current_balance - amount;
                    snprintf(credential_holder[3], sizeof(credential_holder[3]), "%d", new_balance); // update the balance in the credential holder
                }else{
                    // user does not have sufficient balance
                    return 0; // return 0 if the user has insufficient funds
                }
            }
            fprintf(temp_file_ptr, "%s|%s|%s|%s\n", credential_holder[0], credential_holder[1], credential_holder[2], credential_holder[3]);
        }
        fclose(file_ptr);
        fclose(temp_file_ptr);
        remove("./simba_users.db"); // remove the old file
        rename("./temp.db", "./simba_users.db"); // rename the temp file to the old databse file name

        
    

        return 1;
    }else{
        return 0;  // unsuccesful
    }

    return 0;
}

int delete_my_account(char phone_number[12], char password[30]){
    // this function deletes the users account from the database file
    FILE *file_ptr = fopen("./simba_users.db", "r");
        if(file_ptr == NULL){
            return 2; // this returns 2 if the file is not found
        }

        FILE *temp_file_ptr = fopen("./temp.db", "a");

        char user_data[256]; 
        char credential_holder[4][30];
        
        int state = 0;
        while(fgets(user_data, sizeof(user_data), file_ptr) != NULL){

            int i = 0;
            char *token = strtok(user_data, "|");
            while(token != NULL && i < 4){
                // this loop splits the user data into phone number, name, password and account balance
                // and stores them in the credential_holder array
                token[strcspn(token, "\n")] = '\0'; // remove newline character
                credential_holder[i][0] = '\0'; // clear the string before copying new data
                strncpy(credential_holder[i], token, sizeof(credential_holder[i]) - 1);
                i++;
                token = strtok(NULL, "|");
            }

            // printf("\nCurrent line phone number: %s, password: %s", credential_holder[0], credential_holder[2]);

            if(strcmp(credential_holder[0], phone_number) == 0 && strcmp(credential_holder[2], password) == 0){
                // this checks if the phone number and password match the current line in the file
                
                continue; // skip for that particular account being deleted
            }

            fprintf(temp_file_ptr, "%s|%s|%s|%s\n", credential_holder[0], credential_holder[1], credential_holder[2], credential_holder[3]);
            
        }
        fclose(file_ptr);
        fclose(temp_file_ptr);
        remove("./simba_users.db"); // remove the old file
        rename("./temp.db", "./simba_users.db"); // rename the temp file to the old databse file name

    return 1;

}

int update_account_details(char phone_number[12], char password[30], char new_name[30], char new_password[30]){
    // this function updates the users account details in the database file
    FILE *file_ptr = fopen("./simba_users.db", "r");
        if(file_ptr == NULL){
            return 2; // this returns 2 if the file is not found
        }

        FILE *temp_file_ptr = fopen("./temp.db", "a");

        char user_data[256]; 
        char credential_holder[4][30];
        
        int state = 0;
        while(fgets(user_data, sizeof(user_data), file_ptr) != NULL){

            int i = 0;
            char *token = strtok(user_data, "|");
            while(token != NULL && i < 4){
                // this loop splits the user data into phone number, name, password and account balance
                // and stores them in the credential_holder array
                token[strcspn(token, "\n")] = '\0'; // remove newline character
                credential_holder[i][0] = '\0'; // clear the string before copying new data
                strncpy(credential_holder[i], token, sizeof(credential_holder[i]) - 1);
                i++;
                token = strtok(NULL, "|");
            }

            // printf("\nCurrent line phone number: %s, password: %s", credential_holder[0], credential_holder[2]);

            if(strcmp(credential_holder[0], phone_number) == 0 && strcmp(credential_holder[2], password) == 0){
                // this checks if the phone number and password match the current line in the file
                
                strncpy(credential_holder[1], new_name, sizeof(credential_holder[1]) - 1); // update name
                strncpy(credential_holder[2], new_password, sizeof(credential_holder[2]) - 1); // update password
            }

            fprintf(temp_file_ptr, "%s|%s|%s|%s\n", credential_holder[0], credential_holder[1], credential_holder[2], credential_holder[3]);
            
        }
        fclose(file_ptr);
        fclose(temp_file_ptr);
        remove("./simba_users.db"); // remove the old file
        rename("./temp.db", "./simba_users.db"); // rename the temp file to the old databse file name

    return 1;
}