#include <iostream>
#include <list>
#include <vector>
#include "std_lib_facilities.h"
using namespace std;

int main()
{

	int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	vector <int> vector1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	list<int> list1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

	int array2[10];
	copy(begin(array1), end(array1), array2);
	
	vector<int> vector2={};
	vector2 = vector1;
	
	list<int> lista2={};
	lista2 = list1;
	
	for(auto& i : array1)
		i += 2;
	for(auto& i : vector1)
		i += 3;
	for(auto& i : list1)
		i += 5;
	
	cout << "Tömb1: ";
	for(auto& i : array1)
		cout << i << " ";
	cout << endl;
	
	cout << "Tömb2: ";
	for(auto& i : array2)
		cout << i << " ";
	cout << endl;
	
	cout << "vector1: ";
	for(auto& i : vector1)
		cout << i << " ";
	cout << endl;
	
	cout << "vector2: ";
	for(auto& i : vector2)
		cout << i << " ";
	cout << endl;
	
	cout << "list1: ";
	for(auto& i : list1)
		cout << i << " ";
	cout << endl;
	
	cout << "Lista2: ";
	for(auto& i : lista2)
		cout << i << " ";
	cout << endl;
	
	//vector
	auto p = find(begin(vector2),end(vector2),3);
    int position=distance(begin(vector2),p);
    if(p != end(vector2))
        cout<<"The number is in "<< position <<" position."<<endl;
    else 
    	cout<<"The value wasn't found."<<endl;

    position=0;

    //list
    auto p2 = find(begin(lista2),end(lista2),27);
    position=distance(begin(lista2),p2);
    if(p2!=end(lista2))
        cout<<"The number is in "<< position<<" position."<<endl;
    else
    	cout<<"The value wasn't found."<<endl;

	return 0;
}
