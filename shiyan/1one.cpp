#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

struct Book {
    string ID;
    string name;
    float price;
};

void removeDuplicates(vector<Book>& books) {
    set<string> uniqueIDs;
    vector<Book> uniqueBooks;

    for (const auto& book : books) {
        if (uniqueIDs.find(book.ID) == uniqueIDs.end()) {
            uniqueIDs.insert(book.ID);
            uniqueBooks.push_back(book);
        }
    }

    books = uniqueBooks;
}

int main() {
    vector<Book> books;

    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream iss(inputLine);
        string ID, name;
        float price;

        iss >> ID >> name >> price;

        if (ID == "0" && name == "0" && price == 0)
            break;

        Book book = {ID, name, price};
        books.push_back(book);
    }

    removeDuplicates(books);

    cout << books.size() << endl;
    for (const auto& book : books) {
        cout << book.ID << " " << book.name << " " << fixed << setprecision(2) << book.price << endl;
    }

    return 0;
}
