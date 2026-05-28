# MiniBankingSystem
This is a mini banking system written in C. Developed by group 2 day. 
These are the members of group two:
1. Mandre Derrick Ajax
2. Mungufeni Gilbert 
3. Ejiet Haggai
4. Alinda Atunga Alpha
5. Kansiime Marina
6. Okiria Jorem

# A brief Documentation about the Minibanking System
We have decided to call this Mini banking platform as SIMBA for better reference. The mini banking system gives you a menu when you run it. 
1. Create a Simba account
2. Log in to my Simba account
3. View Help Page
4. Quit
   
# Creating a new account
When you select option you, you are promoted to create a new accout. The program asks you for your name, phone number and password. 
The name cannot be an empty string. Your phone number must be 10 characters long and should start with 0 not the country code.
Your password can be any character of your choice but must be between 6 to 30 characters.
Once you have entered your credentials, the program asks you for an initial deposit, this initial deposit must be above 10 thousand Ugandan shillings. Account creation cannot continue if you dont provide this.
Once account creation is done, you are logged in automatically and shown a dashboard.

# Log in
If you select option 2, the program prompts you for your phone number and password. You use your phone number and password for logging in, nit your password. Once logged in, you see the same dashboard you see after creating an account.

# The dashboard
After logging in the dashboard displays various options
1. Deposit Money
2. Update Account Details (You can only change name and password)
3. Withdraw Money
4. View Transaction History
5. Log out
6. Delete my account
7. See Full Account Information

# Important Note 
For some transactions, the program asks you for the agent's transaction token, we have used 123456 by default. This is for Deposit and withdrawals. Thus ensures you cannot just deposit to your account without an agent

# Let's look at the code bit of SIMBA Mini Bank
These are the major functions that have been used here.
1. sign_up() function
   This function runs when the user selects sign up(option 1) from the first menu that appears.
2. validate_sign_up_details()
   This one is called to check if the phone number and password entered by the user to see if the credentials entered are valid before being writeen to simba_users.db
3. write_user_to_file()
   This function runs as the users account is being registered. It is called by the sign up function.
4. log_in()
   The log_in() function runs when the user selects the log in option (option2) fron the menu. 
5. read_user_from_file()
   This function is called by the log_in() function to read and compare if the phone number and password entered match that in the database.
6. update_account_details()
   The update_account_details() function is used to change the name and password of the user. Note though that the phone number cannot be changed.
7. view_help_page()
   This shows the user the help page if he/she is tsuck in the menu and is not quite sure how SIMBA operates.
8. users_dashboard()
   This function is called after sign up or after log in. It displays to the user account management options like deposit, withdraw and so forth.
9. deposit()
    The deposit function credits the users account with the stated sum of money. The user however has to provide an agent's transaction number. This is used to debit the SIMBA agents account and credit the users account. agents trasaction number is 123456
10. withdraw()
    Withdraw works very similar like deposit, just that money is taken in this case.  For dmostration purposes, we shall use 123456 as the default agent transaction number.
11. delete_my_account()
    This removes the users account. With the money.
