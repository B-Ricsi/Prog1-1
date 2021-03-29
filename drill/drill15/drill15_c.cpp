#include "std_lib_facilities.h"

struct Person{
	Person() { };
	Person(string f, string l, int age);

	string first_name() const { return first; };
	string last_name() const { return last; };

	int age() const { return p_age; };

private:
	string first="";
	string last="";
	int p_age=0;
};

Person::Person(string first, string last, int p_age): first(f), last(l), age(p_age)
{
	if(p_age < 0 || p_age>150)
		error("Invalid age!");

	string full_name = first + last;
	for(char not_good: full_name)
		switch(not_good)
		{
			case ';':
				error("Invalid!");
			case ':':
				error("Invalid!");
				
			case '"':
				error("Invalid!");
				
			case '\'':
				error("Invalid!");
				
			case '[':
				error("Invalid!");
				
			case ']':
				error("Invalid!");
				
			case '*':
				error("Invalid!");
				
			case '&':
				error("Invalid!");
				
			case '^':
				error("Invalid!");
				
			case '%':
				error("Invalid!");
				
			case '$':
				error("Invalid!");
				
			case '#':
				error("Invalid!");
				
			case '@':
				error("Invalid!");
				
			case '!':					
				error("Invalid!");
				
			default:
				break;
		}
}

istream& operator>>(istream &in_person, Person &person)
{
	string in_first_name;
	string in_last_name;
	int in_age;
	in_person >> in_first_name >> in_last_name >> in_age;
	in_person = Person{in_first_name, in_last_name, in_age};

	return in_person;
}

ostream& operator<<(ostream &out, Person &person)
{
	out << person.first_name() << " " << person.last_name() << " " << person.age() << endl;
	return out;
}

int main()
{
	Person in_person("Goofy", "Goofy", 63);
	cout << in_person << endl;
	
	vector<Person> vector_person;
	cout << "Enter names and ages, write 'end' if done.\n";
	Person people;
	while(cin >> people)
	{
		if(people.first_name() == "end") break;
		vector_person.push_back(people);
	}

	for(Person people : vector_person)
		cout << people << endl;



	return 0;
}