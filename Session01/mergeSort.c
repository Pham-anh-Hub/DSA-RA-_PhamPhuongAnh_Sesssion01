#include<stdio.h>



void merge(int arr[], int start, int mid, int end){
//	B1. Tao ra 2 mang con ben trai va ben phai
// 	i: chi so cua mang con ben trai
// 	j: chi so cua mang con ben phai
// 	k: chi so cua mang cha
	int i, j, k;
	int leftArrSize = mid - start + 1;
	int rightArrSize = end - mid;
	int leftArr[leftArrSize], rightArr[rightArrSize];
	
//	B2.Sao chep cac gia tri tu mang cha vao mang con
	for(i=0; i<leftArrSize; i++){
		leftArr[i] = arr[start + i];
	}
	for(j=0; j<rightArrSize; j++){
		rightArr[j] = arr[mid + j + 1];
	}
//	B3. Tron 2 mang con lai trong mang cha
	i=0, j=0, k=start;
		// Duyet qua 2 mang con da duoc tach
	while(i < leftArrSize && j < rightArrSize){
		if(leftArr[i] <= rightArr[j]){
			// So sanh 2 phan tu cua 2 mang con do voi nhau
			arr[k] = leftArr[i];
			i++;
		}else{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	
//	Kiem tra va duyet lai cac phan tu con sot lai (vi 2 phan mang ben trai va phai co the so luong khac nhau)
	
	while(i<leftArrSize){
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while(j<rightArrSize){
		arr[k] = rightArr[j];
		j++;
		k++;
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
	int number[5] = {87, 20,13, 82, 6};
	merge_sort(number, 0, 4); 
	for(int i=0; i<5;i++){
		printf("%d ", number[i]);
	}
	return 0;
}

