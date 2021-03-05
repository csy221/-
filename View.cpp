#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000//������������
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include"MoudleAndControl.h"



int main(int argc, char *argv[]) 



{
	system("title ͼ��ݹ���ϵͳ");
	system("color 02");
	//system("mode con cols=60 lines=20");
	//���ô��ڴ�С
	
	
	char index;
	Library library = createLibrary();
	//����ͼ���
	RecordSet recordSet = createRecordSet();
	//�����軹���¼��
	ReaderSet readerSet = createReaderSet();
	//���߽���֤�Ŵ���
	
	
	char path[3][20] = {"library.txt","records.txt","readers.txt"};//�ļ���
	printf("�����ļ���....\n");
	load(path[0],path[1],path[2],&library,&readerSet,&recordSet);	
	
	system("cls");
	printf("�����ļ��ɹ�\n");	
	
	system("cls");
	printf("->ͼ���Ŀǰ���� %d ���飬���� %d ���飬���� %d ����\n",
		library.numOfBookClass,
		
		library.totalMemory,
		
		library.currentMemory);
	printf("+------------------��ӭ����ͼ�����ϵͳ-------------------+\n"); 
	printf("|                                                         |\n");
	printf("|                        1.��ѯ                           |\n");
	printf("|                        2.����                           |\n");
	printf("|                        3.����                           |\n");
	printf("|                        4.�������֤                     |\n");
	printf("|                        5.�޸ĸ�����Ϣ                   |\n");
	printf("+---------------------------------------------------------+\n");
	printf("|                        6.�˳�                           |\n");
	printf("|                        7.����Աϵͳ                     |\n");
	printf("+---------------------------------------------------------+\n");
	printf("|                    ������Ž����Ӧ����                 |\n");
	printf("+---------------------------------------------------------+\n");
	printf("->");
	
	
	
	
	while (scanf("%d", &index) == 1) 
	{
		system("cls");
				
		if (index == 1)
			//��ѯ�鼮 
		{	
			//�ۺϲ�ѯ����			
			BookClass *bookClasses[MAX_SIZE];
			
			char info[20];
			printf("->������ͼ������֡����߻��߳����磺\n->");
			scanf("%s", info);
			
			int length = queryLibrary(library, bookClasses, info);
			
			if (length == 0) 
			{
				system("cls");
				printf("->ͼ������޴���\n");
			}
			else 
			{
				system("cls");
				printf("");
				printf("���\t����\t����\t������\t�ܿ���\t������\n");
				
				for (int i = 0; i < length; i++) 
				{
					printf("%3d%10s%10s%10s%5d%5d\n",
						bookClasses[i]->id,
						bookClasses[i]->name,
						bookClasses[i]->author,
						bookClasses[i]->publisher,
						bookClasses[i]->totalMemory,
						bookClasses[i]->currentMemory);
				}
			}
		}
		
		
		if (index == 2)
			//���� 
		{
			
			int bookId, readerId, amount;
			printf("->��������Ľ���֤�ţ�\n->");
			scanf("%d", &readerId);
			system("cls");
			
			if (searchReader(readerSet, readerId) == NULL) 
			{
				printf("->����֤�Ŵ���\n");
			}
			else 
			{
				printf("->����������Լ�������\n->");
				scanf("%d %d", &bookId, &amount);
				amount = Borrow(&library, &readerSet, &recordSet, readerId, bookId, amount);
				system("cls");
				printf("->������� %d ���顣\n", amount);
			}
		}
		
		
		if (index == 3)
			//���� 
		{
			
			int bookId, readerId, amount;
			printf("->��������Ľ���֤�š���ź�������\n->");
			scanf("%d %d %d", &readerId, &bookId, &amount);
			system("cls");
			
			if (searchReader(readerSet, readerId) == NULL) 
			{
				printf("->����֤�Ŵ���\n");
			}
			else 
			{
				amount = Return(&library, &readerSet, &recordSet, readerId, bookId, amount);
				printf("->��黹�� %d ���顣\n", amount);
			}
		}
		
		
		if (index == 4)
			//�������֤ 
		{
			
			printf("->����������֣�\n->");
			char name[20];
			scanf("%s", name);
			system("cls");
			printf("->��Ľ���֤��Ϊ��%d \n", addReader(&readerSet, name));
		}
		
		
		if (index == 5)
			//�޸ĸ�����Ϣ 
		{
			int readerId;
			char name[20];
			printf("->��������Ľ���֤�ţ�\n->");
			scanf("%d",&readerId);
			system("cls");
			if (searchReader(readerSet, readerId) == NULL) 
			{
				printf("->����֤�Ŵ���\n");
			}
			else 
			{
				printf("->�������������\n->");
				scanf("%s",name);
				alterReader(&readerSet,readerId,name);
				system("cls");
				printf("->�޸ĳɹ�\n");
			}
		}
		
		
		if (index == 6) 
		{
			save(path[0], path[1], path[2], library, readerSet, recordSet);
			printf("->����ɹ���\n");
			system("cls");
			printf("->��л���ʹ�á�\n");
			Sleep(1000);
			exit(0);
		}
		
		
		if(index == 7)
			//����Աģ��
		{
			fflush(stdin);
			char Mima[7];
			char mima[7]="123456";
			save(path[0], path[1], path[2], library, readerSet, recordSet);
		
			library = createLibrary();
			
			//ͼ��ݳ�ʼ��
		
			recordSet = createRecordSet();
			
			//�軹���¼����ʼ��
			
			readerSet = createReaderSet();
			
			//���߽���֤�ų�ʼ��
			
			load(path[0],path[1],path[2],&library,&readerSet,&recordSet);
			
			
			printf("���������Ա���룺");
			scanf("%s",&Mima);
			system("cls");
			
			if(strcmp(Mima,mima)==0)
			{
				printf("+---------------------------------------------------------+\n");
				printf("|                        1.�鿴��¼                       |\n");
				printf("|                        2.�鿴����                       |\n");
				printf("|                        3.�鿴���                       |\n");
				printf("|                        4.�ɱ����                       |\n");
				printf("|                        5.������                       |\n");
				printf("|                        6.ɾ�Ķ���                       |\n");
				printf("|                        7.�˳�                           |\n");
				printf("+---------------------------------------------------------+\n");
				printf("|                  ������Ž����Ӧ����                   |\n");
				printf("+---------------------------------------------------------+\n");
				printf("->");
				int index_2;
				while (scanf("%d", &index_2) == 1)
				{
					system("cls");
					
					if(index_2 == 1)
					{
						showRecord(recordSet);
						//�軹���¼��ʾ
					}
					
					if(index_2 == 2)
					{
						showReaders(readerSet);
						//������Ϣ��ʾ
					}
					
					if(index_2 == 3)
					{
						showAllBooks(&library);
					}
					
					if(index_2 == 4)
						//�ɱ����
					{
						char name[20];
						char author[20];
						char publisher[20];
						int amount;
						printf("->������ͼ�����֡����ߡ��������Լ�������\n->");
						scanf("%s %s %s %d",name,author,publisher,&amount);
						addBooks(&library,name,author,publisher,amount);
						//�����鼮
						system("cls");
						printf("->���ɹ�\n");					
					}
					
					if(index_2 == 5)
						//��տ��
					{
						int id;
						printf("->����������ţ�\n->");
						scanf("%d",&id);
						clearBooks(&library,id);
						//����鼮
					}
					
					
					
					if(index_2 == 6)
					{
						int choose;
						showReaders(readerSet);//������Ϣ��ʾ
						printf("->��������Ҫ���в�������Ӧ��ţ�1���޸Ķ�������|2��ɾ������|3���˳�\n->");
						scanf("%d",&choose);
						if(choose == 1)
						{
							int readerId;
							char name[20];
			                printf("->�����������޸ĵĶ��߽���֤�ţ�\n->");
			                scanf("%d",&readerId);
			                system("cls");
			                if (searchReader(readerSet, readerId) == NULL) 
							{
								printf("->����֤�Ŵ���\n");
							}
							else 
							{
								printf("->�������������\n->");
				                scanf("%s",name);
				                alterReader(&readerSet,readerId,name);
				                system("cls");
				                printf("->�޸ĳɹ�\n");
							}
						}
						else if(choose == 2)
						{
							int readerId;
							printf("->����������ɾ���Ķ��߽���֤�ţ�\n->");
			                scanf("%d",&readerId);
			                system("cls");
							
							if (searchReader(readerSet, readerId) == NULL) 
							{
								printf("->����֤�Ŵ���\n");
							}
							else
							{
								removeReader(&readerSet,readerId);
							}
						}
						else if(choose == 3)
							;
						else
							printf("����������������������!\n");

					}
					
					
					if(index_2 == 7)
					{	
						save(path[0], path[1], path[2], library, readerSet, recordSet);
						library = createLibrary();
						//ͼ��ݳ�ʼ��
			            recordSet = createRecordSet();
						//�軹���¼����ʼ��
			            readerSet = createReaderSet();
						//���߽���֤�ų�ʼ��
			            load(path[0],path[1],path[2],&library,&readerSet,&recordSet);
						system("cls");
						break;
					}
					
					
					
					
					
	                int non;
					printf("\n->�����������ַ��������档\n->");
					scanf("%d",&non);
					system("cls");
					printf("+---------------------------------------------------------+\n");
					printf("|                        1.�鿴��¼                       |\n");
					printf("|                        2.�鿴����                       |\n");
					printf("|                        3.�鿴���                       |\n");
					printf("|                        4.�ɱ����                       |\n");
					printf("|                        5.������                       |\n");
					printf("|                        6.ɾ�Ķ���                       |\n");
				    printf("|                        7.�˳�                           |\n");
					printf("+---------------------------------------------------------+\n");
					printf("|                  ������Ž����Ӧ����                   |\n");
					printf("+---------------------------------------------------------+\n");
					printf("->");
				}
			}
		}
		
		
				
		int non;
		printf("->�����������ַ��������档\n->");
		scanf("%d",&non);
		system("cls");
		printf("->ͼ���Ŀǰ���� %d ���飬���� %d ���飬���� %d ����\n",
			
			library.numOfBookClass,
			
			library.totalMemory,
			
			library.currentMemory);
		printf("+---------------------------------------------------------+\n");
		printf("|                        1.��ѯ                           |\n");
		printf("|                        2.����                           |\n");
		printf("|                        3.����                           |\n");
		printf("|                        4.�������֤                     |\n");
		printf("|                        5.�޸ĸ�����Ϣ                   |\n");
		printf("+---------------------------------------------------------+\n");
		printf("|                        6.�˳�                           |\n");
		printf("|                        7.����Աϵͳ                     |\n");
		printf("+---------------------------------------------------------+\n");
		printf("|                    ������Ž����Ӧ����                 |\n");
		printf("+---------------------------------------------------------+\n");
		printf("->");
	}
	
	
	return 0;
}


