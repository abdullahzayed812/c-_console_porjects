// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

struct Queue {
    int array[100];
    int length;
    
    Queue() {
        length = 0;
    }
    
    void addEnd(int value) {
        array[length++] = value;
    }
    
    void addFront(int value) {
        for (int i = length - 1; i >= 0; i--) {
            array[i + 1] = array[i];
        }
        array[0] = value;
        length++;
    }
    
    int removeFront() {
        int returnedValue = array[0];
        for (int i = 1; i < length; i++) {
            array[i - 1] = array[i];
        }
        length--;
        return returnedValue;
    }
    
    void print() {
        for (int i = 0; i < length; i++) {
            cout << array[i] << " ";
        }
    }
};

struct HospitalQueue {
    string names[MAX_QUEUE];
    int status[MAX_QUEUE];
    int length;
    int spec;
    HospitalQueue() {
        length = 0;
        spec = -1;
    }
    HospitalQueue(int _spec) {
        length = 0;
        spec = _spec;
    }
    bool addEnd(string name, int st) {
        if (length == MAX_QUEUE) {
            return false;
        }
        names[length] = name;
        status[length] = st;
        length++;
        return true;
    }
    bool addFront(string name, int st) {
        if (length == MAX_QUEUE) {
          return false;
        }
        for (int i = length - 1; i >= 0; i--) {
          names[i + 1] = names[i];
          status[i + 1] = status[i];
        }
        names[0] = name;
        status[0] = st;
        length++;
        return true;
    }
    void removeFront() {
        if (length == 0) {
            cout << "The specialization of " << spec << " is empty. have reset dr\n";
            return;
        }
        cout << names[0] << " go with doctor \n";
        for (int i = 1; i < length; i++) {
            names[i - 1] = names[i];
            status[i - 1] = status[i];
        }
        length--;
    }
    void print() {
        if (length == 0) return;
        // cout << "There are " << length << " patient in " << spec << end;
        for (int i = 0; i < length; i++) {
          cout << "\n*************************************\n";
            cout << names[i] << " ";
            if (status[i] == 0) {
                cout << "regular";
            } else {
                cout << "urgent\n";
            }
        }
    }
};

struct HospitalSystem {
  HospitalQueue queues[MAX_SPECIALIZATION];
  HospitalSystem() {
    for (int i = 0; i < MAX_SPECIALIZATION; i++) {
        queues[i] = HospitalQueue(i);
    }
  }
  int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\n\nEnter your choice\n";
        cout << "1) Add Patient\n";
        cout << "2) Print Patient\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit program\n";
        
        cin >> choice;
        if (!(choice >= 1 && choice <= 4)) {
            cout << "Invalid choice. try again\n";
            choice = -1;
        }
    }
    return choice;
  }
  bool addPatient() {
      int status, spec;
      string name;
      cout << "Enter the name, status and specialization\n";
      cin >> name >> status >> spec;
      
      bool statusOp;
      if (status == 0) {
          statusOp = queues[spec].addEnd(name, status);
      } else {
          statusOp = queues[spec].addFront(name, status);
      }
      if (statusOp == false) {
        cout << "Sory can't add another patient\n";
        return false;
      }
      return true;
  }
  void printPatient() {
      for (int i = 0; i < MAX_SPECIALIZATION; i++) {
          queues[i].print();
      }
  }
  void getNextPatient() {
      int spec;
      cout << "Enter specialization you want\n";
      cin >> spec;
      queues[spec].removeFront();
  }
  void run() {
      while (true) {
        int choice = menu();
        if (choice == 1) {
          addPatient();
        } else if (choice == 2) {
          printPatient();
        } else if (choice == 3) {
          getNextPatient();
        } else {
          cout << "\n*************Bey...!*****************\n";
          return;
        }
      }
  }
};

int main() {
    // Write C++ code here
    HospitalSystem hs;
    hs.run();

    return 0;
}
