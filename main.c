/*
    TODO: Change the way the credentials are stored in the .dat file so that the admin can 
        view all the credentials with a simple command.
    
    This program is not suited for real world usage due to the shoddy database being vulnerable.
    No need to improve upon the security of the "database" because it's simply a practice project.
*/

#include "basic_auth.h"

int main(void) { 
    int user_prompt;
    char username[100];
    char password[100];
    printf("1)Login\n2)Register\n> ");
    scanf("%d", &user_prompt);
    printf("Enter Username: ");
    scanf("%s", &username);
    printf("Enter Password: ");
    scanf("%s", &password);
    if (user_prompt == 1) {
        login(username, password);
    }
    else if (user_prompt == 2) {
        register_user(username, password);
    }
    else {
        printf("ERROR: Invalid input\n");
    }
    return 0;
}