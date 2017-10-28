#include "CTLStack.h"
#include "testStack.h"
#include "debug.h"


static void PrintStackClear(struct CTLStack *stack)
{
	printf("\t ��CTLStackClear()�������ؽ�����!\n");
	DealResult( CTLStackClear(stack) );
}

static void PrintStackEmpty(struct CTLStack stack)
{
	if (CTLStackIsEmpty(stack) == TRUE)
		printf("\t \t���ջ�ǿյģ�\n");
	else
		printf("\t \t���ջ���ǿյģ�\n");
}

static void PrintStackFull(struct CTLStack stack)
{
	if (CTLStackIsFull(stack) == TRUE)
		printf("\t \t���ջ������!\n");
	else
		printf("\t \t���ջ��������!\n");
}


static void TestStackInt(){
    int result, num, flag = TRUE;
    char var;

    INIT_CTL_STACK(int, stackInt1, 8);

    printf("�����������Ϊ:\n"
            "c(CTLStackClear),  e(CTLStackIsEmpty),\n"
			"f(CTLStackIsFull), h(CTLStackPush),p(CTLStackPop),\n"
			"g( CTLStackPeek), o(PrintStack), q(quit)\n");

    while (flag == TRUE){
        printf("������������:");
        scanf("%c", &var);
        getchar();   //���ջس�
        switch (var){
            case 'c':
                PrintStackClear(&stackInt1);
                break;
            case 'e':
                PrintStackEmpty(stackInt1);
                break;
            case 'f':
                PrintStackFull(stackInt1);
                break;
            case 'h':
                printf("������������ջ��ֵ:");
                scanf("%d", &num);
                getchar();
                result = CTLStackPush(&stackInt1, (void *)(&num));
                DealResult(result);
                break;
            case 'p':
                result  = CTLStackPop(&stackInt1, (void *)(&num));
                if (result == NORMAL){
                    printf("\t \t��ջ��ֵ�� %d.\n", num);
                }else{
                    DealResult(result);
                }
                break;
            case 'g':
                result = CTLStackPeek( &stackInt1, (void *)(&num));
				if (result == NORMAL)
					printf("\t \tջ����ֵ��%d.\n", num);
				else
					DealResult(result);
				break;
            case 'o':
                PrintStack(stackInt1);
                break;
            case 'q':
                flag = FALSE;
                break;
            default:
                printf("\t \t�������ֵ %c �쳣�����������\n", var);
        }//end of "switch..."
    }//end of " while (flag == TRUE)"
}//end of "TestStackInt"


static void TestStackChar(){
    //Todo
}

static  void TestStackDouble(){

}


void TestCTLStack(){
    printf("����CTLStack�Ĳ��ԣ�\n");
    printf("���ڽ��е��� int ���͵� ����");
    TestStackInt();
    printf("���Խ���!!!!");
}
