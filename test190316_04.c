/**
字节跳动2019春招后端开发3月16日笔试题

第四题:
有N根绳子，第i根长为Li，现需要m根等长绳子。
你可以对N根绳子进行任意剪裁(不能拼接)，计算出这m根绳子最长的长度是多少?

求解思路：二分法 
**/ 

#include<stdio.h>

#define N 100000

// 判断能截成多少段 
int check(int n, int len[], double mid){
	int sum = 0;
	int i;
	for(i=0; i<n; i++){
		sum += len[i]/mid;
	}
	return sum;
}

double getAns(int n, int m, int len[]){
	double ans = 0;
	double max = 0; // 最长的那根绳子的长度 
	int i;
	double l, r, mid;
	
	for(i=1; i<n; i++){
		if(len[i]>max){
			max = len[i];
		}
	} 
	
	// 二分法 
	l = 0;
	r = max;
	while((r-l)>1e-4){
		mid = (l+r)/2;
		if(mid==0){
			break;
		}
		if(check(n, len, mid)>=m){
			l = mid;
			ans = mid;
		} else{
			r = mid;
		}
	}
	
	return ans;
}

int main(){
	double ans;
	int n, m;
	int len[N];
	int i;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d", &len[i]);
	}
	ans = getAns(n, m, len);
	printf("%0.2lf", ans);
	
	return 0;
} 
