
/////////////////////////////////////////////////////////////////////////
//
//  Function name :     	Data Structure Library
//  Input :                 Generic
//  Output :                Generic
//  Description :          	This is Generic library used for Data Structure LinkedList,Stack,Queue.
//  Author :                Aniket Tatyasaheb Wandhekar.
//  Date :                  18/11/2021
//
//////////////////////////////////////////////////////////////////////////

 
#include<iostream>
using namespace std;


template <typename T>		//Structure Declared for Doubly LinkedLists
struct nodeD
{
	T data;
	struct nodeD * next;
	struct nodeD * prev;
};

template <typename T>
struct nodeS				//Structure	Declared for Singly LinkedLists
{
    T data;
    struct nodeS* next;
};

//Function Declaration For Doubly Linear LinkedList.

template <class T>
class DoublyLL
{
private:
	nodeD <T>* first;
	int size;
	
public:
		
		DoublyLL();
		void Display();
		int Count();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);	
};


//Function Declaration For Doubly Circular LinkedList.

template <class T>
class DoublyCL
{
private:
	nodeD<T>* first;	
	nodeD<T>* last;
	int size;

public:

	DoublyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
};

//Function Declaration For Singly Linear LinkedList.

template <class T>
class SinglyLL
{
private:
    nodeS<T>* first;
    int size;			
    
public:
	SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};

//Function Declaration For Singly Circular LinkedList.

template <class T>
class SinglyCL
{
private:
	nodeS<T>* first;
	nodeS<T>* last;
	int size;
	
public:

	SinglyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	
};

//Function Declaration For Stack.

template <class T>
class Stack     
{
private:
    nodeS <T>* first;
    int size;
    
public:
	Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
   
};

//Function Declaration For Queue.

template <class T>
class Queue     
{
private:
    nodeS <T>* first;
    int size;
    
public:
		Queue();
		void Enqueue(T);
		int Dequeue();
		void Display();
		int Count();
  
};

//Return_Value Class_Name :: Function_Name(Parameters)


//Function Defination of Generic Doubly Circular LinkedList.

template <class T>
DoublyCL<T> :: DoublyCL()		//constructor
	{
		first = NULL;	
		last = NULL;
		size = 0;
	}
	
	//Function Definations
	
template <class T>	
void DoublyCL<T> :: InsertFirst(T no)
{
	nodeD<T>* newn = new nodeD<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	
	last->next = first;
	first->prev = last;
	size++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
	nodeD<T>* newn = new nodeD<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next = newn;
		newn->prev = last;
		last = newn;
	}
	
	last->next = first;
	first->prev = last;
	size++;	
}


template <class T>
void DoublyCL<T> :: Display()
{
	nodeD<T>* temp = first;
	
	for(int i = 1;i<=size;i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp -> next;
	}
	cout<<"\n";
}


template <class T>
int DoublyCL<T> :: Count()
{
	return size;
}


template <class T>
void DoublyCL<T> :: DeleteFirst()
{
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first= NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		first -> prev = last;
		last -> next = first;
	}
	size--;
}
template <class T>
void DoublyCL<T> :: DeleteLast()
{
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first= NULL;
		last = NULL;
	}
	else
	{
		last =  last-> prev;
		delete last-> next;
		first -> prev = last;
		last -> next = first;
	}
	size--;
}
template <class T>
void DoublyCL<T> :: InsertAtPos(T no,int iPos)
{
	if((iPos<1)||(iPos>size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		nodeD<T>* newn = new nodeD<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		nodeD<T>* temp = first;
		
		for(int i = 1;i<iPos-1;i++)
		{
			temp = temp-> next;
		}
		
		newn -> next = temp -> next;
		temp->next->prev = newn;
		
		temp->next = newn;
		newn->prev = temp;
		
		size++;
	}
}
	

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
	
	if((iPos<1)||(iPos>size))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		nodeD<T>* temp = first;
	
		for(int i =1;i<iPos-1;i++)
		{
			temp = temp-> next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
		
		size--;
	
	}	
}


////////////////////////////////////////////////////////////////////////////

//Function Defination of Generic Singly Linear LinkedList.

	template <class T>
	SinglyLL<T> :: SinglyLL()		//default constructor
    {
        first = NULL;
        size = 0;
    }
	
    template <class T>
    void SinglyLL<T> :: InsertFirst(T no)
    {
        nodeS <T>* newn = new nodeS<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
	
    template <class T>
    void SinglyLL<T> :: InsertLast(T no)
    {
        nodeS <T>* newn = new nodeS<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            nodeS <T>* temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
	
    template <class T>
    void SinglyLL<T> :: InsertAtPos(T no, int iPos)
    {
		
		nodeS <T>* newn = new nodeS<T>;
		nodeS <T>* temp = first;
		
		newn->data = no;
		newn->next = NULL;
		
		if((iPos<1)||(iPos>size+1))
		{
			return;
		}
		if(iPos == 1)
		{
			InsertFirst(no);
		}
		else if(iPos == size+1)
		{
			InsertLast(no);
		}
		else
		{
			for(int i = 1;i<iPos-1;i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
			size++;
		}
		
		
		
	}
	
    template <class T>
    void SinglyLL<T> :: DeleteFirst()
    {
        nodeS <T>* temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
	
    template <class T>
    void SinglyLL<T> :: DeleteLast()
    {
        nodeS <T>* temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
	
	template <class T>
    void SinglyLL<T> :: DeleteAtPos(int iPos)
    {
		nodeS <T>* temp = first;
		nodeS <T>* targated = NULL;
		
	
		if((iPos < 1) || (iPos > (size)))
		{
			return;
		}
		if(iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == size)
		{
			DeleteLast();
		}
		else
		{
			for(int i = 1;i < iPos-1;i++)
			{
				temp = temp->next;
			}
			targated = temp->next;
			temp->next = targated->next;
			delete targated;
			
			size--;
		}
	}
    
	template <class T>
    void SinglyLL<T> :: Display()
    {
        nodeS <T>* temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
	template <class T>
    int SinglyLL<T> :: Count()
    {
        return size;
    }
	
////////////////////////////////////////////////////////

//Function Defination of Generic Singly Circular LinkedList.

	template <class T>
	SinglyCL<T> :: SinglyCL()
	{
		first = NULL;
		last = NULL;
		size = 0;
	}
	
	template <class T>
	void SinglyCL<T> ::Display()
	{
		nodeS<T>* temp = first;
		
		if((first == NULL)&&(last == NULL))
		{
			return;
		}
		
		do
		{
			cout<<"|"<<temp->data<<"|->";
			temp  = temp -> next;
		}while(temp != last->next);
		
		cout<<"\n";
	}
	
	template <class T>
	int SinglyCL<T> ::Count()
	{
		return size;
	}
	
	template <class T>
	void SinglyCL<T> ::InsertFirst(T no)
	{
		nodeS<T>* newn = new nodeS<T>;
		
		newn->data = no;
		newn->next = NULL;
		
		if(first==NULL && last == NULL)
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn-> next = first;
			first = newn;
		}
		last->next = first ;
		size++;
	}
	
	template <class T>
	void SinglyCL<T> :: InsertLast(T no)
	{
		
		nodeS<T>* newn = new nodeS<T>;
		
		newn->data = no;
		newn->next = NULL;
		
		if(first==NULL && last == NULL)
		{
			first = newn;
			last = newn;
		}
		else
		{
			last->next = newn;
			last = newn;
			
		}
		last->next = first ;
		size++;
	}
	
	template <class T>
	void SinglyCL<T> :: InsertAtPos(T no,int iPos)
	{
		nodeS<T>* temp = first;
		
		nodeS<T>* newn = new nodeS<T>;
		
		newn->data = no;
		newn->next = NULL;
		
		
		if((iPos < 1) || (iPos > (size+1)))
		{
			return;
		}
		if(iPos == 1)
		{
			InsertFirst(no);
		}
		else if(iPos == size+1)
		{
			InsertLast(no);
		}
		else
		{
			for(int i = 1;i < iPos-1;i++)
			{
				temp = temp->next;
			}
			newn->next=temp->next;
			temp->next = newn;
			
			size++;
		}
	
	}
	
	template <class T>
	void SinglyCL<T> :: DeleteFirst()
	{
		if(first == NULL && last == NULL)
		{
			return;
		}
		else if(first == last)
		{
			delete(first);
			first = NULL;
			last = NULL;
		}
		else
		{
			first = first->next;
			delete last->next;
			
			last->next = first;
		}
		size--;
	
	}
	
	template <class T>
	void SinglyCL<T> :: DeleteLast()
	{
		nodeS<T>* temp = first;
		
		if(first == NULL && last == NULL)
		{
			return;
		}
		else if(first == last)
		{
			delete(first);
			first = NULL;
			last = NULL;
		}
		else
		{
			while(temp->next != last)
			{
				temp = temp-> next;
			}
			
			delete last;
			last = temp;
			
			last -> next = first;
		}
		size--;
	}
	
	template <class T>
	void SinglyCL<T> :: DeleteAtPos(int iPos)
	{
		
		nodeS<T>* temp = first;
		nodeS<T>* targated = NULL;
		
	
		if((iPos < 1) || (iPos > (size)))
		{
			return;
		}
		if(iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == size)
		{
			DeleteLast();
		}
		else
		{
			for(int i = 1;i < iPos-1;i++)
			{
				temp = temp->next;
			}
			targated = temp->next;
			temp->next = targated->next;
			delete targated;
			
			size--;
		}
		
	}
	

////////////////////////////////////////////////////////////////////


//Function Defination of Generic Doubly Linear LinkedList.


template <class T>
DoublyLL<T> :: DoublyLL()
{
	first = NULL;
	size = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
	nodeD<T>* newn = new nodeD<T>;
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	size++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
	nodeD<T>* newn = new nodeD<T>;
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		nodeD<T>* temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
	size++;
}

template <class T>
void DoublyLL<T> :: Display()
{
	nodeD<T>* temp = first;
	
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
	return size;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		first = first->next;
		delete first -> prev;
		first -> prev = NULL;
	}
	size--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
	nodeD<T>* temp = first;
	
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		delete temp;
	}
	size--;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int iPos)
{
	nodeD<T>* newn = new nodeD<T>;
	nodeD<T>* temp = first;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((iPos<1)||(iPos>size+1))
	{
		return;
	}
	if(iPos ==1)
	{
		InsertFirst(no);
	}
	if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		for(int i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
	}
	size++;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
	nodeD<T>* temp = first;
	
	if((iPos<1)||(iPos>size))
	{
		return;
	}
	if(iPos ==1)
	{
		DeleteFirst();
	}
	if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		for(int i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
	}
	size--;
}

//////////////////////////////////////////////////////////////

//Function Defination of Generic Stack.


	template <class T>
	Stack<T> :: Stack()
    {
        first = NULL;
        size = 0;
    }
    template <class T>
    void Stack<T> :: push(T no)   
    {
        nodeS <T>* newn = new nodeS<T>;
		newn -> data = no;
		newn -> next = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn -> next = first;
			first = newn;
		}
		size++;
    }
    template <class T>
    int Stack<T> :: pop()  
    {
		int no = 0;	
		nodeS <T>* temp = first;
		
		if(size == 0)	
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		
        if(size == 1)	//stack contain only one nodeS
		{
			no = first->data;
			delete first;
			first = NULL;
		}
		else
		{
			no = first->data;
			first = first->next;
			delete temp;
		}
		size--;
		return no;	//value return keli
    }
    
	template <class T>
    void Stack<T> :: Display()
    {
		nodeS <T>* temp = first;
		
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|\n";
			temp = temp->next;
		}
	}
    template <class T>
    int Stack<T> :: Count()
    {
        return size;
    }
	
	
//////////////////////////////////////////////////////
	
//Function Defination of Generic Queue.
	
	template <class T>
	Queue<T> :: Queue()
    {
        first = NULL;
        size = 0;
    }
	
    template <class T>
    void Queue<T> :: Enqueue(T no)   // InsertLast()
    {
		nodeS <T>* newn = new nodeS<T>;
		newn->data = no;
		newn->next = NULL;
		
		if(size == 0)
		{
			first = newn;
		}
		else
		{
			nodeS <T>* temp = first;
			
			while(temp->next != NULL)		
			{
				temp = temp-> next;
			}
			temp->next = newn;
		}
		size++;
    }
    
	template <class T>
    int Queue<T> :: Dequeue()   
    {
		int no = 0;
        nodeS <T>* temp = first;
		
		if(size == 0)
		{
			cout<<"Queue is empty\n";
			return -1;
		}
		
		if(size == 1)
		{
			no = first->data;
			delete first;
			first = NULL;
		}
		else
		{
			no = first->data;
			first=first->next;
			delete temp;
		}
		size--;
		return no;	
    }
    
	template <class T>
    void Queue<T> :: Display()
    {
		nodeS <T>* temp = first;
		
		for(int i = 1;i <= size;i++)
		{
			cout<<"|"<<temp->data<<"| - ";
			temp=temp->next;
		}
		cout<<"\n";
	}
    
	template <class T>
    int Queue<T> :: Count()
    {
        return size;
    }

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

int main()				//Caller/Entry point Function.
{
	int iRet = 0;
	
	
	//Doubly Circular LinkedList
	
	
	DoublyCL <int> iobj;		//Object is presenting the LinkedList of Integers.
	
	cout<<"Elements of Doubly Circular LinkedList are : "<<"\n";
	
	iobj.InsertFirst(21);
	iobj.InsertFirst(11);
	
	iobj.InsertLast(51);
	iobj.InsertLast(101);
	
	iobj.InsertAtPos(75,3);
	
	iobj.Display();
	
	iobj.DeleteFirst();
	iobj.DeleteLast();
	iobj.DeleteAtPos(2);
	
	iobj.Display();
	
	iRet = iobj.Count();
	cout<<"Number of elemnts are : "<<iRet<<"\n";
	
	cout<<"\n";
	
	///////////////////////////////////////
	
	cout<<"Elements of Doubly Circular LinkedList are : "<<"\n";
	
	DoublyCL <char> cobj;		//Object is presenting the LinkedList of Characters.
	
	cobj.InsertFirst('A');
	cobj.InsertFirst('B');
	
	cobj.InsertLast('C');
	cobj.InsertLast('D');
	
	cobj.InsertAtPos('Z',3);
	cobj.Display();
	
	iRet = cobj.Count();
	cout<<"Number of elemnts are : "<<iRet<<"\n";
	
	cobj.DeleteAtPos(3);
	cobj.DeleteFirst();
	cobj.DeleteLast();
	
	cobj.Display();
	
	iRet = cobj.Count();
	cout<<"Number of elemnts are : "<<iRet<<"\n";
	
	cout<<"\n";


////////////////////////////////////////////////////////////
	
	//Singly Linear LinkedList
	
	cout<<"Elements of Singly Linear LinkedList are : "<<"\n";
	
	SinglyLL <char> pobj;		//Object is presenting the LinkedList of Characters.
	
    pobj.InsertFirst('C');
    pobj.InsertFirst('B');
    pobj.InsertFirst('A');
    
    pobj.InsertLast('D');
    pobj.InsertLast('E');
    
    pobj.Display();
    iRet = pobj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";
	cout<<"\n";
	////////////////////////////////////////////

	cout<<"Elements of Singly Linear LinkedList are : "<<"\n";
	
	SinglyLL <int> mobj;		//Object is presenting the LinkedList of Integers.
	
    
    mobj.InsertFirst(11);
    mobj.InsertFirst(21);
    mobj.InsertFirst(51);
    
    mobj.InsertLast(101);
    mobj.InsertLast(111);
	
	mobj.InsertAtPos(501,4);
	mobj.DeleteAtPos(3);
	
    
    mobj.Display();
    iRet = mobj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";
	cout<<"\n";
	
/////////////////////////////////////////////////////////////////////////
	
	//Singly Circular LinkedList
	
	cout<<"Elements of Singly Circular LinkedList are : "<<"\n";
	
	SinglyCL <int> jobj;		//Object is presenting the LinkedList of Integers.
	
	
	jobj.InsertFirst(51);
	jobj.InsertFirst(21);
	jobj.InsertFirst(11);
	jobj.InsertFirst(41);
	jobj.InsertFirst(31);
	
	jobj.InsertLast(101);
	
	jobj.Display();
	iRet = jobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";
	
	jobj.DeleteFirst();
	jobj.DeleteLast();
	jobj.InsertAtPos(501,2);
	jobj.DeleteAtPos(3);
	
	jobj.Display();
	iRet = jobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";
	
	cout<<"\n";
	////////////////////////////////////////////////
	
	cout<<"Elements of Singly Circular LinkedList are : "<<"\n";
	
	SinglyCL <char>kobj;			//Object is presenting the LinkedList of Characters.

	
	kobj.InsertFirst('A');
	kobj.InsertFirst('B');
	kobj.InsertFirst('C');
	kobj.InsertFirst('D');
	kobj.InsertFirst('E');
	
	kobj.InsertLast('F');
	
	kobj.Display();
	iRet = kobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";
	
	kobj.DeleteFirst();
	kobj.DeleteLast();
	kobj.InsertAtPos('G',3);
	kobj.DeleteAtPos(4);
	
	kobj.Display();
	iRet = kobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";
	
	cout<<"\n";
	
//////////////////////////////////////////////////////////////////////////////
	
	cout<<"Elements of Doubly Linear LinkedList are : "<<"\n";
	
	
	//Doubly Linear LinkedList
	
	DoublyLL <double> dobj;			//Object is presenting the LinkedList of Double.
	
	dobj.InsertFirst(51.336);
	dobj.InsertFirst(41.123);
	dobj.InsertFirst(31.46);
	dobj.InsertFirst(21.26);
	
	dobj.InsertLast(61.23);
	
	dobj.DeleteFirst();
	dobj.DeleteLast();
	
	dobj.InsertAtPos(501.36,2);
	dobj.DeleteAtPos(2);
	
	dobj.Display();
	iRet = dobj.Count();
	cout<<"Number of elements are : "<<iRet<<"\n";
	cout<<"\n";
	
///////////////////////////////////////////////////////////////////////////
	
	//Stack
	
	cout<<"Elements of Stack are : "<<"\n";
	
	Stack <float> obj;			//Object is presenting the stack of float.
    
    obj.push(11.2);
    obj.push(21.3);
    obj.push(51.6);
    obj.push(101.2);
    
	cout<<"Elements of stack : \n";
    obj.Display();       
    iRet = obj.Count();
    cout<<"Size of stack is : "<<iRet<<"\n";        
    
    iRet = obj.pop();    
    cout<<"Popped element value is :"<<iRet<<"\n";           
	
	cout<<"\n";
   
   /////////////////////////////
   
	cout<<"Elements of Stack are : "<<"\n";
	
	char cRet = '\0';
   
    Stack <char> sobj;			//Object is presenting the stack of Characters.
    
    sobj.push('A');
    sobj.push('B');
    sobj.push('C');
    sobj.push('D');
    
	cout<<"Elements of stack : \n";
    sobj.Display();       
    iRet = sobj.Count();
    cout<<"Size of stack is : "<<iRet<<"\n";        
    
    cRet = sobj.pop();    
    cout<<"Popped element value is :"<<cRet<<"\n";           
	
	cout<<"\n";
    
/////////////////////////////////////////////////////////////////////

	//Queue
	
	cout<<"Elements of Queue are : "<<"\n";
	
    Queue <char> Qobj;			//Object is presenting the Queue of Characters.
    
    Qobj.Enqueue('A');
    Qobj.Enqueue('C');
    Qobj.Enqueue('N');
    Qobj.Enqueue('G');
    
	cout<<"Elements of queue\n";
    Qobj.Display();          
    iRet = Qobj.Count();     
    cout<<"Size of queue is : "<<iRet<<"\n";       
    
	
    cRet = Qobj.Dequeue();       
    cout<<"Removed element is :"<<cRet<<"\n";                     
    
	cout<<"\n";

	return 0;
}
