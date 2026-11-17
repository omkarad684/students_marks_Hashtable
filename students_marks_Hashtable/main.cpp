/*
Project: Student Marks Hash Table
PRN: 202501100161
Seed Value: 161
Scenario: Student Marks
Hashing Method: Mid-Square Method
Collision Handling: Separate Chaining
Hash Table Size Used for Testing: 11
Dataset Size: 20
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int midSquareHash(int key, int m) {
    long long square = 1LL * key * key;

    int digits = 1;
    int temp = m - 1;

    while (temp >= 10) {
        digits++;
        temp /= 10;
    }

    string s = to_string(square);

    // Pad if the square has fewer digits
    while ((int)s.length() < digits) {
        s = "0" + s;
    }

    int start = ((int)s.length() - digits) / 2;

    int middle = stoi(s.substr(start, digits));

    return middle % m;
}

void insert(vector<list<int>>& table, int key, int m) {
    int index = midSquareHash(key, m);

    if (!table[index].empty()) {
        cout << "Collision at index " << index << endl;
    }

    table[index].push_back(key);
    cout << "Inserted " << key << " at index " << index << endl;
}

void display(vector<list<int>>& table) {
    cout << "\nFinal Hash Table\n";

    for (int i = 0; i < (int)table.size(); i++) {
        cout << i << " -> ";

        for (int key : table[i]) {
            cout << key << " -> ";
        }

        cout << "NULL" << endl;
    }
}
void searchKey(vector<list<int>>& table, int key, int m) {
    int index = midSquareHash(key, m);

    for (int value : table[index]) {
        if (value == key) {
            cout << "Key " << key
                 << " found at index " << index << endl;
            return;
        }
    }

    cout << "Key " << key << " not found" << endl;
}

int main() {

    int m;

    cout << "STUDENT MARKS HASH TABLE\n";
    cout << "Enter hash table size: ";
    if (!(cin >> m) || m <= 0) {
    cout << "Invalid table size";
    return 1;
}

    int values[20] = {
        61, 74, 87, 0, 13,
        26, 39, 52, 65, 78,
        91, 4, 17, 30, 43,
        56, 69, 82, 95, 8
    };

    vector<list<int>> table(m);

    cout << "\nInsertion Process:\n";

    for (int i = 0; i < 20; i++) {
    insert(table, values[i], m);
}

// Duplicate value testing
cout << "\nDuplicate Value Testing:\n";
insert(table, 61, m);

display(table);

// Search functionality
int searchValue;

cout << "\nEnter mark to search: ";

if (!(cin >> searchValue)) {
    cout << "Invalid search input" << endl;
    return 1;
}

searchKey(table, searchValue, m);

return 0;
}
