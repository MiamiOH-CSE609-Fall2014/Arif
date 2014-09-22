#include<iostream>
using namespace std;
int main()
{
  char menu,q;
  cout<<"p= printing information for new customer"<<endl;
  cout<<"a=adding information for new customer"<<endl;
  cout<<"e=editing information for new customer"<<endl;
  cout<<"d=deleting information for new customer"<<endl;
  cout<<"q=quitting "<<endl;
do
  {
  cout<<"enter a single character"<<endl;
    char menu;
    cin>>menu; 
    switch(menu)
  {
  case 'p':cout<<"printing information for new customer"<<endl;break;
  case 'a':cout<<"adding information for new customer"<<endl;break;
  case 'e':cout<<"editing information for new customer"<<endl;break;
  case 'd':cout<<"deleting information"<<endl;break;  
  case'q':cout<<"quit"<<endl;break;
  }
  }
    while(menu=q);
	 return 0;
}
