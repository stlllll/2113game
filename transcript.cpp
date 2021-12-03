// transcript.cpp
#include <iostream>
#include <string>
#include "transcript.h"
using namespace std;
void print_transcript(int a[]){
   
     int top[6]={8,8,8,8,8,8};
     int j=0;

     for (int i=0;i<6;i++){
         if (a[i]>a[j]){
	    j=i;
	 }
     }	
     top[0]=j;
     int k=0;
     for (int i=0;i<6;i++){
         if (a[i]==a[j]){
	    top[k]=i;
	    k=k+1;
	 }
     }
     cout<<"-------------------------------------"<<endl;
     cout<<"|                                   |"<<endl;
     cout<<"|                                   |"<<endl;
     cout<<"|    The University of Hong Kong    |"<<endl;
     cout<<"|            Transcript             |"<<endl;
     cout<<"|                                   |"<<endl;
     cout<<"|          UID:3031234567           |"<<endl; 
     if (a[top[0]]<=3){
     cout<<"|  Work harder in your future life! |"<<endl;
     cout<<"|      Your performance is bad      |"<<endl;
     cout<<"|                                   |"<<endl;
     cout<<"|                                   |"<<endl;
     cout<<"|                                   |"<<endl;
     for (int i=0;i<10;i++){
     cout<<"|                                   |"<<endl;
     }
     }
     else {
          for (int i=0;i<6;i++){
	  if (top[i]==0){
     cout<<"| You have held lots of activities! |"<<endl;
     cout<<"| They made students' life colorful |"<<endl;
     cout<<"|                                   |"<<endl;
	  }
	  if (top[i]==1){
     cout<<"| Your college life is so romantic! |"<<endl;
     cout<<"|                                   |"<<endl;
	  }
	  if (top[i]==2){
     cout<<"|     You studied quite well!!!     |"<<endl;
     cout<<"|            CGPA:4.23              |"<<endl;
     cout<<"|   MIT will give you phd offer     |"<<endl;
     cout<<"|                                   |"<<endl;
	  }
	  if (top[i]==3){
     cout<<"|  Your life in HKU is full of joy  |"<<endl;
     cout<<"|  You made lots of friends in hall |"<<endl;
     cout<<"|                                   |"<<endl;
	  }
	  if (top[i]==4){
     cout<<"|  You apply your knowledge well!!  |"<<endl;
     cout<<"|   A great company will hire you   |"<<endl;
     cout<<"|                                   |"<<endl;
	  }
	  if (top[i]==5){
     cout<<"| You understand your major deeply! |"<<endl;
     cout<<"|                                   |"<<endl;
	  }
	  }
     for (int i=0;i<6;i++){
     cout<<"|                                   |"<<endl;
     }
     cout<<"|       It's excellent of you!      |"<<endl;
     cout<<"|      Wish you a bright future     |"<<endl;
     }
     cout<<"|                                   |"<<endl;
     cout<<"-------------------------------------"<<endl;
}
