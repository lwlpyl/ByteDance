/**
字节跳动2019春招后端开发3月16日笔试题

第二题:
规则： 
1.三个同样的字母连在一起，一定是拼写错误，去掉一个就好了。比如:helllo --> hello
2.两对一样的字母(AABB型)连在一起，一定是拼写错误，去掉第二对的第一个字母。比如:helloo --> hello
3.上面的规则优先从左到右匹配，即如果是AABBCC型，应优先考虑修复AABB为AABCC。
输入：
一串字符串
输出：
修正后的字符串 

求解思路：遍历一次字符串即可 
**/

#include<stdio.h>

#define S 1000000

int check(char str[]){
	int i = 0;
	int j;
	int count1 = 0; //规则1，三个同样的字母连续 
	int count2 = 0; //规则2，两对一样的字母连在一起  
	int aa = 0;
	
	while(str[i]!='\0'){
		if(i==0){
			count1 = 1;
			count2 = 0; 
			aa = 0;
		}else{
			if(str[i]==str[i-1]){
				count1++;
				if(count1==2){
					aa = 0;
					count2++;
				}
			}else{
				count1 = 1;
				aa++;
				if(aa==2){
					count2 = 0;
				}
			}
		}
		if(count1==3){
			j = i;
			while(str[j+1]!='\0'){
				str[j] = str[j+1];
				j++;	
			}
			str[j] = '\0';
			i = i-2;
			count1 = 1;
			count2 = 0; 
			aa = 0;
			continue;
		}
		if(count2==2){
			j = i;
			while(str[j+1]!='\0'){
				str[j] = str[j+1];
				j++;	
			}
			str[j] = '\0';
			i = i-3;
			count1 = 1;
			count2 = 0; 
			aa = 0;
			continue;
		}
		i++;	
	}
}

int main(){
	int n;
	char str[S];
	int i;
	int flag;
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", str);
		check(str);
		printf("%s\n", str);
	}
	
	return 0;
} 
