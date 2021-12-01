//This is the main program
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct student{
   string name;
   string faculty;
   int round;
   int session;
   int targets[3]; //0.join student associations 1.fall in love 2.gpa higher than 4 3.enjoy hall life 4.do part time job 5.faculty task
   int ability[5]; //0.learning 1.executive 2.charm 3.social 4.wealth
   int tasks[6]; //same as targets, represents how many times a student finished a certain task.
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
            fin>>record.faculty>>record.round>>record.session;
            for (int k=0;k<3;k++){
                fin>>record.targets[k];
            }
            for (int j=0;j<5;j++){
                fin>>record.ability[j];
            }
	    for (int j=0;j<6;j++){
	        fin>>record.tasks[j];
	    }
            records.push_back(record);
      }
      fin.close();
}
  
 int main(){
   read_memory(records);

   string game;
   if (records.size()==0){
      game="New";
   }
   else {
      cout<<"Do you want to start a new game or continue a previous one?(New/Previous)"<<endl;
      cin>>game;
   }
 
   student player("a");  //randomly defined, to avoid bugs, no need to worru

   if (game=="New"){
      cout<<"Let's start a new game!"<<endl;
      cout<<"Please give your character a name:"<<endl;

      string name;
      while (true){
        cin>>name;
	int a=0;
	if (records.size()==0){
	   break;
	}
	for (int i=0;i<records.size();i++){
           if (name==records[i].name){
	      a=1;
	      break;
	   }
	}
	if (a==1){
	   cout<<"There already exists a student "<<name<<", please rename the student"<<endl;
	}
	else{
	   break;
	}
      }

      //Apply a function to randomly choose a faculty for the student
      player.name=name;
      player.round=0;
      player.session=0;
      cout<<"Please choose a background for the character: (Local/India/Mainland/Korea)"<<endl;
      string background;
      cin>>background;
      //Apply a function to initialize the ability for the student basing on his/her background
      for (int i=0;i<6;i++){
          player.tasks[i]=0;
      }
      
      cout<<"Congratulations!! You are admitted into The University of Hong Kong"<<endl;
   }


   else {
      cout<<"which one do you want to continue?"<<endl;
      for (int i=0;i<records.size();i++){
          cout<<records[i].name<<" ";
      }
      cout<<endl;
      cout<<"Please input a name: "<<endl;
      string name;
      int a=0;
      int j;
      while (true){
            cin>>name;
	    for (int i=0;i<records.size();i++){
	        if (name==records[i].name){
		   a=1;
		   j=i;
		   break;
		}
	    }
	    if (a==0){
	       cout<<"There doesn't exist such student, please give a correct name"<<endl;
	    }
	    else{
	         break;
	    }
      }
      player=records[j];
      cout<<player.faculty<<endl;
   }
   


 while (player.round<8){
       cout<<player.name<<", ";
       cout<<"you are a year "<<((player.round-(player.round%2))/2)+1<<" student"<<endl;
       cout<<"Now is semester "<<((player.round)%2)+1<<endl;
       cout<<"Wish you can get what you want in University life"<<endl;
       cout<<"Choose three tasks you want to finish during this semester"<<endl;
       cout<<"(join student associations/fall in love/gpa higher than 4/enjoy hall life/do part time job/";
       

       
       player.round=player.round+1;
       cout<<"Do you want to exit now? (Yes/No)"<<endl;
       string answer;
       cin>>answer;
       if (answer=="Yes"){
          break;
       }
 }
 return 0;
 }
