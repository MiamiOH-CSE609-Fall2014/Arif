#include<iostream>
using namespace std;
int main()
{
  int m,n,p,o,i,j,k;
  cin>>m;
  cin>>n;
  cin>>o;
  cin>>p;
  if (n!=o)
    cout<<"invalid input"<<endl;
  int A[m][n];
  int B[n][p];
  int C[m][p];
  for (i=0;i<m;i++)
    {
      for (j=0;j<n;j++)
{
	cin>>A[i][j];
      }
    }
  for (i=0;i<n;i++)
    {
      for(j=0;j<p;j++)
	{
	  cin>>B[i][j];
	}
    }
  cout<<endl;
  for (i=0;i<m;i++)
{
    cout<<"\n";
    for (j=0;j<n;j++)
      cout<<" "<<A[i][j];
  }
  cout<<endl;
  for (i=0;i<n;i++)
    {
      cout<<"\n";
      for (j=0;j<p;j++)
	cout<<" "<<B[i][j];
    }
for (i=0;i<m;i++)
  {
    for (j=0;j<p;j++)
      {
	C[i][j]=0;
	for(k=0;k<n;k++)
	  {
	C[i][j]=C[i][j]+A[i][k]*B[k][j];
      }
  }
}
cout<<endl;
for (i=0;i<m;i++)
  {
  cout<<"\n";
for(j=0;j<p;j++)
  cout<<" "<<C[i][j];
}
cout<<endl;
return 1;
}
