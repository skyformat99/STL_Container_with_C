#include "debug.h"




//���� typeSize �ĳ��ȣ����ֵ��
// ���� ������������ĸ�������.
void PrintValue(void *ptr, int typeSize){
    switch (typeSize){
         case TYPE_CHAR:
            printf("%c  ", *((char *)ptr));
            break;
        case TYPE_INT:
              printf("%d  ", *((int *)ptr));
            break;
        case TYPE_DOUBLE:
            printf("%f  ", *((double *)ptr));
            break;
        default:
            printf("printValue() -> ����δ֪��ֵ�� typeSize=" + typeSize);

    }
}

// ��console���result�����ڹ۲�
void DealResult(int result){
    switch(result){
        case NORMAL:
            printf("\t \t \t result is normal\n");
            break;
        case CTL_OUT_OF_RANGE:
            printf("\t \t \t ctl is out of range!\n");
            break;
        case CTL_PTR_IS_NULL:
			printf("\t \t \t ctl ptr is null!\n");
			break;
		case CTL_NO_VALUE:
			printf("\t \t \t ctl no value\n");
			break;
		case CTL_TYPESIZE_NO_MATCH:
			printf("\t \t \t ctl typeSize no match!\n");
			break;
		case RECORD_PTR_IS_NULL:
			printf("\t \t \t record ptr is null\n");
			break;
		case MALLOC_FAIL:
			printf("\t \t \t malloc fail\n");
			break;
		case NUM_IS_WRONG:
			printf("\t \t \t num is wrong\n");
			break;
		case NUM_WRONG_BUT_DO_SOMETHING:
			printf("\t \t \t num wrong but do something\n");
			break;
		default:
			printf("\t \t \t debug.cpp�ļ���DealResult()��������δ����ֵ��\n");
			break;
    }
}// end of "DealResult"



// ���stack�е����ݵ����ϡ�
void PrintStack(struct CTLStack stack){

    void *ptr;

    char *str = "";
    switch(stack.typeSize){
        case TYPE_CHAR:
            str = "Stack ����������Ϊ char ����\n";
            break;
        case TYPE_INT:
            str = "Stack ����������Ϊ int ����\n";
            break;
        case TYPE_DOUBLE:
            str = "Stack ����������Ϊ double ����\n";
            break;
        default:
            str = "PrintStack ����δ�����typeSize = " + stack.typeSize;

    }
    printf(str);
	printf("stack��typeSize=%d, \t topָ��λ��=%d, \t length=%d\n", stack.typeSize, stack.top, stack.length);

	printf("stack�е�Ԫ�شӵײ�������������:\n");
	for (int i=0; i<=stack.top; i++){
        if (i%10 == 0)
            printf("\n");
        ptr = stack.data;
        ptr = (char *)ptr + i*stack.typeSize;
        PrintValue(ptr, stack.typeSize);
	}
	putchar(10);
}

// �������queue�е����ݣ������ݵ�λ�����*�Ŵ���(��Ϊ���ǰ� length���ȵ����ݶ����)
void PrintQueue(struct CTLQueue queue, int typeSize){
	int i;
	//double *pVar;
	void *pVoid;

	printf("���queue����Ϣ����:\n");
    char *str = "";
    switch(queue.typeSize){
        case TYPE_CHAR:
            str = "\t\tQueue ����������Ϊ char ����\n";
            break;
        case TYPE_INT:
            str = "\t\tQueue ����������Ϊ int ����\n";
            break;
        case TYPE_DOUBLE:
            str = "\t\tQueue ����������Ϊ double ����\n";
            break;
        default:
            str = "\t\tPrintQueue ����δ�����typeSize = " + queue.typeSize;

    }
    printf(str);

    printf("\t\ttypeSize=%d, front=%d, rear=%d, length=%d\n", queue.typeSize, queue.front, queue.rear, queue.length-1);
	printf("\t\t���queue�й���%d��Ԫ��,���������ǣ�\n", CTLQueueGetNum(queue));


	for (i=0; i<queue.length-1; i++){
        if (i%10 == 0)
            printf("\n");

        if ((i<queue.front) || (i>=queue.rear))
            printf("*  ");
        else{
            pVoid = queue.data;
            pVoid = (char *)pVoid + i * queue.typeSize;
            PrintValue(pVoid, typeSize);
        }
    }
    printf("\n");
}//end of "PrintQueue(..."



