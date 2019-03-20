/**
字节跳动2019春招后端开发3月16日笔试题
 
第一题： 
某国货币系统包含面值1元，4元，16元，64元共计4种硬币，以及面值1024元的纸币。
现在某人使用1024元的纸币购买了一件价格为N(0≤N≤1024)的商品。
请问最少他会收到多少枚硬币?

求解思路：贪心算法 
**/

#include<stdio.h>

int main(){
	int n;
	int z;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	
	scanf("%d", &n);
	z = 1024-n;
	while(z>=64){
		z = z-64;
		count1++;
	}
	while(z>=16){
		z = z-16;
		count2++;
	}
	while(z>=4){
		z = z-4;
		count3++;
	}
	while(z>=1){
		z = z-1;
		count4++;
	}
	printf("%d", count1+count2+count3+count4);
	
	return 0;
} 
