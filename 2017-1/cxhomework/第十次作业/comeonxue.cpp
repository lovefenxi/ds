#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insert_sort(int a[], int n);//ֱ�Ӳ�������
void shell_sort(int a[], int n);//ϣ������
void bubble_sort(int a[], int n);//��������
void quick_sort(int a[], int left, int right, int *movecount, int *comcount);//��������
void select_sort(int array[], int arrayCount);//��ѡ������
void copyarray(int a[], int b[], int n);//�ָ��������

void insert_sort(int a[], int n)//ֱ�Ӳ�������
 {
	int temp;
	int i, j;
	int acount = 0, bcount = 0, ccount;
	for (i = 1; i < n; i++)//����Ԫ�صĲ���
		 {
		temp = a[i];//���ü�����Ԫ��
		
			j = i - 1;
		while (bcount++ && temp < a[j]) {
			a[j + 1] = a[j];//����temp���Ԫ�����κ���
			acount++;
			j--;
			if (j < 0) {
				break;
				
			}
			
		}
		a[j + 1] = temp;//����Ԫ��
		acount++;
		}
	printf("\nֱ�Ӳ��������:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
		
	}
	ccount = acount + bcount;
	printf("\n�ܱȽϴ���:%d,���ƶ���¼����:%d,���ߴ���֮��:%d", bcount, acount, ccount);
	}

void shell_sort(int a[], int n)//ϣ������
 {
	int di = n / 2;
	int i, j;
	int temp;
	int acount = 0, bcount = 0, ccount = 0;
	while (di >= 1) {
	for (i = di; i <= n; i++) {
			temp = a[i];
			j = i - di;
			while (bcount++ && temp < a[j]) {
				a[i] = a[j];
				a[j] = temp;
				acount++;
				j -= di;
				if (j <= 0) {
					break;
					
				}
				
			}
			
				
		}
		di = di / 2;
		
	}
	printf("\nϣ�������:\n");
	for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
		
	}
	ccount = acount + bcount;
	printf("\n�ܱȽϴ���:%d,���ƶ���¼����:%d,���ߴ���֮��:%d", bcount, acount, ccount);
	
		}

void bubble_sort(int a[], int n)//��������
 {
	int i, j;
	int temp;
	int acount = 0, bcount = 0, ccount = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (bcount++ && a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				acount = acount + 3;
				
			}
			
		}
		
	}
	ccount = acount + bcount;
	printf("\nð�������:\n");
	for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
		
	}
	printf("\n�ܱȽϴ���:%d,���ƶ���¼����:%d,���ߴ���֮��:%d", bcount, acount, ccount);
	}

void quick_sort(int a[], int left, int right, int *movecount, int *comcount)//��������
 {
	int i, j, temp;
	i = left;
	j = right;
	temp = a[left];
	if (left > right)
	 return;
	while (i != j) {
		while ((*comcount)++, a[j] >= temp && j > i) {
			j--;
			
		}
		if (j > i) {
			a[i++] = a[j];
			(*movecount)++;
			
		}
		while ((*comcount)++, a[i] <= temp && j > i) { i++; }
		if (j > i) {
			a[j--] = a[i];
			(*movecount)++;
			
		}
		
			
	}
	a[i] = temp;
	quick_sort(a, left, i - 1, movecount, comcount);
	quick_sort(a, i + 1, right, movecount, comcount);
	}

void select_sort(int a[], int n)//��ѡ������
 {
	int min;
	int acount = 0, bcount = 0, ccount = 0;
	int temp;
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		min = i;
		for (j = i; j < n; ++j) {
		if (bcount++ && a[j] < a[min])  //ʹ��min����ָ����СԪ��
				 min = j;
			
		}
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			acount++;
			
		}
		
	}
	ccount = acount + bcount;
	printf("\n��ѡ�������:\n");
	for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
		
	}
	printf("\n�ܱȽϴ���:%d,���ƶ���¼����:%d,���ߴ���֮��:%d", bcount, acount, ccount);
	
		}
void copyarray(int a[], int b[], int n)//�ָ��������
 {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = b[i];
		
	}
	}


int main() {
	int array[100];
	int barry[100];
	int i = 0, m = 2, t = 1;
	srand(time(NULL));
	int movecount = 0, comparecount = 0;
	int length = rand() % 6 + 6;
	for (; i < length; i = i + 1) {
		barry[i] = array[i] = rand() % 7 + m;
		barry[i + 1] = array[i + 1] = rand() % 5 + t;
		m = m + 1;
		t = t + 2;
		
	}
	printf("�������������:\n");
	for (i = 0; i < length; i++) {
		printf("%d ", array[i]);
		
	}
	printf("\n------------------------------------------\n");
	insert_sort(array, length);
	copyarray(array, barry, length);
	printf("\n------------------------------------------\n");
	shell_sort(array, length);
	copyarray(array, barry, length);
	printf("\n------------------------------------------\n");
	bubble_sort(array, length);
	copyarray(array, barry, length);
	printf("\n------------------------------------------\n");
	quick_sort(array, 0, length - 1, &movecount, &comparecount);
	printf("\n���������:\n");
	for (i = 0; i < length; i++) {
		printf("%d ", array[i]);
		
	}
	printf("\n�ܱȽϴ���:%d,���ƶ���¼����:%d,���ߴ���֮��:%d", movecount, comparecount, movecount + comparecount);
	copyarray(array, barry, length);
	printf("\n------------------------------------------\n");
	select_sort(array, length);
	printf("\n------------------------------------------\n");
	return 0;
	
}