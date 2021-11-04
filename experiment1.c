/*
date��2021/10/27
author:SouthRiver
program:����ð�����򡢹鲢���򡢿��������㷨ʱ��Ч�ʵ��о�;
compiler:Dev-c++5.11
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//��clock()��ʱ 
#include<Windows.h>

int begintime = 0;
int endtime = 0;
int arr1[100000] = { 0 };

//�������麯��;
void swap(int* a, int* b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}


//ð������;
//������ÿ�˱ȼ��н���len-1�ε������Ƚϣ���j�αȽ��н���len-j�εıȽϣ�ÿ�˽����󣬽���ֵ����;
void maopao_sort(int arr[], int len){
	int i = 0;
	for (i; i < len - 1; i++){//���ѭ����������;
		int j = 0;
		for (j; j < len - i; j++){//��j�˱Ƚ�len-j��;
			if (arr[j] > arr[j + 1]){  //����һ��С;
				swap(&arr[j], &arr[j + 1]);//����;
			}
		}
	}
}
void merge(int arr[], int low, int mid, int high){
	int i, k;
	int *tmp = (int *)malloc((high - low + 1)*sizeof(int));
	//����ռ䣬ʹ���СΪ����;
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++){ // �Ƚ�����ָ����ָ���Ԫ��;
		if (arr[left_low] <= arr[right_low]){
			tmp[k] = arr[left_low++];
		}
		else{
			tmp[k] = arr[right_low++];
		}
	}
	if (left_low <= left_high){ //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β;
		for (i = left_low; i <= left_high; i++){
			tmp[k++] = arr[i];
		}
	}
	if (right_low <= right_high){
		//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β;
		for (i = right_low; i <= right_high; i++){
			tmp[k++] = arr[i];
		}
	}
	for (i = 0; i < high - low + 1; i++){
		arr[low + i] = tmp[i];
	}
	free(tmp);
}

//�鲢����;
//�����������������з�Ϊ�����֣����ζԷֵõ����������ٴ�ʹ�ù鲢����֮���ٶ�����кϲ�;
void merge_sort(int arr[], unsigned int first, unsigned int last){
	int mid = 0;
	if (first < last){
		mid = first/2 + last/2;// ��ֹ��� ;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

//��������;
/*������������ȡ����һ������Ĭ�ϣ���Ϊ��׼������������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
�ٶ����������ظ��������裬ֱ��������ֻ��һ����;
�����Ĵ������٣�����˳���������ٶ�;
����������£�ʱ�临�Ӷ��Ժ�ð������һ����O(N ^ 2)������ƽ�����Ӷ���O(NlonN);*/
void quick_sort(int arr[], int begin, int end){
	int i = begin;
	int j = end;
	int x = arr[begin];
	if (begin < end){
		while (begin < end){
			while (begin<end && arr[end]>x){
				end--;
			}
			if (begin < end){
				arr[begin++] = arr[end];
			}
			while (begin < end && arr[begin] < x){
				begin++;
			}
			if (begin < end){
				arr[end--] = arr[begin];
			}
		}
		arr[begin] = x;
		quick_sort(arr, i, end - 1);//�õݹ齫ѡȡ�ı�׼���������߶���������;
		quick_sort(arr, begin + 1, j);
	}
}






//����20������ð���������õ�ʱ��
void maopao_time(int len){
	int sum = 0;
	int n = 0;//����;
	printf("20������(ms):>");
	while (n < 20){
		int i = 0;
		for ( i;i < len; i++){
			arr1[i] = rand();
		}
		begintime = clock();	//��ʱ��ʼ;
		maopao_sort(arr1, len);//ð������;
		endtime = clock();	//��ʱ����;
		sum = sum + endtime - begintime;//��ʱ��;
		printf(" %d ", endtime - begintime);
		if (n == 19){
			printf("\n");
		}
		n++;
	}
	printf("��������ƽ��ʱ��:> %d \n", (sum / 20));
}
//����20�������鲢�������õ�ʱ��
void merge_time(int len){
	int sum = 0;
	int n = 0;//����;
	printf("20������(ms):>");
	while (n < 20){
		int i = 0;
		for (i; i < len; i++){
			arr1[i] = rand();
		}
		begintime = clock();	//��ʱ��ʼ;
		merge_sort(arr1, 0, len - 1);//�ϲ�����;
		endtime = clock();	//��ʱ����;
		sum = sum + endtime - begintime;//��ʱ��;
		printf(" %d ", endtime - begintime);
		if (n == 19){
			printf("\n");
		}
		n++;
	}
	printf("��������ƽ��ʱ��:> %d \n", (sum / 20));
}
//����20�����������������õ�ʱ��
void quick_time(int len){
	int sum = 0;
	int n = 0;//����;
	printf("20������(ms):>");
	while (n < 20){
		int i = 0;
		for ( i;i < len; i++){
			arr1[i] = rand();
		}
		begintime = clock();	//��ʱ��ʼ;
		quick_sort(arr1, 0, len - 1);//��������;
		endtime = clock();	//��ʱ����;
		sum = sum + endtime - begintime;//��ʱ��;
		printf(" %d ", endtime - begintime);
		if (n == 19){
			printf("\n");
		}
		n++;
	}
	printf("��������ƽ��ʱ��:> %d \n", (sum / 20));
}

int main(){
	int input = 0;
	int len = 10;
	while (input<1||input>5){
		printf("1.ð������  2.�鲢����  3.��������  ");
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input){
		case 1:
			while (len <= 100000){
				printf("���鳤��Ϊ%dʱ��\n", len);
				maopao_time(len);//����ð���������õ�ʱ��;
				if (len != 100000){
					printf("----------------------------------------------------------------------------------\n");
				}
				len = len * 10;
			}
			break;
		case 2:
			while (len <= 100000){
				printf("���鳤��Ϊ%dʱ��\n", len);
				merge_time(len);//����鲢�������õ�ʱ��;
				if (len != 100000){
					printf("----------------------------------------------------------------------------------\n");
				}
				len = len * 10;
			}
			break;
		case 3:
			while (len <= 100000){
				printf("���鳤��Ϊ%dʱ��\n", len);
				quick_time(len);//��������������õ�ʱ��;
				if (len != 100000){
					printf("----------------------------------------------------------------------------------\n");
				}
				len = len * 10;
			}
			break;
		default:
			printf("ѡ��������������룡");
		}
	}
	/*for (i = 0; i < len; i++){
		printf("%d\n", arr1[i]);
	}*/
	system("pause");
	return 0;
}

