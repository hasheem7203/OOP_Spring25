#include <iostream>
#include<string>
#include <sstream>
using namespace std;

#define max 100


class musicPlayer{
	private :
		string playlist[max];
		string currentSong;
		int songCount;
		int songNo;
		bool isplaying;
		
	public :
		musicPlayer(){
			songCount=0;
			isplaying =false;
		};
		void displaySong(){
			cout<<"Songs : \n";
			if(songCount>0){
				for(int i=0 ;i<songCount;i++){
					cout<<"->"<<playlist[i]<<endl;
				}
			}else{
				cout<<"Playlist Is Empty"<<endl;
			}
		}
		void add(string song){
			if(songCount<max){
				playlist[songCount]=song;
				cout<<"Song : "<<song<<" Added To The Playlist. "<<endl;
				songCount++;
			}else{
				cout<<"Not Enough Storage To Store Song In Playlist."<<endl;
			}
		}
		void remove(string song){
				for (int i =0 ;i < songCount ;i++){
					if (playlist[i]==song){
						for (int j = i; j < songCount - 1; j++) {
            	        	playlist[j] = playlist[j + 1];
	               		}
						cout<<"Song "<<song<<" Removed Successfully "<<endl;
						songCount--;
						return;
					}
				}
				cout <<"Song Not Found "<<endl;
		}
		void play(string song){
				for (int i =0 ;i < songCount ;i++){
					if (playlist[i]==song){
						songNo=i;
						isplaying=true;
						cout<<"Song "<<song<<" Is Being Played Currently "<<endl;
						return;
					}
				}
			cout <<"Song Not Found "<<endl;
		}
		void playing(){
			if (isplaying){
				cout<<"Song "<<playlist[songNo]<<" Is Being Played Currently "<<endl;
				}
		}
		void stop(){
			if(isplaying){
				isplaying=false;
				cout << "Playback stopped." << endl;
			}else{
				cout << "No Song Is Being Played Currently."<<endl;
			}
		}
		
		
};




int main (){
	musicPlayer mp3;
   
    while(1){
    	mp3.playing();
    	int choice;
    	cout<<"1.Add Song \n";
    	cout<<"2.Remove Song \n";
    	cout<<"3.Play Song\n";
    	cout<<"4.Stop Playing\n";
    	cout<<"5.Exit\n";
    	cout<<"--Choice : ";
    	cin>>choice;
    	cin.ignore();
    	switch(choice){
    		case 1:{
    			string song;
    			cout<<"Enter Song Name : ";
    			getline(cin,song);
    			mp3.add(song);
				break;
			}
			case 2:{
				string song;
				mp3.displaySong();
				cout<<"Enter Song Name To Be Removed : ";
				getline(cin,song);
				mp3.remove(song);
				break;
			}
			case 3:{
				string song;
				mp3.displaySong();
				cout<<"Enter Song Name To Be Played : ";
				getline(cin,song);
				mp3.play(song);
				
				break;
			}
			case 4:{
				mp3.stop();
				break;
			}
			case 5:{
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
