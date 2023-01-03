#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

string names[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];
int patientStatus[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];
int frequencySpecializationQueueLength[MAX_SPECIALIZATION];

int menu() {
  int choice = -1;
  while (choice == -1) {
    cout << "\nEnter your choice:\n";
		cout << "1) Add new patient\n";
		cout << "2) Print all patients\n";
		cout << "3) Get next patient\n";
		cout << "4) Exit\n";

    cin >> choice;

    if (choice < 1 || choice > 4) {
      cout << "Invalid choice. Try again\n";
      choice = -1;
    }
  }
  return choice;
}

void shiftLeft(int spec, string namesSpec[], int statusSpec[]) {
  int length = frequencySpecializationQueueLength[spec];
  for (int i = 1; i < length; i++) {
    namesSpec[i - 1] = namesSpec[i];
    statusSpec[i - 1] = statusSpec[i];
  }
  frequencySpecializationQueueLength[spec]--;
}

void shiftRight(int specialization, string namesSpecialization[], int patientStatus[]) {
  int length = frequencySpecializationQueueLength[specialization];
  for (int i = length - 1; i >= 0; i--) {
    namesSpecialization[i + 1] = namesSpecialization[i];
    patientStatus[i + 1] = patientStatus[i];
  }
  frequencySpecializationQueueLength[specialization]++;
}

bool addPatient() {
  string name;
  int status, specialization;
  cout << "Enter patient name, status, specialization\n";
  cin >> name >> status >> specialization;

  int numberOfPatientInSpecialization = frequencySpecializationQueueLength[specialization];
  if (numberOfPatientInSpecialization >= MAX_QUEUE) {
    cout << "Sory can't add new patient\n";
    return false;
  }
  if (status == 0) {
    names[specialization][numberOfPatientInSpecialization] = name;
    patientStatus[specialization][numberOfPatientInSpecialization] = status;
  } else {
    shiftRight(specialization, names[specialization], patientStatus[specialization]);
    names[specialization][0] = name;
    patientStatus[specialization][0] = status;
  }
  return true;
}

void printPatient(int spec, string namesSpec[], int statusSpec[]) {
  int length = frequencySpecializationQueueLength[spec];
  if (length == 0) {
    return;
  }
  for (int i = 0; i < length; i++) {
    cout << namesSpec[i] << " ";
    if (statusSpec[i]) {
      cout << "urgent\n";
    } else {
      cout << "regular\n";
    }
  }
  cout << "\n";
}

void printPatients() {
  cout << "**************************************\n";
  for (int i = 0; i < MAX_SPECIALIZATION; i++) {
    printPatient(i, names[i], patientStatus[i]);
  }
}

void getNextPatient() {
  int specialization;
  cout << "Enter specialization\n";
  cin >> specialization;
  
  int length = frequencySpecializationQueueLength[specialization];
  if (length == 0) {
    cout << "No patient in this specialization. Have reset Doctor\n";
    return;
  }
  cout << names[specialization][0] << " please go with doctor.\n";
  shiftLeft(specialization, names[specialization], patientStatus[specialization]);
}

void hospitalSystem() {
  while (true) {
    int choice = menu();
    if (choice == 1) {
      addPatient();
    } else if (choice == 2) {
      printPatients();
    } else if (choice == 3) {
      getNextPatient();
    } else {
      break;
    }
  }
}

int main() {
  hospitalSystem();

  return 0;
}