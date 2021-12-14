#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
<<<<<<< HEAD
	int arrivalTime;	// 도착 시각.
	int serviceTime;	// 서비스 시간.
	int startTime;		// 시작 시각.
	int endTime;		// 종료 시각: 시작 시각 + 서비스 시간.
=======
	int arrivalTime;	// 도착시간
	int serviceTime;	// 서비스 시간
	int startTime;		// 시작 시간
	int endTime;		// 종료시각: 시작시각+서비스시간
>>>>>>> d4b845db32f2457ce260d02c9882c9557f0ec2df
} SimCustomer;

#endif