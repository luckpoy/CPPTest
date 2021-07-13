#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int Chinese_score;
    int Math_score;
    int English_score;
    int Total;
    float Ave;
    char *name;
    struct Student *next;
};

struct Class
{
	int grade;
    struct Class *next;
};

void printLink(struct Student * head)
{
	struct Student * p = head;
    if (p == NULL){
		printf("NULL！！！\n");
        return;
    }
    while (p != NULL) {
		printf("学生姓名：%s，语文成绩：%d，数学成绩：%d，英语成绩：%d，三科总分：%d，三科平均分：%.2f\n", 
            p->name, p->Chinese_score, p->Math_score, p->English_score, p->Total, p->Ave);
		p = p->next;
    }
}
struct Student * inputStuMes(struct Student *head)
{
	int len = 0;
    printf("Please input the number of students:\n");
    scanf("%d", &len);
  
    int i;
    char *S_name;
    int C_score;
    int M_score;
    int E_score;
    int total;
    float ave;
    struct Student *p = head;
    struct Student *pnew = NULL;
    for (i = 0; i < len; i++){
			pnew = (struct Student *) malloc (sizeof(struct Student));
			S_name = (char *) malloc (128);
            memset(S_name, '\0', 128);
            printf("请输入第%d个学生姓名：\n", i+1);
            scanf("%s", S_name);
            printf("请输入第%d个学生的语文成绩：\n", i+1);
            scanf("%d", &(C_score));
            printf("请输入第%d个学生的数学成绩：\n", i+1);
            scanf("%d", &(M_score));
            printf("请输入第%d个学生的英语成绩：\n", i+1);
            scanf("%d", &(E_score));
            total = C_score + M_score + E_score;
            ave = (float)total / 3;	
            
            pnew->name = S_name;
            pnew->Chinese_score = C_score;
            pnew->Math_score = M_score;
            pnew->English_score = E_score;
            pnew->Total = total;
            pnew->Ave = ave;
            
            p->next = pnew;
            pnew->next = 0;
            p = pnew;
            
    }
    p->next = NULL;

    head=head->next;
    return head;
}
int main()
{
	struct Student * B1 = NULL;
    B1 = (struct Student *) malloc (sizeof(struct Student));
    B1 = inputStuMes(B1);
    // B1->name="kun";
    // B1->Chinese_score=1;
    // B1->Math_score=2;
    // B1->English_score=3;
    // B1->Ave=2;
    // B1->Total=5;
    printLink(B1);
    
	return 0;
}