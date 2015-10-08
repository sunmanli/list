#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Chain;                 //单链表Chain 类的声明

template<typename T>
class Node                   //单链表 结点Node 类的定义
{
    friend class Chain<T>;   //定义 类Chain 为 类Node 的友元类
private:
	T data;                  //结点的数据
	Node<T> *next;           //结点的指针
};

template<typename T>
class Chain							//单链表Chain 类的定义
{
public:
	Chain();						//构造函数
    ~Chain();						//析构函数
	bool IsEmpty(int i);			//判断单链表是否为空
    int Length();				//返回表长
	bool Find(int i, T &x);			//把下标为i的元素取至x
	int Search(const T &x);			//返回x在表中的下标
	void Insert(int i, const T &x); //将元素x插入表中第i个位置
	void Delete(int i, T &x);       //第i个元素送至x，删除其对应的结点
	void ClearList();               //将表清空
    void OutPut(ostream &out)const; //输出表中所有元素的值
    friend ostream& operator<<(ostream &out, const Chain<T> &x) //重载"<<"
	{
		x.OutPut(out);
		return out;
	}  
private:
	Node<T> *head;           //头指针
	int length;              //表长
};

template<typename T>
Chain<T>::Chain()
{
	head=new Node<T>;
	head->next=0;
	length=0;
}

template<typename T>
Chain<T>::~Chain()
{
	ClearList();
	delete head;
}

template<typename T>
bool Chain<T>::IsEmpty(int i)
{
	return i == 0;
}

template<typename T>
int Chain<T>::Length()
{
	return length;
}

template<typename T>
bool Chain<T>::Find(int i, T &x)
{
    if( (i < 0) || (i > (length-1)) )
    {
		return false;
    }
    
	Node<T> *p=head->next;
	int k=0;

	while(k < i)
	{
		p=p->next;
		k++;
	}
    
	x=p->data;
	return true;
}

template<typename T>
int Chain<T>::Search(const T &x)
{
	Node<T> *p=head->next;
	int i=0;

	while(p != 0)
	{
		if (p->data == x)
		{
			return i;
		}

		p=p->next;
		i++;
	}

	return -1;
}

template<typename T>
void Chain<T>::Insert(int i, const T &x)
{
	if ( (i < 0) || (i > length) )
	{
		throw out_of_range("下标越界\n");
	}

	Node<T> *p=head;
	int k=0;

	while(k <= i-1)
	{
        p=p->next;
		k++;
	}

	Node<T> *q;

	q=new Node<T>;
	q->data=x;
	q->next=p->next;
	p->next=q;
	length++;
}

template<typename T>
void Chain<T>::Delete(int i, T &x)
{
	if ( (i < 0) || (i > length-1) )
	{
		throw out_of_range("下标越界\n");
	}

    Node<T> *p=head;

	for (int k=0; k<i; k++)
	{
		p=p->next;
	}

	Node<T> *q=p->next;

	x=q->data;
	p->next=q->next;
	delete q;
	length--;
}

template<typename T>
void Chain<T>::ClearList()
{
	Node<T> *p=head->next, *q;

	while(p != 0)
	{
		q=p;
		p=p->next;
		delete q;
	}

	head->next=0;
	length=0;
}

template<typename T>
void Chain<T>::OutPut(ostream &out)const
{
	Node<T> *p=head->next;

	while(p != 0)
	{
		out<<p->data<<" ";
		p=p->next;
	}
}

/*template<typename T>
ostream& operator<<(ostream &out, const Chain<T> &x)
{
	x.OutPut(out);
	return out;
}*/