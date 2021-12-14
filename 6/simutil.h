#include "arrayqueue.h"
#include "simdef.h"

#ifndef _SIM_UTIL_
#define _SIM_UTIL_

// 고객 도착 큐에 고객 추가.
void insertCutomer(int arrivalTime, int processTime, ArrayQueue *pQueue);

// 고객 도착 처리.
void processArrival(int currentTime, ArrayQueue *pArrivalQueue, ArrayQueue *pWaitQueue);

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

#endif