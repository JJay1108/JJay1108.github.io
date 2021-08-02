#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;

class Person{
public:
	friend class List;
	Person(const char* Name, int Age,const char* Address,const char* Tel);
	virtual void print(ostream &os){
		os << "Person:" << endl;
		os << "Name: " << name << " Age: " << age << " Address: " << add;
		os << " Tel: " << tele << endl; 
	}
	virtual void insert();

protected:
	char name[20];
	int age;
	char add[40];
	char tele[15];	
	Person *ptr;
	Person *next;
};


Person::Person(const char* Name, int Age,const char* Address,const char* Tel)
{
	strcpy(name,Name);
	age = Age;
	strcpy(add,Address);
	strcpy(tele,Tel); 
//	ptr = new Person(Name, Age, Address, Tel);
}

void Person::insert()
{
	ptr = new Person(name,age, add, tele);
}


class Student: public Person{
	friend class List;
	int level;
	float grade_point_average;
	
public:
	Student(char* Name, int Age, char* Address, char* Tel,int Level,float gpa):Person(Name,Age,Address,Tel),
	level(Level),grade_point_average(gpa){};
	void print(ostream &os);
	void insert();
};

/*
Student::Student(char* Name, int Age, char* Address, char* Tel,int Level,float gpa)
{
	strcpy(name, Name);
	age = Age;
	strcpy(add,Address);
	strcpy(tele, Tel);
	level = Level;
	grade_point_average = gpa;
}*/

void Student::print(ostream& os)
{
	os << "Student: "<< endl;

	os << "Name: " << name << " Age: " << age << " Address: " << add;
	os << " Tel: " << tele << " Level: " << level;
	os << " GPA: " << grade_point_average << endl;
}

void Student::insert()
{
	char* Name;
	int Age; 
	char* Address;
	char* Tel;
	int Level;
	float gpa;
//	ptr = new Student(Name, Age, Address, Tel, Level ,gpa);
	ptr = new Student(name, age, add ,tele ,level ,grade_point_average);
}

class Teacher: public Person{
	friend class List;
	float salary;
	
public:
	Teacher(char* Name, int Age, char* Address,char* Tel,float Salary): Person(Name, Age, Address, Tel),
	salary(Salary){};	
	void print(ostream& os);
	void insert();
};

void Teacher::print(ostream &os)
{
	os << "Teacher: "<< endl;
	os << "Name: " << name << " Age: " << age << " Address: " << add;
	os << " Tel: " << tele << " Salary: " << salary << endl;
}

void Teacher::insert()
{
	ptr = new Teacher(name,age, add,tele, salary);
}

class Staff: public Person{
	friend class List;
	float hourly_wages;
	
public:
	Staff(char* Name, int Age, char* Address,char* Tel,float hourWage): Person(Name,Age, Address, Tel),
	hourly_wages(hourWage){};
	void print(ostream& os);
	void insert();
};

void Staff::print(ostream& os)
{
	os << "Staff: "<< endl;
	os << "Name: " << name << " Age: " << age << " Address: " << add;
	os << " Tel: " << tele << " Hourly Wages: " << hourly_wages << endl;
}

void Staff::insert()
{
	char* Name;
	int Age; 
	char* Address;
	char* Tel;
	float hourWages;
//	ptr = new Staff(Name, Age, Address, Tel, hourWages);
	ptr = new Staff(name,age, add, tele, hourly_wages);
}

class List{
private:
	Person *root;
public:
	List();
	void insert_Person(Person* node);
	void remove(char *name);
	void print_List(ostream &os);
	void ReadFiles();
	void WriteFile(); 
};

List::List(){
	root = NULL;
}

void List :: ReadFiles()
{
	cout << "请输入读取的文件名："  << endl;
	string s;
	cin >> s;
	
	ifstream inFile;
	char c;
	char name[10];
	char addr[20];
	char tel[10];
	int age = 0;
	int level = 0;
	float gpa = 0;
	float salary = 0;
	
	inFile.open(s);
	while(inFile >> c >> name >> addr >> tel)
	{
		inFile.clear();
		if(c == 'S')
		{
			inFile >> age >> level >> gpa;
			Student stu(name,age,addr,tel,level,gpa);
			insert_Person(&stu);
		}
		else if(c == 'T')
		{
			inFile >> age >> salary;
			Teacher tea(name,age,addr,tel,salary);
			insert_Person(&tea);
		}
		else if(c == 'E')
		{
			inFile >> age >> salary;
			Staff sta(name,age,addr,tel,salary);
			insert_Person(&sta);
		}
		else if(c != 'P')
		{
			string tmp;
			getline(inFile, tmp);
			cout << "发现不可识别的类型" << c << ", 这一整行忽略"  << endl; 
		}
		else if( c == 'P')
		{
			inFile >> age;
			Person per(name,age,addr, tel);
			insert_Person(&per);
		//	cout << 'p' << endl;
		}
			
		if(!inFile)
		{
			cout << "发现输入流挂起，这一整行忽略，流重新复位" << endl;
		//	clearerr(inFile);
			
		//	inFile.close();
		//	ReadFiles();
			
			string tmp;
			getline(cin,tmp); 
			
		}
		
	}
	
	inFile.close(); 
}

void List::WriteFile()
{
	cout << "请输入要输出到的文件名" << endl;
	string s;
	cin >> s;
	ofstream outFile;
	outFile.open(s);
	print_List(outFile); 
	
	outFile.close();
}

void List::insert_Person(Person *node)
{
	char key[30];
	strcpy(key,node->name);
	Person *curr_node = root;
	Person *previous = NULL;
	while(curr_node != NULL && strcmp(curr_node->name,key) < 0)
	{
		previous = curr_node;
		curr_node = curr_node->next;
	}

	node->insert();
	node->ptr->next = curr_node;
	
	if(previous == NULL)
		root = node->ptr;
	else 
		previous->next = node->ptr;
}

void List::remove(char *name)
{
	Person * curr_node = root;
	Person * previous = NULL;
	while(curr_node != NULL && strcmp(curr_node->name,name)!=0)
	{
		previous = curr_node;
		curr_node = curr_node->next;
	}
	if(curr_node!=NULL && previous==NULL)
	{
		root=curr_node->next;
		delete curr_node;
	}
	else if(curr_node!=NULL && previous!=NULL)
	{
		previous->next=curr_node->next;
		delete curr_node;
	}
}

void List::print_List(ostream &os)
{
	Person *cur = root;
	while(cur != NULL)
	{
		cur->print(os);
		cur = cur->next;
	}
}

int main()
{
	List people;
	people.ReadFiles();
	people.ReadFiles();
	people.WriteFile(); 
	

	
	
	return 0;	
}
