#include"contact.h"
//������ϵ��
void Add_people(contact *book)
{
	assert(book != NULL);
	if (book->count == MAX)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	else
	{
		printf("������������");
		scanf("%s", book->data[book->count].name);
		printf("�������Ա�");
		scanf("%s", book->data[book->count].sex);
		printf("���������䣺");
		scanf("%d", &book->data[book->count].age);
		printf("������绰��");
		scanf("%s", book->data[book->count].tele);
		printf("�������ַ��");
		scanf("%s", book->data[book->count].addr);
		book->count++;
		printf("��ӳɹ�\n");
	}
}
//ֻ�ڱ�Դ�ļ���ʹ�ã�����static�ı��������ԣ�ʹ�ø��Ӱ�ȫ
//�����������Ƿ��������������±�
static int find_people(contact *book)
{
	char names[20];
	printf("������������");
	scanf("%s", names);
	int i = 0;
	for (; i < book->count; i++)
	{
		if (0 == strcmp(book->data[i].name, names))
		{
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void Dele_people(contact *book)
{
	if (book->count == 0)
	{
		printf("ͨѶ¼�ѿ�\n");
		return;
	}
	else
	{
		int ret = find_people(book);
		if (ret < 0)
		{
			printf("���޴���\n");
			return;
		}
		else
		{
			int i = ret;
			for (; i < book->count - 1; i++)
			{
				book->data[i] = book->data[i + 1];
			}
			book->count--;
		}
	}
}
//�޸���ϵ����Ϣ
void Alert_people(contact *book)
{
	int ret = find_people(book);
	if (ret < 0)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("������Ҫ�޸ĵ�������");
		scanf("%s", book->data[ret].name);
		printf("������Ҫ�޸ĵ��Ա�");
		scanf("%s", book->data[ret].sex);
		printf("������Ҫ�޸ĵ����䣺");
		scanf("%d", &book->data[ret].age);
		printf("������Ҫ�޸ĵĵ绰��");
		scanf("%s", book->data[ret].tele);
		printf("������Ҫ�޸ĵĵ�ַ��");
		scanf("%s", book->data[ret].addr);
		printf("�޸ĳɹ�\n");
	}
}
//����ָ����ϵ��
void Search_people(contact *book)
{
	int ret = find_people(book);
	if (ret < 0)
	{
		printf("û�в��ҵ�����ϵ��\n");
		return;
	}
	else
	{
		printf("���֣�%s �Ա�%s ���䣺%d �绰��%s ��ַ��%s\n",
			book->data[ret].name,
			book->data[ret].sex,
			book->data[ret].age,
			book->data[ret].tele,
			book->data[ret].addr);
	}	
}
//��ӡ������ϵ����Ϣ
void Show_people(contact *book)
{
	if (book->count == 0)
	{
		printf("��ͨѶ¼Ϊ��\n");
		return;
	}
	else
	{
		int i = 0;
		printf("%-5s\t%-5s\t%-3s\t%-12s\t%-12s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		for (; i < book->count; i++)
		{
			printf("%-5s\t%-5s\t%-3d\t%-12s\t%-17s\n",
				book->data[i].name,
				book->data[i].sex,
				book->data[i].age,
				book->data[i].tele,
				book->data[i].addr);
		}
	}
}
//��ʼ��ͨѶ¼
void Init_contact(contact *book)
{
	book->count = 0;
	book->max = 3;
	book->data = (people*)malloc(book->max * sizeof(people));
}
//���ͨѶ¼
void Empty_people(contact *book)
{
	book->count = 0;
	book->max = 3;
	book->data = (people*)malloc(book->max * sizeof(people));
	printf("��ճɹ�\n");
}
//����������ͨѶ¼
void Sort_people(contact *book)
{
	if (book->count > 1)
	{
		int i = 0;
		for (; i < book->count - 1; i++)
		{
			int j = 0;
			for (; j < book->count - 1 - i; j++)
			{
				if (strcmp(book->data[j].name, book->data[j + 1].name))
				{
					people temp = book->data[j];
					book->data[j] = book->data[j + 1];
					book->data[j + 1] = temp;
				}
			}
		}
	}
	printf("����ɹ�\n");
}