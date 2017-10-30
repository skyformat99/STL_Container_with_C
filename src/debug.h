/**
 *  1. ���ļ��������ĺ������ڶ�CTL���в����������Ҫ�ǽ���Щ�ṹ����������ڹ۲�
 *  2. ���ǽ��в���ʱ��Ĭ��ֻ���� char��int��double���ͣ����� �ڽ������ʱ��ֱ�Ӹ��� typeSize ����������
 *  2. ����stack��queueʱ�����ǽ�int��double��char�����ò�ͬ�ĺ����������֣�
 *     ��list��ʼ����Щ�ط��ڲ���int��double��char���Ͷ�����typeSize��С������PrintType()��ScaleType������������
 */


 #ifndef _CTL_DEBUG_H
 #define _CTL_DEBUG_H

 #include "CTLStack.h"
 #include "CTLQueue.h"

 extern void PrintStack(struct CTLStack stack);
 extern void DealResult(int result);
 extern void PrintQueue(struct CTLQueue queue, int typeSize);



 #endif // _CTL_DEBUG_H
