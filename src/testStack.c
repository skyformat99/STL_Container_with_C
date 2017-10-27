#include "CTLStack.h"
#include "testStack.h"
#include "debug.h"


static void PrintStackClear(struct CTLStack *stack)
{
	printf("��CTLStackClear()�������ؽ�����!\n");
	DealResult( CTLStackClear(stack) );
}

static void PrintStackEmpty(struct CTLStack stack)
{
	if (CTLStackIsEmpty(stack) == TURE)
		printf("���ջ�ǿյģ�\n");
	else
		printf("���ջ���ǿյģ�\n");
}

static void PrintStackFull(struct CTLStack stack)
{
	if (CTLStackIsFull(stack) == TURE)
		printf("���ջ������!\n");
	else
		printf("���ջ��������!\n");
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

        switch (var){
            case `c`:
                PrintStackClear(&stackInt1);
                break;
            case `e`:
                PrintStackEmpty(stackInt1);
                break;
            case `f`:
                PrintStackFull(stackInt1);
                break;
            case `h`:
                printf("������������ջ��ֵ:");
                scanf("%d", &num);
                getchar();
                result = CTLStackPush(&stackInt1, (void *)(&num));
                DealResult(result);
                break;
            case `p`:
                result  = CTLStackPop(&stackInt1, (void *)(&num));
                if (result == NORMAL){
                    printf("��ջ��ֵ�� %d.\n", num);
                }else{
                    DealResult(result);
                }
                break;
            case `g`:
                result = CTLStackGetTop( &stackInt1, (void *)(&num));
				if (result == NORMAL)
					printf("ջ����ֵ��%d.\n", num);
				else
					DealResult(result);
				break;
            case `o`:
                PrintStack(stackInt1);
                break;
            case `q`:
                flag = FALSE;
                break;
            default:
                printf("�������ֵ %c �쳣�����������\n", var);
        }
    }//end of " while (flag == TRUE)"
}//end of "TestStackInt"


static void TestStackChar(){
    //Todo
}

staic void TestStackDouble(){

}


void TestCTLStack(){
    printf("����CTLStack�Ĳ��ԣ�\n");
    printf("���ڽ��е��� int ���͵� ����");
    TestStackInt();
}
