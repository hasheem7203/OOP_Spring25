#include <iostream>
#include<string>
#include <sstream>
using namespace std;

string to_string(float num) {
    stringstream ss;
    ss<<num;
    return ss.str();
}

class tracker{
	private :
		string userName;
		int dailyStepGoal;
		int stepsTaken;
		float caloriesBurned;
		string progressHistory[10];
		int Index;
		void progressRecord(string entry) {
        	if (Index < 10) {
    	        progressHistory[Index] = entry;
	            Index++;
        	} else {
	            for (int i = 1; i < 10; i++) {
            	    progressHistory[i-1]=progressHistory[i];
        	    }
    	        progressHistory[9]=entry;
	        }
    }	
	public :
		tracker(string name,int stepGoal){
			userName= name;
			dailyStepGoal=stepGoal;
			stepsTaken=0;
			caloriesBurned=0;
			Index=0;
		}
		string getname(){
			return userName;
		}
		void logSteps(int steps){
			if (steps>0){
				stepsTaken+=steps;
				caloriesBurned+=steps*0.05;
				progressRecord("Steps Walked : "+to_string(steps));
				cout << "Steps Logged Successfully!\nCurrent Steps: " << stepsTaken << "\nCalories Burned: " << caloriesBurned << "\n";
			}else{
				 cout << "Invalid Step Count!" << endl;
			}	
		}
		void displayProgress(){
	        cout << "Progress Report for " << userName << "\n";
    	    cout << "Steps Taken: " << stepsTaken << " / " << dailyStepGoal << endl;
        	cout << "Calories Burned: " << caloriesBurned << "\n";
        	if (stepsTaken >= dailyStepGoal) {
        	    cout << "Congratulations! You have met your daily step goal!\n";
        	} else {
        	    cout << "Keep going! You need " << (dailyStepGoal - stepsTaken) << " more steps to reach your goal.\n";
        	}			
		}
		void displayHistory(){
	        cout << "\nProgress History:\n";
    	    for (int i =0;i<Index; i++) {
        	    cout << progressHistory[i] << endl;
        	}
        	if (Index == 0) {
        	    cout << "No progress recorded yet." << endl;
        	}			
		}
};




int main (){
	tracker lbfit("Laiba",300);
	int steps;
   
    while(1){
    	cout <<"WELCOME "<<lbfit.getname()<<endl;
		lbfit.displayProgress();
    	int choice;
    	cout<<"\n--Menu--\n";
    	cout<<"1.Log Steps\n";
    	cout<<"2.Progress History\n";
    	cout<<"3.Exit\n";
    	cout<<"--Choice : ";
    	cin>>choice;
    	switch(choice){
			case 1:{
				cout<<"\nEnter Steps To Log : ";
				cin>>steps;
				lbfit.logSteps(steps);
				break;
			}
			case 2:{
				lbfit.displayHistory();
				break;
			}
			case 3:{
				return 0;
				break;
			}
			default :{
				cout<<"Invalid Choice";
				break;
			}
		}
		system("pause");
		system("cls");
	}
    
}
