#include <iostream>
#include <string>
using namespace std;

//Node struktur untuk menu
struct nodeMenu {
  string name;
  int price;
  nodeMenu* next;
};

//Head pointer untuk tiap kategori menu
nodeMenu* headMakanan = nullptr;
nodeMenu* headMinuman = nullptr;
nodeMenu* headAppetizer = nullptr;
nodeMenu* headDessert = nullptr;

//Nampilin menu
void showMenu(nodeMenu* head) {
    nodeMenu* current = head;
    if (current == nullptr) {
        cout << "(Kosong)" << endl;
        return;
    }
    
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << current->name << " - Rp" << current->price << endl;
        current = current->next;
        i++;
    }
}
//Tambah menu diakhir
void addMenuAtTheEnd(nodeMenu*& head, string newName, int newPrice) {
  nodeMenu* newNode = new nodeMenu;
  newNode->name = newName;
  newNode->price = newPrice;
  newNode->next = nullptr;

  if(head == nullptr) {
    head = newNode;
  } else {
    nodeMenu* temp = head;
    while(temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

//Deklarasi function
void addMenuFunc();
void custPath();
void workPath();

int main() {
  int PATH_BRANCH; //Choosing the path (worker/owner or customer)
  do { //Biar bisa balik ke menu awal terus
    cout << "\n=========================" << endl;
    cout << "WELCOME TO WARTEG KEPUTIH" << endl;
    cout << "=========================\n" << endl;
    cout << "Sign in as : " << endl;
    cout << "1. Worker or owner" << endl;
    cout << "2. Customer" << endl;
    cout << "3. Exit" << endl;
    cout << "Type option here (1/2/3) : ";
    cin >> PATH_BRANCH;

    switch (PATH_BRANCH) { //Nentuin pathnya mau dibawa ke function mana
      case 1: //Worker/owner path
        workPath();
        break;
      case 2: //Customer path
        custPath();
        break;
      case 3:
        cout << "Exiting program." << endl; //Ini kalo mau langsung keluar
        break;
      default:
        cout << "Invalid option. Please choose 1, 2, or 3." << endl;
        break;
    }
  } while (PATH_BRANCH != 3);

  return 0;
}

void custPath() {
  //Tulis kebutuhan function customer disini
}

void workPath() {
  int option;

  do {
    cout << "\n=========================" << endl;
    cout << "WELCOME WORKER/OWNER" << endl;
    cout << "=========================\n" << endl;
    cout << "Menu Management Options: " << endl;
    cout << "1. View Menu Items" << endl;
    cout << "2. Add Menu Item" << endl;
    cout << "3. Remove Menu Item" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Type option here (1/2/3/4) : ";
    cin >> option;

    switch (option) {
      case 1:
        cout << "\n=== DAFTAR MAKANAN ===" << endl;
        showMenu(headMakanan);
        cout << "\n=== DAFTAR MINUMAN ===" << endl;
        showMenu(headMinuman);
        cout << "\n=== DAFTAR APPETIZER ===" << endl;
        showMenu(headAppetizer);
        cout << "\n=== DAFTAR DESSERT ===" << endl;
        showMenu(headDessert);
        break;
      case 2:
        addMenuFunc();
        break;
      case 3:
        //Remove Menu Item function call
        break;
      case 4:
        cout << "Returning to Main Menu." << endl;
        break;
      default:
        cout << "Invalid option. Please choose between 1-4." << endl;
        break;
    }
  } while (option != 4);
}

void addMenuFunc() {
  int category;
  string newName;
  int newPrice;
  int positionOption;

  cout << endl;
  cout << "Select category to add menu item: " << endl;
  cout << "1. Makanan" << endl;
  cout << "2. Minuman" << endl;
  cout << "3. Appetizer" << endl;
  cout << "4. Dessert" << endl;
  cout << "Type option here (1/2/3/4) : ";
  cin >> category;

  cout << endl;
  cout << "Where to add the new menu item?" << endl;
  cout << "1. At the end" << endl;
  cout << "2. At the beginning" << endl;
  cout << "3. At a specific position" << endl;
  cout << "Type option here (1/2/3) : ";
  cin >> positionOption;

  cout << endl;
  cout << "Enter the name of the new menu item: ";
  cin.ignore(); 
  getline(cin, newName);

  cout << "Enter the price of the new menu item (Rp): ";
  cin >> newPrice;

  switch (positionOption) {
    case 1:
      switch (category) {
        case 1:
          addMenuAtTheEnd(headMakanan, newName, newPrice);
          cout << "Menu item added to Makanan successfully." << endl;
          break;
        case 2:
          addMenuAtTheEnd(headMinuman, newName, newPrice);
          cout << "Menu item added to Minuman successfully." << endl;
          break;
        case 3:
          addMenuAtTheEnd(headAppetizer, newName, newPrice);
          cout << "Menu item added to Appetizer successfully." << endl;
          break;
        case 4:
          addMenuAtTheEnd(headDessert, newName, newPrice);
          cout << "Menu item added to Dessert successfully." << endl;
          break;
        default:
          cout << "Invalid category option." << endl;
          break;
      }
      break;
    case 2:
      // Sama kayak atasnya tapi pake function addMenuAtTheBeginning
      cout << "Feature to add at the beginning is not yet implemented." << endl;
      break;
    case 3:
      // Sama kayak atasnya tapi pake function addMenuAtSpecificPosition
      cout << "Feature to add at a specific position is not yet implemented." << endl;
      break;
    default:
      cout << "Invalid position option." << endl;
      break;
  }
}