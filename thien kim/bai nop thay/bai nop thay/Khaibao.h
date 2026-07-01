#ifndef TICKETSYSTEM_H
#define TICKETSYSTEM_H

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int ROW = 5;
const int COL = 5;
const int PRICE = 100000;

//==================== STRUCT ====================

struct Seat
{
    bool booked;
    string customerID;
};

struct Customer
{
    string id;
    string name;
    bool vip;
    int row, col;
};

//==================== BST ====================

struct Node
{
    Customer data;
    Node* left;
    Node* right;
};

Node* createNode(Customer);
Node* insert(Node*, Customer);
Node* search(Node*, string);
void inorder(Node*);

//==================== PRIORITY QUEUE ====================

struct Compare
{
    bool operator()(Customer a, Customer b);
};

extern priority_queue<Customer, vector<Customer>, Compare> waiting;

//==================== STACK ====================

extern stack<Customer> history;

//==================== GLOBAL ====================

extern Seat cinema[ROW][COL];
extern Node* root;
extern int revenue;

//==================== FUNCTION ====================

void initSeat();

void displaySeat();

bool fullSeat();

void bookTicket();

void cancelTicket();

void searchCustomer();

void statistic();

#endif
