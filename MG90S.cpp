#include<stdio.h>
#include<wiringPi.h>
#include<unistd.h>
void init();
void rotate(int angle);
void lock();
void unlock();
void setBatteryTime();
int i;
int x=1;
int main() {
	init();
	int mode;
	while(1){
	printf("选择功能\n\t1.解锁\n\t2.锁定\n\t3.设置时间（以时为单位）		\n");
	scanf("%d",&mode);
	switch(mode){
		case 1:unlock();break;
		case 2:lock();break;
		case 3:setBatteryTime();break;
	}	
	}
	return 0;

}

void setBatteryTime(){
float time;
printf("请输入充电时间，以h为单位\n");
scanf("%f",&time);
time=time*3600;
if(i!=90)
	lock();
sleep(time);
unlock();
}

void init() {
        wiringPiSetup();
        pinMode(1,OUTPUT);
}
void rotate(int angle){
	if(x==1){
	i=90;
	int k=190;
	while(k>0)
	{
		digitalWrite(1,HIGH);
		delayMicroseconds(1000);
		digitalWrite(1,LOW);
		delayMicroseconds(20000-90*11.11);
		k--;
	}
	}
	if(i!=angle){
		if(i<angle)
			for(i;i<=angle;i+=2){
				digitalWrite(1,HIGH);
				delayMicroseconds(i*11.11);
				digitalWrite(1,LOW);
				delayMicroseconds(20000-i*11.11);
				}
		else
			for(i;i>=angle;i-=2){
				digitalWrite(1,HIGH);
				delayMicroseconds(i*11.11);
				digitalWrite(1,LOW);
				delayMicroseconds(20000-i*11.11);
				}	
	}
	else
		return;
	x++;
}

void unlock(){
	rotate(90);
}
void lock(){
	rotate(180);
}

