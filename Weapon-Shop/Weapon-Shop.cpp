//Designed by Michael Noseworthy(101027533), Madalyn Kendrick(101007249), Kevin Ly(101044351) 
//Data Structures Assignment 2 - January 12th 2017


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool debugging = false;


class Weapon {
public:
	string weaponName;  //The name of the weapon
	int range; //The range of the weapon
	int damage; //The damage that the weapon does
	float weight; //How heavy the weapon is
	float cost; //How much it costs to buy it
	
	//Creating the weapon
	Weapon(string n, int rang, int dam, float w, float c) {
		weaponName = n;
		damage = dam;
		range = rang;
		weight = w;
		cost = c;
	}
	
};

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	//WeaponInfo
	Weapon **table;
	int tableLength;
	int size = 5;
	int numItems;
	//WeaponEnd


	Node(int d)
	{
		data = d;

		//WeaponInfo
		tableLength = size;
		numItems = 0;
		table = new Weapon*[tableLength];
		for (int i = 0; i<tableLength; i++) {
			table[i] = NULL;
		}
		//WeaponEnd
		left = right = NULL;

	}
};  
class BinaryTree
{
public:
	Node *root;
	
	BinaryTree()
	{
		root = NULL;
		int numItems;
	}

	void push(int x, Weapon *item)
	{
		//WeaponInfo
		int index = 0;
		int tableSize = 5;
		//WeaponEnd

		Node* newNode = new Node(x);

		//WeaponInfo
		newNode->table[index] = item;
		//WeaponEnd
		if (root == NULL)
		{
			root = newNode;
			return;
		}

		Node* parent = root;
		Node* current = root;
		while (current != NULL)
		{
			parent = current;
			if (current->data < x)
			{
				current = current->right;
			}
			else
				current = current->left;
		}
		if (parent->data < x)
		{
			parent->right = newNode;			
		}
		else
		{
			parent->left = newNode;
		}
	}

	Weapon *search(int x)
	{
		Node* searchNode = new Node(x);
		searchNode->data = x;
		Weapon* ptr;

		Node* parent = root;
		Node* current = root;
		while (current->data != searchNode->data)
		{
			parent = current;
			if (current->data < x)
			{
				current = current->right;
			}
			if (current->data > x)
				current = current->left;
		}
		return ptr = current->table[0];	
	}
	


	
	void displayInOrder()
	{
		cout << "Weapon List: " << endl;
		inOrder(root);
	}

	void inOrder(Node* n)
	{
		if (n != NULL)
		{
			inOrder(n->left);
			//cout << "Item Number: " << n->data << " ";
			cout << "Name: " << n->table[0]->weaponName << "   Damage: " << n->table[0]->damage << "    Cost:" << n->table[0]->cost << " "; 

			//WeaponInfo
			//cout << "Name: " << n->table[0]->weaponName << "   Damage: " << n->table[0]->damage << "    Cost:" << n->table[0]->cost << endl;
			cout << "Item Number: " << n->data << endl; 
			//WeaponEnd

			inOrder(n->right);
		}
	}

	void displayPreorder()
	{
		cout << " Preorder: " << endl;
		preOrder(root);
	}

	void preOrder(Node* n)
	{
		if (n != NULL)
		{
			cout << "Item Number: " <<n->data << " ";
			cout << "Name: " << n->table[0]->weaponName << "   Damage: " << n->table[0]->damage << "    Cost:" << n->table[0]->cost << endl;
			preOrder(n->left);
			preOrder(n->right);
		}
	}

	void displayPostOrder()
	{
		cout << "Postorder: " << endl;
		postOrder(root);
	}

	void postOrder(Node* n)
	{
		if (n != NULL)
		{
			postOrder(n->left);
			postOrder(n->right);
			cout << "Item Number: " << n->data << " ";
			cout << "Name: " << n->table[0]->weaponName << "   Damage: " << n->table[0]->damage << "    Cost:" << n->table[0]->cost << endl;
		}
	}
};  
//Hashtable is no longer used.
/*
class hashTable {

public:
	int tableLength;    // records the max size of the table
	int numItems;       // records number of items in the list
	Weapon **table; //hashtable itself

	hashTable(int size) {
		tableLength = size;
		numItems = 0;
		table = new Weapon*[tableLength];
		for (int i = 0; i<tableLength; i++) {
			table[i] = NULL;
		}
	}


	int hash(string key)
	{
		int value = 0;
		for (int i = 0; i < key.length(); i++)
			value = value + key[i];
		return value % tableLength;
	}

	void put(Weapon *item) {
		int location = hash(item->weaponName); //gets location in table based on name
		while (table[location] != NULL) {
			location = (location + 1);      // look one down
			location = location%tableLength; // to ensure wraparound at end of array
		}
		table[location] = item;
		numItems++;
	}

	Weapon* get(string key) {
		int location = hash(key); //gets location in table based on key
		while (table[location] != NULL && key.compare(table[location]->weaponName) != 0) {  // not empty and not item
			location = (location + 1);      // look one down
			location = location%tableLength; // to ensure wraparound at end of array
		}
		return table[location];
	}

	void printTable() {
		int count = 0;
		for (int x = 0; x<tableLength; x++) {
			
			if (table[x] != NULL) {
				cout << "Name: " << table[x]->weaponName << "   Damage:" << table[x]->damage << "    Cost:" << table[x]->cost << endl;
			}
		}
	}
}; 
*/
class Player {
public:
	string name;
	Weapon ** backpack;
	int numItems;
	float money;

	Player(string n, float m) {
		name = n;
		money = m;
		numItems = 0;
		backpack = new Weapon*[10];
	}

	void buy(Weapon * w) {
		cout << w->weaponName << " bought..." << endl;
		backpack[numItems] = w;
		numItems++;
		//cout << numItems;
	}
	void withdraw(float amt) {
		money = money - amt;
	}

	bool inventoryFull() {
		bool full = false;
		if (numItems == 10)full = true;
		return full;
	}


	void printCharacter() {
		cout << " Name:" << name << "\n Money:" << money << endl;
		printBackpack();
	}

	void printBackpack() {
		cout << " " << name << ", you own " << numItems << " Weapons:" << endl;
		for (int x = 0; x < numItems; x++) {
			cout << " " << backpack[x]->weaponName << endl;
		}

		/*struct Node {
			int data;
			struct Node*left;
			struct Node *right;
		}; */

	 /*struct Node* Delete(struct Node*root, int data)
		{
			if (root == NULL) return root;
			cout << "Which weapon would you like to delete?" << numItems << endl; 
			else if (data < root->data)root->Delete(root->left, data);
			else (data > root->data) root->right = Delete(right->right, data);
			else
			{
				else if (root->left == NULL)
				{
					struct Node *temp = root;
					root = root->right;
					delete temp;
					return root;
				}
				//cout << endl;
			} */
	 
		cout << endl;
	}

};

void addWeapons(BinaryTree &bt)
{
	int index = 1;
	cout << "***********WELCOME TO THE WEAPON ADDING MENU*********" << endl;
	string weaponName; int weaponRange; int weaponDamage; float weaponWeight; float weaponCost;
	cout << "Please enter the NAME of the Weapon ('end' to quit):"; cin >> weaponName;
	while (weaponName.compare("end") != 0) {
		cout << "Please enter the Range of the Weapon (0-10):"; cin >> weaponRange;
		cout << "Please enter the Damage of the Weapon:"; cin >> weaponDamage;
		cout << "Please enter the Weight of the Weapon (in pounds):"; cin >> weaponWeight;
		cout << "Please enter the Cost of the Weapon (0-45):"; cin >> weaponCost;
		Weapon *w = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, w);
		index++;
		cout << "Please enter the NAME of one more Weapon. Once you've purchased both of your weapons, type end. ('end' to quit):"; cin >> weaponName;
	}
}

void showRoom(BinaryTree ht, Player *p) {
	string choice;
	cout << "WELCOME TO THE SHOWROOM!!!!" << endl;
	ht.displayInOrder();
	cout << " You have " << p->money << " money." << endl;
	cout << "Please select a weapon to buy('end' to quit):"; cin >> choice;
	while (choice.compare("end") != 0 && !p->inventoryFull()) {
		stringstream geek(choice);
		int x = 0;
		geek >> x;
		Weapon *w = ht.search(x);
		if (w != NULL) {
			if (w->cost > p->money) {
				cout << "Insufficient funds to buy " << w->weaponName << endl;
			}
			else {
				p->buy(w);
				p->withdraw(w->cost);
			}
		}
		else {
			cout << " ** " << choice << " not found!! **" << endl;
		}
		cout << "Please select another weapon to buy. Once all weapons are purchased, type end. ('end' to quit):"; cin >> choice;
	}
	cout << endl;
}

//For testing and debugging purposes only
/*
void addWeaponstest(BinaryTree &bt)
{
	int index = 1;
	cout << "***********WELCOME TO THE WEAPON ADDING MENU*********" << endl;
	string weaponName; int weaponRange; int weaponDamage; float weaponWeight; float weaponCost;
	weaponName = "Best"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
	cout << weaponName << " " << weaponRange << " " << weaponDamage << " " << weaponWeight << " " << weaponCost << endl;
	cout << "Begin order testing: " << endl;
	
		Weapon *w = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, w);
		index++;
		weaponName = "Program"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
		Weapon *c = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, c);
		index++;
		weaponName = "ToHave"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
		Weapon *d = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, d);
		index++;
		weaponName = "Ever"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
		Weapon *e = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, e);
		index++;
		weaponName = "To"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
		Weapon *f = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, f);
		index++;
		weaponName = "Existed"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
		Weapon *g = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, g);
}
*/
int main() {
	/*
	//OLD STUFF:
	string pname;
	cout << "Please enter Player name:" << endl;
	cin >> pname;
	Player pl(pname, 45);
	hashTable ht(101);
	addWeapons(ht);
	showRoom(ht, &pl);
	pl.printCharacter();
	*/

	string pname;
	cout << "Please enter Player name:" << endl;
	cin >> pname;
	Player pl(pname, 45);

	//NEW STUFF:
	cout << endl;

	//Binary Tree
	BinaryTree b;
	//addWeaponstest(b); // Test code
	addWeapons(b); //Adding weapons to the game

	showRoom(b, &pl); //Begin the buying of weapons
	pl.printCharacter(); //Prints character bought weapon choices
	pl.printBackpack(); //Prints character's backpack to show and delete weapons 

	int Size;
	cout << "How many weapons did you purchase? (1-5) : ";
	cin >> Size;
	int Array[5];
	cout << "Which weapons would you like to highlight? (1-5) : ";
	for (int Index = 0; Index < Size; Index++)
	{
		cin >> Array[Index];
	}
	int position;
	cout << "Which highlighed weapon would you like to delete? : ";
	cin >> position;
	position--;
	for (int Index = position; Index < Size; Index++)
	{
		int Temp = Array[Index];
		Array[Index] = Array[Index + 1];
		Array[Index + 1] = Temp;
	}
	for (int Index = 0; Index < Size - 1; Index++)
	{
		cout << Array[Index] << " ";
	}
	
	return 0;


	//Debugging code:
	/*
	int test = 3;
	cout << "At this point the search finds item number: " << test << endl;
	Weapon *w = b.search(test);
	cout << w->weaponName << endl;
	cout << "end of testing the search." << endl;

	//Testing:
	b.displayInOrder();
	cout << endl;
	/*
	b.displayPreorder();
	cout << endl;
	b.displayPostOrder();
	*/
	cout << endl;

	system("PAUSE");
	return 0;
}