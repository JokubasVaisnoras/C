#include<stdlib.h>
#include<stdio.h>
int thirdMax(int* nums, int numsSize);
int *bubbleSort(int arr[], int n);
void swap(int *xp, int *yp) ;
int *clean (int *array,int *size);

int main(){
    int array[]={-2147483648,1,1}, array_size=3,third;
    third=thirdMax(array,array_size);
    for(int i=0; i<array_size; i++){
        printf("%d\n",array[i]);
    }

    printf("%d",third);
}

int thirdMax(int* nums, int numsSize){
    nums=bubbleSort(nums,numsSize);
    nums=clean(nums,&numsSize);

    if(numsSize>=3){
        return nums[2];
    }
    else{
        return nums[0];
    }
    

}

int *clean (int *array,int *size){
    int *right_array=(int*)malloc(*size*sizeof(int));
    int c=0;
    
    for(int i=0; i<*size; i++){
        int found=0;
        for(int j=0; j<*size; j++){
            if(right_array[j]==array[i])
             found++;
        }
        if(found==0){
        right_array[c]=array[i];
        c++;
        }

    }
    right_array=(int*)realloc(right_array,sizeof(int)*c);
    *size=c;
    return right_array;
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
int *bubbleSort(int arr[], int n) 
{ 

   for (int i = 0; i < n-1; i++)           
       for (int j = 0; j < n-i-1; j++)  
           if (arr[j] < arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 

    return arr;          
} 