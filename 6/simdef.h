#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착시간
	int serviceTime;	// 서비스 시간
	int startTime;		// 시작 시간
	int endTime;		// 종료시각: 시작시각+서비스시간
} SimCustomer;

#endif