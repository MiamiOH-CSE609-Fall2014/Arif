#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<fstream>
#include<map>

using namespace std;

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
      else sequence=sequence+buf;
  
     }
  tuple<string, vector<string>, string>DNA{header, comments, sequence};
  return DNA;
}
map<string,int> digramFreqScores(string s)
{
  map<string,int> scores;
  string s1;
  int i1;
  for(int i=0;i<s.size()-1;i++)
    { 
      s1="";
      s1=s1+s[i]+s[i+1];
      i1 =scores[s1];
      scores[s1]=i1+1;
    }
  return scores;
}
vector< vector<int> > digramFreqMatrix(map<string, int> d)
{
  vector< vector<int> > m;
  vector<int> v;
  v.push_back(d["AA"]);
  v.push_back(d["AG"]);
  v.push_back(d["AC"]);
  v.push_back(d["AT"]);
  m.push_back(v);
  v.clear();
  v.push_back(d["GA"]);
  v.push_back(d["GG"]);
  v.push_back(d["GC"]);
  v.push_back(d["GT"]);
  m.push_back(v);
  v.clear();
  v.push_back(d["CA"]);
  v.push_back(d["CG"]);
  v.push_back(d["CC"]);
  v.push_back(d["CT"]);
  m.push_back(v);
  v.clear();
  v.push_back(d["TA"]);
  v.push_back(d["TG"]);
  v.push_back(d["TC"]);
  v.push_back(d["TT"]);
  m.push_back(v);
  v.clear();

  return m;
}
pair<int,int> scoreSequence(string haystack,string needle,vector< vector<int> > scoring_matrix)
{
  map<string,int> Acid_Base;
  int max_score=0;
  int pos=0;
  Acid_Base["AA"]= scoring_matrix.at(0).at(0);
  Acid_Base["AG"]= scoring_matrix.at(0).at(1);
  Acid_Base["AC"]= scoring_matrix.at(0).at(2);
  Acid_Base["AT"]= scoring_matrix.at(0).at(3);
  Acid_Base["GA"]= scoring_matrix.at(1).at(0);
  Acid_Base["GG"]= scoring_matrix.at(1).at(1);
  Acid_Base["GC"]= scoring_matrix.at(1).at(2);
  Acid_Base["GT"]= scoring_matrix.at(1).at(3);
  Acid_Base["CA"]= scoring_matrix.at(2).at(0);
  Acid_Base["CG"]= scoring_matrix.at(2).at(1);
  Acid_Base["CC"]= scoring_matrix.at(2).at(2);
  Acid_Base["CT"]= scoring_matrix.at(2).at(3);
  Acid_Base["TA"]= scoring_matrix.at(3).at(0);
  Acid_Base["TG"]= scoring_matrix.at(3).at(1);
  Acid_Base["TC"]= scoring_matrix.at(3).at(2);
  Acid_Base["TT"]= scoring_matrix.at(3).at(3);
  for(int i=0;i<haystack.size()-needle.size();i++)
    {
      int sum=0;
      string s="";
      for(int j=0;j<needle.size();j++)
	{
	  s=s+haystack[i+j]+needle[j];
	  sum=sum+ Acid_Base[s];
	  s ="";
	}
      if(sum>=max_score)
	{max_score=sum;
	  pos=i;}
    }
  pair<int,int> pos_score;
  pos_score.first=pos;
  pos_score.second=max_score;
  cout<<"needle: "<<needle<<" maximum position: "<<pos<<" score: "<<max_score<<endl;
  return pos_score;
}
vector< vector<int> > parseScoringFile(string filepath)
{
  fstream file;
  file.open(filepath, fstream::in);
  vector< vector<int> > score_m;
  vector<int> r;
  char buf[500];
  while(file.getline(buf,500,','))
    {
      r.push_back(stoi(buf));
      file.getline(buf,500,',');
      r.push_back(stoi(buf));
      file.getline(buf,500,',');
      r.push_back(stoi(buf));
      file.getline(buf,500);
      r.push_back(stoi(buf));
      score_m.push_back(r);
      r.clear();
    }

  return score_m;
}
tuple<int,int,string> findHighScore(string haystack,vector<string> needles,vector< vector<int> > scoring_matrix)
{
  pair<int,int> pos_score;
  tuple<int,int,string> HighScore;
  for(int i=0;i<needles.size();i++)
    {
      pos_score = scoreSequence(haystack,needles.at(i),scoring_matrix);
      if(pos_score.second>get<1>(HighScore))
	{
	  get<0>(HighScore)=pos_score.first;
	  get<1>(HighScore)=pos_score.second;
	  get<2>(HighScore)=needles.at(i);
	}
    }
  return HighScore;
}

int main(int argc,char* argv[])
{
  tuple<string, vector<string>, string> DNA = parseFastaFile(string(argv[1]));
  string sequence = get<2>(DNA);
  map<string, int> scores = digramFreqScores(sequence);
 
  vector< vector<int> > m = digramFreqMatrix(scores);

  cout << "Digram Frequency Matrix:" << endl;
  for(int row1 = 0; row1 < 4; row1++)
    {
      for(int col1 = 0; col1 < 4; col1++)
	{
	  cout << m[row1][col1] << " ";
	}
      cout << endl;
    }
  vector< vector<int> > scoreMatrix = parseScoringFile(string(argv[2]));
  cout << "Scoring Matrix:" << endl;
  for(int row2 = 0; row2 < 4; row2++)
    {
      for(int col2 = 0; col2 < 4; col2++)
	{
	  cout << scoreMatrix[row2][col2] << " ";
	}
      cout <<endl;

    }

  int num_seq;
  vector<string> sequences;
  string seqs;
  cout << "How many sequences would you like to score? ";
  cin >> num_seq;
  cout << "Enter your sequences: " << endl;
  for(int i = 0; i < num_seq; i++)
    {
      cin >> seqs;
      sequences.push_back(seqs);
    }
  tuple<int, int, string> highScore = findHighScore(sequence, sequences, scoreMatrix);
  cout << "Highest score: " << get<2>(highScore) << "; Score " << get<1>(highScore) << " at position " << get<0>(highScore) << endl;

  return 0;
}
