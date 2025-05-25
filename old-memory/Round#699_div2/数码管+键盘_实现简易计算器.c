#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code num[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,0x00,0x40};
uchar code loc[]={0xff,0xfe,0xfd,0xfb,0xf7};                                  
uint  n=0,n1=0,n2=0; 
//n为显示的量，n1储存当前的输入，n2储存第一个数（即输入运算符之前的数）                                                                                            
uchar flag=0,temp;// flag记录运算方式
 
void delay(int);
void display(int);

void main(){
	while(1){       
		//第一行检测
		P3=0xfe;
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0){
			delay(5);//消除抖动
			temp=P3;
			temp=temp&0xf0;
			if(temp!=0xf0){
				temp=P3;
				switch(temp){
					case 0xe0:n1=0;n2=0;n=0;flag=0;break;   //清零
					case 0xd0:n1=10*n1+0;n=n1;break;        //0
					case 0xb0:								//=
							if(flag==1)n=n2+n1;            
							if(flag==2)n=n2-n1;
							if(flag==3)n=n2*n1;
							if(flag==4)n=n2/n1;
							n1=0;break;                 											
					case 0x70:      						// +
							n2=n1;n1=0;
							flag=1;break;
				}
				while(temp!=0xf0){
					temp=P3;temp=temp&0xf0;
				}   
				delay(5);//消除抖动    
			}
		}
	
		//第二行检测
		P3=0xfd;
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0){
			delay(5);//消除抖动
			temp=P3;
			temp=temp&0xf0;
			if(temp!=0xf0){
				temp=P3;
				switch(temp){
					case 0xd0:n1=10*n1+1;n=n1;break;        //1
					case 0xd0:n1=10*n1+2;n=n1;break;        //2
					case 0xb0:n1=10*n1+3;n=n1;break;		//3				
					case 0x70:      						//-
							n2=n1;n1=0;
							flag=2;break;
				}
				while(temp!=0xf0){
					temp=P3;temp=temp&0xf0;
				}   
				delay(5);//消除抖动    
			}
		}
	
		//第三行检测
		P3=0xfb;
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0){
			delay(5);//消除抖动
			temp=P3;
			temp=temp&0xf0;
			if(temp!=0xf0){
				temp=P3;
				switch(temp){
					case 0xd0:n1=10*n1+4;n=n1;break;        //4
					case 0xd0:n1=10*n1+5;n=n1;break;        //5
					case 0xb0:n1=10*n1+6;n=n1;break;		//6				
					case 0x70:      						//*
							n2=n1;n1=0;
							flag=3;break;
				}
				while(temp!=0xf0){
					temp=P3;temp=temp&0xf0;
				}   
				delay(5);//消除抖动    
			}
		}
	
		//第四行检测
		P3=0xf7;
		temp=P3;
		temp=temp&0xf0;
		if(temp!=0xf0){
			delay(5);//消除抖动
			temp=P3;
			temp=temp&0xf0;
			if(temp!=0xf0){
				temp=P3;
				switch(temp){
					case 0xd0:n1=10*n1+7;n=n1;break;        //7
					case 0xd0:n1=10*n1+8;n=n1;break;        //8
					case 0xb0:n1=10*n1+9;n=n1;break;		//9			
					case 0x70:      						//'/'
							n2=n1;n1=0;
							flag=4;break;
				}
				while(temp!=0xf0){
					temp=P3;temp=temp&0xf0;
				}   
				delay(5);//消除抖动    
			}
		}

		display(n);
	}
}

//延时函数
void delay(uint z){
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

//数码管显示
void display(int n){   
	//溢出处理
	uchar g,s,b,q;//个十百千
	uchar flag1,cur=0xef;//flag1记录是否是负数，cur记录负号应该显示在哪里
	if(n>=0)flag1=0;
	else {flag1=1;n=-n;}
	g=n%10;s=n/10%10;
	b=n/100%10;q=n/1000%10;	
	if(q==0)cur=0xf7;
	if(b==0)cur=0xfb;
	if(s==0)cur=0xfd;

	dula=1;
	P0=num[g];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0xfe;
	wela=0;
	delay(1);

	if(n>=10){
        dula=1;
		P0=num[s];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfd;
		wela=0;
		delay(1);
	}
	if(n>=100){
        dula=1;
		P0=num[b];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfb;
		wela=0;
		delay(1);
	}
	if(n>=1000){       
        dula=1;
		P0=num[q];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xf7;
		wela=0;
		delay(1);
	}
	if(flag1){
		dula=1;
		P0=num[17];
		dula=0;
		P0=0xff;
		wela=1;
		P0=cur;
		wela=0;
		delay(1);
	}
}