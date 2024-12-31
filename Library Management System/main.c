#include "library.h"
int main(){
    Book* books = NULL;
    User* users = NULL;
    Transaction* transactions = NULL;
    int choice, id;
    char title[100], author[100], name[100], email[100];
    while (1)
    {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Add User\n");
        printf("4. Display Users\n");
        printf("5. Borrow Book\n");
        printf("6. Display Transactions\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &id);
            printf("Enter Book TItle: ");
            scanf(" %[^\n]", title);
            printf("Enter Book Author");
            scanf(" %[^\n]", author);
            addBook(&books, id, title, author);
            break;
        case2:
            displayBooks(books);
            break;
        case 3:
            printf("Enter User ID: ");
            scanf("%d", &id);
            printf("Enter User Name: ");
            scanf(" %[^\n]", name);
            printf("Enter User Email: ");
            scanf(" %[^\n]", email);
            addUser(&users, id, name, email);
            break;
        case 4:
            displayUsers(users);
            break;
        case 5:
            printf("Enter User ID: ");
            scanf("%d", &id);
            int bookId;
            printf("Enter Book ID to Borrow: ");
            scanf("%d", &bookId);
            borrowBook(books, &transactions, id, bookId);
            break;
        case 6:
            displayTransactions(transactions);
            break;
        case 0:
            printf("Existing...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}