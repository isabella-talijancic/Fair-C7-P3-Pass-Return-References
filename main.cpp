// Inventory Displayer & Referencer
// Demonstrates constant references

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

string favFoods;
int choice;
int MAX = 5;
void formList();

//parameter vec is a constant reference to a vector of strings
void display(const vector<string>& inventory);
//returns a reference to a string
string& refToElement(vector<string>& inventory, int i);

vector<string> inventory;
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;

int main()
{
	cout << "🥪 🍤 Favorite Foods 🥨 🥞\n\n";
	cout << "Please list 5 of your favorite foods :\n";
	formList();

    display(inventory);
    
    //displays string that the returned reference refers to 
    cout << "\nSending the returned reference to cout : ";
    cout << refToElement(inventory, 0) << "\n\n";
	
    //assigns one reference to another -- inexpensive assignment 
    cout << "Assigning the returned reference to another reference.\n";
    string& rStr = refToElement(inventory, 1); 
    cout << "Sending the new reference to cout : ";
    cout << refToElement(inventory, 1) << "\n\n";

    //copies a string object -- expensive assignment
    cout << "Assigning the returned reference to a string object.\n";
    string str = refToElement(inventory, 2);
    cout << "Sending the new string object to cout : ";
    cout << refToElement(inventory, 2) << "\n\n";
    
    //altering the string object through a returned reference
    cout << "Altering an object through a returned reference.\n";
    rStr = "meatloaf";
    cout << "Sending the altered object to cout : ";
    cout << inventory[1] << endl;
    cout << string(55, '-');
    cout << "\nChoose a favorite food you would like to replace (1-5) : ";
    cin >> choice;
    
    if(choice == 1)
    	inventory.erase(inventory.begin()+0);
    if(choice == 2)
		inventory.erase(inventory.begin()+1);
    if(choice == 3)
    	inventory.erase(inventory.begin()+2);
    if(choice == 4)
		inventory.erase(inventory.begin()+3);
    if(choice == 5)
    	inventory.erase(inventory.begin()+4);
    
    cout << "\nWhat are you replacing this food item with? ";
    cin >> favFoods;
    inventory.push_back(favFoods);
    cout << string(55, '-') << "\n";
    display(inventory);

    cout << "\n🥪 🍤 End of Program 🥨 🥞";
    return 0;
}

//parameter vec is a constant reference to a vector of strings
void display(const vector<string>& vec)
{
    cout << "Your Favorite Foods :\n";
    
    for (vector<string>::const_iterator iter = vec.begin(); 
         iter != vec.end(); ++iter)
	{
         cout << "• " << *iter << endl;
	}
	cout << string(55, '-');
}

//returns a reference to a string
string& refToElement(vector<string>& vec, int i)
{
    return vec[i];
}

void formList()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "•";
		getline(cin, favFoods);
		inventory.push_back(favFoods);
	}
	cout << string(55, '-') << "\n";
}