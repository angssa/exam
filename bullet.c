
*/

#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
	float v[361]={0};                      
	int i=0,ii=0,a=4; 
	float Dsum=0;
	float DDsum=0;
	float Sum=0;
	float D=0;
	float j;
	float jj;
	float ref;
	FILE *fp;
	char *add;
	add = (char *) malloc(20);
	printf("���� �ּҸ� �Է��ϼ��� ex)c:/ideal.txt \n");
	gets(add);
	fp=fopen(add,"r"); 	
	if(fp==NULL)
	{
		printf("���� ���� ����.\n");
		return 0;
	}                            
	printf("������ �̷а��� �Է��� �ּ���\n");
	scanf("%f",&ref);
	if(200<ref || ref<0){
		printf("�߸��� �Է°��Դϴ�.");
		return 0;
	}
	for(i=1;i<=360; i++)
   {
 	  fscanf(fp,"%f",&v[i]);
	  fseek(fp,a,SEEK_SET);                // �޸��� ���е� txt������ �б� ���� ó�� ��ġ���� a����Ʈ ������ ��ġ�� ���� �����͸� �� ��ġ�ϵ��� �߽��ϴ�.
                                           //printf("%d���� ���氪�� %f�Դϴ�.\n",i,v[i]);
	  a=a+4;
	  Sum=Sum + v[i];                      // ������ ������ ���ϱ� ���� ���� ���ϴ� �κ�
	 	 }
 

	for(ii=1;ii<360;ii++)                  //�����⸦ ���ϱ����� �κ� 
	{
		D=(v[ii+1]-v[ii])/2;
		if(D>=0)
		DDsum = DDsum + D;                // �������� ���� ���밪���� �����ϴ� �κ�
		else
			DDsum =DDsum-D;
		
	}
 

	j=Sum/(i-1);              // ������ ���հ� ���ϱ�.
	jj=DDsum/360;             // �߽� ���� �������� ������ ���� ���ϱ�-> 0�̸� �߽�. ->0�� �ƴϸ� �ҷ�ǰ�̳� ����.

	                                //printf("������ �������� ���հ��� %f�Դϴ�.\n",jj);
	
	if(jj==0 & j==ref)              //������ �Է��� ���۷��� ���� ���� �������� ������ ���ٸ� �߽ɿ��� ������ ��ǰ�Դϴ�.
		printf("�Էµ� ���氪 : %f�Դϴ�.\n������ ���� ���氪 : %f�Դϴ�.\n�� ��ǰ�� �߽ɿ��� ������ ��ǰ�Դϴ�.\n",ref,j);
	else if(jj!=0 & j==ref)         //������ ������ �������� ������ �ִٸ� ���ɿ��� ������ ��ǰ�Դϴ�.
		printf("�Էµ� ���氪 : %f�Դϴ�.\n������ ���� ���氪 : %f�Դϴ�.\n�� ��ǰ�� ���ɿ��� ������ ��ǰ�Դϴ�.\n",ref,j);
	else                            // ���հ��� �Է��� ���� �ٸ��� �ҷ�ǰ�Դϴ�. 
	printf("�Էµ� ���氪 : %f�Դϴ�.\n������ ���� ���氪�� %f�Դϴ�.\n�� ��ǰ�� �ҷ�ǰ�Դϴ�.\n",ref,j);
	  
    system("pause");
   
} 
 
   
   
    

 

       

        


 

 
   
 