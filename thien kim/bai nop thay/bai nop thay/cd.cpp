#include "Khaibao.h"

//==================== GLOBAL ====================

Seat cinema[ROW][COL];
Node* root = NULL;
int revenue = 0;

priority_queue<Customer, vector<Customer>, Compare> waiting;
stack<Customer> history;

//==================== BST ====================

Node* createNode(Customer x)
{
    Node* p = new Node;

    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

Node* insert(Node* root, Customer x)
{
    if (root == NULL)
        return createNode(x);

    if (x.id < root->data.id)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

Node* search(Node* root, string id)
{
    if (root == NULL || root->data.id == id)
        return root;

    if (id < root->data.id)
        return search(root->left, id);

    return search(root->right, id);
}

void inorder(Node* root)
{
    if (root == NULL) return;

    inorder(root->left);

    cout << root->data.id << " | "
        << root->data.name
        << " | (" << root->data.row
        << "," << root->data.col << ")" << endl;

    inorder(root->right);
}

//==================== PRIORITY ====================

bool Compare::operator()(Customer a, Customer b)
{
    return a.vip < b.vip;
}

//==================== FUNCTION ====================

void initSeat()
{
    for (int i = 0;i < ROW;i++)
        for (int j = 0;j < COL;j++)
        {
            cinema[i][j].booked = false;
            cinema[i][j].customerID = "";
        }
}

void displaySeat()
{
    cout << "\n===== SO DO GHE =====\n";

    for (int i = 0;i < ROW;i++)
    {
        for (int j = 0;j < COL;j++)
        {
            if (cinema[i][j].booked)
                cout << "[X]";
            else
                cout << "[ ]";
        }

        cout << endl;
    }
}

bool fullSeat()
{
    for (int i = 0;i < ROW;i++)
        for (int j = 0;j < COL;j++)
            if (!cinema[i][j].booked)
                return false;

    return true;
}

void bookTicket()
{
    Customer c;

    cout << "Ma KH: ";
    cin >> c.id;

    cin.ignore();

    cout << "Ten: ";
    getline(cin, c.name);

    cout << "VIP (1/0): ";
    cin >> c.vip;

    if (fullSeat())
    {
        waiting.push(c);

        cout << "Rap da het ghe.\n";

        return;
    }

    cout << "Dong: ";
    cin >> c.row;

    cout << "Cot: ";
    cin >> c.col;

    if (cinema[c.row][c.col].booked)
    {
        cout << "Ghe da duoc dat.\n";
        return;
    }

    cinema[c.row][c.col].booked = true;
    cinema[c.row][c.col].customerID = c.id;

    root = insert(root, c);

    history.push(c);

    revenue += PRICE;

    cout << "Dat ve thanh cong.\n";
}

void cancelTicket()
{
    string id;

    cout << "Nhap ma KH: ";
    cin >> id;

    Node* p = search(root, id);

    if (p == NULL)
    {
        cout << "Khong tim thay.\n";
        return;
    }

    cinema[p->data.row][p->data.col].booked = false;

    revenue -= PRICE;

    cout << "Da huy ve.\n";

    if (!waiting.empty())
    {
        Customer next = waiting.top();
        waiting.pop();

        next.row = p->data.row;
        next.col = p->data.col;

        cinema[next.row][next.col].booked = true;
        cinema[next.row][next.col].customerID = next.id;

        root = insert(root, next);

        revenue += PRICE;

        cout << "Da cap ghe cho " << next.name << endl;
    }
}

void searchCustomer()
{
    string id;

    cout << "Nhap ma KH: ";
    cin >> id;

    Node* p = search(root, id);

    if (p == NULL)
    {
        cout << "Khong tim thay.\n";
        return;
    }

    cout << "\nTen: " << p->data.name << endl;
    cout << "Ghe: " << p->data.row << " " << p->data.col << endl;
}

void statistic()
{
    int empty = 0;

    for (int i = 0;i < ROW;i++)
        for (int j = 0;j < COL;j++)
            if (!cinema[i][j].booked)
                empty++;

    cout << "\nSo ghe trong: " << empty << endl;
    cout << "Doanh thu: " << revenue << " VND" << endl;
}