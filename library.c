#include "library.h"
#include<stdio.h>
#include<stdlib.h>
void addBook(Book** head, int id, char* title, char* author){
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->available = 1;
    newBook->next = *head;
    *head = newBook;
    printf("Book added successfully!\n");   
}
void displayBooks(Book* head){
    if(!head){
        printf("No Books available.\n");
        return;
    }
    printf("ID\tTitle\tAuthor\t\tAvailable\n");
    while (head)
    {
        printf("%d\t%s\t\t%s\t\t%s\n", head->id, head->title, head->author, head->available ? "Yes" : "No");
        head = head->next;
    }
}
Book* searchBook(Book* head, int id){
    while (head)
    {
        if(head->id == id){
            return head;
        }
        head = head->next;
    }
    return NULL;
}
void addUser(User** head, int id, char* name, char* email){
    User* newUser = (User*)malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    strcpy(newUser->email, email);
    newUser->next = *head;
    *head = newUser;
    printf("User added successfully!\n");
}
void displayUsers(User* head){
    if(!head){
        printf("No users available.\n");
        return;
    }
    printf("Id\tName\t\tEmail\n");
    while(head){
        printf("%d\t%s\t\t%s\n", head->id, head->name, head->email);
        head = head->next;
    }
}
void borrowBook(Book* books, Transaction** transactions, int userId, int bookId){
    Book* book = searchBook(books, bookId);
    if(book && book->available){
        book->available = 0;
        Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
        newTransaction->userId = userId;
        newTransaction->bookId = bookId;
        strcpy(newTransaction->borrowDate, "2024-12-30");
        strcpy(newTransaction->returnDate, "");
        newTransaction->next = *transactions;
        *transactions = newTransaction;
        printf("Book borrowed successfully!\n");
    }else{
        printf("Book not available or not found.\n");
    }
}
void displayTransactions(Transaction* head){
    if(!head){
        printf("No transactions available.\n");
        return;
    }
    printf("UserID\tBookID\tBorrow Date\tReturn Date\n");
    while (head)
    {
        printf("%d\t%d\t%s\t%s\n", head->userId, head->bookId, head->borrowDate, head->returnDate[0] ? head->returnDate : "Not Returned");
        head = head->next;
    }
}