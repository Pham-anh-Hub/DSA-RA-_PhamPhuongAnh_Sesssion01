#include<stdio.h>
int main(){
//	insertion sort

	int number[10] = {23,54,76,12,34,21,10,16};
	int n = sizeof(number)/sizeof(number[0]);
	
	for(int i=0; i<n; i++){
		int temp = number[i]; // Phan tu can chen
		int j = i - 1;
		while(j>=0 && number[j] > temp){
			number[j+1] = number[j];
			j--; 
		}
		//chen temp ve dung vi tri
		number[j+1] = temp;
	}
		
	return 0;
}

