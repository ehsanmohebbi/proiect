#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <fstream>

using namespace std;

typedef struct student
{
	char name[20];
	char info[50];
	struct student * next;
} student;

student* init()
{
	return new student;
}

unsigned int hash(char *s)
{
	unsigned int seed = 0;
	unsigned int h = seed;
	while(*s)
	{
		h = h * 101 + *s++;
	}
	return h;

}
int readStN()
{
	int n;
	cout<<"Insert the number of muximum student>>"<<endl;
	cin>>n;
	return n;
}

student* *allocation(int n)
{
	student* *v;
	v = (student**)calloc(n,sizeof(student*));	
	return v;
}

void addList(student* *head, student *news)
{
	student* p = *head;

	if(p == NULL)
		*head = news;
	else {
		while(p->next != NULL)
			p = p->next;
		p->next = news;
	}
}

void addStud(student* *v, student *s, int n)
{	
	student **head;
	head = &v[hash(s->name) % n];
	addList(head,s);
}

student* createStud()
{
	student* news = new student;

	cout<<"Student Name:"<<endl;
	cin>>news->name;

	cout<<"Student Information:"<<endl;
	cin>>news->info;

	news->next = NULL;

	return news;
}
student* findSt(student *head, char *name)
{
	if(head == NULL)
		return NULL;
			
	student *p = head;
	while(p != NULL){
		if(strcmp(p->name, name) == 0)
			return p;
		p = p->next;
	}	
}

student* readName(student* *v, int n)
{
	char name[20];
	cout<<"Name:"<<endl;
	cin>>name;

	student* stud;
	student* head = v[hash(name) % n];
	stud = findSt(head,name);
	return stud;
}

void displaySt(student *s)
{
	if(s == NULL){
		cout<<"No student found with this name!!"<<endl;
		cout<<"=========================================================="<<endl;
		return;
	}
	cout<<"Student Name:"<<s->name<< endl;
	cout<<"Student Information:"<<s->info<<endl;
}

void meniuSt()
{
	cout<<"Options: \n1. Add Student >>\n2. Get Information about student >>\n0. Exit"<<endl;
}

void options(int n,student* *v)
{
	int opt = -1;
	
	student* s;
	
	if(opt == 0)
		return;
	meniuSt();

	cin>>opt;
		
	if(opt == 1){
		s = createStud();
		addStud(v, s, n);	
	}

	if(opt == 2){
		s = readName(v, n);
		displaySt(s);
	}
	options(n,v);
} 
student* *readFile(studen* *v,char *s)
{
	ifstream infile(s);
	char buf[50], c;
	while(c = infile.getch() != '|') || (c = infile.getch() != '\n')
		buf[i++] = c;
	buf[i] = '\0';

	if(infile.open()){
		while(!infile.eof()){
			student *s = new student;
			strcpy(s->name,readFile(infile));
			strcpy(s->info,readFile(infile));
		}
	} 
}

int main()
{

	int n, m = 131;
	student* *v;
	student *head, *stud;

	n = readStN();
	v = allocation(m);
	student *s = init();
	strcpy(s->name, (char*)"ehsan");
	strcpy(s->info, (char*)"afghanistan");
	s->next = NULL;
	v[0] = s;

	displaySt(v[0]);

	head = v[0];

	cout<<"here"<<endl;
	stud = findSt(head,s->name);
	cout << "stud found:" << endl;
	displaySt(stud);


	options(n,v);
	
	return 0;
}










