#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <stdlib.h> 
#include <vector>
#include <conio.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Random{
  	protected:
  	int random, r;
  	
  	public:
    int get_random(){
    	random=rand()%r; 
	  	return random;
    }
};

class Cloud1:public Random{
  	public:
  	void cloud(){
  		r=5;
    }
};
class Cloud2:public Random{
  	public:
  	void cloud(){
  		r=3;
    }
};
class Cloud3:public Random{
  	public:
  	void cloud(){
  		r=6;
    }
};
class Cloud4:public Random{
  	public:
  	void cloud(){
  		r=7;
    }
};
class Obstacle:public Random{
  	public:
  	void obstacle(){
  		r=3;
    }
};
   
char Table(int var);
void Sleep(int milliseconds);

int main(){
	int c_rand, o_rand, k=0, lvl=0, jmp=0, length=0, level=0, jumps=0, distance=0, quit=0, br=0, w=0, obstacles[50]={}, jump[50]={}, win=0;
	int count1=0, count2=0, count3=0, count4=0, count5=0;
	
	srand (time(NULL));
	
	vector<int> cloud1;
	vector<int> cloud2;
	vector<int> cloud3;
	vector<int> cloud4;
	vector<int> obstacle;
	Cloud1 c1;
	Cloud2 c2;
	Cloud3 c3;
	Cloud3 c4;
	Obstacle o;

	//-----Pradzios ekranas-----
while(1){
	if(quit>0) break;
	br=0;
	char choice;
	while(1){
		system("cls");
		cout<<endl<<endl<<"      ";
		cout<<"                C O N T R O L S"<<endl;
		cout<<"      ";
		cout<<Table(201);
		for(int i=0; i<44; i++){
			if(i==16 || i==31) cout<<Table(203);
			else cout<<Table(205);
		} 
		cout<<Table(187)<<endl;
		cout<<"      "<<Table(186)<<"  SPACE - Jump  "<<Table(186)<<"  R - Return  "<<Table(186)<<"  E - Exit  "<<Table(186)<<endl;
		cout<<"      "<<Table(200);
		for(int i=0; i<44; i++){
			if(i==16 || i==31) cout<<Table(202);
			else cout<<Table(205);
		} 
		cout<<Table(188)<<endl;
		cout<<endl<<endl<<"      CHOSE HOW TO PLAY"<<endl<<endl;
		cout<<"      Type in 1 to play"<<endl;
		cout<<"      Type in 2 to let computer play"<<endl<<endl;
		cout<<"      Type in E to exit"<<endl<<endl;
		cin>>choice;
		if((int)choice==69 || (int)choice==101){
			quit++;
			break;
			
		}
		else if((int)choice!=49 && (int)choice!=50) {
			system("cls");
     		cout<<endl<<endl<<"      CHOOSE 1 OR 2"<<endl<<endl;
     		Sleep(2000);
		}
		else if((int)choice==49 || (int)choice==50) break;
	}
	
	for(int i=0; i<50; i++){
		c1.cloud();
		c_rand=c1.get_random();
		
		if(c_rand==0){
			cloud1.push_back(176);
		}
		else cloud1.push_back(' ');
	}
	for(int i=0; i<50; i++){
		c2.cloud();
		c_rand=c2.get_random();
		
		if(c_rand==0){
			cloud2.push_back(176);
		}
		else cloud2.push_back(' ');
	}
	for(int i=0; i<50; i++){
		c3.cloud();
		c_rand=c3.get_random();
		
		if(c_rand==0){
			cloud3.push_back(176);
		}
		else cloud3.push_back(' ');
	}
	for(int i=0; i<50; i++){
		c4.cloud();
		c_rand=c4.get_random();
		
		if(c_rand==0){
			cloud4.push_back(176);
		}
		else cloud4.push_back(' ');
	}
	
	for(int i=0; i<25; i++) obstacle.push_back(' ');
	while(1){
		o.obstacle();
		o_rand=o.get_random();
		if(o_rand==0){
			obstacle.push_back(178);
			w++;
			obstacle.push_back(' ');
		}
		else obstacle.push_back(' ');
		if(w==5){
			for(int i=0; i<3; i++){
				obstacle.push_back(' ');
			}
			obstacle.push_back(178);
			w++;
			obstacle.push_back(' ');
		}
		else if(w==10){
			for(int i=0; i<4; i++){
				obstacle.push_back(' ');
			}
			obstacle.push_back(178);
			w++;
			obstacle.push_back(' ');
		}
		else if(w==15){
			for(int i=0; i<5; i++){
				obstacle.push_back(' ');
			}
			obstacle.push_back(178);
			w++;
			obstacle.push_back(' ');
		}
		else if(w==20){
			for(int i=0; i<5; i++){
				obstacle.push_back(' ');
			}
			obstacle.push_back(178);
			w++;
			obstacle.push_back(' ');
		}
		else if(w==25){
			obstacle.push_back(' ');
			obstacle.push_back(' ');
			obstacle.push_back(' ');
			obstacle.push_back(' ');
			break;
		}
	}
	
	length=obstacle.size();

	for(int i=0; i<50; i++){
		jump[i]=' ';
	} 	
	
	k=15;
	//-----Pradzios ekranas-----

	if(choice==49) while(1){
		
		system("cls"); 
		if(quit>0) break;
	

		if(jmp>0){
			jmp=0;
			jump[15]=' ';
		}	

		if(_kbhit()){
            char current=_getch();
            
            if(current==82 || current=='r') break;
            if(current==69 || current=='e') quit++;		
           	if(current==32){
           		jumps++;
           		jmp++;
           		for(int i=0; i<50; i++){
           			if(i==15) jump[15]=Table(254);
           			else jump[i]=' ';
           		}
				for(int i=0; i<50; i++){
					obstacles[i]=obstacle[i];
					
					if(i==16 && obstacles[i]==178){
						br++;
					}
				}
			}
			else{
				for(int i=0; i<50; i++){
					obstacles[i]=obstacle[i];
					if(i==15 && obstacles[i]==' ') obstacles[i]=Table(254);
				}
			}
			if(br!=0){
				system("cls"); 
				break;
			}
    	}
    	else{
            for(int i=0; i<50; i++){
				obstacles[i]=obstacle[i];
				if(i==15 && obstacles[i]==' '){ 
					obstacles[i]=Table(254);
				}
				if(i==15 && obstacles[i]==178){
					br++;
				}
			}
			if(br!=0){
				system("cls"); 	
				break;
			}
		}
		
		cout<<endl<<endl<<"      ";
		cout<<Table(201);
		for(int i=0; i<50; i++){
			cout<<Table(205);
		}
		cout<<Table(187)<<endl;
		
		cloud1.push_back(cloud1[0]);
		cloud1.erase(cloud1.begin());
		cloud2.push_back(cloud2[0]);
		cloud2.erase(cloud2.begin());
		cloud3.push_back(cloud3[0]);
		cloud3.erase(cloud3.begin());
		cloud4.push_back(cloud4[0]);
		cloud4.erase(cloud4.begin());
		
		for(int i=0; i<10; i++){
			cout<<"      ";
			cout<<Table(186);
			
			if(i==0){
				for(int j=0; j<50; j++){
					cout<<(char)cloud1[j];	
				}
			}
			else if(i==1){
				for(int j=0; j<50; j++){
					cout<<(char)cloud2[j];	
				}
			}
			else if(i==2){
				for(int j=0; j<50; j++){
					cout<<(char)cloud3[j];	
				}
			}
			else if(i==3){
				for(int j=0; j<50; j++){
					cout<<(char)cloud4[j];	
				}
			}
			else if(i==5){
				for(int j=0; j<50; j++){
					if(j==15) cout<<(char)jump[j];
					else cout<<" ";
				} 
			} 
			else if(i==6){
				if(obstacles[15]==178) lvl++;
				for(int j=0; j<50; j++) cout<<(char)obstacles[j];
			}
			else if(i==7){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else if(i==8){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else if(i==9){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else if(i==10){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else for(int j=0; j<50; j++) cout<<" ";
			cout<<Table(186)<<endl;
		}
		cout<<"      ";
		cout<<Table(204);
		for(int i=0; i<50; i++){
			if(i==15 || i==30) cout<<Table(203);
			else cout<<Table(205);
		}
		
		distance=1.0*k/length*100-10;

		if(lvl<=5) level=1;
		else if(lvl<=10) level=2;
		else if(lvl<=15) level=3;
		else if(lvl<=20) level=4;
		else level=5;
		if(lvl==25) win++;
		
		if(jmp>0 && level==1) count1++;
		if(jmp>0 && level==2) count2++;
		if(jmp>0 && level==3) count3++;
		if(jmp>0 && level==4) count4++;
		if(jmp>0 && level==5) count5++;

		cout<<Table(185)<<endl;
		cout<<"      ";
		cout<<Table(186);
		cout<<"   LEVEL - "<<level<<"   "<<Table(186);
		if(jumps<10) cout<<"   JUMPS - "<<jumps<<"  "<<Table(186);
		else if(jumps>=10) cout<<"  JUMPS - "<<jumps<<"  "<<Table(186);
		if(distance<10) cout<<"   DISTANCE - "<<distance<<"%   "<<Table(186)<<endl;
		else if(distance>=10 && distance<100) cout<<"  DISTANCE - "<<distance<<"%   "<<Table(186)<<endl;
		else cout<<"  DISTANCE - "<<distance<<"%  "<<Table(186)<<endl;
		cout<<"      ";
		cout<<Table(200);
		for(int i=0; i<50; i++){
			if(i==15 || i==30) cout<<Table(202);
			else cout<<Table(205);
		}
		cout<<Table(188);
		k++;
		obstacle.erase(obstacle.begin());
		if(level==1) Sleep(600);
		if(level==2) Sleep(500);
		if(level==3) Sleep(400);
		if(level==4) Sleep(300);
		if(level==5) Sleep(200);
		
		if(k==length) break;
	}
//-----Zaidzia kompiuteris-----
	if(choice==50) while(1){
		system("cls"); 
		if(quit>0) break;
		
		if(jmp>0){
			jmp=0;
			jump[15]=' ';
		}	
		
		for(int i=0; i<50; i++){
          	obstacles[i]=obstacle[i];
          	if(i==15 && obstacles[i]==' ') obstacles[i]=Table(254);
    	}
		
		if(jmp==0 && obstacles[15]==178){
			jumps++;
          	jmp++;
          	for(int i=0; i<50; i++){
           		if(i==15) jump[15]=Table(254);
           		else jump[i]=' ';
           	}
           	obstacles[16]==' ';
		}
		
		
		if(_kbhit()){
            char current=_getch();
            
            if(current==82 || current=='r') break;
            if(current==69 || current=='e') quit++;		

			else{
				for(int i=0; i<50; i++){
					obstacles[i]=obstacle[i];
					if(i==15 && obstacles[i]==' ') obstacles[i]=Table(254);
				}
			}
    	}


		
		cout<<endl<<endl<<"      ";
		cout<<Table(201);
		for(int i=0; i<50; i++){
			cout<<Table(205);
		}
		cout<<Table(187)<<endl;
		
		cloud1.push_back(cloud1[0]);
		cloud1.erase(cloud1.begin());
		cloud2.push_back(cloud2[0]);
		cloud2.erase(cloud2.begin());
		cloud3.push_back(cloud3[0]);
		cloud3.erase(cloud3.begin());
		cloud4.push_back(cloud4[0]);
		cloud4.erase(cloud4.begin());
		
		for(int i=0; i<10; i++){
			cout<<"      ";
			cout<<Table(186);
			
			
			if(i==0){
				for(int j=0; j<50; j++){
					cout<<(char)cloud1[j];	
				}
			}
			else if(i==1){
				for(int j=0; j<50; j++){
					cout<<(char)cloud2[j];	
				}
			}
			else if(i==2){
				for(int j=0; j<50; j++){
					cout<<(char)cloud3[j];	
				}
			}
			else if(i==3){
				for(int j=0; j<50; j++){
					cout<<(char)cloud4[j];	
				}
			}
			else if(i==5){
				for(int j=0; j<50; j++){
					if(j==15) cout<<(char)jump[j];
					else cout<<" ";
				} 
			} 
			else if(i==6){
				if(obstacles[15]==178) lvl++;
				for(int j=0; j<50; j++) cout<<(char)obstacles[j];
			}
			else if(i==7){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else if(i==8){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else if(i==9){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else if(i==10){
				for(int j=0; j<50; j++) cout<<Table(177);
			}
			else for(int j=0; j<50; j++) cout<<" ";
			cout<<Table(186)<<endl;
		}
		cout<<"      ";
		cout<<Table(204);
		for(int i=0; i<50; i++){
			if(i==15 || i==30) cout<<Table(203);
			else cout<<Table(205);
		}
		
		distance=1.0*k/length*100;

		if(lvl<=5) level=1;
		else if(lvl<=10) level=2;
		else if(lvl<=15) level=3;
		else if(lvl<=20) level=4;
		else level=5;
		if(lvl==25) win++;
		
		if(jmp>0 && level==1) count1++;
		if(jmp>0 && level==2) count2++;
		if(jmp>0 && level==3) count3++;
		if(jmp>0 && level==4) count4++;
		if(jmp>0 && level==5) count5++;

		cout<<Table(185)<<endl;
		cout<<"      ";
		cout<<Table(186);
		cout<<"   LEVEL - "<<level<<"   "<<Table(186);
		if(jumps<10) cout<<"   JUMPS - "<<jumps<<"  "<<Table(186);
		else if(jumps>=10) cout<<"  JUMPS - "<<jumps<<"  "<<Table(186);
		if(distance<10) cout<<"   DISTANCE - "<<distance<<"%   "<<Table(186)<<endl;
		else if(distance>=10 && distance<100) cout<<"  DISTANCE - "<<distance<<"%   "<<Table(186)<<endl;
		else cout<<"  DISTANCE - "<<distance<<"%  "<<Table(186)<<endl;
		cout<<"      ";
		cout<<Table(200);
		for(int i=0; i<50; i++){
			if(i==15 || i==30) cout<<Table(202);
			else cout<<Table(205);
		}
		cout<<Table(188);
		k++;
		obstacle.erase(obstacle.begin());
		if(level==1) Sleep(400);
		if(level==2) Sleep(300);
		if(level==3) Sleep(200);
		if(level==4) Sleep(100);
		if(level==5) Sleep(50);
		
		if(k==length) break;
	}
	distance++;

	if(br>0){
		while(1){
			system("cls"); 	
			cout<<endl<<endl<<"             YOU LOST"<<endl<<endl;
			cout<<"            YOUR SCORE"<<endl;
			cout<<"      "<<Table(201);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(187)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"   Reached  level   "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"      Level - "<<level<<"     "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(204);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(185)<<endl;
			cout<<"      ";
			if(jumps<10) cout<<Table(186)<<"     Jumps - "<<jumps<<"      "<<Table(186)<<endl;
			else cout<<Table(186)<<"     Jumps - "<<jumps<<"     "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(204);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(185)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"  Number of jumps:  "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     1 lvl. - "<<count1<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    1 lvl. - "<<count1<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     2 lvl. - "<<count2<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    2 lvl. - "<<count2<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     3 lvl. - "<<count3<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    3 lvl. - "<<count3<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     4 lvl. - "<<count4<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    4 lvl. - "<<count4<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     5 lvl. - "<<count5<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    5 lvl. - "<<count5<<"     "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(204);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(185)<<endl;
			cout<<"      ";
			if(distance<10) cout<<Table(186)<<"    Distance - "<<distance<<"%   "<<Table(186)<<endl;
			else if(distance<100) cout<<Table(186)<<"   Distance - "<<distance<<"%   "<<Table(186)<<endl;
			else cout<<Table(186)<<"  Distance - "<<distance<<"%   "<<Table(186)<<endl;
			cout<<"      "<<Table(200);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(188)<<endl;
			if(_kbhit()) break;
			Sleep(1000);
		}
	}
	if(win>0){
		while(1){
			system("cls"); 	
			cout<<endl<<endl<<"             YOU WON!"<<endl<<endl;
			cout<<"            YOUR SCORE"<<endl;
			cout<<"      "<<Table(201);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(187)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"   Reached  level   "<<Table(186)<<endl<<"      "<<Table(186)<<"       FINISH       "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(204);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(185)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"     Jumps - "<<jumps<<"     "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(204);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(185)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"  Number of jumps:  "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     1 lvl. - "<<count1<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    1 lvl. - "<<count1<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     2 lvl. - "<<count2<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    2 lvl. - "<<count2<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     3 lvl. - "<<count3<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    3 lvl. - "<<count3<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     4 lvl. - "<<count4<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    4 lvl. - "<<count4<<"     "<<Table(186)<<endl;
			cout<<"      ";
			if(count1<10) cout<<Table(186)<<"     5 lvl. - "<<count5<<"     "<<Table(186)<<endl;
			else cout<<Table(186)<<"    5 lvl. - "<<count5<<"     "<<Table(186)<<endl;
			cout<<"      ";
			cout<<Table(204);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(185)<<endl;
			cout<<"      ";
			cout<<Table(186)<<"  Distance - "<<distance<<"%   "<<Table(186)<<endl;
			cout<<"      "<<Table(200);
			for(int i=0; i<20; i++) cout<<Table(205);
			cout<<Table(188)<<endl;
			if(_kbhit()) break;
			Sleep(1000);
		}
	}


	
	c_rand=0, o_rand=0, k=0, lvl=0, jmp=0, length=0, level=0, jumps=0, distance=0, br=0, w=0, win=0, count1=0, count2=0, count3=0, count4=0, count5=0;
	
	fill_n(obstacles, 50, 0);
	fill_n(jump, 50, 0);
	
	obstacle.clear();
	cloud1.clear();
	cloud2.clear();
	cloud3.clear();
	cloud4.clear();
	
	
} //ciklas
	system("cls"); 
	cout<<endl<<endl<<"      THANKS FOR PLAYING"<<endl<<endl;
	return 0;
} //main
char Table(int var){
	char symbol;
	symbol=(char)var;
	return symbol;
}
void Sleep(int milliseconds){
    clock_t time_end;
    time_end=clock()+milliseconds*CLOCKS_PER_SEC/1000;
    while(clock()<time_end){}
}

