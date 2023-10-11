#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;

    printf("Enter username (up to %d characters): ", MAX_USERNAME_LENGTH - 1);
    scanf("%s", newUser.username);

    printf("Enter password (up to %d characters): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%s", newUser.password);

    users[numUsers++] = newUser;

    printf("Registration successful!\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}