#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void delay(int a){
	
	int time = a*100000000;
	for(int i=0;i<time;i++){
	}
}

int main(){
	again:
	char road = '-', finish = '|', horse = '%', play;
	
	int Numroad=10; 
	
	int NumHorse;
	//int horse[5] road_1 = Numroad, random, bet;
	
	
	int horse_1 = 1, road_1 = Numroad, random, bet;
	int horse_2 = 2, road_2 = Numroad, number = 1; 
	int horse_3 = 3, road_3 = Numroad;
	int horse_4 = 4, road_4 = Numroad;
	int horse_5 = 5, road_5 = Numroad;
	
	
	
	srand(time(0));
	random = (rand()%5)+1;
	
	cout<<"Horse Game\n";
	cout<<"Choose Horse (1-5): ";
	cin>>bet;
	
	for(int k=0; k<=4; k++){
		cout<<number;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_1; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
			number++;
		}
		cout<<endl;
	delay(5);
	system("cls");
	do{
		cout<<"Horse Game"<<endl;
		cout<<"Your Horse: "<<bet<<endl;
		if (random==horse_1){
			road_1-=2;
		}
		else if (random==horse_2) {
			road_2-=2;
		}else if (random==horse_3) {
			road_3-=2;
		}else if (random==horse_4) {
			road_4-=2;
		}else if (random==horse_5) {
			road_5-=2;
		}
		for(int k=0; k<=0; k++){
		cout<<horse_1;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_1; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_2;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_2; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_3;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_3; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_4;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_4; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_5;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_5; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		random = (rand()%5)+1;
		delay(5);
		system("cls");
		
	}while(road_1 > 0 && road_2 > 0 && road_3 > 0 && road_4 > 0 && road_5 >0);
	
	cout<<"Horse Game"<<endl;
	cout<<"Your Horse: "<<bet<<endl;
	for(int k=0; k<=0; k++){
		cout<<horse_1;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_1; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_2;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_2; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_3;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_3; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_4;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_4; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;
		}
		for(int k=0; k<1; k++){
		cout<<horse_5;
			for(int i=0; i<1; i++){
				cout<<finish;
				for(int j = 0; j<road_5; j++){
					cout<<road;	
				}
				for(int o = 0; o<1; o++){
				cout<<horse;
				}
			}
			cout<<endl;		
		}
	
	if(road_1 == 0){
		if(bet==horse_1){
			cout<<"You Won!\n";
		}else{
			cout<<"You Lose...\n";
		}
		cout<<"Horse 1 won the race";
	}else if (road_2 == 0){
		if(bet==horse_2){
			cout<<"You Won!\n";
		}else{
			cout<<"You Lose...\n";
		}
		cout<<"Horse 2 won the race";
	}else if (road_3 == 0){
		if(bet==horse_3){
			cout<<"You Won!\n";
		}else{
			cout<<"You Lose...\n";
		}
		cout<<"Horse 3 won the race";
	}else if (road_4 == 0){
		if(bet==horse_4){
			cout<<"You Won!\n";
		}else{
			cout<<"You Lose...\n";
		}
		cout<<"Horse 4 won the race";
	}else if (road_5 == 0){
		if(bet==horse_5){
			cout<<"You Won!\n";
		}else{
			cout<<"You Lose...\n";
		}
		cout<<"Horse 5 won the race";
	}
	cout<<endl;
	cout<<"Play Again?\n";
	cout<<"(Y/N)";
	cin>>play;
	system("cls");
	switch(toupper(play)){
		case 'Y':
			goto again;
			
			break;
		case 'N':
			
			break;
	}	
}
