#include "chain.h"//xiugai

void main()
{
    char str[]="1C++ 2FORTRAN 3PASCAL 4BASIC";
	Chain<char> L;
	int i;

	try
	{
        for(i=0; str[i] != '\0'; i++)
        {
            L.Insert(i, str[i]);
        }
	}
	catch(const out_of_range &exc)
	{
		cout<<exc.what()<<endl;
	}

	cout<<L<<endl;

	i=0;
	char x;

	while( i < L.Length() )
	{
		L.Find(i, x);

		if ( (x >= '0') && (x <= '9') )
		{
			L.Delete(i, x);
		}
		else
		{
			i++;
		}
	}

    cout<<L<<endl;
	system("pause");
}