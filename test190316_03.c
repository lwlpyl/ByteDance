/**
字节跳动2019春招后端开发3月16日笔试题

第三题： 
n个人参加比赛，结束后每个人一个分数。
领奖时所有人依次排成一圈，第一个和第n个相邻。 
要求:
1.如果某个人的分数比旁边的人高，那么奖品数量也要比他多。
2.每个至少得一个奖品。
问最少应该准备多少个奖品?

求解思路：化环为直，动态调整循环次数 
**/

#include<stdio.h>

#define N 100000

int getAns(int n, int grade[]) {
	int num[N]; //奖品数
	int sum; //奖品总数
	int i;
	int flag = 0; //数据是否发生变化 

	for(i=0; i<=n+1; i++) {
		num[i] = 1;
	}

	do {
		flag = 0;
		for(i=1; i<=n; i++) {
			// 与左边的人比 
			if(grade[i]>grade[i-1] && num[i]<=num[i-1]){
				num[i] = num[i]+1;
				flag = 1;
			}
		}
		for(i=1; i<=n; i++){
			// 与右边的人比
			if(grade[i]>grade[i+1] && num[i]<=num[i+1]){
				num[i] = num[i]+1;
				flag = 1;
			}
		}
		num[0] = num[n];
		num[n+1] = num[1];
	}while(flag==1);

	sum = 0;
	for(i=1; i<=n; i++) {
		sum += num[i];
	}

	return sum;
}

int main() {
	int ans;
	int count; //测试样例个数
	int n; //人数
	int grade[N];
	int i,j;

	scanf("%d", &count);
	for(i=0; i<count; i++) {
		scanf("%d", &n);
		for(j=1; j<=n; j++) {
			scanf("%d", &grade[j]);
		}
		
		//首尾相连 
		grade[0] = grade[n];
		grade[n+1] = grade[1];
		  
		ans = getAns(n, grade);
		printf("%d\n", ans);
	}

	return 0;
}
