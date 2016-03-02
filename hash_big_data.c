#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bitValue[] = {  
	        0x80000000,
	        0x40000000, 
	        0x20000000, 
	        0x10000000, 
	        0x08000000,  
	        0x04000000, 
	        0x02000000, 
	        0x01000000, 
	        0x00800000, 
	        0x00400000,  
	        0x00200000, 
	        0x00100000,
	        0x00080000,  
	        0x00040000,  
	        0x00020000, 
	        0x00010000,      
	        0x00008000, 
	        0x00004000,
	        0x00002000, 
	        0x00001000, 
	        0x00000800,
	        0x00000400,  
	        0x00000200,
	        0x00000100, 
	        0x00000080,
	        0x00000040,
	        0x00000020,
	        0x00000010,  
	        0x00000008, 
	        0x00000004, 
	        0x00000002, 
	        0x00000001       
	    };  
int datalength;
int* bits;

void  bitArray(int length) 
{  
	if(length < 0)
	{  
	   printf("length必须大于零!\n");
	}  
	bits=(int*)malloc(length/32+(length%32>0?1:0));
	datalength=length;
}  

int getBit(int index)
{  
	if(index<0||index>datalength)
	{  
		printf("长度必须大于零小于\n");	    
	}  
	int intData = bits[index/32]; 	      
	return (intData&bitValue[index%32])>>(32-index%32 -1);  
} 

 void setBit(int index,int value)
 {  
	if(index <0 || index > datalength)
	{
		printf("长度必须大于零小于\n");	         
	}         
	if(value!=1&&value!=0)
	{  
		printf("数组值必须为0或者1\n");
	}  
	int intData=bits[index/32];   //intData=0
	if(value == 1)
	{  
	    bits[index/32]=intData|bitValue[index%32]; 
	    //bits[13503]  =   0| bitvalue[16]    
	}
	else
	{  
	    bits[index/32]=intData&~bitValue[index%32];  
	}  
}  

int main(int argc, char const *argv[])
{	
	bitArray(100000);
	char phoneNum[]="13520";////13573228432
    char destNum[20];//只是随意写了个数组长度,应该根据计算指定数组长度
    strcpy(destNum,phoneNum+3);
    char p;
    int i=0;
    int num;
    int dnum=0;
    //这里需要再写一个函数将字符数组转换成整数
    while(1)
    {
    	if(destNum[i]=='\0')
    		break;
    	p=destNum[i];
    	num=p-'0';    	
        dnum=dnum*i*10+num;       
    	i++;
    }   
    printf("dnum=%d\n", dnum);
	setBit(dnum,1);  
	for(i=0;i<100000;i++)
	{
		//这里需要继续改进
	   if(getBit(i)==1)
	   {
	   	  printf("ret=%d\n",i);		  
	   }
	}
	return 0;
}
