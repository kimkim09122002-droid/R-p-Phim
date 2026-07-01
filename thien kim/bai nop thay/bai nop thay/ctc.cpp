#include "Khaibao.h"

int main()
{
    initSeat();

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";

        cout << "1. Hien thi so do ghe\n";
        cout << "2. Dat ve\n";
        cout << "3. Huy ve\n";
        cout << "4. Tim khach hang\n";
        cout << "5. Danh sach da dat\n";
        cout << "6. Thong ke\n";
        cout << "0. Thoat\n";

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displaySeat();
            break;

        case 2:
            bookTicket();
            break;

        case 3:
            cancelTicket();
            break;

        case 4:
            searchCustomer();
            break;

        case 5:
            inorder(root);
            break;

        case 6:
            statistic();
            break;
        }

    } while (choice != 0);

    return 0;
}