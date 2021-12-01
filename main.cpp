//This is the main program
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct student{
   string name;
   int round;
   int session;
   int targets[3]; //0.join student associations 1.fall in love 2.gpa higher than 4 3.enjoy     hall life 4.do part time job 5.faculty task
   int ability[5]; //0.learning 1.executive 2.charm 3.social 4.wealth
    student(string name) {
        this->name = name;
    };
};

vector<student> records; 

void read_memory(vector<student> & records){
      ifstream fin ("memory.txt");
      string name;
      while (fin >> name){
            student record(name);
            fin>>record.round>>record.session;
            for (int k=0;k<3;k++){
                fin>>record.targets[k];
            }
            for (int j=0;j<5;j++){
                fin>>record.ability[j];
            }
            records.push_back(record);
      }
      fin.close();
}
  
 int main(){
   cout<<"Do you want to start a new game?(Yes/No)"<<endl:
   string * s=new string;
   cin>>*s;

   read_memory(records);
 return 0;
 }

