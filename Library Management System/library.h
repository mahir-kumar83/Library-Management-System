#ifndef LIBRARY_H
#define LIBRARY_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book{
    int id;
    char title[100];
    char author[100];
    int available;
    struct Book* next;
}Book;
typedef struct User{
    int id;
    char name[100];
    char email[100];
    struct User* next;
}User;
typedef struct Transaction{
    int userId;
    int bookId;
    char borrowDate[20];
    char returnDate[20];
    struct Transaction* next;
}Transaction;
void addBook(Book** head, int id, char* title, char* author);
void displayBooks(Book* head);
Book* searchBook(Book* head, int id);
void addUser(User** head, int id, char* name, char* email);
void displayUsers(User* head);
void borrowBook(Book* books, Transaction** transactions, int userId, int bookId);
void displayTransactions(Transaction* head);
#endif