#include <iostream>
#include <string>

using namespace std;

bool debugging = false;


class Weapon {
public:
	string weaponName;
	int range;
	int damage;
	float weight;
	float cost;
	

	Weapon(string n, int rang, int dam, float w, float c) {
		weaponName = n;
		damage = dam;
		range = rang;
		weight = w;
		cost = c;
	}

	string getName()
	{
		string name;
		name = weaponName;
		return name;
	}
};

template <typename T>
std::string to_string(const T& object) {
	std::ostringstream ss;
	ss << object;
	return ss.str();
}

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Weapon **table;
	//Weapon
	int tableLength;
	int size = 5;
	int numItems;
	//WeaponEnd


	Node(int d)
	{
		data = d;
		//Weapon
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
/*
void put(Weapon *item) {
	int location = hash(item->weaponName); //gets location in table based on name
	while (table[location] != NULL) {
		location = (location + 1);      // look one down
		location = location%tableLength; // to ensure wraparound at end of array
	}
	table[location] = item;
	numItems++;
}
*/
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
		//Weapon
		int index = 0;
		int tableSize = 5;
		//WeaponEnd
		Node* newNode = new Node(x);
		//Weapon
		//Weapon* newWeapon = new Weapon(item);
		
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

	void displayInOrder()
	{
		cout << " In-Order: " << endl;
		inOrder(root);
	}

	void inOrder(Node* n)
	{
		if (n != NULL)
		{
			//Cout Needs if statement so that it does not appear when there is no child.
			//cout << " In-Order: ";
			inOrder(n->left);
			cout << n->data << " ";
			//Weapon
			int x = 0;
			Weapon *ptr;
			//weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost
			//string weaponName; int weaponRange; int weaponDamage; float weaponWeight; float weaponCost;
			/*
			  weaponName = n;
				  damage = dam;
				   range = rang;
				  weight = w;
					cost = c;
			*/
			cout << "Name: " << n->table[x]->weaponName << "   Damage: " << n->table[x]->damage << "    Cost:" << n->table[x]->cost << endl;
			//cout << "test" << endl;
			//WeaponEnd

			inOrder(n->right);
			//Cout Needs if statement so that it does not appear when there is no child.
			//cout << " In-Order: ";
		}
	}

	void displayPreorder()
	{
		cout << " Preorder: ";
		preOrder(root);
	}

	void preOrder(Node* n)
	{
		if (n != NULL)
		{
			cout << n->data << " ";
			preOrder(n->left);
			preOrder(n->right);
		}
	}

	void displayPostOrder()
	{
		cout << "Postorder: ";
		postOrder(root);
	}

	void postOrder(Node* n)
	{
		if (n != NULL)
		{
			postOrder(n->left);
			postOrder(n->right);
			cout << n->data << " ";
		}
	}
};  


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
		cout << numItems;
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
		for (int x = 0; x<numItems; x++) {
			cout << " " << backpack[x]->weaponName << endl;
		}
		cout << endl;
	}

};
/*
void addWeapons(hashTable h) {
	cout << "***********WELCOME TO THE WEAPON ADDING MENU*********" << endl;
	string weaponName; int weaponRange; int weaponDamage; float weaponWeight; float weaponCost;
	cout << "Please enter the NAME of the Weapon ('end' to quit):"; cin >> weaponName;
	while (weaponName.compare("end") != 0) {
		cout << "Please enter the Range of the Weapon (0-10):"; cin >> weaponRange;
		cout << "Please enter the Damage of the Weapon:"; cin >> weaponDamage;
		cout << "Please enter the Weight of the Weapon (in pounds):"; cin >> weaponWeight;
		cout << "Please enter the Cost of the Weapon:"; cin >> weaponCost;
		Weapon *w = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		h.put(w);
		cout << "Please enter the NAME of another Weapon ('end' to quit):"; cin >> weaponName;
	}
}

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
		cout << "Please enter the Cost of the Weapon:"; cin >> weaponCost;
		Weapon *w = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, w);
		index++;
		cout << "Please enter the NAME of another Weapon ('end' to quit):"; cin >> weaponName;
	}
}
*/
void showRoom(hashTable ht, Player *p) {
	string choice;
	cout << "WELCOME TO THE SHOWROOM!!!!" << endl;
	ht.printTable();
	cout << " You have " << p->money << " money." << endl;
	cout << "Please select a weapon to buy('end' to quit):"; cin >> choice;
	while (choice.compare("end") != 0 && !p->inventoryFull()) {
		Weapon *w = ht.get(choice);
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
		cout << "Please select another weapon to buy('end' to quit):"; cin >> choice;
	}
	cout << endl;
}
/*
void addWeaponstest(BinaryTree bt)
{
	int index = 1;
	cout << "***********WELCOME TO THE WEAPON ADDING MENU*********" << endl;
	string weaponName; int weaponRange; int weaponDamage; float weaponWeight; float weaponCost;
	weaponName = "test"; weaponRange = 1; weaponDamage = 2; weaponWeight = 3; weaponCost = 4;
	cout << weaponName << " " << weaponRange << " " << weaponDamage << " " << weaponWeight << " " << weaponCost << endl;
	cout << "Begin order testing: " << endl;
	
		Weapon *w = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
		bt.push(index, w);
		index++;
}
*/

int main() {
	/*
	string pname;
	cout << "Please enter Player name:" << endl;
	cin >> pname;
	Player pl(pname, 45);
	hashTable ht(101);
	addWeapons(ht);
	showRoom(ht, &pl);
	pl.printCharacter();
	*/
	cout << endl;
	//Binary Tree Testing
	BinaryTree b;
	//addWeaponstest(b);
	
	string weaponName = "test";int weaponRange = 1; int weaponDamage = 2; float weaponWeight = 3; float weaponCost = 3;
	//Weapon w(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
	Weapon *w = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
	
	
	
	
	b.push(40, w);
	//b.push(39, w);
	weaponName = "newtest"; weaponRange = 50; weaponDamage = 52; weaponWeight = 53; weaponCost = 53;
	Weapon *y = new Weapon(weaponName, weaponRange, weaponDamage, weaponWeight, weaponCost);
	//b.push(41, y);
	/*
	b.push(25);
	b.push(78);
	b.push(32);
	b.push(10);
	*/
	b.displayInOrder();
	cout << endl;
	b.displayPreorder();
	cout << endl;
	b.displayPostOrder();
	cout << endl;

	system("PAUSE");
	return 0;
}


//Binary Tree testing:
/*
int main()
{
BinaryTree b;
b.push(40);
b.push(25);
b.push(78);
b.push(32);
b.push(10);
b.displayInOrder();
cout << endl;
b.displayPreorder();
cout << endl;
b.displayPostOrder();
cout << endl;
return 0;
}​
*/