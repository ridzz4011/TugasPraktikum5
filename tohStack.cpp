#include <iostream>
#include <iomanip>

using namespace std;

int maks = 3;
int topA = 0, topB = 0, topC = 0;

int rodA[3], rodB[3], rodC[3];

void push(char rod, int n) {
    switch(rod) {
        case 'a':
            rodA[topA] = n;
            topA++;
            break;
        case 'b':
            rodB[topB] = n;
            topB++;
            break;
        case 'c':
            rodC[topC] = n;
            topC++;
            break;
        default:
            cout << "ERROR" << endl;
            break;
    }
}

void pop(char rod) {
    switch(rod) {
        case 'a':
            if((rodA[topA - 1]) == 0) {
                cout << "Data tidak ada...\n";
            } else {
                rodA[topA - 1] = 0;
            }
            break;
        case 'b':
            if((rodB[topB - 1]) == 0) {
                cout << "Data tidak ada...\n";
            } else {
                rodB[topB - 1] = 0;
            }
            break;
        case 'c':
            if((rodC[topC - 1]) == 0) {
                cout << "Data tidak ada...\n";
            } else {
                rodC[topC - 1] = 0;
            }
            break;
        default:
            cout << "ERROR\n";
            break;
    }
}

void display() {
    cout << "Tower of Hanoi\n";
    cout << "=====================\n";

    cout << setw(2) << "Tower A | ";
    for(int i = topA; i>=0; i--) {
        if(rodA[i] != 0) {
            cout << rodA[i] << " ";
        }
    }
    cout << "\n";

    cout << setw(2) << "Tower B | ";
    for(int i = topB; i>=0; i--) {
        if(rodB[i] != 0) {
            cout << rodB[i] << " ";
        }
    }
    cout << "\n";

    cout << setw(2) << "Tower C | ";
    for(int i = topC; i>=0; i--) {
        if(rodC[i] != 0) {
            cout << rodC[i] << " ";
        }
    }
    cout << "\n";
}

void move(char from, int n, char to) {
    push(to, n);
    pop(from);
    cout << "Memindahkan nilai " << n << " dari " << from << " ke " << to << "\n";

    switch(from) {
        case 'a':
            topA--;
            break;
        case 'b':
            topB--;
            break;
        case 'c':
            topC--;
            break;
        default:
            cout << "Data Kosong...\n";
            break;
    }
}

int main() {
    char xA = 'a', xB = 'b', xC = 'c';

    push('b', 20);
    push('c', 40);
    push('c', 60);

    cout << "Inisialisasi Tower Awal\n\n";
    display();

    cout << "\nVisualisasikan proses pemindahan data? (Y/N): ";
    char y;
    cin >> y;
    bool graphic = (y == 'Y' || y == 'y');

    cout << "\nPROSES PEMINDAHAN DATA KE TOWER LAIN\n\n";
    // move(towerAsal, nilai, towerTujuan)
    move(xB, rodB[topB - 1], xA);
    if(graphic) {
        cout << "\n";
        display();
        cout << "\n";
    }

    move(xC, rodC[topC - 1], xB);
    if(graphic) {
        cout << "\n";
        display();
        cout << "\n";
    }

    move(xC, rodC[topC - 1], xB);
    if(graphic) {
        cout << "\n";
        display();
        cout << "\n";
    }

    move(xA, rodA[topA - 1], xC);
    if(graphic) {
        cout << "\n";
        display();
        cout << "\n";
    }

    move(xB, rodB[topB - 1], xA);
    if(graphic) {
        cout << "\n";
        display();
    }
    
    cout << "\nHASIL SETELAH PEMINDAHAN DATA\n\n";
    display();
    cout << endl;

    cout << "Program ini dibuat oleh:\n";
    cout << "Nama: Farid Noer Hakim\n";
    cout << "NPM: 2310631170081\n";
    cout << "Kelas: 2C Informatika\n" << endl;

    system("PAUSE");
    return 0;
}