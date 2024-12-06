#include <iostream>
#include <random>
#include <windows.h>
using namespace std;
 void TextColor(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
 void printDice(int num1, int num2, int num3) {
    string dice[6][5] = {
        {"-----", "|   |", "| o |", "|   |", "-----"},
        {"-----", "|o  |", "|   |", "|  o|", "-----"},
        {"-----", "|o  |", "| o |", "|  o|", "-----"},
        {"-----", "|o o|", "|   |", "|o o|", "-----"},
        {"-----", "|o o|", "| o |", "|o o|", "-----"},
        {"-----", "|o o|", "|o o|", "|o o|", "-----"}
    };
    for (int i = 0; i < 5; i++) {
        TextColor(9);
        cout << dice[num1 - 1][i] << " " << dice[num2 - 1][i] << " " << dice[num3 - 1][i] << endl;
    }
}
 int callCount = 0;
 int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}
 void displayMenu() {
    TextColor(12);
    cout << "************ MENU ************" << endl;
    cout << "1. XIN MOI BAN DAT (XIU)" << endl;
    cout << "2. XIN MOI BAN DAT (TAI)" << endl;
    cout << "3. All In" << endl;
    cout << "4. Quit" << endl;
    cout << "*******************************" << endl;
}
 int main() {
    int choice;
    long long money = 100000;
    long long bet;
     do {

        displayMenu();
        TextColor(14);
        cout << "SO TIEN HIEN CO: " << money << "k" << endl;
        cout << "XIN NHAP SO TIEN MUON CA CUOC: ";
        cin >> bet;
         if (bet > money) {
            cout << "SO TIEN CUOC KHONG DU. XIN MOI NHAP LAI." << endl;
            continue;
        }
         cout << "XIN MOI CHON: ";
        cin >> choice;
        int prediction;
         switch (choice) {
            case 1:
                prediction = 10;
                break;
            case 2:
                prediction = 11;
                break;
            case 3:
                if (money == 0) {
                    cout << "BAN DA HET TIEN! GAME OVER." << endl;
                    continue;
                }
                bet = money;
                cout << "XIN MOI CHON: ";
                cin >> prediction;
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }
         int randomNum1 = getRandomNumber(1, 6);
        int randomNum2 = getRandomNumber(1, 6);
        int randomNum3 = getRandomNumber(1, 6);
        printDice(randomNum1, randomNum2, randomNum3);
        cout << endl;
        int sum = randomNum1 + randomNum2 + randomNum3;
         if (sum <= 10) {
            TextColor(5);
            cout << "KET QUA CUA VAN CUOC LA XIU " << sum;
        } else {
            TextColor(5);
            cout << "KET QUA CUA VAN CUOC LA TAI " << sum;
        }
         cout << endl;
         if ((sum <= 10 && prediction == 10) || (sum > 10 && prediction == 11)) {
            TextColor(5);
            cout << "You win!" << endl;
            money += bet;
        } else {
            TextColor(5);
            cout << "You lose!" << endl;
            money -= bet;
        }
         cout << endl;
     } while (choice != 4 && money > 0);
     if (money <= 0) {
        cout << "BAN DA HET TIEN! GAME OVER." << endl;
    }
     return 0;

}
