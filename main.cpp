#include <algorithm>
#include <iostream>
using namespace std;
bool isarrayidentical(int idArray[], int backupIDS[], int arrayCount, int backupCount);

void DeleteID(int idArray[], int arrayCount);

int insertid(int array[], int &count, int size);

void printids(int idArray[], int arrayCount);

void searchID(int idArray[], int arrayCount);

void replaceID(int idarray[], int arrayCount);

int BackupID(int idArray[], int backupIDS[], int arrayCount);



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
    int backupIds[20];

    int arrayCount = 0;
    int backupCount = 0;

    int id;
    int selection;

    printMenu();
    cout << " What would like to do with the ID?: " << endl;
    cin >> selection;

    while (selection != -1) {
        switch (selection) {
            case 1: {
                insertid(idArray, arrayCount, 20);
            }
            break;
            case 2:
                searchID(idArray, arrayCount);

                break;
            case 3:
                replaceID(idArray, arrayCount);
                break;
            case 4:
                DeleteID(idArray, arrayCount);
                break;
            case 5:
                printids(idArray, arrayCount);
                cout << "Backup IDs" << endl;
                printids(backupIds, backupCount);
                break;
            case 6:
                backupCount = BackupID(idArray, backupIds, arrayCount);

                break;
            case 7:
                isarrayidentical(idArray, backupIds, arrayCount, backupCount);
                break;
            case 8:
                exit(0);
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


int linearSearch(int idArray[], int arrayCount, int id) {
    for (int i = 0; i < arrayCount; i++) {
        if (idArray[i] == id) {
            return i;
        }
    }
    return -1;
}

void searchID(int idArray[], int arrayCount) {
    int index;
    int id;
    cout << "Enter ID: ";
    cin >> id;
    index = linearSearch(idArray, arrayCount, id);
    if (index == -1 || arrayCount == 0) {
        cout << "Invalid ID" << endl;
        return;
    }
    cout << "The following ID was found: " << id << endl;
}

void printids(int idArray[], int arrayCount) {
    cout << "Student IDs" << endl;
    cout << "-----------" << endl;

    if (arrayCount == 0) {
        cout << "Array is empty" << endl << endl;
    }

    for (int i = 0; i < arrayCount; i++) {
        cout << idArray[i] << endl << endl;
    }
}

void replaceID(int idArray[], int arrayCount) {
    int index;
    int id;
    int newid;
    cout << "Enter ID to replace: ";
    cin >> id;
    index = linearSearch(idArray, arrayCount, id);

    // this checks if id exist
    if (index == -1 || arrayCount == 0) {
        cout << "Invalid ID" << endl;
        return;
    }

    // id exits, so replace with new
    cout << "The ID was found: " << id << endl;
    cout << "Enter new ID: ";
    cin >> newid;

    idArray[index] = newid;
}

void DeleteID(int idArray[], int arrayCount) {
    int index;
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    index = linearSearch(idArray, arrayCount, id);
    if (index == -1 || arrayCount == 0) {
        cout << "Invalid ID" << endl;
        return;
    }

    for (int i = index; i < arrayCount - 1; i++) {
        idArray[i] = idArray[i + 1];
    }
}


int BackupID(int idArray[], int backupIDS[], int arrayCount) {
    for (int i = 0; i < arrayCount; i++) {
        backupIDS[i] = idArray[i];
    }

    return arrayCount;
}



bool isarrayidentical(int idArray[], int backupIDS[], int arrayCount, int backupCount) {
    if (arrayCount != backupCount) {
        cout<<"the backups are different"<<endl;
        return false;

    }

    for (int i = 0; i < backupCount; i++) {
        if (idArray[i] != backupIDS[i]) {
            cout<<"the backups are different"<<endl;
            return false;
        }
    }

    cout<<"the backups are identical"<<endl;
    return true;
}
//done