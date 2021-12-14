#include "arrayqueue.h"
#include "simdef.h"
#include "simutil.h"

// 고객 도착 큐에 고객 추가.
void insertCutomer(int arrivalTime, int processTime, ArrayQueue *pQueue)
{
	ArrayQueue node;

	if (!pQueue)
		return (FALSE);
	node.pElement->status = arrival;
	node.pElement->arrivaltime = arrivalTime;
	node.pElement->processtime = processTime;
	node.pElement->starttime = 0;
	node.pElement->endtime = 0;
	enqueueAQ(pQueue, node); //고객대기큐에 넣기
}

// 고객 도착 처리.
void processArrival(int currentTime, ArrayQueue *pArrivalQueue, ArrayQueue *pWaitQueue)
{
	ArrayQueueNode *node;

	while (isArrayQueueEmpty(node))
	{

	}
}

// 서비스 시작 처리.
ArrayQueueNode* processServiceNodeStart(int currentTime, ArrayQueue *pWaitQueue);

// 서비스 종료 처리.
ArrayQueueNode* processServiceNodeEnd(int currentTime, ArrayQueueNode *pServiceNode,
					  int *pServiceUserCount, int *pTotalWaitTime);

// 고객의 상태를 출력.
void printSimCustomer(int currentTime, SimCustomer customer);

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, ArrayQueue *pWaitQueue);

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(ArrayQueue *pWaitQueue,
				 int serviceUserCount,
				 int totalWaitTime);