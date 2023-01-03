#include <iostream>
#include <algorithm>
using namespace std;

struct Book {
  int id, quantity;
  string name;
};

struct User {
  int id, name;
};

bool startsWith(string name, string prefix) {
  for (int i = 0; i < prefix.size(); i++) {
    if (prefix[i] != name[i]) {
      return false;
    }
  }
  return true;
}

struct LibrarySystem {
  Book book[100];
  User user[100];
  int length;

  LibrarySystem() {
    length = 0;
  }

  void addBook() {
    cout << "Enter id, book name and quantity of the book\n";
    
    int _id, _quantity;
    string _bookName;
    cin >> _id >> _bookName >> _quantity;

    book[length].id = _id;
    book[length].name = _bookName;
    book[length].quantity = _quantity;
    length++;
  }

  void searchBookByPrefix() {
    string prefix;
    cout << "Enter book name\n";
    cin >> prefix;
    for (int i = 0; i < length; i++) {
      if (startsWith(book[i].name, prefix)) {
        cout << book[i].name << endl;
      } else {
        cout << "No book found match this name\n";
      }
    }
  }

  void printById() {
    int ids[100];
    for (int i = 0; i < length; i++) {
      ids[i] = book[i].id;
    }

    sort(ids, ids + length);

    for (int i = 0; i < length; i++) {
      cout << ids[i];
    }
  }

  void print() {
    for (int i = 0; i < length; i++) {
      cout << "***********************************\n";
      cout << book[i].name << " " << book[i].id << " " << book[i].quantity << endl;
    }
  }
  
  int menu() {
    int choice = -1;
    while (choice == -1) {
      cout << "\n\nEnter your choice\n";
      cout << "1) Add Book\n";
      cout << "2) Search Book By Prefix\n";

      cin >> choice;
      if (!(choice >= 1 && choice <= 4)) {
        cout << "Invalid choice. Try again\n";
        choice = -1;
      }
    }
    return choice;
  }

  void run() {
    while (true) {
      int choice = menu();
      if (choice == 1) {
        addBook();
      } else if (choice == 2) {
        searchBookByPrefix();
      } else {
        return;
      }
    }
  }
};

int main() {
  // LibrarySystem lb;
  // lb.run();
  
  return 0;
}