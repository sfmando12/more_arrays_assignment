#include <iostream>
using namespace std;

int insertid(int array[], int &count, int size);

void printMenu() {
    cout << "Student ID Manager Menu" << endl;
    cout << "1. Insert ID" << endl;
    cout << "2. Search ID" << endl;
    cout << "3. Replace ID" << endl;
    cout << "4. Delete ID" << endl;
    cout << "5. Display ID" << endl;
    cout << "6. Copy to Backup" << endl;
    cout << "7. compare to backup" << endl;
    cout << "8. Exit" << endl;
}

int main() {

    int idArray[20];
    int arrayCount = 0;
    int id;
    int selection;
    int backupIds[20];
    printMenu();
    cout << " What would like to do with the ID?: " << endl;
    cin >> selection;

    while (selection != -1) {
        switch (selection) {
            case 1: {
                insertid(idArray, arrayCount, 20);
            }
            break;
            case 2: {
            }
            break;
            case 3: {
            }
            break;
            case 4: {
            }
            break;
            case 5: {

            }
            break;
            default:
                cout << "Invalid choice" << endl;
        }
        printMenu();
        cout << " What would like to do with the ID?: " << endl;
        cin >> selection;
    }
}

// ------------------------------------------------------------------ //

//
//
// return: -1 not enough space
//         0 was success
int insertid(int array[], int &count, int size) {
    if (count == size) {
        cout << "Array is full" << endl;
        return -1;
    }

    cout << "Enter ID: ";
    int id;
    cin >> id;

    array[count] = id;
    count++;
    return 0;
}
