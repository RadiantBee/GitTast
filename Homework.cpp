#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Human
{
	char* name;
	int age;
	int height;
	float weight;
};


void PrintGroupOfHumans(Human* group, int size)
{
	cout << "\n---Group informaton---\n";
	for (int i = 0; i < size; i++)
	{
		cout << "---Human " << i + 1 << "---\n";
		cout << "Name: " << group[i].name << "\n";
		cout << "Age: " << group[i].age << "\n";
		cout << "Height: " << group[i].height << "\n";
		cout << "Weight: " << group[i].weight << "\n";
	}
}


Human InputHumanInformation()
{
	Human obj;
	char buff[255];
	cout << "\n---Input human information---\n";
	cout << "Name: ";
	cin.getline(buff, 255);
	obj.name = new char[strlen(buff) + 1];
	strcpy(obj.name, buff);
	cout << "Age: ";
	cin >> obj.age;

	cout << "Height: ";
	cin >> obj.height;

	cout << "Weight: ";
	cin >> obj.weight;
	cin.ignore();

	return obj;
}


void AddHumanToGroup(Human*& group, int& size, Human obj)
{
	Human* newGroup = new Human[size + 1];
	for (int i = 0; i < size; i++)
	{
		newGroup[i] = group[i];
	}
	newGroup[size] = obj;
	delete[]group;
	group = newGroup;
	size++;
}


void SwapHumans(Human*& group, int id1, int id2)
{
	Human temp = group[id1];
	group[id1] = group[id2];
	group[id2] = temp;
}


void SortByName(Human*& group, int size)
{
	//Bubble sort
	for (int id1 = 0; id1 < size; id1++)
	{
		for (int id2 = 0; id2 < size; id2++)
		{
			if (strcmp(group[id1].name, group[id2].name) == -1)
			{
				SwapHumans(group, id1, id2);
			}
		}
	}
}

int main()
{
	Human* group = nullptr;
	Human newHuman;
	int size = 0;

	for (int i = 0; i < 5; i++)
	{
		newHuman = InputHumanInformation();
		AddHumanToGroup(group, size, newHuman);
		
	}
	PrintGroupOfHumans(group, size);
	SortByName(group, size);
	PrintGroupOfHumans(group, size);

	//Deleting heap memory
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
			delete[] group[i].name;
	}
}

