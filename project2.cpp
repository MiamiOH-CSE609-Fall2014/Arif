//Project 2//

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<stdlib.h>
#include<math.h>

using namespace std;


string name;//name of the students
string s;//score of the students
double score;
double mean=0.0;
double sum=0.0;
double sd;
double var=0.0;

vector<string>names;
vector<double>scores;

int  nameandgrade();

void meanandsd();

char  gradeofscore(double score);

//Main function//                                                            
 
int main()
{

  cout<<"Enter name and score or enter 'none' to quit"<<endl;
  nameandgrade();
  meanandsd();
  cout<<"name            "<<"score  "<<setprecision(3)<<"Grade "<<endl;
  for(int i=0;i<scores.size();i++)
    {
      cout<<i+1<<"."<<names.at(i)<<"  "<<scores.at(i)<<"%"<< \
	"  "<<gradeofscore(scores.at(i))<<endl;
    }
  cout<<"Clss average ="<<setprecision(4)<<mean<<"%"<<endl;
  cout<<"Standerd deviation ="<<setprecision(4)<<sd<<endl;

  return 0;

}

//Taking information about students(Name & Score)//

int  nameandgrade()
{
  while(1)
    {
      getline(cin,name);
      if (name.empty())
	{
	  cout<<"Invalid Input, try again..."<<endl;
	  cin.clear();
	  cin.sync();
	}
      if (name=="none")
	{
	  break;
	
      cin.clear();
      cin.sync();
	}
      names.push_back(name);
      
      getline(cin,s);
      score=atof(s.c_str());
      if ((score<0) || (score>100))
	{
          cout<<"Score is out of range,try again..."<<endl;
          cin.clear();
          cin.sync();
	}
          scores.push_back(score);
	
    }
}

//Determining Mean and Standard Deviation//

void meanandsd() 
{   
  for (int i=0;i<scores.size();i++)
    {
      sum=sum+scores.at(i);
    }
  mean=sum/scores.size();
  for (int i=0;i<scores.size();i++)
    {
      var=var+pow((scores.at(i)-mean),2.0);
    }
  sd=sqrt(var/scores.size());
       
  //Finding the upper limit and lower limit of grades//
 
  cout<<endl;
  cout<<endl;
  cout<<"Grading scale"<<endl;
  cout<<"A above "<<setprecision(3)<<mean+1.5*sd<<"%"<<endl;
  cout<<"B "<<setprecision(3)<<mean+0.5*sd<<"%-"<<mean+1.5*sd<<"%"<<endl;
  cout<<"C "<<setprecision(3)<<mean-0.5*sd<<"%-"<<mean+0.5*sd<<"%"<<endl;
  cout<<"D "<<setprecision(3)<<mean-1.5*sd<<"%-"<<mean-0.5*sd<<"%"<<endl;
  cout<<"F below "<<setprecision(3)<<mean-1.5*sd<<"%"<<endl;
}

//Determining grades of individual students//

char  gradeofscore(double score)
{
  char  A,B,C,D,F;
  if(score>mean+1.5*sd) 
    return 'A';
  if(score>mean+0.5*sd&&score<mean+1.5*sd)
    return 'B';
  if(score>mean-0.5*sd&&score<mean+0.5*sd)
    return 'C';
  if(score>mean-1.5*sd&&score<mean-0.5*sd)
    return 'D';
  if (score<mean-1.5*sd)
    return 'F';
}


