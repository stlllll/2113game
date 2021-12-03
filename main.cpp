//This is the main program
#include <iostream>
#include <fstream>
#include <string>
#include "transcript.h"
#include <vector>
using namespace std;
struct student{  //use struct to store the information of a student.
   string name;
   string faculty; 
   int round;
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
            fin>>record.faculty>>record.round;
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
 
int change;

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

      //(FJH)Apply a function to randomly choose a faculty for the student
      player.name=name;
      player.round=0;
      cout<<"Please choose a background for the character: (Local/India/Mainland/Korea)"<<endl;
      string background;
      cin>>background;
      //(FJH)Apply a function to initialize the ability for the student basing on his/her background
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
      while (true){
            cin>>name;
	    for (int i=0;i<records.size();i++){
	        if (name==records[i].name){
		   a=1;
		   change=i;
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
      player=records[change];
   }
   
 string faculties[]={"science","engineer","law","business","art","social science"};
 string fac_task[]={"Be a research assistant","Be a research assistant","Intern at a law firm","Find a job","Publish a paper","Publish a paper"};
 int fac_task_num;
 for (int i=0;i<6;i++){
     if (faculties[i]==player.faculty){
        fac_task_num=i;
	break;
     }
 }
 if (player.round==8){
    cout<<"You've already graduated"<<endl;
    cout<<"Here is your transcript"<<endl;
    print_transcript(player.tasks);
 }

 //Now we go into a round
 while (player.round<8){
   for (int i=0;i<5;i++){
       player.ability[i]=0;
   }
       cout<<player.name<<", ";
       cout<<"you are a year "<<((player.round-(player.round%2))/2)+1<<" student"<<endl;
       cout<<"Now is semester "<<((player.round)%2)+1<<endl;
       cout<<"Wish you can get what you want in University life"<<endl;
       cout<<"Choose three tasks you want to finish during this semester (please input the number like (1 2 3))"<<endl;
       cout<<"(1.join student associations 2.fall in love 3.gpa higher than 4 4.enjoy hall life 5.do part time job 6.";
       cout<<fac_task[fac_task_num]<<")"<<endl;
       int task;
       for (int i=0;i<3;i++){
           cin>>task;
	   player.targets[i]=task-1;
       }

       //session begin
       for (int m=0;m<3;m++){
           if (m==0){
	      cout<<"It's September 1st today!!! Semester start!!!"<<endl;
           }
	   else if (m==1){
	      cout<<"The midterm is approaching!!!"<<endl;
	   }
	   else if (m==2){
	      cout<<"Final exam will be held in two days!!!"<<endl;
	   }
	   //(FJH)Apply fuction to happen some unexpected things and their influence
           int time[4];
	   while (true){
	   cout<<"You have a total time of 20! How you decide to spend them?"<<endl;
	   cout<<"The time you decide to spend on studying: "<<endl;
	   cin>>time[0];
	   cout<<"The time you decide to spend on shopping: "<<endl;
	   cin>>time[1];
	   cout<<"The time you decide to spend on socializing: "<<endl;
	   cin>>time[2];
	   cout<<"The time you decide to spend for student associations: "<<endl;
	   cin>>time[3];
	   if (time[0]+time[1]+time[2]+time[3]==20){
	      break;
	   }
	   cout<<"the total time is wrong,please input again"<<endl;
           }
	   //(FJH)Apply functions to improve student's ability for this semester.
 
       }

       //(FJH)Apply functions to calculate if the student finish his targets tasks
       cout<<"Wow, you've finished"<<endl;
       //(FJH)cout what he has finished here
       //(FJH)Add what he has finished to the player.tasks 
       player.round=player.round+1;
       if (player.round==8){
          cout<<"Congratulations!! you graduate!"<<endl;
	  cout<<"The Academic Services Office has generated a transcript for you"<<endl;
	  print_transcript(player.tasks);
	  break;
       }
       cout<<"Do you want to exit now? (Yes/No)"<<endl;
       string answer;
       cin>>answer;
       if (answer=="Yes"){
          break;
       }
 }
 
 //I save the game here (save function found in former codes)
 if (game=="New"){
    ofstream fout;
    fout.open("memory.txt",ios::app);
    fout<<player.name<<" "<<player.faculty<<" "<<player.round<<" ";
    for (int i=0;i<3;i++){
        fout<<player.targets[i]<<" ";
    }
    for (int i=0;i<5;i++){
        fout<<player.ability[i]<<" ";
    }
    for (int i=0;i<6;i++){
        fout<<player.tasks[i]<<" ";
    }
    fout.close();
 }
 else{
    records[change]=player;
    ofstream fout;
    fout.open("memory.txt");
    for (int i=0;i<records.size();i++){
        fout<<records[i].name<<" "<<records[i].faculty<<" "<<records[i].round<<" ";
	for (int j=0;j<3;j++){
	    fout<<records[i].targets[j]<<" ";
	}
	for (int j=0;j<5;j++){
	    fout<<records[i].ability[j]<<" ";
	}
	for (int j=0;j<6;j++){
	    fout<<records[i].tasks[j]<<" ";
	}
	fout<<endl;
    
    fout.close();
    }
 }
 return 0;
 }
