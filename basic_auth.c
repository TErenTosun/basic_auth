#include "basic_auth.h"

enum error_codes {
    SUCCESS = 0,
    FAILURE = 1,
    USERNAME_EXISTS = -1,
    DATABASE_DOESNT_EXIST = -2
};

const char* db_name = "db.dat";

int check_db() {
    int check = access(db_name, F_OK);
    return check; 
}

void create_db() {
    int check = check_db();
    if (check == 0) {
        printf("INFO: Database exists\n");
        return;
    }
    else if (check == -1) {
        printf("INFO: Database doesn't exist, creating a new one\n");
        FILE* db;
        fopen(db_name, "w");
        fclose(db);
    }
}

int register_user(char* username, char* password) {
    if (check_db() == 0) {
        FILE* db;
        db = fopen(db_name, "r");
        int username_exists = 0;
        //Check for username;
        char line[100];
        while(fgets(line, sizeof(line), db) != NULL) {
            strtok(line, "\n");
            if (strcmp(username, line) == 0) {
                printf("ERROR: Username %s already exists\n", username);
                username_exists = 1;
                break;
            }
        }
        fclose(db);

        if (username_exists) {
            return USERNAME_EXISTS;
        }
        else {
            db = fopen(db_name, "a");
            printf("INFO: Adding user: %s and password: %s to database\n", username, password);
            fprintf(db, "START\n%s\n%s\nEND\n", username, password);
            fclose(db);
            return SUCCESS;
        }
    }
    else {
        printf("ERROR: Database doesn't exist. Create a new database or check the db_name variable\n");
        return DATABASE_DOESNT_EXIST;
    }
}

int login(char* username, char* password) {
    if (check_db() == 0) {
        FILE* db;
        db = fopen(db_name, "r");
        //Check for username;
        char line[100];
        while(fgets(line, sizeof(line), db) != NULL) {
            strtok(line, "\n");
            if (strcmp(username, line) == 0) {
                fgets(line, sizeof(line), db);
                strtok(line, "\n");
                if (strcmp(password, line) == 0) {
                    printf("INFO: User %s has logged in successfully\n", username, password);
                    return SUCCESS;
                }
            }
        }
        printf("ERROR: Username or password invalid\n");
        return FAILURE;
    }
    else {
        printf("ERROR: Database doesn't exist. Create a new database or check the db_name variable\n");
        return DATABASE_DOESNT_EXIST;
    }
}
