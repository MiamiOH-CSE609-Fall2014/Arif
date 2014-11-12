#include<iostream>
#include<tuple>
#include<string>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include<map>
using namespace std;

//string digrams[] = {"AA", "AG", "AC", "AT", "GA", "GG", "GC", "GT", "CA", "CG", "CC", "CT", "TA", "TG", "TC", "TT"};

tuple< string, vector<string>, string> parseFastaFile(string filepath)
{
  string header;
  vector<string>comments;
  string sequence;
  fstream file;
  file.open(filepath, fstream::in);
  char buf[500];
  while (file.getline(buf,500))
    {
      if (buf[0] == '>'){
	header=buf;
      }
      else if (buf[0] == ';'){
	comments.push_back(buf);
      }
      else {
	sequence=sequence+buf;
      }
    }
  DNA = make_tuple(header,comments,sequence);
  return DNA;
}
map<string,int> digramFreqScores(string s){
  map<string,int> scores=
    {
      {"AA",0},{"AC",0},{"GT",0},
      {"AG",0},{"CC",0},{"CA",0},
      {"CG",0},{"TT",0},{"GG",0},
      {"GC",0},{"AT",0},{"GA",0},
      {"TG",0},{"TA",0},{"TC",0},
      {"CT",0}
    };
  for (int i=1;i<16;i++)
    {
      ++scores[s.substr(i-1,2)];
    }
  return scores;
}
vector< vector<int> > digramFreqMatrix(map<string, int> scores){
  vector< vector<int> > m;
  vector<int> A,G,C,T;
 
 vector_A.push_back(scores["AA"]);
 vector_A.push_back(scores["AG"]);
 vector_A.push_back(scores["AC"]);
 vector_A.push_back(scores["AT"]);
 vector_G.push_back(scores["GA"]);
 vector_G.push_back(scores["GG"]);
 vector_G.push_back(scores["GC"]);
 vector_G.push_back(scores["GT"]);
 vector_C.push_back(scores["CA"]);
 vector_C.push_back(scores["CG"]);
 vector_C.push_back(scores["CC"]);
 vector_C.push_back(scores["CT"]);
 vector_T.push_back(scores["TA"]);
 vector_T.push_back(scores["TG"]);
 vector_T.push_back(scores["TC"]);
 vector_T.push_back(scores["TT"]);
  m.push_back(vector_A);
  m.push_back(vector_G);
  m.push_back(vector_C);
  m.push_back(vector_T);
  return m;
}

