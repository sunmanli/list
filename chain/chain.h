#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Chain;                 //������Chain �������

template<typename T>
class Node                   //������ ���Node ��Ķ���
{
    friend class Chain<T>;   //���� ��Chain Ϊ ��Node ����Ԫ��
private:
	T data;                  //��������
	Node<T> *next;           //����ָ��
};

template<typename T>
class Chain							//������Chain ��Ķ���
{
public:
	Chain();						//���캯��
    ~Chain();						//��������
	bool IsEmpty(int i);			//�жϵ������Ƿ�Ϊ��
    int Length();				//���ر�
	bool Find(int i, T &x);			//���±�Ϊi��Ԫ��ȡ��x
	int Search(const T &x);			//����x�ڱ��е��±�
	void Insert(int i, const T &x); //��Ԫ��x������е�i��λ��
	void Delete(int i, T &x);       //��i��Ԫ������x��ɾ�����Ӧ�Ľ��
	void ClearList();               //�������
    void OutPut(ostream &out)const; //�����������Ԫ�ص�ֵ
    friend ostream& operator<<(ostream &out, const Chain<T> &x) //����"<<"
	{
		x.OutPut(out);
		return out;
	}  
private:
	Node<T> *head;           //ͷָ��
	int length;              //��
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
		throw out_of_range("�±�Խ��\n");
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
		throw out_of_range("�±�Խ��\n");
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