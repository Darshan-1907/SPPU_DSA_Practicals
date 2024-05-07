#include<iostream>
#include<string.h>
using namespace std;

struct book_node
{
	char title[20];
	int chapt_count;
	struct book_node *down[10];
	
}*root;  

class book
{
	public:
		void create_tree();
		void display(book_node *r);
		
	book()
	{
	    	root=NULL;
	}
};

void book::create_tree()
{
	 int i,j,k;
	root=new book_node;
	cout<<"Enter name of the book: "<<endl;
	fflush(stdin);
	gets(root->title);
	cout<<"Enter total number of chapters in the book: "<<endl;
	cin>>root->chapt_count;
//	cout<<root->chapt_count;
	for(i=0;i<root->chapt_count;i++)   //for every chapter enter title ,section
	{	
	root->down[i]=new book_node;
	cout<<"Enter Name for chapter "<<i+1<<endl; 
	fflush(stdin);
	gets(root->down[i]->title);
	cout<<"Enter no. of sections in  "<<root->down[i]->title<<endl;
	cin>>root->down[i]->chapt_count;
	cout<<"Enter details for chapter " <<i+1<<endl;
	for(j=0;j<root->down[i]->chapt_count;j++)  //for every section enter title and subsections
	{
		 
	root->down[i]->down[j]=new book_node;
	cout<<"Enter title for section "<<j+1<<endl;
	fflush(stdin);
	gets(root->down[i]->down[j]->title);
	cout<<"Enter no. of sub sections in section "<<j+1<<endl;
	cin>>root->down[i]->down[j]->chapt_count;
	for(k=0;k<root->down[i]->down[j]->chapt_count;k++)
	{
	root->down[i]->down[j]->down[k]=new book_node;
	cout<<"Enter title for subsection "<<k+1<<endl;
	fflush(stdin);
	gets(root->down[i]->down[j]->down[k]->title);
	}
	}
	
} 
	 
	
	
}  

void book::display(book_node *r)
{    int i,j,k;
	if(r!=NULL)
	{
		cout<<"****index****"<<endl; 
		cout<<"Book Title: "<<r->title<<endl<<endl;

		for(i=0;i<r->chapt_count;i++)
    	{  cout<<"\t";
	       cout<<"Chapter " <<i+1<<": "<<r->down[i]->title<<endl;
	      
	       for(j=0;j<r->down[i]->chapt_count;j++)
		    {
		    cout<<"\t\t"; 
	       cout<<"Section "<<j+1<<": "<<r->down[i]->down[j]->title<<endl;
	       
		   for(k=0;k<r->down[i]->down[j]->chapt_count;k++)
		   {  cout<<"\t\t\t";
			 cout<<"Sub Section "<<k +1<<": "<<r->down[i]->down[j]->down[k]->title<<endl; 
        	} 
          }
		}
		
		
	}
}

int main()
{
	int choice;
	book book;
	while(1)
	{
		cout<<"Menu:"<<endl;
		cout<< "Book tree structure"<<endl;
		cout<<"1. Create tree"<<endl;
		cout<<"2. Display tree"<<endl;
		cout<<"3. Exit"<<endl;
		cout<< "Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			book.create_tree();
			break;
			
		case 2:
			book.display(root);
			break;
		case 3:
			exit(0);
			
		}
	}
	return 0;
}

/* OutPut:
Menu:
Book tree structure
1. Create tree
2. Display tree
3. Exit
Enter your choice
1
Enter name of the book:
Data Structures
Enter total number of chapters in the book:
2
Enter Name for chapter 1
Hashing
Enter no. of sections in  Hashing
2
Enter details for chapter 1
Enter title for section 1
Linear probing
Enter no. of sub sections in section 1
2
Enter title for subsection 1
with chaining
Enter title for subsection 2
without chaining
Enter title for section 2
quadratic probing
Enter no. of sub sections in section 2
0
Enter Name for chapter 2
Tree
Enter no. of sections in  Tree
3 
Enter details for chapter 2
Enter title for section 1
General Tree
Enter no. of sub sections in section 1
0
Enter title for section 2
Binary tree
Enter no. of sub sections in section 2
0
Enter title for section 3
BST
Enter no. of sub sections in section 3
0
Menu:
Book tree structure
1. Create tree
2. Display tree
3. Exit
Enter your choice
2
****index****
Book Title: Data Structures

        Chapter 1: Hashing
                Section 1: Linear probing
                        Sub Section 1: with chaining
                        Sub Section 2: without chaining
                Section 2: quadratic probing
        Chapter 2: Tree
                Section 1: General Tree
                Section 2: Binary tree
                Section 3: BST
Menu:
Book tree structure
1. Create tree
2. Display tree
3. Exit
Enter your choice
3
*/
