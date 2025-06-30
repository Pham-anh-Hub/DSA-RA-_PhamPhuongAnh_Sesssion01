#include<stdio.h>



void merge(int arr[], int start, int mid, int end){
//	B1. Tao ra 2 mang con ben trai va ben phai
// i: chi so cua mang con ben trai
// j: chi so cua mang con ben phai
// k: chi so cua mang cha
	int i, j, k;
	int leftArrSize = mid - start + 1;
	int rightArrSize = end - mid;
	int leftArr[leftArrSize], rightArr[rightArr];
	
//	B2. Doi vi tri cua cac phan tu trong mang con
	for(int i=0; i<leftArrSize; i++){
		
	}
	
	
	

}

void merge_sort(int arr[], int start, int end){
	// Xay dung dieu kien dung, khi chia mang chi con 1 phan tu 
	if(start == end){
		return;
	}
//	Giai quyet cac bai con voi phan nua ben trai
	int mid = (start+end)/2;
	merge_sort(arr, start, mid);
// Giai quyet bai toan con voi phan nua ben phai
	merge_sort(arr, mid+1, end);
	
// Tron cac mang con lai (Xay dung ham tron)
	merge(arr, start, mid, end); 
	
}



int main(){

	return 0;
}

