//Ϊ�˷�����⣬����Ĵ��������ԭ״̬װ���Ĺ��̣����ǲ���Ҫ�ģ��Ѿ�ע�͵���
#include"CommentCovert.h"

//�������봦��
void DoNulStaus(FILE *pfIn, FILE *pfOut, enum status *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '/':
	{
				int second = fgetc(pfIn);
				switch (second)
				{
				case'*':
				{
						   fputc('/', pfOut);
						   fputc('/', pfOut);
						   *ps = C_STATUS;
				}
					break;
				case'/':
				{
						   fputc(first, pfOut);
						   fputc(second, pfOut);
						   *ps = CPP_STAUS;
				}
					break;
				default:
				{
						   fputc(first, pfOut);
						   fputc(second, pfOut);
						   /**ps = NUL_STATUS;*/
				}
					break;
				}
	}
		break;
	case EOF:
	{
				fputc(first, pfIn);
				*ps = END_STATUS;
	}
		break;
	default:
	{
			   fputc(first, pfOut);
			   /**ps = NUL_STATUS;*/
	}
		break;
	}
}
//c������ע��������
void DoCStaus(FILE *pfIn, FILE *pfOut, enum status *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case'*':
	{
			   int second = fgetc(pfIn);
			   switch (second)
			   {
			   case'/':
			   {
						  int third = fgetc(pfIn);
						  if (third != '\n')
						  {
							  fseek(pfIn, -1, SEEK_CUR);
							  //���third����'\n'���Ǹ��ַ��Ѿ������ߣ�Ӧ�ð��Ǹ��ַ�����ȥ�ڷ�һ��'\n'
							  fputc('\n', pfOut);
						  }
						  else
						  {
							  fputc(third, pfOut);
						  }
						  *ps = NUL_STATUS;
			   }
				   break;
			   case'*':
			   {
						  fputc(first, pfOut);
						  fseek(pfIn, -1, SEEK_CUR);
						  /**ps = C_STATUS;*/
						  //��fpָ���ƶ������ļ���ǰλ��-1�ֽڴ�,����1���ַ�
						  //��Ϊ�ڶ����ַ������*Ҫ��/һ���ж��Ƿ���C����ע�ͷ�����
			   }
				   break;
			   default:
			   {
						  fputc(first, pfOut);
						  fputc(second, pfOut);
						  /**ps = C_STATUS;*/
			   }
				   break;
			   }
	}
		break;
	case'\n':
	{
				fputc(first, pfOut);
				fputc('/', pfOut);
				fputc('/', pfOut);
				/**ps = C_STATUS;*/
	}
		break;
	default:
	{
			   fputc(first, pfOut);
			   /**ps = C_STATUS;*/
	}
		break;
	}
}
//c++������ע��������
void DoCppStaus(FILE *pfIn, FILE *pfOut, enum status *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case'\n':
	{
				fputc(first, pfOut);
				*ps = NUL_STATUS;
	}
		break;
	case EOF:
		fputc(first, pfOut);
		*ps = END_STATUS;
		break;
	default:
		fputc(first,pfOut);
		/**ps = CPP_STAUS;*/
		break;
	}
}