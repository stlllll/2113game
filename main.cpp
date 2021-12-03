//This is the main program
#include <iostream>
#include <fstream>
#include <string>
#include "transcript.h"
#include "print_tasks.h"
#include <vector>
#include <cstdlib>
#include <ctime>
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
 
   student player("a");  //randomly defined, to avoid bugs, no need to worry
 
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

      //(FJH)Apply a function for player to choose a faculty for the student
	   while (true){
		   cout<<"Please choose your faculty by type in number: "<<endl;
	           cout<<"1. Science Faculty"<<endl;
		   cout<<"2. Engineering Faculty"<<endl;
		   cout<<"3. Law Faculty"<<endl;
	           cout<<"4. Bussiness Faculty"<<endl;
		   cout<<"5. Art Facuty"<<endl;
		   cout<<"6. Social Science Faculty"<<endl;
		   string faculty_num;
		   cin>>faculty_num;
		   if (faculty_num=="1"){player.faculty="science"; break;}
		   else if (faculty_num=="2"){player.faculty="engineering"; break;}
		   else if (faculty_num=="3"){player.faculty="law"; break;}
		   else if (faculty_num=="4"){player.faculty="business"; break;}
		   else if (faculty_num=="5"){player.faculty="art"; break;}
		   else if (faculty_num=="6"){player.faculty="social science"; break;}
		   else {cout<<"Wrong input! Think again before you choose your faculty. Note that you need to type in number but not alphabet"<<endl;}
	   }
      //The end of this faculty choosing function	   
	   
      player.name=name;
      player.round=0;
      cout<<"Please choose a background for the character: (Local/India/Mainland/Korea)"<<endl;
      string background;
      
      //(FJH)Apply a function to initialize the ability for the student basing on his/her background
      while  (true){
      cin>>background;
      if (background=="Local"){
      player.ability[3]=player.ability[3]+5;
      break;}
      else if (background=="Mainland"){
      player.ability[1]=player.ability[1]+5;
      break;}
      else if (background=="India"){
      player.ability[0]=player.ability[0]+5;
      break;}
      else if (background=="Korea"){
      player.ability[2]=player.ability[2]+5;
      break;}
      else{cout<<"Wrong input! please input a right format background. Note that you need to type in a word with uppercase first character."<<endl;}
      }
      // end of ability initialization based on background
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
                  player.ability[i]=10;
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
         srand(time(NULL));
	 
	 for (int m=0;m<3;m++){
           if (m==0){
	      cout<<"It's September 1st today!!! Semester start!!!"<<endl;
	            }
	   else if(m==1){
	      cout<<"The midterm is approaching!!!"<<endl;
	            }
	   else{	
	      cout<<"The final exam will be held in two days!!!"<<endl;
	            }
	   int random;
	   random=rand() %10 +1;
           if (random == 1){
		      cout<<"You are rewarded for scholarship! You weatlth inceases."<<endl;
		      player.ability[4] += 5;}
	      if (random == 2){
		      cout<<"You made a new friend. Remember, friends are the family you choose. You are more social than before."<<endl;
	      		player.ability[3]+=5;}
	      if (random== 2){
		      cout<<"You are getting more and more confident. Confidence builds your charm."<<endl;
	      		player.ability[2]+=5;}
	      if (random ==3){
		      cout<<"You are inspired by the saying 'Just do it'. Your learn to execute without hesitation."<<endl;
		      player.ability[1]+=5;}
	      if (random == 4){
		      cout<<"You are learning how to learn, and you really learn something. You develop more learning ability."<<endl;
		      player.ability[0]+=5;}
	      if (random == 5){
		      cout<<"You took a test of psychology department and you won some coupons. More wealth!"<<endl;
		      player.ability[4] +=3;}
	      if (random == 6){
		      cout<<"You climbed the Victoria peak with your hallmates. You are getting more familiar with them."<<endl;
		      player.ability[3]+=3;}
	      if (random == 7){
		      cout<<"You led a group project and learnt more about execution."<<endl;
		      player.ability[2]+=3;}
	      if (random == 8){
		      cout<<"Shopping time for the Black Friday! You are less wealthy but you are more charming now."<<endl;
		      player.ability[4]-=2;
		      player.ability[2]+=5;}
	      if (random == 9){
		      cout<<"You encounter a free rider when doing group project. You have to spare some time but you learn more about execution."<<endl;
		      player.ability[0]+=5;
		      player.ability[2]-=2;}
	      if (random == 10){
		      cout<<"You drank with your friends at the seaside of Kennedy town. You get more social, but you are really sick after that."<<endl;
		      player.ability[2]+=5;
		      player.ability[1]-=3;
		      player.ability[0]-=5;}
	               
	   //(FJH)Apply fuction to happen some unexpected eventes and their influence
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
 		 
		 player.ability[0]+=time[0];
		 player.ability[1]+=time[3];
		 player.ability[3]+=time[2];
		 player.ability[2]+=time[1]*(player.ability[3]/10);
       
}
       //(FJH)Apply functions to calculate if the student finish his targets tasks
	int finish[3]={8,8,8};
	for (int i=0;i<3;i++){
	 	if (player.targets[i]==0){
	 		if ((player.ability[1]+player.ability[3])>(rand()%47)){finish[i]=0;
		player.tasks[0]=player.tasks[0]+1;	}
		                         }
		if (player.targets[i]==1){
			if (player.ability[2]>(rand()%29))
			{finish[i]=1;player.tasks[1]=player.tasks[1]+1;}
	 		                 }
		if (player.targets[i]==2){
			if ((player.ability[0]+player.ability[1])>(rand()%53))
			{finish[i]=2;player.tasks[2]=player.tasks[2]+1;}
			                 }
		if (player.targets[i]==3){
			if ((player.ability[2]+player.ability[3])>(rand()%47))
			{finish[i]=3;player.tasks[3]=player.tasks[3]+1;}
			                 }
		if (player.targets[i]==4){
			if (player.ability[1]>(rand()%23))
			{finish[i]=4;player.tasks[4]=player.tasks[4]+1;}
			                 }
	 	if (player.targets[i]==5){
	 	if (player.faculty=="science"){
	 	    if ((player.ability[0]+player.ability[1])>(rand()%53))
			{finish[i]=5;player.task[5]=player.task[5]+1;}
			}
	 	if (player.faculty=="engineering"){
			if ((player.ability[0]+player.ability[1])>(rand()%53))
			{finish[i]=5;player.task[5]=player.task[5]+1;}
	 	                                  }
	 	if (player.faculty=="law"){
			if ((player.ability[1]+player.ability[3])>(rand()%53))
			{finishi[i]=5;player.task[5]=player.task[5]+1;}
	 	                          }
		if (player.faculty=="business"){
			if ((player.ability[1]+player.ability[3]+player.ability[2]+player.ability[4])>(rand()%79))
			{finishi[i]=5;player.task[5]=player.task[5]+1;}
					  }
		if (player.faculty=="art"){
			if ((player.ability[0]+player.ability[1])>(rand()%53))
			{finish[i]=5;player.task[5]=player.task[5]+1;}
		}
	 	if (player.faculty=="social science"){
			if ((player.ability[0]+player.ability[1])>(rand()%53))
			{finish[i]=5;player.task[5]=player.task[5]+1;}
			}
	 	                                     }
	   }					     
       for (int i=0;i<3;i++){
           if (finish[i]!=8){
	      cout<<""//print what he has finished,that is ,what we stored in the "finish" array
	   }
       }
       	 
       player.round=player.round+1;
       if (player.round==8){
          cout<<"Congratulations!! you graduate!"<<endl;
	  print_tasks(player.tasks);
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
