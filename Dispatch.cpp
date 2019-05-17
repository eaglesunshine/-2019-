#include "Dispatch.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include "Floyd.h"
using namespace std;
#define BADTIME 100000
#define PI 3.1415926
//#define  RANUM 1200   //����·�ϳ�����

////������
//bool Dispatch::mainBackup(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime)
//{
//	//��һ�α���
//	if (backup_GlobalTime == 0 && backup_GlobalTime2 == 0)
//	{
//		Backup(CAR, CROSS, ROAD, GlobalTime);
//		return true;
//	}
//
//	//˭���ݵ�ʱ�����磬����˭�������µ�
//	if (backup_GlobalTime > 0 && backup_GlobalTime2 >= 0)
//	{
//		if (backup_GlobalTime == backup_GlobalTime2)
//		{
//			Backup(CAR, CROSS, ROAD, GlobalTime);
//			return true;
//		}
//		if (backup_GlobalTime < backup_GlobalTime2)
//		{
//			Backup(CAR, CROSS, ROAD, GlobalTime);
//			return true;
//		}
//		if (backup_GlobalTime > backup_GlobalTime2)
//		{
//			Backup2(CAR, CROSS, ROAD, GlobalTime);
//			return true;
//		}
//	}
//
//	Backup(CAR, CROSS, ROAD, GlobalTime);
//	return false;
//}
//
////���ع�
//bool Dispatch::mainRollback(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, const Graph_DG &OriginalCarGraph)
//{
//	//ֻ����һ������
//	if (backup_GlobalTime > 0 && backup_GlobalTime2 == 0)
//	{
//		Rollback(CAR, CROSS, ROAD, GlobalTime, OriginalCarGraph);
//		backup_GlobalTime = 0;
//		backup_GlobalTime2 = 0;
//		return true;
//	}
//
//	//�����������ݣ�˭��������ͻָ�˭
//	if (backup_GlobalTime > 0 && backup_GlobalTime2 > 0)
//	{
//		if (backup_GlobalTime == backup_GlobalTime2)
//		{
//			Rollback(CAR, CROSS, ROAD, GlobalTime, OriginalCarGraph);
//			backup_GlobalTime = 0;
//			backup_GlobalTime2 = 0;
//			return true;
//		}
//		if (backup_GlobalTime < backup_GlobalTime2)
//		{
//			Rollback(CAR, CROSS, ROAD, GlobalTime, OriginalCarGraph);
//			backup_GlobalTime = 0;
//			backup_GlobalTime2 = 0;
//			return true;
//		}
//		if (backup_GlobalTime > backup_GlobalTime2)
//		{
//			Rollback2(CAR, CROSS, ROAD, GlobalTime, OriginalCarGraph);
//			backup_GlobalTime = 0;
//			backup_GlobalTime2 = 0;
//			return true;
//		}
//	}
//
//	Rollback(CAR, CROSS, ROAD, GlobalTime, OriginalCarGraph);
//	backup_GlobalTime = 0;
//	backup_GlobalTime2 = 0;
//	return false;
//}
//
//void Dispatch::Backup(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime)
//{
//	//dispatch backup
//	this->backup_GlobalTime = GlobalTime;
//	backup_roadCarNumber = roadCarNumber;
//	backup_EmptyCarportNumber = EmptyCarportNumber;
//
//	int i;
//	//CAR backup
//	for (i = 0; i < carSize; i++)
//	{
//		CAR[i].backup_PT = CAR[i].PT;
//		CAR[i].backup_ATD = CAR[i].ATD;
//		CAR[i].backup_EndTime = CAR[i].EndTime;
//		CAR[i].backup_nowSpeed = CAR[i].nowSpeed;
//		CAR[i].backup_maxSpeed = CAR[i].maxSpeed;
//		memcpy(CAR[i].backup_location, CAR[i].location, sizeof(CAR[i].location));
//		CAR[i].backup_nextRoad = CAR[i].nextRoad;
//		CAR[i].backup_nextCross = CAR[i].nextCross;
//		CAR[i].backup_nextRoadSpeed = CAR[i].nextRoadSpeed;
//		CAR[i].backup_nextCrossDirection = CAR[i].nextCrossDirection;
//		CAR[i].backup_nextCrossDistance = CAR[i].nextCrossDistance;
//		CAR[i].backup_state = CAR[i].state;
//		CAR[i].backup_blockDistance = CAR[i].blockDistance;
//		CAR[i].backup_isReverse = CAR[i].isReverse;
//		CAR[i].backup_toNextRoad = CAR[i].toNextRoad;
//		CAR[i].backup_isTerminate = CAR[i].isTerminate;
//		CAR[i].backup_nextReverse = CAR[i].nextReverse;
//		CAR[i].backup_passRoadNumber = CAR[i].passRoadNumber;
//		CAR[i].backup_isReset = CAR[i].isReset;
//		CAR[i].backup_LastRoad = CAR[i].LastRoad;
//		CAR[i].backup_usedToBeDeadCar = CAR[i].usedToBeDeadCar;
//
//		CAR[i].backup_maxSP.clear();
//		CAR[i].backup_maxSP.insert(CAR[i].backup_maxSP.begin(), CAR[i].maxSP.begin(), CAR[i].maxSP.end());
//		CAR[i].backup_reverse.clear();
//		CAR[i].backup_reverse.insert(CAR[i].backup_reverse.begin(), CAR[i].reverse.begin(), CAR[i].reverse.end());
//		CAR[i].backup_direction.clear();
//		CAR[i].backup_direction.insert(CAR[i].backup_direction.begin(), CAR[i].direction.begin(), CAR[i].direction.end());
//		CAR[i].backup_route.clear();
//		CAR[i].backup_route.insert(CAR[i].backup_route.begin(), CAR[i].route.begin(), CAR[i].route.end());
//	}
//
//	//CROSS backup
//	for (i = 0; i < crossSize; i++)
//	{
//		CROSS[i].backup_StartCar.clear();
//		CROSS[i].backup_StartCar.insert(CROSS[i].backup_StartCar.begin(), CROSS[i].StartCar.begin(), CROSS[i].StartCar.end());
//	}
//
//	//ROAD backup
//	for (i = 0; i < roadSize; i++)
//	{
//		memcpy(ROAD[i].backup_roadCar, ROAD[i].roadCar, sizeof(ROAD[i].roadCar));
//		ROAD[i].backup_nowCarNum = ROAD[i].nowCarNum;
//		ROAD[i].backup_allCarNum = ROAD[i].allCarNum;
//		memcpy(ROAD[i].backup_nowNum, ROAD[i].nowNum, sizeof(ROAD[i].nowNum));
//		memcpy(ROAD[i].backup_allNum, ROAD[i].allNum, sizeof(ROAD[i].allNum));
//		memcpy(ROAD[i].backup_crowding, ROAD[i].crowding, sizeof(ROAD[i].crowding));
//	}
//}
//
//void Dispatch::Rollback(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, const Graph_DG &OriginalCarGraph)
//{
//	//dispatch rollback
//	GlobalTime = this->backup_GlobalTime;
//	roadCarNumber = backup_roadCarNumber;
//	EmptyCarportNumber = backup_EmptyCarportNumber;
//
//	int i;
//	//CAR rollback
//	for (i = 0; i < carSize; i++)
//	{
//		CAR[i].PT = CAR[i].backup_PT;
//		CAR[i].ATD = CAR[i].backup_ATD;
//		CAR[i].EndTime = CAR[i].backup_EndTime;
//		CAR[i].nowSpeed = CAR[i].backup_nowSpeed;
//		CAR[i].maxSpeed = CAR[i].backup_maxSpeed;
//		memcpy(CAR[i].location, CAR[i].backup_location, sizeof(CAR[i].backup_location));
//		CAR[i].nextRoad = CAR[i].backup_nextRoad;
//		CAR[i].nextCross = CAR[i].backup_nextCross;
//		CAR[i].nextRoadSpeed = CAR[i].backup_nextRoadSpeed;
//		CAR[i].nextCrossDirection = CAR[i].backup_nextCrossDirection;
//		CAR[i].nextCrossDistance = CAR[i].backup_nextCrossDistance;
//		CAR[i].state = CAR[i].backup_state;
//		CAR[i].blockDistance = CAR[i].backup_blockDistance;
//		CAR[i].isReverse = CAR[i].backup_isReverse;
//		CAR[i].toNextRoad = CAR[i].backup_toNextRoad;
//		CAR[i].isTerminate = CAR[i].backup_isTerminate;
//		CAR[i].nextReverse = CAR[i].backup_nextReverse;
//		CAR[i].passRoadNumber = CAR[i].backup_passRoadNumber;
//		CAR[i].isReset = CAR[i].backup_isReset;
//		CAR[i].LastRoad = CAR[i].backup_LastRoad;
//		CAR[i].usedToBeDeadCar = CAR[i].backup_usedToBeDeadCar;
//
//		if (CAR[i].changeDeadFlag == true) {
//			CAR[i].changeDeadFlag = false;
//			this->changeDeadCarRoute(CAR[i], CROSS, ROAD, OriginalCarGraph);
//		}
//		else {
//			CAR[i].maxSP.clear();
//			CAR[i].maxSP.insert(CAR[i].maxSP.begin(), CAR[i].backup_maxSP.begin(), CAR[i].backup_maxSP.end());
//			CAR[i].reverse.clear();
//			CAR[i].reverse.insert(CAR[i].reverse.begin(), CAR[i].backup_reverse.begin(), CAR[i].backup_reverse.end());
//			CAR[i].direction.clear();
//			CAR[i].direction.insert(CAR[i].direction.begin(), CAR[i].backup_direction.begin(), CAR[i].backup_direction.end());
//			CAR[i].route.clear();
//			CAR[i].route.insert(CAR[i].route.begin(), CAR[i].backup_route.begin(), CAR[i].backup_route.end());
//		}
//	}
//
//	//CROSS rollback
//	for (i = 0; i < crossSize; i++)
//	{
//		CROSS[i].StartCar.clear();
//		CROSS[i].StartCar.insert(CROSS[i].StartCar.begin(), CROSS[i].backup_StartCar.begin(), CROSS[i].backup_StartCar.end());
//	}
//
//	//ROAD rollback
//	for (i = 0; i < roadSize; i++)
//	{
//		memcpy(ROAD[i].roadCar, ROAD[i].backup_roadCar, sizeof(ROAD[i].backup_roadCar));
//		ROAD[i].nowCarNum = ROAD[i].backup_nowCarNum;
//		ROAD[i].allCarNum = ROAD[i].backup_allCarNum;
//		memcpy(ROAD[i].nowNum, ROAD[i].backup_nowNum, sizeof(ROAD[i].backup_nowNum));
//		memcpy(ROAD[i].allNum, ROAD[i].backup_allNum, sizeof(ROAD[i].backup_allNum));
//		memcpy(ROAD[i].crowding, ROAD[i].backup_crowding, sizeof(ROAD[i].backup_crowding));
//	}
//}
//
//void Dispatch::Backup2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime)
//{
//	//dispatch backup
//	this->backup_GlobalTime2 = GlobalTime;
//	backup_roadCarNumber2 = roadCarNumber;
//	backup_EmptyCarportNumber2 = EmptyCarportNumber;
//
//	int i;
//	//CAR backup
//	for (i = 0; i < carSize; i++)
//	{
//		CAR[i].backup_PT2 = CAR[i].PT;
//		CAR[i].backup_ATD2 = CAR[i].ATD;
//		CAR[i].backup_EndTime2 = CAR[i].EndTime;
//		CAR[i].backup_nowSpeed2 = CAR[i].nowSpeed;
//		CAR[i].backup_maxSpeed2 = CAR[i].maxSpeed;
//		memcpy(CAR[i].backup_location2, CAR[i].location, sizeof(CAR[i].location));
//		CAR[i].backup_nextRoad2 = CAR[i].nextRoad;
//		CAR[i].backup_nextCross2 = CAR[i].nextCross;
//		CAR[i].backup_nextRoadSpeed2 = CAR[i].nextRoadSpeed;
//		CAR[i].backup_nextCrossDirection2 = CAR[i].nextCrossDirection;
//		CAR[i].backup_nextCrossDistance2 = CAR[i].nextCrossDistance;
//		CAR[i].backup_state2 = CAR[i].state;
//		CAR[i].backup_blockDistance2 = CAR[i].blockDistance;
//		CAR[i].backup_isReverse2 = CAR[i].isReverse;
//		CAR[i].backup_toNextRoad2 = CAR[i].toNextRoad;
//		CAR[i].backup_isTerminate2 = CAR[i].isTerminate;
//		CAR[i].backup_nextReverse2 = CAR[i].nextReverse;
//		CAR[i].backup_passRoadNumber2 = CAR[i].passRoadNumber;
//		CAR[i].backup_isReset2 = CAR[i].isReset;
//		CAR[i].backup_LastRoad2 = CAR[i].LastRoad;
//		CAR[i].backup_usedToBeDeadCar2 = CAR[i].usedToBeDeadCar;
//
//		CAR[i].backup_maxSP2.clear();
//		CAR[i].backup_maxSP2.insert(CAR[i].backup_maxSP2.begin(), CAR[i].maxSP.begin(), CAR[i].maxSP.end());
//		CAR[i].backup_reverse2.clear();
//		CAR[i].backup_reverse2.insert(CAR[i].backup_reverse2.begin(), CAR[i].reverse.begin(), CAR[i].reverse.end());
//		CAR[i].backup_direction2.clear();
//		CAR[i].backup_direction2.insert(CAR[i].backup_direction2.begin(), CAR[i].direction.begin(), CAR[i].direction.end());
//		CAR[i].backup_route2.clear();
//		CAR[i].backup_route2.insert(CAR[i].backup_route2.begin(), CAR[i].route.begin(), CAR[i].route.end());
//	}
//
//	//CROSS backup
//	for (i = 0; i < crossSize; i++)
//	{
//		CROSS[i].backup_StartCar2.clear();
//		CROSS[i].backup_StartCar2.insert(CROSS[i].backup_StartCar2.begin(), CROSS[i].StartCar.begin(), CROSS[i].StartCar.end());
//	}
//
//	//ROAD backup
//	for (i = 0; i < roadSize; i++)
//	{
//		memcpy(ROAD[i].backup_roadCar2, ROAD[i].roadCar, sizeof(ROAD[i].roadCar));
//		ROAD[i].backup_nowCarNum2 = ROAD[i].nowCarNum;
//		ROAD[i].backup_allCarNum2 = ROAD[i].allCarNum;
//		memcpy(ROAD[i].backup_nowNum2, ROAD[i].nowNum, sizeof(ROAD[i].nowNum));
//		memcpy(ROAD[i].backup_allNum2, ROAD[i].allNum, sizeof(ROAD[i].allNum));
//		memcpy(ROAD[i].backup_crowding2, ROAD[i].crowding, sizeof(ROAD[i].crowding));
//	}
//}
//
//void Dispatch::Rollback2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, const Graph_DG &OriginalCarGraph)
//{
//	//dispatch rollback
//	GlobalTime = this->backup_GlobalTime2;
//	roadCarNumber = backup_roadCarNumber2;
//	EmptyCarportNumber = backup_EmptyCarportNumber2;
//
//	int i;
//	//CAR rollback
//	for (i = 0; i < carSize; i++)
//	{
//		CAR[i].PT = CAR[i].backup_PT2;
//		CAR[i].ATD = CAR[i].backup_ATD2;
//		CAR[i].EndTime = CAR[i].backup_EndTime2;
//		CAR[i].nowSpeed = CAR[i].backup_nowSpeed2;
//		CAR[i].maxSpeed = CAR[i].backup_maxSpeed2;
//		memcpy(CAR[i].location, CAR[i].backup_location2, sizeof(CAR[i].backup_location2));
//		CAR[i].nextRoad = CAR[i].backup_nextRoad2;
//		CAR[i].nextCross = CAR[i].backup_nextCross2;
//		CAR[i].nextRoadSpeed = CAR[i].backup_nextRoadSpeed2;
//		CAR[i].nextCrossDirection = CAR[i].backup_nextCrossDirection2;
//		CAR[i].nextCrossDistance = CAR[i].backup_nextCrossDistance2;
//		CAR[i].state = CAR[i].backup_state2;
//		CAR[i].blockDistance = CAR[i].backup_blockDistance2;
//		CAR[i].isReverse = CAR[i].backup_isReverse2;
//		CAR[i].toNextRoad = CAR[i].backup_toNextRoad2;
//		CAR[i].isTerminate = CAR[i].backup_isTerminate2;
//		CAR[i].nextReverse = CAR[i].backup_nextReverse2;
//		CAR[i].passRoadNumber = CAR[i].backup_passRoadNumber2;
//		CAR[i].isReset = CAR[i].backup_isReset2;
//		CAR[i].LastRoad = CAR[i].backup_LastRoad2;
//		CAR[i].usedToBeDeadCar = CAR[i].backup_usedToBeDeadCar2;
//
//		if (CAR[i].changeDeadFlag == true) {
//			CAR[i].changeDeadFlag = false;
//			this->changeDeadCarRoute(CAR[i], CROSS, ROAD, OriginalCarGraph);
//		}
//		else {
//			CAR[i].maxSP.clear();
//			CAR[i].maxSP.insert(CAR[i].maxSP.begin(), CAR[i].backup_maxSP2.begin(), CAR[i].backup_maxSP2.end());
//			CAR[i].reverse.clear();
//			CAR[i].reverse.insert(CAR[i].reverse.begin(), CAR[i].backup_reverse2.begin(), CAR[i].backup_reverse2.end());
//			CAR[i].direction.clear();
//			CAR[i].direction.insert(CAR[i].direction.begin(), CAR[i].backup_direction2.begin(), CAR[i].backup_direction2.end());
//			CAR[i].route.clear();
//			CAR[i].route.insert(CAR[i].route.begin(), CAR[i].backup_route2.begin(), CAR[i].backup_route2.end());
//		}
//	}
//
//	//CROSS rollback
//	for (i = 0; i < crossSize; i++)
//	{
//		CROSS[i].StartCar.clear();
//		CROSS[i].StartCar.insert(CROSS[i].StartCar.begin(), CROSS[i].backup_StartCar2.begin(), CROSS[i].backup_StartCar2.end());
//	}
//
//	//ROAD rollback
//	for (i = 0; i < roadSize; i++)
//	{
//		memcpy(ROAD[i].roadCar, ROAD[i].backup_roadCar2, sizeof(ROAD[i].backup_roadCar2));
//		ROAD[i].nowCarNum = ROAD[i].backup_nowCarNum2;
//		ROAD[i].allCarNum = ROAD[i].backup_allCarNum2;
//		memcpy(ROAD[i].nowNum, ROAD[i].backup_nowNum2, sizeof(ROAD[i].backup_nowNum2));
//		memcpy(ROAD[i].allNum, ROAD[i].backup_allNum2, sizeof(ROAD[i].backup_allNum2));
//		memcpy(ROAD[i].crowding, ROAD[i].backup_crowding2, sizeof(ROAD[i].backup_crowding2));
//	}
//}

void Dispatch::givePT(vector<Car> &CAR)
{
	for (int i = 0; i < (int)(CAR.size()); i++)
	{
		oldPT.push_back(CAR[i].PT);
	}
}

void Dispatch::recoveryPT(vector<Car> &CAR)
{
	for (int i = 0; i < (int)(CAR.size()); i++)
	{
		CAR[i].PT = oldPT[i];
	}
}

void Dispatch::computeRoadCrowding(vector<Road> &ROAD)
{
	int num, m, k, j;
	int firstCH = 0;
	for (num = 0; num < roadSize; num++)
	{
		ROAD[num].nowCarNum = 0;
		ROAD[num].nowNum[0] = 0;
		ROAD[num].nowNum[1] = 0;
		for (m = 0; m < 2; m++)
		{
			if (m == 1 && ROAD[num].isDuplex == 0)
				break;
			for (k = 0; k < ROAD[num].channel; k++)
				for (j = 0; j < ROAD[num].length; j++)
				{
					if (ROAD[num].roadCar[m][k][j] != -1)
					{
						if (k == 0)
							++firstCH;
						++ROAD[num].nowCarNum;
						++ROAD[num].nowNum[m];
					}
				}
			ROAD[num].allNum[m] += ROAD[num].nowNum[m];
			//ROAD[num].crowding[m] = 0.8*(float)(firstCH) / (float)(ROAD[num].length) +0.2*( float)(ROAD[num].nowNum[m]) / ( float)(ROAD[num].channel*ROAD[num].length);
			ROAD[num].crowding[m] = (float)(ROAD[num].nowNum[m]) / (float)(ROAD[num].channel*ROAD[num].length);
		}
		ROAD[num].allCarNum += ROAD[num].nowCarNum;
	}
}

void Dispatch::setLimitNum(int limitNum)
{
	RANUM = limitNum;
}

void Dispatch::setRoadCarNUm(int Num)
{
	roadCarNumber = Num;
}

vector<int> Dispatch::getCar2(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR,int COUNT)
{
	vector<int> lockCar;
	int i, j;
	int count = 0;
	roadID = roadID - ROAD[0].id;
	for (i = ROAD[roadID].length - 1; i >= 0; i--) //λ�ôӸߵ���
	{
		for (j = 0; j < ROAD[roadID].channel; j++) //������С����
		{
			if (ROAD[roadID].roadCar[dir][j][i] == -1)
				continue;
			int carID = ROAD[roadID].roadCar[dir][j][i] - car0;
			if (CAR[carID].state == 0 && CAR[carID].toNextRoad == 1)
			{
				lockCar.push_back(carID + car0);
				++count;
			}
			if (count > COUNT)
				return lockCar;
		}
	}
	return lockCar;
}

vector<int> Dispatch::getCar3(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT)
{
	vector<int> lockCar;
	int i, j;
	int count = 0;
	roadID = roadID - ROAD[0].id;
	for (i = ROAD[roadID].length - 1; i >= 0; i--) //λ�ôӸߵ���
	{
		for (j = 0; j < ROAD[roadID].channel; j++) //������С����
		{
			if (ROAD[roadID].roadCar[dir][j][i] == -1)
				continue;
			int carID = ROAD[roadID].roadCar[dir][j][i] - car0;
			if (CAR[carID].state == 0)
			{
				lockCar.push_back(carID + car0);
				++count;
			}
			if (count > COUNT)
				return lockCar;
		}
	}
	return lockCar;
}

vector<int> Dispatch::getCar4(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT)
{
	vector<int> lockCar;
	int i, j;
	int count = 0;
	roadID = roadID - ROAD[0].id;
	for (i = ROAD[roadID].length - 1; i >= 0; i--) //λ�ôӸߵ���
	{
		for (j = 0; j < ROAD[roadID].channel; j++) //������С����
		{
			if (ROAD[roadID].roadCar[dir][j][i] == -1)
				continue;
			int carID = ROAD[roadID].roadCar[dir][j][i] - car0;
			if (CAR[carID].state == 0 && CAR[carID].toNextRoad != 1)
			{
				lockCar.push_back(carID + car0);
				++count;
			}
			if (count > COUNT)
				return lockCar;
		}
	}
	return lockCar;
}

vector<int> Dispatch::getCar5(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT)
{
	vector<int> allCar;
	int i, j;
	int count = 0;
	roadID = roadID - ROAD[0].id;
	for (i = ROAD[roadID].length - 1; i >= 0; i--) //λ�ôӸߵ���
	{
		for (j = 0; j < ROAD[roadID].channel; j++) //������С����
		{
			if (ROAD[roadID].roadCar[dir][j][i] == -1)
				continue;
			int carID = ROAD[roadID].roadCar[dir][j][i] - car0;
			allCar.push_back(carID + car0);
			++count;
			if (count > COUNT)
				return allCar;
		}
	}
	return allCar;
}

//int Dispatch::searchBestTime1(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
//{
//	int GlobalTime = 1;
//	vector<Car> bestCAR,tempCAR;
//	bestCAR.insert(bestCAR.begin(), CAR.begin(), CAR.end());
//	int bestTime = dispathMAIN(bestCAR, CROSS, ROAD, GlobalTime, 0, BADTIME);
//	cout << bestTime << endl;
//	int count = 0;
//	while (count < 100)
//	{
//		tempCAR.clear();
//		tempCAR.insert(tempCAR.begin(), bestCAR.begin(), bestCAR.end());
//
//		subEndCarPT(tempCAR, count);
//
//		GlobalTime = 1;
//		int newTime = dispathMAIN(tempCAR, CROSS, ROAD, GlobalTime, 1, bestTime);
//		cout << newTime << endl;
//		if (newTime < bestTime)
//		{
//			bestTime = newTime;
//			swap(tempCAR, bestCAR);
//		}
//		++count;
//	}
//
//	swap(bestCAR, CAR);
//	return bestTime;
//}

int Dispatch::searchBestTime2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
{
	vector<int> ATDneed;
	vector<Car> bestCAR;
	vector<Car> tempCAR;
	vector<Cross> tempCROSS;
	vector<Road> tempROAD;

	tempCAR.insert(tempCAR.begin(), CAR.begin(), CAR.end());
	tempCROSS.insert(tempCROSS.begin(), CROSS.begin(), CROSS.end());
	tempROAD.insert(tempROAD.begin(), ROAD.begin(), ROAD.end());

	int GlobalTime = 1;
	int bestTime = dispathMAIN(tempCAR, tempCROSS, tempROAD, GlobalTime, 0, BADTIME);

	for (int i = 0; i < (int)(tempCAR.size()); i++)
	{
		CAR[i].setPT(tempCAR[i].PT);
		ATDneed.push_back(tempCAR[i].ATD);
	}

	int count = 0;
	while (count < 100)
	{
		tempCAR.clear();
		tempCROSS.clear();
		tempROAD.clear();
		tempCAR.insert(tempCAR.begin(), CAR.begin(), CAR.end());
		tempCROSS.insert(tempCROSS.begin(), CROSS.begin(), CROSS.end());
		tempROAD.insert(tempROAD.begin(), ROAD.begin(), ROAD.end());

		subEndCarPT(tempCAR, count);

		GlobalTime = 1;
		int newTime = dispathMAIN(tempCAR, tempCROSS, tempROAD, GlobalTime, 0, bestTime);
		//int newTime = mainLoop(tempCAR1, tempCROSS1, tempROAD1, GlobalTime, 1, bestTime);
		cout << newTime << endl << endl;

		if (newTime < bestTime)
		{
			bestTime = newTime;
			ATDneed.clear();
			for (int i = 0; i < (int)(tempCAR.size()); i++)
			{
				CAR[i].setPT(tempCAR[i].PT);
				ATDneed.push_back(tempCAR[i].ATD);
			}
		}
		++count;
	}

	for (int i = 0; i < (int)(ATDneed.size()); i++)
	{
		CAR[i].setATD(ATDneed[i]);	
	}

	return bestTime;
}

int Dispatch::mainLoop1(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bsetTime)
{
	int bestTime = dispathMAIN(CAR, CROSS, ROAD, GlobalTime, 0, BADTIME);
	int count = 0;
	while (bestTime== BADTIME && count < 30)
	{
		++count;
		GlobalTime = 1;
		deadLockProcess1(CAR, CROSS, ROAD);
		int nowTime = dispathMAIN(CAR, CROSS, ROAD, GlobalTime, 1, BADTIME);
		cout << nowTime << endl;
		if (nowTime < BADTIME)
		{
			bestTime = nowTime;
			break;
		}
	}
	return bestTime;
}

int Dispatch::mainLoop2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bsetTime)
{
	int bestTime = BADTIME;
	vector<int> deadCar;
	vector<Car> tempCAR;
	vector<Cross> tempCROSS;
	vector<Road> tempROAD;
	int count = 0;
	while (count < 100)
	{
		tempCAR.clear();
		tempCROSS.clear();
		tempROAD.clear();
		tempCAR.insert(tempCAR.begin(), CAR.begin(), CAR.end());
		tempCROSS.insert(tempCROSS.begin(), CROSS.begin(), CROSS.end());
		tempROAD.insert(tempROAD.begin(), ROAD.begin(), ROAD.end());

		if (deadCar.size() > 0)
		{
			for (int i = 0; i < (int)(deadCar.size()); i++)
			{
				int RandomNumber = rand() % 10 + 1;//����1~5�����
				tempCAR[deadCar[i] - car0].addPT(RandomNumber);
			}
		}
		
		GlobalTime = 1;
		int tempTime = dispathMAIN(tempCAR, tempCROSS, tempROAD, GlobalTime, 0, BADTIME);
		if (tempTime == BADTIME)
		{
			deadCar.clear();
			deadCar = getDeadCarFirstAll(tempCAR, tempCROSS, tempROAD);
		}

		if (tempTime < BADTIME)
		{
			bestTime = tempTime;
			swap(tempCAR, CAR);
			break;
		}

		++count;
	}

	return bestTime;
}

void Dispatch::deadLockProcess1(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
{
	int carNumber = 0, roadOrder = 0;
	vector<int> roadIDS, dir, lockCar;
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		roadIDS.clear();
		roadIDS.push_back(CROSS[num].road1);
		roadIDS.push_back(CROSS[num].road2);
		roadIDS.push_back(CROSS[num].road3);
		roadIDS.push_back(CROSS[num].road4);
		sort(roadIDS.begin(), roadIDS.end());

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		dir.clear();
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
			{
				dir.push_back(-1);
				continue;
			}
			if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
				dir.push_back(0);
			else
				dir.push_back(1);
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ�ȴ��ĳ�
				lockCar = getCar3(roadIDS[q], dir[q], ROAD, CAR, 200);
				carNumber = (int)(lockCar.size());
				cout << carNumber << "---------------------" << endl;
				for (int i = 0; i < carNumber; i++)
				{
					//Ӧ���������ĳ������ܵطֿ���������������������need modify
					//int RandomNumber = rand() % 20 + 1;//����1~5�����
					CAR[lockCar[i] - car0].addPT(roadOrder + i);
					//CAR[lockCar[i] - car0].addPT(RandomNumber);
				}
				++roadOrder;
				break;
			}
		}
	}
}

void Dispatch::deadLockProcess2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
{
	int carNumber = 0;
	vector<int> roadIDS, dir, lockCar;
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		roadIDS.clear();
		roadIDS.push_back(CROSS[num].road1);
		roadIDS.push_back(CROSS[num].road2);
		roadIDS.push_back(CROSS[num].road3);
		roadIDS.push_back(CROSS[num].road4);
		sort(roadIDS.begin(), roadIDS.end());

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		dir.clear();
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
			{
				dir.push_back(-1);
				continue;
			}
			if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
				dir.push_back(0);
			else
				dir.push_back(1);
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��ǰ��·�ϵ����еȴ��ĳ�
				lockCar = getCar3(roadIDS[q], dir[q], ROAD, CAR, 200);
				carNumber = (int)(lockCar.size());
				for (int i = 0; i < carNumber; i++)
				{
					//Ӧ���������ĳ�ȫ������������ٴ���
					CAR[lockCar[i] - car0].addPT(9999);
				}
				break;
			}
		}
	}
}

void Dispatch::deadLockProcess3(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
{
	int carNumber = 0, roadOrder = 0;
	vector<int> roadIDS, dir, lockCar1, lockCar2;
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		roadIDS.clear();
		roadIDS.push_back(CROSS[num].road1);
		roadIDS.push_back(CROSS[num].road2);
		roadIDS.push_back(CROSS[num].road3);
		roadIDS.push_back(CROSS[num].road4);
		sort(roadIDS.begin(), roadIDS.end());

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		dir.clear();
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
			{
				dir.push_back(-1);
				continue;
			}
			if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
				dir.push_back(0);
			else
				dir.push_back(1);
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��ǰ��·�ϵĵȴ��ҹ��¸�·�ڵĳ���ȫ����Զ
				lockCar1 = getCar2(roadIDS[q], dir[q], ROAD, CAR, 200);
				carNumber = (int)(lockCar1.size());
				for (int i = 0; i < carNumber; i++)
				{
					//Ӧ���������ĳ�ȫ������������ٴ���
					CAR[lockCar1[i] - car0].addPT(9999);
				}

				//��ȡ��ǰ��·�ϵĵȴ��Ҳ����¸�·�ڵĳ���ԭ�ش�ɢ
				lockCar2 = getCar3(roadIDS[q], dir[q], ROAD, CAR, 200);
				carNumber = (int)(lockCar2.size());
				for (int i = 0; i < carNumber; i++)
				{
					CAR[lockCar2[i] - car0].addPT(roadOrder + i);
				}
				++roadOrder;
				break;
			}
		}
	}
}

vector<int> Dispatch::getDeadCarID(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
{
	vector<int> tempDeadCar, deadCar;

	for (int num = 0; num < crossSize; num++)
	{
		int roadIDS[4] = { CROSS[num].road1,CROSS[num].road2, CROSS[num].road3, CROSS[num].road4 };
		sort(roadIDS, roadIDS + 4); //��С��������

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		int dir[4];
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
				continue;
			if (ROAD[roadIDS[q] - road0].to == num + cross0)
				dir[q] = 0;
			else
				dir[q] = 1;
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��һ���ȼ��ĳ�...
				tempDeadCar.clear();
				tempDeadCar = getCar3(roadIDS[q], dir[q], ROAD, CAR, 15);
				deadCar.insert(deadCar.end(), tempDeadCar.begin(), tempDeadCar.end());
				break;
			}
		}
	}
	return deadCar;
}

vector<int> Dispatch::getDeadCarFirstAll(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD)
{
	vector<int> deadCar;
	//int count = 0;
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���

		vector<int> roadIDS;
		roadIDS.push_back(CROSS[num].road1);
		roadIDS.push_back(CROSS[num].road2);
		roadIDS.push_back(CROSS[num].road3);
		roadIDS.push_back(CROSS[num].road4);
		sort(roadIDS.begin(), roadIDS.end());

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		vector<int> dir;
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
			{
				dir.push_back(-1);
				continue;
			}
			if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
				dir.push_back(0);
			else
				dir.push_back(1);
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ�ȴ��ĵ�һ���ȼ��ĳ�
				int carID = getCar(roadIDS[q], dir[q], ROAD, CAR);
				if (carID == -1)
					break;
				deadCar.push_back(carID);
				//int RandomNumber = rand() % 10 + 1;//����1~5�����
				//CAR[carID - car0].addPT(RandomNumber);
				//++count;
				//if (count > 10)
				//	return true;
				break;
			}
		}
	}
	return deadCar;
}

void Dispatch::clearData()
{
	allCarSpeed.clear();
	priorityCarSpeed.clear();
	allCarPlanTime.clear();
	allCarEndTime.clear();
	priorityCarPlanTime.clear();
	priorityCarEndTime.clear();
	allCarFrom.clear();
	priorityCarFrom.clear();
	allCarTo.clear();
	priorityCarTo.clear();
}

void Dispatch::computeData(vector<Car> &CAR)
{
	clearData();

	Tsum = 0;
	Tsumpri = 0;
	priorityCarSize = 0;
	for (int i = 0; i < carSize; i++)
	{
		//���ٶȣ�ʵ�ʳ���ʱ�䣬�����أ���ֹ��
		Tsum += CAR[i].EndTime - CAR[i].planTime;
		allCarSpeed.push_back(CAR[i].speed);
		allCarPlanTime.push_back(CAR[i].planTime);
		allCarEndTime.push_back(CAR[i].EndTime);
		allCarFrom.insert(CAR[i].from);
		allCarTo.insert(CAR[i].to);
		if (CAR[i].priority == 1)
		{
			++priorityCarSize;
			Tsumpri += CAR[i].EndTime - CAR[i].planTime;
			priorityCarSpeed.push_back(CAR[i].speed);
			priorityCarPlanTime.push_back(CAR[i].planTime);
			priorityCarEndTime.push_back(CAR[i].EndTime);
			priorityCarFrom.insert(CAR[i].from);
			priorityCarTo.insert(CAR[i].to);
		}
	}

	//����
	sort(allCarSpeed.begin(), allCarSpeed.end());
	sort(priorityCarSpeed.begin(), priorityCarSpeed.end());
	sort(allCarPlanTime.begin(), allCarPlanTime.end());
	sort(allCarEndTime.begin(), allCarEndTime.end());
	sort(priorityCarPlanTime.begin(), priorityCarPlanTime.end());
	sort(priorityCarEndTime.begin(), priorityCarEndTime.end());
}

int Dispatch::computeT()
{
	T = allCarEndTime[allCarEndTime.size() - 1];
	return T;
}

//�������ȳ�������ʱ��
int Dispatch::computeTpri()
{
	Tpri = priorityCarEndTime[priorityCarEndTime.size() - 1] - priorityCarPlanTime[0];
	return Tpri;
}

double toFive(double x)
{
	double a;
	a= (double)((round(x*100000.0))) / (double)(100000.0);
	return a;
}

//�������յ���ʱ��:TE = a*Tpri + T
int Dispatch::computeTE(vector<Car> &CAR)
{
	if (isDeadlock == true)
		return BADTIME;

	computeData(CAR);

	T = computeT();
	Tpri = computeTpri();

	//0.05*(��������/���ȳ�����)
	 double allCarNumber = ( double)(carSize);
	 double priorityCarNumber = ( double)(priorityCarSize);
	a1 = toFive(allCarNumber / priorityCarNumber);

	//0.2375*((���г�����߳���/���г�����ͳ���)/(���ȳ�����߳���/���ȳ�����ͳ���))
	 double allCarMaxSpeed = ( double)(allCarSpeed[allCarSpeed.size()-1]);
	 double allCarMinSpeed = ( double)(allCarSpeed[0]);
	 double priorityCarMaxSpeed = ( double)(priorityCarSpeed[priorityCarSpeed.size()-1]);
	 double priorityCarMinSpeed = ( double)(priorityCarSpeed[0]);
	a2 = toFive(toFive(allCarMaxSpeed / allCarMinSpeed) / toFive(priorityCarMaxSpeed / priorityCarMinSpeed));


	//0.2375*((���г����������ʱ��/���г����������ʱ��)/(���ȳ����������ʱ��/���ȳ����������ʱ��))
	 double allCarLastPlanTime = ( double)(allCarPlanTime[allCarPlanTime.size()-1]);
	 double allCarFirstPlanTime = ( double)(allCarPlanTime[0]);
	 double priorityCarLastPlanTime = ( double)(priorityCarPlanTime[priorityCarPlanTime.size()-1]);
	 double priorityCarFirstPlanTime = ( double)(priorityCarPlanTime[0]);
	a3 = toFive(toFive(allCarLastPlanTime / allCarFirstPlanTime) / toFive(priorityCarLastPlanTime / priorityCarFirstPlanTime));

	//0.2375*(���г��������طֲ�/���ȳ��������طֲ�)
	 double allCarStartDistribute = ( double)(allCarFrom.size());
	 double priorityCarStartDistribute = ( double)(priorityCarFrom.size());
	a4 = toFive(allCarStartDistribute / priorityCarStartDistribute);

	//0.2375*(���г�����ֹ�طֲ�/���ȳ�����ֹ�طֲ�)
	 double allCarEndDistribute = ( double)(allCarTo.size());
	 double priorityCarEndDistribute = ( double)(priorityCarTo.size());
	a5 = toFive(allCarEndDistribute / priorityCarEndDistribute);

	//���
	 double a = (double)(0.05*a1) + (double)(0.2375*a2) + (double)(0.2375*a3) + (double)(0.2375*a4) + (double)(0.2375*a5);

	 cout << "a is " << a << endl;
	 cout << "T is " << T << ", Tpri is " << Tpri << endl;

	//�������յ���ʱ��
	TE = (int)(round(a*( double)(Tpri)+( double)(T)));

	return TE;
}

//���������ܵ���ʱ��:TESum = b*Tsumpri + Tsum
int Dispatch::computeTEsum(vector<Car> &CAR)
{
	if (isDeadlock == true)
		return BADTIME;

	//0.8*(��������/���ȳ�����)
	//0.05*((���г�����߳���/���г�����ͳ���)/(���ȳ�����߳���/���ȳ�����ͳ���))
	//0.05*((���г����������ʱ��/���г����������ʱ��)/(���ȳ����������ʱ��/���ȳ����������ʱ��))
	//0.05*(���г��������طֲ�/���ȳ��������طֲ�)
	//0.05*(���г�����ֹ�طֲ�/���ȳ�����ֹ�طֲ�)

	//���
	 double b = (double)(0.8*a1) + (double)(0.05*a2) + (double)(0.05*a3) + (double)(0.05*a4) + (double)(0.05*a5);

	 cout << "b is " << b << endl;
	 cout << "Tsum is " << Tsum << ", Tsumpri is " << Tsumpri << endl;

	//�������յ���ʱ��
	TEsum = (int)(round(b*( double)(Tsumpri)+( double)(Tsum)));

	return TEsum;
}

int Dispatch::searchBestBatchNum(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int batchNum, int t, int limitNum)
{
	int GlobalTime = 1;
	int bestBatchNum = batchNum;
	int bestTime = BADTIME;
	int count = 0;
	while (count < 100)
	{
		vector<Car> tempCAR;
		vector<Cross> tempCROSS;
		vector<Road> tempROAD;
		tempCAR.insert(tempCAR.begin(), CAR.begin(), CAR.end());
		tempCROSS.insert(tempCROSS.begin(), CROSS.begin(), CROSS.end());
		tempROAD.insert(tempROAD.begin(), ROAD.begin(), ROAD.end());

		int tempBatchNum = batchNum - 50 + count;
		Batch2(tempCAR, tempBatchNum,t);
		setLimitNum(limitNum);

		GlobalTime = 1;
		int tempTime = dispathMAIN(tempCAR, tempCROSS, tempROAD, GlobalTime, 0, BADTIME);
		
		tempTime = computeTE(tempCAR);
		if (tempTime < bestTime)
		{
			bestBatchNum = tempBatchNum;
			bestTime = tempTime;
		}

		cout << "batchNum " << tempBatchNum << " , Time is " << tempTime << ", bestBatchNum is " << bestBatchNum << ", best time is " << bestTime << endl;
		++count;
	}
	return bestBatchNum;
}

int Dispatch::searchBestLimitNum(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int batchNum,int limitNum)
{
	int GlobalTime = 1;
	int bestLimitNum = limitNum;
	int bestTime = BADTIME;
	int count = 0;
	while (count < 100)
	{
		vector<Car> tempCAR;
		vector<Cross> tempCROSS;
		vector<Road> tempROAD;
		tempCAR.insert(tempCAR.begin(), CAR.begin(), CAR.end());
		tempCROSS.insert(tempCROSS.begin(), CROSS.begin(), CROSS.end());
		tempROAD.insert(tempROAD.begin(), ROAD.begin(), ROAD.end());

		int tempLimitNum = limitNum + 250 - 5*count;
		Batch1(tempCAR, batchNum,1);
		setLimitNum(tempLimitNum);

		GlobalTime = 1;
		int tempTime = dispathMAIN(tempCAR, tempCROSS, tempROAD, GlobalTime, 0, BADTIME);
		//int tempTime= mainLoop(CAR, CROSS, ROAD, GlobalTime, 0, BADTIME);

		if (tempTime < bestTime)
		{
			bestLimitNum = tempLimitNum;
			bestTime = tempTime;
		}

		cout << "limitNum " << tempLimitNum << " , Time is " << tempTime << ", bestLimitNum is " << bestLimitNum << ", best time is " << bestTime << endl;
		++count;
	}
	return bestLimitNum;
}

void Dispatch::resetRoadCarNumber()
{
	roadCarNumber = 0;
}

void Dispatch::addRoadCarNumber()
{
	roadCarNumber = roadCarNumber + 1;
}

void Dispatch::subRoadCarNumber()
{
	roadCarNumber = roadCarNumber - 1;
}

bool Dispatch::controlInitCar(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime)
{
	int i, j, count;
	//ɨ�赱ǰʱ�̿ɷ���Ԥ�ó�����SDCar��Ԥ�ó�����presetCar
	vector<int> SDCar, presetCar;
	for (i = 0; i < crossSize; i++)
	{
		if ((int)(CROSS[i].StartCar.size()) == 0)
			continue;
		for (j = 0; j < (int)(CROSS[i].StartCar.size()); j++)
		{
			int carID = CROSS[i].StartCar[j] - car0;
			if (CAR[carID].PT <= GlobalTime)
			{
				if (CAR[carID].preset == 0)
					SDCar.push_back(carID);
				if (CAR[carID].preset == 1)
					presetCar.push_back(carID);
			}
		}
	}
	//���û�пɷ���Ԥ�ó���ֱ��GG�ͺ�
	if ((int)(SDCar.size()) == 0)
		return false;

	/*****************ע�Ͳ�������û��batch()�����Ҫ��ʹ�õ�**********************/
	//speedAll�����е��ٶ�����
	int num;
	set<int, less<int>> speedAll;
	for (num = 0; num < (int)(SDCar.size()); num++)
	{
		speedAll.insert(CAR[SDCar[num]].speed);
	}

	//�ٶȴ�С��������
	count = 0;
	set<int>::iterator it;
	vector<vector<int>> speedIndex;
	for (it = speedAll.begin(); it != speedAll.end(); it++)
	{
		vector<int> tempVEC;
		speedIndex.push_back(tempVEC);
		for (num = 0; num < (int)(SDCar.size()); num++)
		{
			if (CAR[SDCar[num]].speed == *it)
				speedIndex[count].push_back(SDCar[num]);
		}
		++count;
	}

	//��������������
	vector<int> IndexAll;
	for (i = 0; i < (int)(speedIndex.size()); i++)
	{
		IndexAll.insert(IndexAll.end(), speedIndex[i].begin(), speedIndex[i].end());
	}

	////��������������
	//vector<int> IndexAll;
	//IndexAll.insert(IndexAll.end(), SDCar.begin(), SDCar.end());

	int N1 = (int)(presetCar.size());  //�ɷ�Ԥ�ó�����
	int N2 = (int)(SDCar.size());	   //�ɷ���Ԥ�ó�����

	if (N1 >= RANUM)	//�ɷ�Ԥ�ó���Ŀ���ˣ������з�Ԥ�ó�PT+1
	{
		for (i = 0; i < (int)(IndexAll.size()); i++)
		{
			CAR[IndexAll[i]].addPT(1);
		}
	}

	if (N1 < RANUM)		//�ɷ�Ԥ�ó���Ŀ������ʣ�µĴӷ�Ԥ�ó��в���
	{
		int Need = RANUM - N1;	//��󲹳�����

		if (N2 <= Need) 		//�ɷ���Ԥ�ó���������
			return false;

		if (N2 > Need)			//�ɷ���Ԥ�ó�����������������PT+1
		{
			//�������ȳ�:�����ӳٷ����ȳ�
			count = 0;
			for (i = 0; i < (int)(IndexAll.size()); i++)
			{
				if (count >= (N2 - Need))
					break;
				if (CAR[IndexAll[i]].priority == 0)
				{
					CAR[IndexAll[i]].addPT(1);
					++count;
				}
			}
			if (count < (N2 - Need))
			{
				for (i = 0; i < (int)(IndexAll.size()); i++)
				{
					if (count >= (N2 - Need))
						break;
					if (CAR[IndexAll[i]].priority == 1)
					{
						CAR[IndexAll[i]].addPT(0);
						++count;
					}
				}
			}
		}
	}

	return true;
}

bool Dispatch::modifyPlantime(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime)
{
	int i, j;
	//ɨ�赱ǰʱ�̿ɷ���Ԥ�ó�����SDCar��Ԥ�ó�����presetCar
	vector<int> SDCar, presetCar;
	for (i = 0; i < crossSize; i++)
	{
		if ((int)(CROSS[i].StartCar.size()) == 0)
			continue;
		for (j = 0; j < (int)(CROSS[i].StartCar.size()); j++)
		{
			int carID = CROSS[i].StartCar[j] - car0;
			//ע�⣺��Щ��PT�Ѵ�����Ѿ���·���ˣ�����ɷ���
			if (CAR[carID].PT <= (GlobalTime + 1) && CAR[carID].ATD == -1)
			{
				if (CAR[carID].preset == 0)
					SDCar.push_back(carID);
				if (CAR[carID].preset == 1)
					presetCar.push_back(carID);
			}
		}
	}
	//���û�пɷ���Ԥ�ó���ֱ��GG�ͺ�
	if ((int)(SDCar.size()) == 0)
		return false;

	if (roadCarNumber >= RANUM)			//��·�ϳ���̫��,��׼�����������з�Ԥ�ó�PT+1
	{
		for (i = 0; i < (int)(SDCar.size()); i++)
		{
			int carID = SDCar[i];
			CAR[carID].addPT(1);
		}
		return false;
	}

	int N1 = (int)(presetCar.size());  //�ɷ�Ԥ�ó�����
	int N2 = (int)(SDCar.size());	   //�ɷ���Ԥ�ó�����

	if (roadCarNumber < RANUM)			//��·�ϳ�������,��Ҫ����
	{
		int AllNeed = RANUM - roadCarNumber; //������Ҫ���ܵķ�����

		/*****************ע�Ͳ�������û��batch()�����Ҫ��ʹ�õ�**********************/
		//speedAll�����е��ٶ�����
		int num, count;
		set<int, less<int>> speedAll;
		for (num = 0; num < (int)(SDCar.size()); num++)
		{
			speedAll.insert(CAR[SDCar[num]].speed);
		}

		//�ٶȴ�С��������
		count = 0;
		set<int>::iterator it;
		vector<vector<int>> speedIndex;
		for (it = speedAll.begin(); it != speedAll.end(); it++)
		{
			vector<int> tempVEC;
			speedIndex.push_back(tempVEC);
			for (num = 0; num < (int)(SDCar.size()); num++)
			{
				if (CAR[SDCar[num]].speed == *it)
					speedIndex[count].push_back(SDCar[num]);
			}
			++count;
		}

		//��������������
		vector<int> IndexAll;
		for (i = 0; i < (int)(speedIndex.size()); i++)
		{
			IndexAll.insert(IndexAll.end(), speedIndex[i].begin(), speedIndex[i].end());
		}

		////��������������
		//vector<int> IndexAll;
		//IndexAll.insert(IndexAll.end(), SDCar.begin(), SDCar.end());

		if (N1 >= AllNeed)			//�ɷ�Ԥ�ó������ѹ��������з�Ԥ�ó�PT+1
		{
			for (i = 0; i < (int)(IndexAll.size()); i++)
			{
				CAR[IndexAll[i]].addPT(1);
			}
		}

		if (N1 < AllNeed)			//�ɷ�Ԥ�ó���������������Ҫ�ӷ�Ԥ�ó��в���
		{
			int Need = AllNeed - N1;	//��Ҫ������Ԥ�ó�����

			if (N2 <= Need) 			//�ɷ���Ԥ�ó�����
				return false;

			if (N2 > Need)				//�ɷ���Ԥ�ó������������Ĳ���PT+1
			{
				//�������ȳ�:�����ӳٷ����ȳ�
				count = 0;
				for (i = 0; i < (int)(IndexAll.size()); i++)
				{
					if (count >= (N2 - Need))
						break;
					if (CAR[IndexAll[i]].priority == 0)
					{
						CAR[IndexAll[i]].addPT(1);
						++count;
					}
				}
				if (count < (N2 - Need))
				{
					for (i = 0; i < (int)(IndexAll.size()); i++)
					{
						if (count >= (N2 - Need))
							break;
						if (CAR[IndexAll[i]].priority == 1)
						{
							CAR[IndexAll[i]].addPT(0);
							++count;
						}
					}
				}
			}
		}

	}

	return true;
}

//δ�������ȳ��������ȳ�
void Dispatch::Batch1(vector<Car> &CAR, int batchNum,int t)
{
	int i, j,num, count;

	//t-���μ����С

	//speedAll�����е��ٶ�����
	set<int, less<int>> speedAll;
	for (num = 0; num < (int)(CAR.size()); num++)
	{
		speedAll.insert(CAR[num].speed);
	}

	//�ٶȴ�С��������
	count = 0;
	set<int>::iterator it;
	vector<vector<int>> speedIndex;
	for (it = speedAll.begin(); it != speedAll.end(); it++)
	{
		vector<int> tempVEC;
		speedIndex.push_back(tempVEC);
		for (num = 0; num < (int)(CAR.size()); num++)
		{
			if (CAR[num].speed == *it)
				speedIndex[count].push_back(num);
		}
		++count;
	}

	////���ٶ������ڰ�·��"����"����
	//for (i = 0; i < (int)(speedIndex.size()); i++)
	//{
	//	//��ȡͬһ�����������е�route��С����
	//	set<int, less<int>> routeNumberAll;
	//	for (j = 0; j < (int)(speedIndex[i].size()); j++)
	//	{
	//		routeNumberAll.insert(CAR[speedIndex[i][j]].route.size());
	//	}
	//	//route�ɶ̵�������
	//	set<int>::iterator it;
	//	vector<int> tempID;
	//	for (it = routeNumberAll.begin(); it != routeNumberAll.end(); it++)
	//	{
	//		for (j = 0; j < (int)(speedIndex[i].size()); j++)
	//		{
	//			if (CAR[speedIndex[i][j]].route.size() == *it)
	//				tempID.push_back(speedIndex[i][j]);
	//		}
	//	}
	//	for (j = 0; j < (int)(speedIndex[i].size()); j++)
	//	{
	//		speedIndex[i][j] = tempID[j];
	//	}
	//}

	////���ٶ������ڰ�����ʱ������
	//for (i = 0; i < (int)(speedIndex.size()); i++)
	//{
	//	//��ȡͬһ�����������е�route��С����
	//	set<int, less<int>> planTimeAll;
	//	for (j = 0; j < (int)(speedIndex[i].size()); j++)
	//	{
	//		planTimeAll.insert(CAR[speedIndex[i][j]].planTime);
	//	}
	//	//route�ɶ̵�������
	//	set<int>::iterator it;
	//	vector<int> tempID;
	//	for (it = planTimeAll.begin(); it != planTimeAll.end(); it++)
	//	{
	//		for (j = 0; j < (int)(speedIndex[i].size()); j++)
	//		{
	//			if (CAR[speedIndex[i][j]].planTime == *it)
	//				tempID.push_back(speedIndex[i][j]);
	//		}
	//	}
	//	for (j = 0; j < (int)(speedIndex[i].size()); j++)
	//	{
	//		speedIndex[i][j] = tempID[j];
	//	}
	//}

	//��������������
	vector<int> IndexAll;
	for (i = 0; i < (int)(speedIndex.size()); i++)
	{
		IndexAll.insert(IndexAll.end(), speedIndex[i].begin(), speedIndex[i].end());
	}

	//�������޸�plantime
	count = 0;
	int interval = (int)(CAR.size()) / batchNum;
	for (i = 0; i < batchNum - 1; i++)
	for (j = i * interval; j < (i + 1)*interval; j++)
	{
		CAR[IndexAll[count++]].addPT(t*i);
	}
	for (j = (int)(CAR.size()) - interval; j < (int)(CAR.size()); j++)
	{
		CAR[IndexAll[count++]].addPT(t*(batchNum - 1));
	}

	////���ε���
	//int a1 = interval * 0.1;
	//int d = ((int)(CAR.size()) - batchNum * a1)*(2 / (batchNum*(batchNum - 1)));
	//for (i = 0; i < batchNum - 1; i++)
	//	for (j = a1+i * d; j < a1+(i + 1)*d; j++)
	//	{
	//		CAR[IndexAll[count++]].addPT(2 * i);
	//	}
	//for (j = count; j < (int)(CAR.size()); j++)
	//	CAR[IndexAll[count++]].addPT(2 * (batchNum - 1)); 

	////���εݼ�
	//int a1 = interval * 5;
	//int d = (-(int)(CAR.size()) + batchNum * a1)*(2 / (batchNum*(batchNum - 1)));
	//for (i = 0; i < batchNum - 1; i++)
	//	for (j = a1 - i * d; j < a1 - (i + 1)*d; j++)
	//	{
	//		CAR[IndexAll[count++]].addPT(2 * i);
	//	}
	//for (j = count; j < (int)(CAR.size()); j++)
	//	CAR[IndexAll[count++]].addPT(2 * (batchNum - 1));

	////ǰ������,����ǰ10ʱ�̣�ÿ��ʱ��������Ŀ100
	//int addClockNum = 100;
	//int addNumber = 50;
	//for (int time = 1; time <= addClockNum; time++)
	//{
	//	count = 0;
	//	for (i = 0; i < (int)(CAR.size()); i++)
	//	{
	//		if (count > addNumber)
	//			break;
	//		if (CAR[i].planTime == time)
	//		{
	//			CAR[i].setPT(CAR[i].planTime);
	//			++count;
	//		}
	//	}
	//}
}

vector<int> Dispatch::bathSort(vector<Car> &CAR, vector<int> &bath)
{
	int num, count, i;

	//speedAll�����е��ٶ�����
	set<int, less<int>> speedAll;
	for (num = 0; num < (int)(bath.size()); num++)
	{
		speedAll.insert(CAR[bath[num]].speed);
	}

	//�ٶȴ�С��������
	count = 0;
	set<int>::iterator it;
	vector<vector<int>> speedIndex;
	for (it = speedAll.begin(); it != speedAll.end(); it++)
	{
		vector<int> tempVEC;
		speedIndex.push_back(tempVEC);
		for (num = 0; num < (int)(bath.size()); num++)
		{
			if (CAR[bath[num]].speed == *it)
				speedIndex[count].push_back(bath[num]);
		}
		++count;
	}

	//��������������
	vector<int> IndexAll;
	for (i = 0; i < (int)(speedIndex.size()); i++)
	{
		IndexAll.insert(IndexAll.end(), speedIndex[i].begin(), speedIndex[i].end());
	}

	bath.clear();
	bath.insert(bath.begin(), IndexAll.begin(), IndexAll.end());

	return bath;
}

vector<int> Dispatch::bathSort2(vector<Car> &CAR, vector<int> &bath)
{
	int num, count, i;

	//speedAll�����е��ٶ�����
	set<int, greater<int>> speedAll;
	for (num = 0; num < (int)(bath.size()); num++)
	{
		speedAll.insert(CAR[bath[num]].speed);
	}

	//�ٶȴӴ�С����
	count = 0;
	set<int>::iterator it;
	vector<vector<int>> speedIndex;
	for (it = speedAll.begin(); it != speedAll.end(); it++)
	{
		vector<int> tempVEC;
		speedIndex.push_back(tempVEC);
		for (num = 0; num < (int)(bath.size()); num++)
		{
			if (CAR[bath[num]].speed == *it)
				speedIndex[count].push_back(bath[num]);
		}
		++count;
	}

	//��������������
	vector<int> IndexAll;
	for (i = 0; i < (int)(speedIndex.size()); i++)
	{
		IndexAll.insert(IndexAll.end(), speedIndex[i].begin(), speedIndex[i].end());
	}

	bath.clear();
	bath.insert(bath.begin(), IndexAll.begin(), IndexAll.end());

	return bath;
}

//�������ȳ��������ȳ�
void Dispatch::Batch2(vector<Car> &CAR, int batchNum, int t)
{
	int i, j, num, count;

	//t-���μ����С

	//���������Ƿ����ȷ�Ϊ��������
	vector<int> bath1, bath2;
	for (num = 0; num < (int)(CAR.size()); num++)
	{
		if (CAR[num].priority == 1)
			bath1.push_back(num);
		if (CAR[num].priority == 0)
			bath2.push_back(num);
	}

	bath1 = bathSort(CAR, bath1);
	bath2 = bathSort(CAR, bath2);	
	
	//��������
	vector<int> IndexAll;
	IndexAll.insert(IndexAll.end(), bath1.begin(), bath1.end());
	IndexAll.insert(IndexAll.end(), bath2.begin(), bath2.end());

	//�������޸�plantime
	count = 0;

	bool IS = false;
	int KK = 0;
	int interval = (int)(IndexAll.size()) / batchNum;
	for (i = 0; i < batchNum-1; i++)
	{
		for (j = i * interval; j < (i + 1)*interval; j++)
		{
			if (i == 40)
				break;
			if (CAR[IndexAll[count]].priority == 1)
				CAR[IndexAll[count]].addPT(0);
			if (CAR[IndexAll[count]].priority == 0 && KK==0)  //��һ�������ȳ�
			{
				CAR[IndexAll[count]].addPT(i*t);
			}
			if (CAR[IndexAll[count]].priority == 0 && KK == 1)  //�������εķ����ȳ�
			{
				CAR[IndexAll[count]].addPT(t*(i));
			}
			++count;
		}
		if (IS == true)
			++KK;
	}		
}

bool Dispatch::isAllEnd(vector<Car> &CAR)
{
	int count = 0;
	for (int i = 0; i < (int)(CAR.size()); i++)
	{
		if (CAR[i].state == 0)
		{
			++count;
			break;
			//cout << "car-" << CAR[i].id << " state==0" << endl;
		}
	}
	if (count == 0) //û�г��ɱ����ȣ�������
		return true;
	else
		return false;
}

bool Dispatch::subEndCarPT(vector<Car> &tempCAR, int count)
{
	int i,num;

	int changeNum, rate;
	if (count < 100)
	{
		changeNum = 1000;
		rate = 1;
	}
	if (count > 300 && count < 500)
	{
		changeNum = 10000;
		rate = 5;
	}
	if (count > 1000)
	{
		changeNum = 10000;
		rate = 2;
	}

	////���ѡ��һЩ��
	for (i = 0; i < changeNum; i++)
	{
		num = rand() % (int)(tempCAR.size()) + 1;
		tempCAR[num].subPT(rate);
	}

	//cout << endCar[endCar.size() - 1][num] << ":";
	//cout << tempCAR[endCar[endCar.size() - 1][num] - tempCAR[0].id].PT << endl;
	return true;
}

int Dispatch::gainWaitNum(vector<Car> &CAR)
{
	int count = 0;
	for (int i = 0; i < (int)(CAR.size()); i++)
	{
		if (CAR[i].state == 0)
			++count;
	}
	return count;
}

bool Dispatch::clearSF(vector<Car> &tempCar)
{
	for (int num = 0; num < (int)(tempCar.size()); num++)
	{
		tempCar[num].renew();
	}
	return true;
}

bool Dispatch::isAllTerminate(vector<Car> &CAR)
{
	int count = 0;
	for (int i = 0; i < (int)(CAR.size()); i++)
	{
		if (CAR[i].isTerminate == 0)
		{
			++count;
			break;
		}
		//else
			//cout << "car-" << CAR[i].id << " is not terminated. " << endl;
	}
	if (count == 0)
		return true;
	else
		return false;
}

//��ȡλ��roadID·��dir�����·�еĵ�һ���ȼ��ȴ���
int Dispatch::getCar(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR)
{
	int i, j, count, k;
	roadID = roadID - ROAD[0].id;
	//ɨ���һ�����ȴ�+����һ��·+����+���赲���ĳ���ֱ�ӷ��ؽ��
	for (i = ROAD[roadID].length - 1; i >= 0; i--) //λ�ôӸߵ���
	{
		for (j = 0; j < ROAD[roadID].channel; j++) //������С����
		{
			if (ROAD[roadID].roadCar[dir][j][i] == -1)
				continue;
			int carID = ROAD[roadID].roadCar[dir][j][i] - car0;
			//ɨ��ǰ���Ƿ����赲
			count = 0;
			if (i < ROAD[roadID].length - 1)
			{
				for (k = i + 1; k < ROAD[roadID].length; k++)
				{
					if (ROAD[roadID].roadCar[dir][j][k] != -1)
					{
						++count;
						break;
					}
				}
			}
			if (CAR[carID].state == 0 && CAR[carID].toNextRoad == 1 && CAR[carID].priority==1 && count==0)
				return (carID + car0);
		}
	}

	//ǰ��ɨ��ʧ�ܣ�����ɨ��õ���һ�����ȴ�+����һ��·���ĳ�����
	for (i = ROAD[roadID].length - 1; i >= 0; i--) //λ�ôӸߵ���
	{
		for (j = 0; j < ROAD[roadID].channel; j++) //������С����
		{
			if (ROAD[roadID].roadCar[dir][j][i] == -1)
				continue;
			int carID = ROAD[roadID].roadCar[dir][j][i] - car0;
			//�ȴ�+����һ��·��ֱ�ӷ��ؽ��
			if (CAR[carID].state == 0 && CAR[carID].toNextRoad == 1)
				return (carID + car0);
		}
	}

	return -1; //����ɨ��ʧ�ܣ�����·���Ѿ�û��Ҫ���¸�·�ڵĳ�
}

bool Dispatch::isConflict(int nowOrder, int carID, vector<int> &roadAll, vector<int> &dir, vector<Road> &ROAD, vector<Car> &CAR)
{
	//��ȡ��ǰ����Ҫȥ�ĵ�·
	int NEXTRoadID = CAR[carID - car0].nextRoad;
	int NEXTReverse = CAR[carID - car0].nextReverse;

	//���������յ���û����һ��·��ֱ�ӷ���
	if (CAR[carID - car0].nextCross == CAR[carID - car0].to  && NEXTRoadID == -1)
		return false;

	//���������յ�������һ��·����Ҫ���Ƿ������ȳ�����������
	//������������·�ĵ�һ���ȼ��Ƿ�Ҳ��ȥ����·�ĳ��������ȼ���carID��Ļ��ͷ���false������true
	for (int i = 0; i < 4; i++)
	{
		if (i == nowOrder)
			continue;
		if (roadAll[i] == -1) //û��·
			continue;
		int otherRoadID = roadAll[i];
		int otherDri = dir[i];
		int otherCarID = getCar(otherRoadID, otherDri, ROAD, CAR);
		if (otherCarID == -1) //��·��û�п���ȥ�¸�·�ڵĳ�
			continue;

		//��ǰ�ȴ������ȵĳ�û������Ȩ
		if (CAR[carID - car0].priority == 0)
		{
			//��������ȵĳ�Ҫȥ����·���������,ֱ��GG
			if ((CAR[otherCarID - car0].nextRoad == NEXTRoadID)
				&& (CAR[otherCarID - car0].nextReverse == NEXTReverse)
				&& (CAR[otherCarID - car0].priority == 1))
				return true;

			//�������������ͬһ����·��ͬһ���򳵵�,������һ����ת�����ȼ����ߣ��Ǿͳ�ͻ
			if ((CAR[otherCarID - car0].nextRoad == NEXTRoadID)
				&& (CAR[otherCarID - car0].nextReverse == NEXTReverse)
				&& (CAR[otherCarID - car0].nextCrossDirection < CAR[carID - car0].nextCrossDirection))
				return true;
		}

		//��ǰ�ȴ������ȵĳ�������Ȩ
		if (CAR[carID - car0].priority == 1)
		{
			//ֻ�����ȵĳ�Ҫȥ����·����������ǾͰ�ֱ>��>���жϣ�ת�䷽����߾�GG
			if ((CAR[otherCarID - car0].nextRoad == NEXTRoadID)
				&& (CAR[otherCarID - car0].nextReverse == NEXTReverse)
				&& (CAR[otherCarID - car0].priority == 1)
				&& (CAR[otherCarID - car0].nextCrossDirection < CAR[carID - car0].nextCrossDirection))
				return true;
		}
	}
	return false;
}

bool Dispatch::isRoadOver(int roadID,int dir,vector<Road> &ROAD, vector<Car> &CAR)
{
	//��û�пɵ��ȳ���˵������
	if (roadID == -1)
		return true;

	int i, j;
	int roadNum = roadID - road0;
	for (i = 0; i < ROAD[roadNum].channel; i++)
	{
		for (j = ROAD[roadNum].length - 1; j >= 0; j--)
		{
			if (ROAD[roadNum].roadCar[dir][i][j] == -1)
				continue;
			int carID = ROAD[roadNum].roadCar[dir][i][j] - car0;
			if (CAR[carID].state == 0)
				return false;
		}
	}
	return true;
}

void Dispatch::dispathINIT(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT)
{
	int num, m;
	vector<int> carCut;

	car0 = CAR[0].id, carSize = (int)(CAR.size());
	road0 = ROAD[0].id, roadSize = (int)(ROAD.size());
	cross0 = CROSS[0].id, crossSize = (int)(CROSS.size());

	if (TT >= 1)
	{
		EmptyCarportNumber = 0;
		//backup_GlobalTime = 0;
		//backup_GlobalTime2 = 0;
		for (num = 0; num < carSize; num++)
			CAR[num].renew();
		for (num = 0; num < roadSize; num++)
			ROAD[num].renew();
		for (num = 0; num < crossSize; num++)
			CROSS[num].renew();
		/*if (TT > 2)
			subEndCarPT(CAR, 50);*/
		/*if(TT==2)
			recoveryPT(CAR);
		if (TT == 1)
			subEndCarPT(CAR, 50);*/
		resetRoadCarNumber();
	}

	/************************************************T0ʱ��***************************************/
		//���ý��������·���ŶӶ���,T0ʱ��ȫ����ֱ��
	
	for (num = 0; num < carSize; num++)
	{
		//�������복�⣬�����ó�����һ����·
		CROSS[CAR[num].from - cross0].addStartCar(CAR[num].id);

		int roadID = CAR[num].route[0] - road0;
		if (CAR[num].from == ROAD[roadID].from) //����
		{
			CAR[num].addRverse(0);
			CAR[num].isRVER(0);
		}
		if (CAR[num].from == ROAD[roadID].to) //����
		{
			CAR[num].addRverse(1);
			CAR[num].isRVER(1);
		}
		//���������������ٶ�
		for (int i = 0; i < (int)(CAR[num].route.size()); i++)
		{
			int newRoadID = CAR[num].route[i] - road0;
			if (i > 0)
			{
				if (CAR[num].reverse[i - 1] == 0) //��һ��·��from-to���ǳ����н�����
				{
					int lastRoad = CAR[num].route[i - 1] - road0;
					if (ROAD[lastRoad].to == ROAD[newRoadID].from)
						CAR[num].addRverse(0);
					else
						CAR[num].addRverse(1);
				}
				if (CAR[num].reverse[i - 1] == 1) //��һ��·��to-from���ǳ����н�����
				{
					int lastRoad = CAR[num].route[i - 1] - road0;
					if (ROAD[lastRoad].from == ROAD[newRoadID].from)
						CAR[num].addRverse(0);
					else
						CAR[num].addRverse(1);
				}
			}

			if (CAR[num].speed < ROAD[CAR[num].route[i] - road0].speed)
				CAR[num].addMaxSpeed(CAR[num].speed);
			else
				CAR[num].addMaxSpeed(ROAD[CAR[num].route[i] - road0].speed);
		}
	}

	//��������Ȩ����ÿ��·�ڳ����ڵĳ������������ȳ���ǰ������planTime�������У����ڸ�ʱ�������ڱ���ID��������
	vector<int> priorityCar, tempCar;
	vector<int>::iterator pos;
	set<int, less<int>> planTimeAll;
	set<int>::iterator it;
	for (num = 0; num < crossSize; num++)
	{
		if (CROSS[num].StartCar.size() == 0)
			continue;
		priorityCar.clear();
		for (int i = 0; i < (int)(CROSS[num].StartCar.size()); i++)
		{
			if (CAR[CROSS[num].StartCar[i]-car0].priority == 1)
				priorityCar.push_back(CROSS[num].StartCar[i]);
		}

		//ɾ��ԭ�������ȳ���
		for (int j = 0; j < (int)(priorityCar.size()); j++)
		{
			pos = find(CROSS[num].StartCar.begin(), CROSS[num].StartCar.end(), priorityCar[j]);
			if (pos != CROSS[num].StartCar.end())
				CROSS[num].StartCar.erase(pos);
		}

		//�����ȳ���������ͷ
		CROSS[num].StartCar.insert(CROSS[num].StartCar.begin(), priorityCar.begin(), priorityCar.end());

		//������ĳ��������·���ŶӶ���
		for (int i = 0; i < (int)(CROSS[num].StartCar.size()); i++)
		{
			int carID = CROSS[num].StartCar[i] - car0;
			if (CAR[carID].PT <= GlobalTime)
			{
				int roadID = CAR[carID].route[0] - road0;
				if (CAR[carID].from == ROAD[roadID].from) //����
				{
					ROAD[roadID].addWaitCar(0, 0, CAR[carID].id);
				}
				if (CAR[carID].from == ROAD[roadID].to) //����
				{
					ROAD[roadID].addWaitCar(1, 0, CAR[carID].id);
				}
			}
		}
	}

	//���Ƴ�ʼ��������
	controlInitCar(CAR, CROSS, ROAD, GlobalTime);

	//����ÿ����·��ÿ������ÿ�����������ݳ���ǰ�ٶȣ�����ѡ������
	for (num = 0; num < roadSize; num++)
	{
		for (m = 0; m < 2; m++)
		{
			if (m == 1 && ROAD[num].isDuplex == 0)
				break;

			if ((int)(ROAD[num].WaitCar[m][0].size()) == 0) //�������·�ĳ�Ϊ��
				continue;

			int carNum = 0, i = 0, flag = 0, lastCarId = 0, count = 0;	//i��ʾ����id
			carCut.clear();
			while (carNum < (int)(ROAD[num].WaitCar[m][0].size()))
			{
				if (ROAD[num].roadCar[m][i][0] != -1) //��������������һ������
				{
					++i;
					flag = 1;
					if (i == ROAD[num].channel)
						break;
					continue;
				}
				int carID = ROAD[num].WaitCar[m][0][carNum] - car0;

				//���µ�ǰ�ٶ�
				if (CAR[carID].speed > ROAD[num].speed)
					CAR[carID].setNowSpeed(ROAD[num].speed);
				else
					CAR[carID].setNowSpeed(CAR[carID].speed);

				//���µ�ǰλ��
				if (count == 0 || flag == 1) //��һ�������߻����ĵ�һ����
				{
					CAR[carID].updateLocation(ROAD[num].id, i, CAR[carID].nowSpeed); //���³���λ��
					CAR[carID].setATD(GlobalTime);	//����ʵ�ʳ���ʱ��
					ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0); //���µ�·�ĳ���λ��
					lastCarId = carID; //������һ��λ�ó���id
					flag = 0;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				if (CAR[carID].nowSpeed < CAR[lastCarId].location[2])	//�ռ乻
				{
					CAR[carID].updateLocation(ROAD[num].id, i, CAR[carID].nowSpeed);
					CAR[carID].setATD(GlobalTime);
					ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
					lastCarId = carID;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				CAR[carID].updateLocation(ROAD[num].id, i, CAR[lastCarId].location[2] - 1); //�ռ䲻��
				CAR[carID].setATD(GlobalTime);
				ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
				lastCarId = carID;
				carCut.push_back(carID + car0);
				++carNum;
				++count;
			}

			//��յ�·�Ŷӳ���
			ROAD[num].clearWaitCar(m);
			if (m == 0) //����
				CROSS[ROAD[num].from - cross0].subStartCar(carCut);
			else //����
				CROSS[ROAD[num].to - cross0].subStartCar(carCut);
		}
	}
}

void Dispatch::setState(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime)
{
	int num, m, i, j, k, count;

	//����nextRoad,nextRoadSpeed,nextCrossDirection,nextCrossDistance
	for (num = 0; num < carSize; num++)
	{
		CAR[num].toNextRoad = 0;
		CAR[num].setState(-1);
		if (CAR[num].isTerminate == 1)
			continue;
		if (CAR[num].ATD > 0)
		{
			CAR[num].computeNEXT(ROAD, CROSS);
			addRoadCarNumber();
		}
	}

	//������·�ӳ��ڵ����ɨ�����ó���״̬
	for (num = 0; num < roadSize; num++)
	{
		for (m = 0; m < 2; m++) //˫���·
		{
			if (m == 1 && ROAD[num].isDuplex == 0)
				break;
			for (i = 0; i < ROAD[num].channel; i++) //������
			{
				int carID;
				count = 0;

				int sum = accumulate(ROAD[num].roadCar[m][i], ROAD[num].roadCar[m][i] + ROAD[num].length, 0);
				if (sum == -ROAD[num].length)
					continue;

				for (j = ROAD[num].length - 1; j >= 0; j--) //λ��
				{
					carID = ROAD[num].roadCar[m][i][j] - car0;

					if (ROAD[num].roadCar[m][i][j] == -1)
						continue;

					if (CAR[carID].isTerminate == 1)
						continue;

					//ɨ��·�����г���λ��
					count = 0;
					for (k = j + 1; k < ROAD[num].length; k++)
					{
						if (ROAD[num].roadCar[m][i][k] != -1)
						{
							++count;
							break;
						}
					}

					if (count == 0)	//�����赲
					{
						if (CAR[carID].nextCrossDistance < CAR[carID].maxSpeed)	//�ɿ��·��
						{
							CAR[carID].setState(0);	//����Ϊ�ȴ���ʻ
							CAR[carID].setToNextRoad(1);
							continue;
						}

						//��Ҫ��һ�������յ�·�ڵĳ���ǰ����벻���г��赲��������nextRoadSpeed=-1���Բ��ɿ��·��
						if (CAR[carID].nextCrossDistance >= CAR[carID].maxSpeed)	//���ɿ��·��
						{
							CAR[carID].setNowSpeed(CAR[carID].maxSpeed);
							int oldPosition = CAR[carID].location[2];
							CAR[carID].updateLocation(ROAD[num].id, i, oldPosition + CAR[carID].nowSpeed); //����λ��
							ROAD[num].subRoadCar(m, i, oldPosition - 1); //ɾ����λ��
							ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
							CAR[carID].setState(1);	//����Ϊ��ֹ״̬
							CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
							continue;
						}
					}

					//���赲

					//ȷ���赲����λ��k
					int carIDB = ROAD[num].roadCar[m][i][k] - car0;
					CAR[carID].setBlockDistance(k - j);		//���赲���ľ���
					if (CAR[carIDB].state == 1)	 //���赲��ǰ������ֹ����
					{
						int oldPosition = CAR[carID].location[2];
						ROAD[num].subRoadCar(m, i, oldPosition - 1); //ɾ����λ��
						//��������㹻��
						if (CAR[carID].maxSpeed <= (CAR[carID].blockDistance - 1))
						{
							CAR[carID].setNowSpeed(CAR[carID].maxSpeed);
							CAR[carID].updateLocation(ROAD[num].id, i, oldPosition + CAR[carID].maxSpeed); //����λ��
							ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
						}
						//������಻��
						if (CAR[carID].maxSpeed > (CAR[carID].blockDistance - 1))
						{
							CAR[carID].setNowSpeed(CAR[carID].blockDistance - 1);//ע�⣺�����˼��٣��´ο�����Ҫ����
							CAR[carID].updateLocation(ROAD[num].id, i, oldPosition + CAR[carID].nowSpeed); //����λ��
							ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
						}
						CAR[carID].setState(1);
						CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
					}

					if (CAR[carIDB].state == 0)	 //���赲��ǰ���ǵȴ�����
					{
						int oldPosition = CAR[carID].location[2];
						//��������㹻��
						if ((CAR[carID].blockDistance - 1) >= CAR[carID].maxSpeed)
						{
							CAR[carID].updateLocation(ROAD[num].id, i, oldPosition + CAR[carID].maxSpeed); //����λ��
							ROAD[num].subRoadCar(m, i, oldPosition - 1); //ɾ����λ��
							ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
							CAR[carID].setState(1);
							CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
						}
						//������಻��
						if ((CAR[carID].blockDistance-1) < CAR[carID].maxSpeed)
						{
							CAR[carID].setState(0);
							if (CAR[carID].nextCrossDistance < CAR[carID].maxSpeed)	//�ɿ��·��
							{
								CAR[carID].setToNextRoad(1);
							}
						}
					}
				}
			}
		}
	}
}

bool Dispatch::moveToNextRoad(int carID, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime)
{
	//�ȴ�����ĳ�����road.waitcar���Ŷ�
	//���ڸ�������ĳ�����ǰ��->������С��������
	int  m, i, j;
	carID = carID - car0;

	int oldRoadID = CAR[carID].location[0] - road0;
	int oldCHA = CAR[carID].location[1];
	int oldPosition = CAR[carID].location[2];

	//���жϵ�ǰ��·���Ƿ�����ֹ��������
	int count = 0;
	for (j = oldPosition; j < ROAD[oldRoadID].length; j++)
	{
		if (ROAD[oldRoadID].roadCar[CAR[carID].isReverse][oldCHA][j] != -1 )
		{
			++count;
			break;
		}
	}

	//ȥ�յ�·�ڵĳ�����ǰ�������г��赲��
	if (count == 0 && CAR[carID].nextCross == CAR[carID].to)
	{
		CAR[carID].setState(1);
		CAR[carID].setIsTerminate(1);
		CAR[carID].setEndTime(GlobalTime);
		subRoadCarNumber();
		ROAD[oldRoadID].subRoadCar(CAR[carID].isReverse, oldCHA, oldPosition - 1); //�������յ�ĳ����Ƴ�
		return false;
	}

	//�������ֹ��������
	if (count == 1)
	{
		//��ǰ��·������
		m = CAR[carID].isReverse;
		CAR[carID].setBlockDistance(j - oldPosition + 1);		//���赲���ľ���
		int oldPosition = CAR[carID].location[2];
		ROAD[oldRoadID].subRoadCar(m, oldCHA, oldPosition - 1); //ɾ����λ��
		//��������㹻��
		if (CAR[carID].maxSpeed <= (CAR[carID].blockDistance - 1))
		{
			CAR[carID].updateLocation(ROAD[oldRoadID].id, oldCHA, oldPosition + CAR[carID].maxSpeed); //����λ��
			ROAD[oldRoadID].addRoadCar(m, oldCHA, CAR[carID].location[2] - 1, carID + car0);
		}
		//������಻��
		if (CAR[carID].maxSpeed > (CAR[carID].blockDistance - 1))
		{
			CAR[carID].setNowSpeed(CAR[carID].blockDistance - 1);//ע�⣺�����˼��٣��´ο�����Ҫ����
			CAR[carID].updateLocation(ROAD[oldRoadID].id, oldCHA, oldPosition + CAR[carID].nowSpeed); //����λ��
			ROAD[oldRoadID].addRoadCar(m, oldCHA, CAR[carID].location[2] - 1, carID + car0);
		}
		CAR[carID].setState(1);
		CAR[carID].computeNEXT(ROAD, CROSS); //����״̬

		return false;
	}

	//m������һ����·�ϵ�������
	m = CAR[carID].nextReverse;

	int stopPosition = CAR[carID].nextRoadSpeed - CAR[carID].nextCrossDistance;
	if (stopPosition < 0)
		stopPosition = 0;
	int NextRoadID = CAR[carID].nextRoad - road0;

	if (stopPosition > 0)
	{
		int CHA = -1, POS = -1, isend = 0;
		for (i = 0; i < ROAD[NextRoadID].channel; i++) //�����򳵵���Ѱ�ҿɲ���λ��
		{
			for (j = 0; j < stopPosition; j++)
			{
				if (ROAD[NextRoadID].roadCar[m][i][j] == -1)
				{
					CHA = i; //û�г��赲
					POS = j;
					if (j == stopPosition - 1) //һ������ȫ�գ�����
					{
						isend = 1;
						break;
					}
					continue;
				}
				if (ROAD[NextRoadID].roadCar[m][i][j] != -1)
				{
					int blockCarID = ROAD[NextRoadID].roadCar[m][i][j] - car0;
					if (CAR[blockCarID].state == 1) //�赲������ֹ
					{
						CHA = i;
						POS = j - 1;
						if (POS > -1)   //�������ɲ���λ�þͽ���
							isend = 1;
						break; //����һ����������
					}
					if (CAR[blockCarID].state == 0) //�赲���ȴ�
					{
						CHA = -1;
						POS = -1;
						isend = 1; //����
						break;
					}
				}
			}

			if (isend == 1)
				break;
		}

		if (CHA > -1) //�ɲ���
		{
			if (POS == -1) //������·�����е�һ��λ��ȫ������ֹ״̬�ĳ�
			{
				//����λ��
				CAR[carID].updateLocation(CAR[carID].location[0], oldCHA, ROAD[oldRoadID].length);
				ROAD[oldRoadID].subRoadCar(CAR[carID].isReverse, oldCHA, oldPosition - 1);
				ROAD[oldRoadID].addRoadCar(CAR[carID].isReverse, oldCHA, CAR[carID].location[2] - 1, carID + car0);
				//����״̬
				CAR[carID].setState(1);
				CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
				return false;
			}

			//����λ��
			CAR[carID].updateLocation(ROAD[NextRoadID].id, CHA, POS + 1);
			ROAD[oldRoadID].subRoadCar(CAR[carID].isReverse, oldCHA, oldPosition - 1);
			ROAD[NextRoadID].addRoadCar(m, CHA, POS, carID + car0);
			
			//����״̬
			CAR[carID].setState(1);
			CAR[carID].passRoadNumber += 1;
			CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
			return true;
		}
	}

	if (stopPosition == 0)
	{
		//����λ��
		CAR[carID].updateLocation(CAR[carID].location[0], oldCHA, ROAD[oldRoadID].length);
		ROAD[oldRoadID].subRoadCar(CAR[carID].isReverse, oldCHA, oldPosition - 1);
		ROAD[oldRoadID].addRoadCar(CAR[carID].isReverse, oldCHA, CAR[carID].location[2] - 1, carID + car0);
		//����״̬
		CAR[carID].setState(1);
		CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
		return false;
	}

	return false;
}

bool Dispatch::moveOnTheRoad(int carID, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime)
{
	int  m,j,count;

	int oldRoadID = CAR[carID].location[0] - road0;
	int oldCHA = CAR[carID].location[1];
	int oldPosition = CAR[carID].location[2];

	m = CAR[carID].isReverse;
	//��ȡ�赲��λ��
	count = 0;
	for (j = oldPosition; j < ROAD[oldRoadID].length; j++)
	{
		if (ROAD[oldRoadID].roadCar[m][oldCHA][j] != -1)
		{
			++count;
			break;
		}
	}

	if (count == 0) //�����赲
	{
		CAR[carID].setNowSpeed(CAR[carID].maxSpeed);
		int oldPosition = CAR[carID].location[2];
		CAR[carID].updateLocation(ROAD[oldRoadID].id, oldCHA, oldPosition + CAR[carID].nowSpeed); //����λ��
		ROAD[oldRoadID].subRoadCar(m, oldCHA, oldPosition - 1); //ɾ����λ��
		ROAD[oldRoadID].addRoadCar(m, oldCHA, CAR[carID].location[2] - 1, carID + car0);
		CAR[carID].setState(1);	//����Ϊ��ֹ״̬
		CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
		return true;
	}

	if (count == 1) //���赲
	{
		CAR[carID].setBlockDistance(j - oldPosition + 1);
		if (CAR[carID].maxSpeed > (CAR[carID].blockDistance-1))		//�ռ䲻��
			CAR[carID].setNowSpeed(CAR[carID].blockDistance - 1); 
		if (CAR[carID].maxSpeed <= (CAR[carID].blockDistance - 1))	//�ռ乻��
			CAR[carID].setNowSpeed(CAR[carID].maxSpeed); 	
	}

	//����λ��
	CAR[carID].updateLocation(ROAD[oldRoadID].id, oldCHA, oldPosition + CAR[carID].nowSpeed);
	ROAD[oldRoadID].subRoadCar(m, oldCHA, oldPosition - 1);
	ROAD[oldRoadID].addRoadCar(m, oldCHA, CAR[carID].location[2] - 1, carID + car0);
	//����״̬
	CAR[carID].setState(1);
	CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
	
	return true;
}

//���ȵ�num�������ڵȴ������ȳ�
bool Dispatch::moveCarportPriorityCar(int crossNum, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime)
{
	int  i, m, j;

	if ((int)(CROSS[crossNum].StartCar.size()) == 0)
		return false;

	//�����ڵȴ��ĳ����鵽���������:StartCar���Ѿ������ȼ�+ID��������Ҫ��PT����(Ҫ��֤Ԥ�ó��ȷ�)
	//���ڵ���PT����ʱ������ܷ����ĳ�ҪPT+1(�����ĳ������ʱ��)
	set<int, less<int>> tempRoadAll;
	vector<int> waitCar;
	for (i = 0; i < (int)(CROSS[crossNum].StartCar.size()); i++)
	{
		int carID = CROSS[crossNum].StartCar[i] - car0;

		//���ȳ���·����ֻɨ�賵��������ǰ������ȳ���һ��ɨ�赽�����ȳ�����ֱ���˳�
		if (CAR[carID].priority == 0)
			break;

		int roadID = CAR[carID].route[0] - road0;
		if (CAR[carID].PT <= GlobalTime)
		{			
			tempRoadAll.insert(roadID);
			waitCar.push_back(carID + car0);
		}	
	}
	if ((int)(waitCar.size()) == 0)
		return false;

	vector<int> roadAll;
	set<int>::iterator it;
	for (it = tempRoadAll.begin(); it != tempRoadAll.end(); it++)
	{
		roadAll.push_back(*it);
	}

	//��ֻ�������ȳ���waitCar��PT����
	//(���ڵ����ȼ��Ƕ���:ʵ�ʷ���ʱ��Ϊ����IDΪ����vector�ﶼ�ǵ����˷���ʱ������ȳ�)
	set<int, less<int>> PTAll;
	vector<int> tempCar;
	for (i = 0; i < (int)(waitCar.size()); i++)
	{
		PTAll.insert(CAR[waitCar[i] - car0].PT);
	}
	for (it = PTAll.begin(); it != PTAll.end(); it++)
	{
		for (i = 0; i < (int)(waitCar.size()); i++)
		{
			if (CAR[waitCar[i] - car0].PT == *it)
				tempCar.push_back(waitCar[i]);
		}
	}
	waitCar.clear();
	waitCar.insert(waitCar.begin(),tempCar.begin(), tempCar.end());

	//���������·�Ŷ�
	for (i = 0; i < (int)(waitCar.size()); i++)
	{
		int carID = waitCar[i] - car0;
		int roadID = CAR[carID].route[0] - road0;
		if (CAR[carID].from == ROAD[roadID].from) //����
			ROAD[roadID].addWaitCar(0, 0, waitCar[i]);
		if (CAR[carID].from == ROAD[roadID].to) //����
			ROAD[roadID].addWaitCar(1, 0, waitCar[i]);
	}

	//��ʼ�ɳ���ע��ǰ���赲������ֹ�����ǵȴ���
	vector<int> carCut;
	for (int q = 0; q < (int)(roadAll.size()); q++)
	{
		int roadID = roadAll[q];
		for (m = 0; m < 2; m++)
		{
			if ((int)(ROAD[roadID].WaitCar[m][0].size()) == 0) //�������·�ĳ�Ϊ��
				continue;

			int carNum = 0, i = 0, flag = 0, lastCarId = -1, count = 0;	//i��ʾ����id
			carCut.clear();
			while (carNum < (int)(ROAD[roadID].WaitCar[m][0].size()))
			{
				if (ROAD[roadID].roadCar[m][i][0] != -1) //��������������һ������
				{
					int carID = ROAD[roadID].roadCar[m][i][0] - car0;
					//���ݳ����̶�������򣬵�ǰ�������ȴ�����ͷ��ֱ��GG
					if (CAR[carID].state == 0)
						break;
					++i;
					flag = 1;
					if (i == ROAD[roadID].channel)
						break;
					continue;
				}

				int carID = ROAD[roadID].WaitCar[m][0][carNum] - car0;

				//���µ�ǰ�ٶ�
				if (CAR[carID].speed > ROAD[roadID].speed)
					CAR[carID].setNowSpeed(ROAD[roadID].speed);
				else
					CAR[carID].setNowSpeed(CAR[carID].speed);				

				//���복���ĵ�һ����
				if (count == 0 || flag == 1) 
				{
					//��ѯ��������
					int blockPOS = -1;
					for (j = 1; j < CAR[carID].nowSpeed; j++)
					{
						if (ROAD[roadID].roadCar[m][i][j] != -1)
						{
							blockPOS = j + 1;
							break;
						}
					}

					//�����г�����
					if (blockPOS != -1)
					{
						if (CAR[carID].nowSpeed > (blockPOS - 1))  //��಻��
						{
							int blockCarID = ROAD[roadID].roadCar[m][i][j] - car0;
							//������赲�����ǵȴ��ģ���Ӱ���������ȳ�
							if (CAR[blockCarID].state == 0)
							{
								////��յ�·�Ŷӳ���
								//ROAD[roadID].clearWaitCar(0);
								//ROAD[roadID].clearWaitCar(1);
								////ɾ���������Ѿ������·�ĳ�
								//CROSS[crossNum].subStartCar(carCut);
								//return false;
								++carNum;
								flag = 1;	//��������ĵ�һ��������ȥ���������ĳ����µĵ�һ����
								continue;
							}
							//������赲��������ֹ�ģ��Ǿͷ���
							if (CAR[blockCarID].state == 1)
							{
								CAR[carID].setNowSpeed(blockPOS - 1);
							}						
						}
					}

					CAR[carID].updateLocation(ROAD[roadID].id, i, CAR[carID].nowSpeed); //���³���λ��
					CAR[carID].setATD(GlobalTime);	//����ʵ�ʳ���ʱ��
					ROAD[roadID].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0); //���µ�·�ĳ���λ��
					//����״̬
					CAR[carID].setState(1);
					CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
					lastCarId = carID; //������һ��λ�ó���id
					flag = 0;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				//���복���ķǵ�һ����
				if (CAR[carID].nowSpeed < CAR[lastCarId].location[2])	//�ռ乻
				{
					CAR[carID].updateLocation(ROAD[roadID].id, i, CAR[carID].nowSpeed);
					CAR[carID].setATD(GlobalTime);
					ROAD[roadID].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
					//����״̬
					CAR[carID].setState(1);
					CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
					lastCarId = carID;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				CAR[carID].updateLocation(ROAD[roadID].id, i, CAR[lastCarId].location[2] - 1); //�ռ䲻��
				CAR[carID].setATD(GlobalTime);
				ROAD[roadID].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
				//����״̬
				CAR[carID].setState(1);
				CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
				lastCarId = carID;
				carCut.push_back(carID + car0);
				++carNum;
				++count;
			}
			//ɾ���������Ѿ������·�ĳ�
			CROSS[crossNum].subStartCar(carCut);
		}
		//��յ�·�Ŷӳ���
		ROAD[roadID].clearWaitCar(0);
		ROAD[roadID].clearWaitCar(1);
	}
	return true;
}

//���Ƚ����·�÷�������ȳ�����
bool Dispatch::moveCarportCarPriorityToRoad(int roadId, int dir, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime)
{
	int i;
	
	int roadID = roadId - road0;
	int crossID=0;

	//��ȡ�����·�÷�������ȳ�����·��
	if (dir == 0)
		crossID = ROAD[roadID].from - cross0;
	if (dir == 1)
		crossID = ROAD[roadID].to - cross0;

	//��ȡ���ȳ�
	if ((int)(CROSS[crossID].StartCar.size()) == 0)
		return false;

	//�����ڵȴ��ĳ����鵽������·�����������
	vector<int> waitCar;
	for (int num = 0; num < (int)(CROSS[crossID].StartCar.size()); num++)
	{
		int carID = CROSS[crossID].StartCar[num] - car0;
		
		//���ȳ���·����ֻɨ�賵��������ǰ������ȳ���һ��ɨ�赽�����ȳ�����ֱ���˳�
		if (CAR[carID].priority == 0)
			break;

		int carRoadID = CAR[carID].route[0] - road0;
		if (carRoadID == roadID && CAR[carID].reverse[0]==dir && CAR[carID].PT <= GlobalTime)  //ֻ��Ҫȥ����·���������ĳ��Ż�����Ŷ�����
			waitCar.push_back(carID + car0);														   
	}
	if (waitCar.size() == 0)
		return false;

	//��ֻ�������ȳ���waitCar��PT����
	//(���ڵ����ȼ��Ƕ���:ʵ�ʷ���ʱ��Ϊ����IDΪ����vector�ﶼ�ǵ����˷���ʱ������ȳ�)
	set<int, less<int>> PTAll;
	set<int>::iterator it;
	vector<int> tempCar;
	for (i = 0; i < (int)(waitCar.size()); i++)
	{
		PTAll.insert(CAR[waitCar[i] - car0].PT);
	}
	for (it = PTAll.begin(); it != PTAll.end(); it++)
	{
		for (i = 0; i < (int)(waitCar.size()); i++)
		{
			if (CAR[waitCar[i] - car0].PT == *it)
				tempCar.push_back(waitCar[i]);
		}
	}
	waitCar.clear();
	waitCar.insert(waitCar.begin(), tempCar.begin(), tempCar.end());

	//���������·�Ŷ�
	for (i = 0; i < (int)(waitCar.size()); i++)
	{
		ROAD[roadID].addWaitCar(dir, 0, waitCar[i]);
	}

	i = 0;
	int carNum = 0, j=0, flag = 0, lastCarId = -1, count = 0;	//i��ʾ����id
	vector<int> carCut;
	while (carNum < (int)(ROAD[roadID].WaitCar[dir][0].size()))
	{
		if (ROAD[roadID].roadCar[dir][i][0] != -1) //��������������һ������
		{
			int carID = ROAD[roadID].roadCar[dir][i][0] - car0;
			//���ݳ����̶�������򣬵�ǰ�������ȴ�����ͷ��ֱ��GG
			if (CAR[carID].state == 0)
				break;
			++i;
			flag = 1;
			if (i == ROAD[roadID].channel)
				break;
			continue;
		}

		int carID = ROAD[roadID].WaitCar[dir][0][carNum] - car0;

		//���µ�ǰ�ٶ�
		if (CAR[carID].speed > ROAD[roadID].speed)
			CAR[carID].setNowSpeed(ROAD[roadID].speed);
		else
			CAR[carID].setNowSpeed(CAR[carID].speed);

		//���복���ĵ�һ����
		if (count == 0 || flag == 1)
		{
			//��ѯ��������
			int blockPOS = -1;
			for (j = 1; j < CAR[carID].nowSpeed; j++)
			{
				if (ROAD[roadID].roadCar[dir][i][j] != -1)
				{
					blockPOS = j + 1;
					break;
				}
			}

			//�����г�����
			if (blockPOS != -1)
			{
				if (CAR[carID].nowSpeed > (blockPOS - 1))  //��಻��
				{
					int blockCarID = ROAD[roadID].roadCar[dir][i][j] - car0;
					//������赲�����ǵȴ��ģ���Ӱ���������ȳ�
					if (CAR[blockCarID].state == 0)
					{
						////��յ�·�Ŷӳ���
						//ROAD[roadID].clearWaitCar(0);
						//ROAD[roadID].clearWaitCar(1);
						////ɾ���������Ѿ������·�ĳ�
						//CROSS[crossID].subStartCar(carCut);
						//return false;
						++carNum;
						flag = 1;	//��������ĵ�һ��������ȥ���������ĳ����µĵ�һ����
						continue;
					}
					//������赲��������ֹ�ģ��Ǿͷ���
					CAR[carID].setNowSpeed(blockPOS - 1);
				}
			}

			CAR[carID].updateLocation(ROAD[roadID].id, i, CAR[carID].nowSpeed); //���³���λ��
			CAR[carID].setATD(GlobalTime);	//����ʵ�ʳ���ʱ��
			ROAD[roadID].addRoadCar(dir, i, CAR[carID].location[2] - 1, carID + car0); //���µ�·�ĳ���λ��
			//����״̬
			CAR[carID].setState(1);
			CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
			lastCarId = carID; //������һ��λ�ó���id
			flag = 0;
			carCut.push_back(carID + car0);
			++carNum;
			++count;
			continue;
		}

		//���복���ķǵ�һ����
		if (CAR[carID].nowSpeed < CAR[lastCarId].location[2])	//�ռ乻
		{
			CAR[carID].updateLocation(ROAD[roadID].id, i, CAR[carID].nowSpeed);
			CAR[carID].setATD(GlobalTime);
			ROAD[roadID].addRoadCar(dir, i, CAR[carID].location[2] - 1, carID + car0);
			//����״̬
			CAR[carID].setState(1);
			CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
			lastCarId = carID;
			carCut.push_back(carID + car0);
			++carNum;
			++count;
			continue;
		}

		CAR[carID].updateLocation(ROAD[roadID].id, i, CAR[lastCarId].location[2] - 1); //�ռ䲻��
		CAR[carID].setATD(GlobalTime);
		ROAD[roadID].addRoadCar(dir, i, CAR[carID].location[2] - 1, carID + car0);
		//����״̬
		CAR[carID].setState(1);
		CAR[carID].computeNEXT(ROAD, CROSS); //����״̬
		lastCarId = carID;
		carCut.push_back(carID + car0);
		++carNum;
		++count;
	}
	//ɾ���������Ѿ������·�ĳ�
	CROSS[crossID].subStartCar(carCut);
	//��յ�·�Ŷӳ���
	ROAD[roadID].clearWaitCar(dir);

	return true;
}

//·�����г����Ƚ�������ʼ���ȵ�num�������ڵȴ��ĳ�
bool Dispatch::moveCarport(int crossNum, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime)
{
	int  num, m, j;

	if ((int)(CROSS[crossNum].StartCar.size()) == 0)
		return false;

	//�����ڵȴ��ĳ����鵽������·�����������
	set<int, less<int>> tempRoadAll;
	vector<int> waitCar;
	for (num = 0; num < (int)(CROSS[crossNum].StartCar.size()); num++)
	{
		int carID = CROSS[crossNum].StartCar[num] - car0;
		int roadID = CAR[carID].route[0] - road0;
		if (CAR[carID].PT <= GlobalTime)
		{
			tempRoadAll.insert(roadID);
			waitCar.push_back(carID + car0);
		}
	}
	if (waitCar.size() == 0)
		return false;

	vector<int> roadAll;
	set<int>::iterator it;
	for (it = tempRoadAll.begin(); it != tempRoadAll.end(); it++)
	{
		roadAll.push_back(*it);
	}

	//��������Ȩ����ÿ��·�ڳ����ڵĳ������������ȳ���ǰ������PT�������У����ڸ�ʱ�������ڱ���ID��������
	vector<int> priorityCar, tempCar;
	vector<int>::iterator pos;
	set<int, less<int>> PTimeAll;
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		if (CAR[waitCar[i] - car0].priority == 1)
			priorityCar.push_back(waitCar[i]);
	}

	//�������ȳ�����PT��������
	for (int i = 0; i < (int)(priorityCar.size()); i++)
	{
		PTimeAll.insert(CAR[priorityCar[i] - car0].PT);
	}
	tempCar.clear();
	for (it = PTimeAll.begin(); it != PTimeAll.end(); it++)
	{
		for (int i = 0; i < (int)(priorityCar.size()); i++)
		{
			if (CAR[priorityCar[i] - car0].PT == *it)
				tempCar.push_back(priorityCar[i]);
		}
	}
	priorityCar.clear();
	priorityCar.insert(priorityCar.begin(), tempCar.begin(), tempCar.end());

	//ɾ��ԭ�������ȳ���
	for (int j = 0; j < (int)(priorityCar.size()); j++)
	{
		pos = find(waitCar.begin(), waitCar.end(), priorityCar[j]);
		if (pos != waitCar.end())
			waitCar.erase(pos);
	}

	//�������ȳ���PT������
	PTimeAll.clear();
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		PTimeAll.insert(CAR[waitCar[i] - car0].PT);
	}
	tempCar.clear();
	for (it = PTimeAll.begin(); it != PTimeAll.end(); it++)
	{
		for (int i = 0; i < (int)(waitCar.size()); i++)
		{
			if (CAR[waitCar[i] - car0].PT == *it)
				tempCar.push_back(waitCar[i]);
		}
	}
	waitCar.clear();
	waitCar.insert(waitCar.begin(), tempCar.begin(), tempCar.end());

	//��������
	waitCar.insert(waitCar.begin(), priorityCar.begin(), priorityCar.end());

	//���������·�Ŷ�
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		int carID = waitCar[i] - car0;
		int roadID = CAR[carID].route[0] - road0;
		if (CAR[carID].from == ROAD[roadID].from) //����
			ROAD[roadID].addWaitCar(0, 0, waitCar[i]);
		if (CAR[carID].from == ROAD[roadID].to) //����
			ROAD[roadID].addWaitCar(1, 0, waitCar[i]);
	}

	//��ʼ�ɳ�
	vector<int> carCut;
	for (int q = 0; q < (int)(roadAll.size()); q++)
	{
		num = roadAll[q];
		for (m = 0; m < 2; m++)
		{
			if ((int)(ROAD[num].WaitCar[m][0].size()) == 0) //�������·�ĳ�Ϊ��
				continue;

			int carNum = 0, i = 0, flag = 0, lastCarId = -1, count = 0;	//i��ʾ����id
			carCut.clear();
			while (carNum < (int)(ROAD[num].WaitCar[m][0].size()))
			{
				if (ROAD[num].roadCar[m][i][0] != -1) //��������������һ������
				{
					++i;
					flag = 1;
					if (i == ROAD[num].channel)
						break;
					continue;
				}

				int carID = ROAD[num].WaitCar[m][0][carNum] - car0;

				if (CAR[carID].PT > GlobalTime) //δ�ﵽplanTime���ܷ���
				{
					++carNum;
					continue;
				}

				//���µ�ǰ�ٶ�
				if (CAR[carID].speed > ROAD[num].speed)
					CAR[carID].setNowSpeed(ROAD[num].speed);
				else
					CAR[carID].setNowSpeed(CAR[carID].speed);

				//���µ�ǰλ��
				if (count == 0 || flag == 1) //��һ�������߻����ĵ�һ����
				{
					//��ѯ��������
					int blockPOS = -1;
					for (j = 1; j < CAR[carID].nowSpeed; j++)
					{
						if (ROAD[num].roadCar[m][i][j] != -1)
						{
							blockPOS = j + 1;
							break;
						}
					}

					if (blockPOS != -1)
					{
						if (CAR[carID].nowSpeed > (blockPOS - 1))  //��಻��
							CAR[carID].setNowSpeed(blockPOS - 1);
					}

					CAR[carID].updateLocation(ROAD[num].id, i, CAR[carID].nowSpeed); //���³���λ��
					CAR[carID].setATD(GlobalTime);	//����ʵ�ʳ���ʱ��
					ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0); //���µ�·�ĳ���λ��
					lastCarId = carID; //������һ��λ�ó���id
					flag = 0;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				if (CAR[carID].nowSpeed < CAR[lastCarId].location[2])	//�ռ乻
				{
					CAR[carID].updateLocation(ROAD[num].id, i, CAR[carID].nowSpeed);
					CAR[carID].setATD(GlobalTime);
					ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
					lastCarId = carID;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				CAR[carID].updateLocation(ROAD[num].id, i, CAR[lastCarId].location[2] - 1); //�ռ䲻��
				CAR[carID].setATD(GlobalTime);
				ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
				lastCarId = carID;
				carCut.push_back(carID + car0);
				++carNum;
				++count;
			}
			//ɾ���������Ѿ������·�ĳ�
			CROSS[crossNum].subStartCar(carCut);
		}
		//��յ�·�Ŷӳ���
		ROAD[num].clearWaitCar(0);
		ROAD[num].clearWaitCar(1);
	}

	//����һ��waitCar�����ڵ���ʱ��ȴû�з���ȥ�ķ�Ԥ�ó�����PT+1
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		int carID = waitCar[i] - car0;
		if (CAR[carID].preset == 0 && CAR[carID].ATD == -1)
			CAR[carID].addPT(1);
	}

	if ((int)(CROSS[crossNum].StartCar.size()) == 0)
		EmptyCarportNumber += 1;

	return true;
}

//·�����г����Ƚ�������ʼ���ȵ�num�������ڵȴ��ĳ�
bool Dispatch::moveCarport2(int crossNum, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime)
{
	int  num, m, j;

	if ((int)(CROSS[crossNum].StartCar.size()) == 0)
		return false;

	//�����ڵȴ��ĳ����鵽������·�����������
	set<int, less<int>> tempRoadAll;
	vector<int> waitCar;
	for (num = 0; num < (int)(CROSS[crossNum].StartCar.size()); num++)
	{
		int carID = CROSS[crossNum].StartCar[num] - car0;
		int roadID = CAR[carID].route[0] - road0;
		if (CAR[carID].PT <= GlobalTime)
		{
			tempRoadAll.insert(roadID);
			waitCar.push_back(carID + car0);
		}
	}
	if (waitCar.size() == 0)
		return false;

	vector<int> roadAll;
	set<int>::iterator it;
	for (it = tempRoadAll.begin(); it != tempRoadAll.end(); it++)
	{
		roadAll.push_back(*it);
	}

	//��������Ȩ����ÿ��·�ڳ����ڵĳ������������ȳ���ǰ������PT�������У����ڸ�ʱ�������ڱ���ID��������
	vector<int> priorityCar, tempCar;
	vector<int>::iterator pos;
	set<int, less<int>> PTimeAll;
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		if (CAR[waitCar[i] - car0].priority == 1)
			priorityCar.push_back(waitCar[i]);
	}

	//�������ȳ�����PT��������
	for (int i = 0; i < (int)(priorityCar.size()); i++)
	{
		PTimeAll.insert(CAR[priorityCar[i] - car0].PT);
	}
	tempCar.clear();
	for (it = PTimeAll.begin(); it != PTimeAll.end(); it++)
	{
		for (int i = 0; i < (int)(priorityCar.size()); i++)
		{
			if (CAR[priorityCar[i] - car0].PT == *it)
				tempCar.push_back(priorityCar[i]);
		}
	}
	priorityCar.clear();
	priorityCar.insert(priorityCar.begin(), tempCar.begin(), tempCar.end());

	//ɾ��ԭ�������ȳ���
	for (int j = 0; j < (int)(priorityCar.size()); j++)
	{
		pos = find(waitCar.begin(), waitCar.end(), priorityCar[j]);
		if (pos != waitCar.end())
			waitCar.erase(pos);
	}

	//�������ȳ���PT������
	PTimeAll.clear();
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		PTimeAll.insert(CAR[waitCar[i] - car0].PT);
	}
	tempCar.clear();
	for (it = PTimeAll.begin(); it != PTimeAll.end(); it++)
	{
		for (int i = 0; i < (int)(waitCar.size()); i++)
		{
			if (CAR[waitCar[i] - car0].PT == *it)
				tempCar.push_back(waitCar[i]);
		}
	}
	waitCar.clear();
	waitCar.insert(waitCar.begin(), tempCar.begin(), tempCar.end());

	//��������
	waitCar.insert(waitCar.begin(), priorityCar.begin(), priorityCar.end());

	//���������·�Ŷ�
	for (int i = 0; i < (int)(waitCar.size()); i++)
	{
		int carID = waitCar[i] - car0;
		int roadID = CAR[carID].route[0] - road0;
		if (CAR[carID].from == ROAD[roadID].from) //����
			ROAD[roadID].addWaitCar(0, 0, waitCar[i]);
		if (CAR[carID].from == ROAD[roadID].to) //����
			ROAD[roadID].addWaitCar(1, 0, waitCar[i]);
	}

	//��ʼ�ɳ�
	vector<int> carCut;
	for (int q = 0; q < (int)(roadAll.size()); q++)
	{
		num = roadAll[q];
		for (m = 0; m < 2; m++)
		{
			if ((int)(ROAD[num].WaitCar[m][0].size()) == 0) //�������·�ĳ�Ϊ��
				continue;

			int carNum = 0, i = 0, flag = 0, lastCarId = -1, count = 0;	//i��ʾ����id
			carCut.clear();
			while (carNum < (int)(ROAD[num].WaitCar[m][0].size()))
			{
				if (ROAD[num].roadCar[m][i][0] != -1) //��������������һ������
				{
					++i;
					flag = 1;
					if (i == ROAD[num].channel)
						break;
					continue;
				}

				int carID = ROAD[num].WaitCar[m][0][carNum] - car0;

				if (CAR[carID].PT > GlobalTime) //δ�ﵽplanTime���ܷ���
				{
					++carNum;
					continue;
				}

				//���µ�ǰ�ٶ�
				if (CAR[carID].speed > ROAD[num].speed)
					CAR[carID].setNowSpeed(ROAD[num].speed);
				else
					CAR[carID].setNowSpeed(CAR[carID].speed);

				//���µ�ǰλ��
				if (count == 0 || flag == 1) //��һ�������߻����ĵ�һ����
				{
					//��ѯ��������
					int blockPOS = -1;
					for (j = 1; j < CAR[carID].nowSpeed; j++)
					{
						if (ROAD[num].roadCar[m][i][j] != -1)
						{
							blockPOS = j + 1;
							break;
						}
					}

					if (blockPOS != -1)
					{
						if (CAR[carID].nowSpeed > (blockPOS - 1))  //��಻��
							CAR[carID].setNowSpeed(blockPOS - 1);
					}

					CAR[carID].updateLocation(ROAD[num].id, i, CAR[carID].nowSpeed); //���³���λ��
					CAR[carID].setATD(GlobalTime);	//����ʵ�ʳ���ʱ��
					ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0); //���µ�·�ĳ���λ��
					lastCarId = carID; //������һ��λ�ó���id
					flag = 0;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				if (CAR[carID].nowSpeed < CAR[lastCarId].location[2])	//�ռ乻
				{
					CAR[carID].updateLocation(ROAD[num].id, i, CAR[carID].nowSpeed);
					CAR[carID].setATD(GlobalTime);
					ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
					lastCarId = carID;
					carCut.push_back(carID + car0);
					++carNum;
					++count;
					continue;
				}

				CAR[carID].updateLocation(ROAD[num].id, i, CAR[lastCarId].location[2] - 1); //�ռ䲻��
				CAR[carID].setATD(GlobalTime);
				ROAD[num].addRoadCar(m, i, CAR[carID].location[2] - 1, carID + car0);
				lastCarId = carID;
				carCut.push_back(carID + car0);
				++carNum;
				++count;
			}
			//ɾ���������Ѿ������·�ĳ�
			CROSS[crossNum].subStartCar(carCut);
		}
		//��յ�·�Ŷӳ���
		ROAD[num].clearWaitCar(0);
		ROAD[num].clearWaitCar(1);
	}

	return true;
}

bool Dispatch::delayCarPT2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &nowTime, vector<int> &deadCar)
{
	int i, j, carID, roadID, count = 0;
	bool isFind = false;
	vector<int>::iterator pos;
	vector<int> modifyCar, tempCar;
	set<int, less<int>> PTAll;
	set<int>::iterator it;

	//�ҳ���ǰʱ�̱��ݳ�����PT<=nowTime�ĳ�,�����ع������ڵ�CAR���Ǳ��ݵ�����
	//����Щ���еķ����ȳ��ķ���ʱ���Ӻ�N��ʱ��
	int limitNumber = 50;

	bool isFirst = true;
	for (j = 0; j < limitNumber; j++)
	{
		for (i = 0; i < crossSize; i++)
		{
			if ((int)(CROSS[i].StartCar.size()) < limitNumber)
				continue;
			carID = CROSS[i].StartCar[j] - car0;
			roadID = CAR[carID].route[0] - road0;
			if (ROAD[roadID].crowding[CAR[carID].isReverse] < 0.1)
				continue;
			//����deadCar�Ƿ��и�Ԫ��
			pos = find(deadCar.begin(), deadCar.end(), CROSS[i].StartCar[j]);
			if (pos != deadCar.end())  //�ҵ���
			{
				isFind = true;
				deadCar.erase(pos);
			}
			if (CAR[carID].PT <= nowTime && CAR[carID].priority == 0 && CAR[carID].preset == 0 && isFind == true)
			{
				modifyCar.push_back(carID);
				PTAll.insert(CAR[carID].PT);
				isFind = false;
				++count;
				//CAR[carID].addPT(limitNumber - count);
				if (isFirst == true)
				{
					isFirst = false;
					cout << "PT is modifyed!!---------------" << endl;
				}
			}
		}
	}

	//�Գ�����PT��С��������
	for (it = PTAll.begin(); it != PTAll.end(); it++)
	{
		for (i = 0; i < (int)(modifyCar.size()); i++)
		{
			if (CAR[modifyCar[i]].PT == *it)
				tempCar.push_back(modifyCar[i]);
		}
	}
	modifyCar.clear();
	modifyCar.insert(modifyCar.begin(), tempCar.begin(), tempCar.end());
	if ((int)(modifyCar.size()) > limitNumber)
		modifyCar.erase(modifyCar.begin() + limitNumber, modifyCar.end());

	//�޸�PT
	int T = 0, N;
	for (N = (int)(modifyCar.size()); N >= 1; N--)
	{
		CAR[modifyCar[T]].addPT(N);
		++T;
	}
	int lastSize = (int)(modifyCar.size());

	//�ж��Ƿ��㹻
	if ((int)(modifyCar.size()) == limitNumber)
		return true;

	modifyCar.clear();
	tempCar.clear();
	PTAll.clear();
	isFirst = true;
	for (j = 0; j < limitNumber; j++)
	{
		for (i = 0; i < crossSize; i++)
		{
			if ((int)(CROSS[i].StartCar.size()) < limitNumber)
				continue;
			carID = CROSS[i].StartCar[j] - car0;
			roadID = CAR[carID].route[0] - road0;
			if (ROAD[roadID].crowding[CAR[carID].isReverse] < 0.1)
				continue;
			//����deadCar�Ƿ��и�Ԫ��
			pos = find(deadCar.begin(), deadCar.end(), CROSS[i].StartCar[j]);
			if (pos == deadCar.end())  //û�ҵ�
			{
				isFind = false;
			}
			if (CAR[carID].PT <= nowTime && CAR[carID].priority == 0 && CAR[carID].preset == 0 && isFind == false)
			{
				modifyCar.push_back(carID);
				PTAll.insert(CAR[carID].PT);
				isFind = true;
				++count;
				//if (count == limitNumber-1)
				//{
				//	j = limitNumber;
				//	break;
				//}
				//CAR[carID].addPT(limitNumber - count);
				if (isFirst == true)
				{
					isFirst = false;
					cout << "PT is modifyed!!----*-*-*-*-*-*----*-*-*-*-*-*-*---------" << endl;
				}
			}
		}
	}

	//�Գ�����PT��С��������
	for (it = PTAll.begin(); it != PTAll.end(); it++)
	{
		for (i = 0; i < (int)(modifyCar.size()); i++)
		{
			if (CAR[modifyCar[i]].PT == *it)
				tempCar.push_back(modifyCar[i]);
		}
	}
	modifyCar.clear();
	modifyCar.insert(modifyCar.begin(), tempCar.begin(), tempCar.end());
	if ((int)(modifyCar.size()) > (limitNumber - lastSize))
		modifyCar.erase(modifyCar.begin() + (limitNumber - lastSize), modifyCar.end());

	//�޸�PT
	T = 0;
	for (N = (int)(modifyCar.size()); N >= 1; N--)
	{
		CAR[modifyCar[T]].addPT(N);
		++T;
	}

	return true;
}

bool Dispatch::delayCarPT(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &nowTime, vector<int> &deadCar)
{
	int i, j, carID, roadID, count = 0;
	bool isFind = false;
	vector<int>::iterator pos;

	//�ҳ���ǰʱ�̱��ݳ�����PT<=nowTime�ĳ�,�����ع������ڵ�CAR���Ǳ��ݵ�����
	//����Щ���еķ����ȳ��ķ���ʱ���Ӻ�N��ʱ��
	int limitNumber = 50;
	
	int N = 0;
	for (j = 0; j < limitNumber; j++)
	{
		for (i = 0; i < crossSize; i++)
		{
			if ((int)(CROSS[i].StartCar.size()) < limitNumber)
				continue;
			carID = CROSS[i].StartCar[j] - car0;
			roadID = CAR[carID].route[0] - road0;
			if (ROAD[roadID].crowding[CAR[carID].isReverse] < 0.1)
				continue;
			//����deadCar�Ƿ��и�Ԫ��
			pos = find(deadCar.begin(), deadCar.end(), CROSS[i].StartCar[j]);
			if (pos != deadCar.end())  //�ҵ���
			{
				isFind = true;
				deadCar.erase(pos);
			}
			if (CAR[carID].PT <= nowTime && CAR[carID].priority == 0 && CAR[carID].preset == 0 && isFind == true)
			{
				isFind = false;
				++count;
				if (count > limitNumber)
					return true;
				CAR[carID].addPT(N);
				++N;
				if (N > 30)
					N = 1;
				if (count == 1)
					cout << "PT is modifyed!!---------------" << endl;
			}
		}
	}

	for (j = 0; j < limitNumber; j++)
	{
		for (i = 0; i < crossSize; i++)
		{
			if ((int)(CROSS[i].StartCar.size()) < limitNumber)
				continue;
			carID = CROSS[i].StartCar[j] - car0;
			roadID = CAR[carID].route[0] - road0;
			if (ROAD[roadID].crowding[CAR[carID].isReverse] < 0.1)
				continue;
			//����deadCar�Ƿ��и�Ԫ��
			pos = find(deadCar.begin(), deadCar.end(), CROSS[i].StartCar[j]);
			if (pos == deadCar.end())  //û�ҵ�
			{
				isFind = false;
			}
			if (CAR[carID].PT <= nowTime && CAR[carID].priority == 0 && CAR[carID].preset == 0 && isFind == false)
			{
				isFind = true;
				++count;
				if (count > limitNumber)
					return true;
				CAR[carID].addPT(N);
				++N;
				if (N > 30)
					N = 1;
				if (count == 1)
					cout << "PT is modifyed!!----*-*-*-*-*-*----*-*-*-*-*-*-*---------" << endl;
			}
		}
	}
	return true;
}

//��������_�ع�
void Dispatch::dealDeadLock_back(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph, vector<int> &freeRoads, vector<int> &busyRoads, vector<int> &CROSSID) {
	vector<int> carIDs;
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		//cout << ", cross num is " << num;
		int roadIDS[4] = { CROSS[num].road1,CROSS[num].road2, CROSS[num].road3, CROSS[num].road4 };
		sort(roadIDS, roadIDS + 4); //��С��������

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		int dir[4];
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
				continue;
			if (ROAD[roadIDS[q] - road0].to == num + cross0)
				dir[q] = 0;
			else
				dir[q] = 1;
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��һ���ȼ��ĳ�...
				carIDs.clear();
				carIDs = getCar3(roadIDS[q], dir[q], ROAD, CAR, 20);
				if (carIDs.size() == 0)
					break;
				for (int i = 0; i < (int)carIDs.size(); i++) {

					if (CAR[carIDs[i] - car0].preset == 1) {
						continue;
					}
					if (CAR[carIDs[i] - car0].nextCrossDistance < CAR[carIDs[i] - car0].maxSpeed) {//��ǰʱ��Ҫ��·�ڵĳ�����Ҫ�޸ģ����̫�࣬��bug
						continue;
					}
					if (CAR[carIDs[i] - car0].passRoadNumber == (int)(CAR[carIDs[i] - car0].route.size()) - 1) {//Ŀǰ����·�Ǹó������һ��·��Ҳ��Ҫ��������
						continue;
					}
					else if (CAR[carIDs[i] - car0].passRoadNumber == (int)(CAR[carIDs[i] - car0].route.size()) - 2) {//�ó�����һ��·��Ҫ���յ㣬Ҳ��Ҫ��������
						continue;
					}
					else if (CAR[carIDs[i] - car0].passRoadNumber == (int)(CAR[carIDs[i] - car0].route.size()) - 3) {//�ó�������һ��·��Ҫ���յ㣬Ҳ��Ҫ��������
						continue;
					}
					CAR[carIDs[i] - car0].changeDeadFlag = true;
					Graph_DG deadCarGraph(OriginalCarGraph);
					deadCarGraph.initRoute_DealLock_back(CAR[carIDs[i] - car0], CROSS, ROAD, freeRoads, busyRoads, CROSSID);
					//����Ҫ���ɸĸó�����һ��·�����¼����ĸ�vector
					//����maxSP��reverse
					int carid = carIDs[i] - car0;
					CAR[carid].maxSP.clear();
					CAR[carid].reverse.clear();
					int roadID = CAR[carid].route[0] - road0;
					if (CAR[carid].from == ROAD[roadID].from) //����
					{
						CAR[carid].addRverse(0);
					}
					if (CAR[carid].from == ROAD[roadID].to) //����
					{
						CAR[carid].addRverse(1);
					}
					for (int i = 0; i < (int)(CAR[carid].route.size()); i++)
					{
						int newRoadID = CAR[carid].route[i] - road0;
						if (i > 0)
						{
							if (CAR[carid].reverse[i - 1] == 0) //��һ��·��from-to���ǳ����н�����
							{
								int lastRoad = CAR[carid].route[i - 1] - road0;
								if (ROAD[lastRoad].to == ROAD[newRoadID].from)
									CAR[carid].addRverse(0);
								else
									CAR[carid].addRverse(1);
							}
							if (CAR[carid].reverse[i - 1] == 1) //��һ��·��to-from���ǳ����н�����
							{
								int lastRoad = CAR[carid].route[i - 1] - road0;
								if (ROAD[lastRoad].from == ROAD[newRoadID].from)
									CAR[carid].addRverse(0);
								else
									CAR[carid].addRverse(1);
							}
						}

						if (CAR[carid].speed < ROAD[CAR[carid].route[i] - road0].speed)
							CAR[carid].addMaxSpeed(CAR[carid].speed);
						else
							CAR[carid].addMaxSpeed(ROAD[CAR[carid].route[i] - road0].speed);
					}
				}
				break;
			}
		}
	}
}


//��������
void Dispatch::dealDeadLock(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph, vector<int> &freeRoads, vector<int> &busyRoads, vector<int> &CROSSID) {
	vector<int> carIDs;
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		//cout << ", cross num is " << num;
		int roadIDS[4] = { CROSS[num].road1,CROSS[num].road2, CROSS[num].road3, CROSS[num].road4 };
		sort(roadIDS, roadIDS + 4); //��С��������

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		int dir[4];
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
				continue;
			if (ROAD[roadIDS[q] - road0].to == num + cross0)
				dir[q] = 0;
			else
				dir[q] = 1;
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��һ���ȼ��ĳ�...
				carIDs.clear();
				carIDs = getCar3(roadIDS[q], dir[q], ROAD, CAR, 5);
				if (carIDs.size() == 0)
					break;
				for (int i = 0; i < (int)carIDs.size(); i++) {
					if (CAR[carIDs[i] - car0].preset == 1) {
						continue;
					}
					Graph_DG deadCarGraph(OriginalCarGraph);
					deadCarGraph.initRoute_DealLock(CAR[carIDs[i] - car0], CROSS, ROAD, freeRoads, busyRoads, CROSSID);
				}

				break;
			}
		}
	}
}

//�����������������
int Dispatch::dispathMAIN_withDeal(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bestTime, const Graph_DG &OriginalCarGraph, vector<int> &CROSSID)
{
	//int waitNumber;
	int num, j;
	vector<int> roadIDS, dir;

	//T1ʱ�̳�ʼ��
	dispathINIT(CAR, CROSS, ROAD, GlobalTime, TT);
	++GlobalTime;
	//cout << "Inition OVER!" << endl;

	while (!isAllTerminate(CAR)) //δ�����г������յ㳵��
	{
		//cout << endl << endl;
		cout << "GlobalTime is " << GlobalTime << endl;

		//if (GlobalTime > 20) {
			dynamicPlanSet(CAR, CROSS, ROAD, OriginalCarGraph);
		//}

		//ֱ�Ӵ���ɴ��յ�״̬�ĳ���
		setState(CAR, CROSS, ROAD, GlobalTime);

		//���ȳ�������ȳ���
		if (EmptyCarportNumber < crossSize)
		{
			for (num = 0; num < crossSize; num++)
				moveCarportPriorityCar(num, CAR, ROAD, CROSS, GlobalTime);
		}

		//�������е�·�ϵȴ�״̬�ĳ�������ֹ״̬
		while (!isAllEnd(CAR))
		{
			//gain waitNumber
			//waitNumber = gainWaitNum(CAR);
			isDeadlock = true;
			for (num = 0; num < crossSize; num++)
			{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���			
				roadIDS.clear();
				roadIDS.push_back(CROSS[num].road1);
				roadIDS.push_back(CROSS[num].road2);
				roadIDS.push_back(CROSS[num].road3);
				roadIDS.push_back(CROSS[num].road4);
				sort(roadIDS.begin(), roadIDS.end());

				//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
				dir.clear();
				for (int q = 0; q < 4; q++)
				{
					if (roadIDS[q] == -1) //û��·
					{
						dir.push_back(-1);
						continue;
					}
					if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
						dir.push_back(0);
					else
						dir.push_back(1);
				}

				//���������·�ĵ�һ���ȼ�����
				for (int q = 0; q < 4; q++)
				{
					//��ǰ��·�ϵĳ�δ��������
					while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
					{
						//��ȡ��һ���ȼ��ĳ�
						int carID = getCar(roadIDS[q], dir[q], ROAD, CAR);

						if (carID == -1)
							break;

						//���ã���ֹ���¶�ʧ
						int oldRoadID = roadIDS[q] - road0;
						int oldChannel = CAR[carID - car0].location[1];
						int oldPosition = CAR[carID - car0].location[2];

						/*int tempRoad = CAR[carID - car0].nextRoad;
						int tempDir = CAR[carID - car0].nextReverse;*/

						if (isConflict(q, carID, roadIDS, dir, ROAD, CAR)) //�����ͻ���ͻ���һ��·����
						{
							break;
						}

						//���ȳ���
						//bool isEndInNextRoad = false;
						moveToNextRoad(carID, CAR, ROAD, CROSS, GlobalTime);

						if (CAR[carID - car0].state == 0) //����ʧ�ܣ�Ҫȥ��·���еȴ��ĳ����赲
						{
							break;
						}

						//***********setdeadlock*************
						isDeadlock = false;

						if (CAR[carID - car0].state == 1)	//���ȳɹ�
						{
							if (oldPosition == 1)
								break;

							for (j = oldPosition - 2; j >= 0; j--)
							{
								if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] == -1)
									continue;
								int newCar = ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] - car0;
								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 1) //�ȴ��´α���
								{
									//ɨ�赱ǰ�����Ƿ�����ֹ���赲
									int count = 0;
									for (int n = j + 1; n < ROAD[oldRoadID].length; n++)
									{
										if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][n] != -1)
										{
											++count;
											break;
										}
									}
									//�ܵ��赲��ֱ����ֹ
									if (count == 1)
										moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
									//�����赲����������ɨ�豾��·�����ȼ�
									if (count == 0)
										break;
								}
								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 0)
									moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
							}

							////���������ȳ�ȥͷ��ͣ�ڵ�����·��
							//if (tempRoad != -1)
							//{
							//	moveCarportCarPriorityToRoad(tempRoad, tempDir, CAR, ROAD, CROSS, GlobalTime);
							//}

							//��·��ͨ������Ҫ����·�����ȳ�
							moveCarportCarPriorityToRoad(roadIDS[q], dir[q], CAR, ROAD, CROSS, GlobalTime);

							////���ȳ�������ȳ���
							//for (num = 0; num < crossSize; num++)
							//	moveCarportPriorityCar(num, CAR, ROAD, CROSS, GlobalTime);
						}

					}
				}
			}
			//deadlock happen
			if (isDeadlock == true)
			{
				cout << "deadlock happen at GlobalTime in " << GlobalTime << endl;
				this->getFreeBusyRoads(ROAD);	//��ȡfreeRoads��busyRoads.	
				this->dealDeadLock(CAR, CROSS, ROAD, OriginalCarGraph, freeRoads, busyRoads, CROSSID);
				return BADTIME;

			}
			/*int nowWaitNumber = gainWaitNum(CAR);
			if (waitNumber == nowWaitNumber)
					return BADTIME;*/

		}

		if (EmptyCarportNumber < crossSize)
		{
			//���Ʒ�������
			modifyPlantime(CAR, CROSS, ROAD, GlobalTime);
			//���ȳ���ĳ���
			for (num = 0; num < crossSize; num++)
				moveCarport(num, CAR, ROAD, CROSS, GlobalTime);
		}

		//����ӵ����
		computeRoadCrowding(ROAD);

		resetRoadCarNumber();

		++GlobalTime;

		//computeRANUM(GlobalTime);

		if (GlobalTime > bestTime)
			return 2 * BADTIME;
	}

	return GlobalTime - 1;
}


////�����������������
//int Dispatch::dispathMAIN_withDeal2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bestTime, const Graph_DG &OriginalCarGraph, vector<int> &CROSSID)
//{
//	//int waitNumber;
//	int num, j,  dieCount = 0;
//	vector<int> roadIDS, dir, deadCar;
//	vector<float> futureCrowing;
//	vector<vector<int>> CarDeadRoadId;
//	vector<int> deadRoadId;
//	for (int i = 0; i < (int)(CAR.size()); i++) {
//		CarDeadRoadId.push_back(deadRoadId);
//	}
//
//	//T1ʱ�̳�ʼ��
//	dispathINIT(CAR, CROSS, ROAD, GlobalTime, TT);
//	++GlobalTime;
//	//cout << "Inition OVER!" << endl;
//
//	while (!isAllTerminate(CAR)) //δ�����г������յ㳵��
//	{
//		//cout << endl << endl;
//		//cout << "GlobalTime is " << GlobalTime << endl;
//
//		//if (GlobalTime > 20) 
//			dynamicPlanSet(CAR, CROSS, ROAD, OriginalCarGraph);
//
//		//ֱ�Ӵ���ɴ��յ�״̬�ĳ���
//		setState(CAR, CROSS, ROAD, GlobalTime);
//
//		//���ȳ�������ȳ���
//		if (EmptyCarportNumber < crossSize)
//		{
//			for (num = 0; num < crossSize; num++)
//				moveCarportPriorityCar(num, CAR, ROAD, CROSS, GlobalTime);
//		}		
//
//		//�������е�·�ϵȴ�״̬�ĳ�������ֹ״̬
//		while (!isAllEnd(CAR))
//		{
//			//gain waitNumber
//			//waitNumber = gainWaitNum(CAR);
//			isDeadlock = true;
//			for (num = 0; num < crossSize; num++)
//			{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���			
//				roadIDS.clear();
//				roadIDS.push_back(CROSS[num].road1);
//				roadIDS.push_back(CROSS[num].road2);
//				roadIDS.push_back(CROSS[num].road3);
//				roadIDS.push_back(CROSS[num].road4);
//				sort(roadIDS.begin(), roadIDS.end());
//
//				//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
//				dir.clear();
//				for (int q = 0; q < 4; q++)
//				{
//					if (roadIDS[q] == -1) //û��·
//					{
//						dir.push_back(-1);
//						continue;
//					}
//					if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
//						dir.push_back(0);
//					else
//						dir.push_back(1);
//				}
//
//				//���������·�ĵ�һ���ȼ�����
//				for (int q = 0; q < 4; q++)
//				{
//					//��ǰ��·�ϵĳ�δ��������
//					while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
//					{
//						//��ȡ��һ���ȼ��ĳ�
//						int carID = getCar(roadIDS[q], dir[q], ROAD, CAR);
//
//						if (carID == -1)
//							break;
//
//						//���ã���ֹ���¶�ʧ
//						int oldRoadID = roadIDS[q] - road0;
//						int oldChannel = CAR[carID - car0].location[1];
//						int oldPosition = CAR[carID - car0].location[2];
//
//						/*int tempRoad = CAR[carID - car0].nextRoad;
//						int tempDir = CAR[carID - car0].nextReverse;*/
//
//						if (isConflict(q, carID, roadIDS, dir, ROAD, CAR)) //�����ͻ���ͻ���һ��·����
//						{
//							break;
//						}
//
//						//���ȳ���
//						//bool isEndInNextRoad = false;
//						moveToNextRoad(carID, CAR, ROAD, CROSS, GlobalTime);
//
//						if (CAR[carID - car0].state == 0) //����ʧ�ܣ�Ҫȥ��·���еȴ��ĳ����赲
//						{
//							break;
//						}
//
//						//***********setdeadlock*************
//						isDeadlock = false;
//
//						if (CAR[carID - car0].state == 1)	//���ȳɹ�
//						{
//							if (oldPosition == 1)
//								break;
//
//							for (j = oldPosition - 2; j >= 0; j--)
//							{
//								if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] == -1)
//									continue;
//								int newCar = ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] - car0;
//								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 1) //�ȴ��´α���
//								{
//									//ɨ�赱ǰ�����Ƿ�����ֹ���赲
//									int count = 0;
//									for (int n = j + 1; n < ROAD[oldRoadID].length; n++)
//									{
//										if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][n] != -1)
//										{
//											++count;
//											break;
//										}
//									}
//									//�ܵ��赲��ֱ����ֹ
//									if (count == 1)
//										moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
//									//�����赲����������ɨ�豾��·�����ȼ�
//									if (count == 0)
//										break;
//								}
//								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 0)
//									moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
//							}
//							//��·��ͨ������Ҫ����·�����ȳ�
//							moveCarportCarPriorityToRoad(roadIDS[q], dir[q], CAR, ROAD, CROSS, GlobalTime);
//						}
//
//					}
//				}
//			}
//			if (isDeadlock == true)
//				break;
//		}
//		//deadlock happen
//		if (isDeadlock == true)
//		{
//			cout << "deadlock happen at GlobalTime in " << GlobalTime << endl;
//			//this->getFreeBusyRoads(ROAD);	//��ȡfreeRoads��busyRoads.	
//			this->setFlagDeadCar(CAR, CROSS, ROAD, CarDeadRoadId);//��������������־λ����������ʱ�ĵ�·����������ʱ����һ����·
//			//this->dealDeadLock_back(CAR, CROSS, ROAD, OriginalCarGraph, freeRoads, busyRoads, CROSSID);//��������������ʵû�õ��ˣ�����ɾ��
//			
//			//��ȡ������
//			deadCar.clear();
//			deadCar = getDeadCarID(CAR, CROSS, ROAD);
//			//deadCar=getDeadCarFirstAll(CAR, CROSS, ROAD);
//			cout<<"deadCar size is "<<(int)(deadCar.size())<<endl;
//
//			////����ӵ����Ϣ
//			//futureCrowing.clear();
//			//for (int i = 0; i < roadSize; i++)
//			//{
//			//	futureCrowing.push_back(ROAD[i].crowding[0]);
//			//	futureCrowing.push_back(ROAD[i].crowding[1]);
//			//}
//
//			//��ȡ�޸ĵ�·��				
//			int nowTime = GlobalTime;
//			//���ݻع�������ʱ��
//			++dieCount;
//			cout << "back_1 time is " << backup_GlobalTime << ", " << "back_2 time is " << backup_GlobalTime2 << endl;
//			mainRollback(CAR, CROSS, ROAD, GlobalTime, OriginalCarGraph);
//			cout << "rollback time is " << GlobalTime << endl;
//			cout << "dieCount is " << dieCount << endl;
//			this->delayCarPT(CAR, CROSS, ROAD, nowTime,deadCar);
//		}
//
//		if (isDeadlock == false)
//		{
//			if (EmptyCarportNumber < crossSize)
//			{
//				//���Ʒ�������
//				modifyPlantime(CAR, CROSS, ROAD, GlobalTime);
//				//���ȳ���ĳ���
//				for (num = 0; num < crossSize; num++)
//					moveCarport(num, CAR, ROAD, CROSS, GlobalTime);
//			}		
//		}
//
//		//����ӵ����
//		computeRoadCrowding(ROAD);
//
//		////���δ����ӵ����Ϣ
//		//int count=0;
//		//if (isDeadlock == true)
//		//{
//		//	for (int i = 0; i < roadSize; i++)
//		//	{
//		//		ROAD[i].crowding[0] = 0.3*ROAD[i].crowding[0] + 0.7*futureCrowing[count];
//		//		++count;
//		//		ROAD[i].crowding[1] = 0.3*ROAD[i].crowding[1] + 0.7*futureCrowing[count];
//		//		++count;
//		//	}
//		//}
//
//		//ÿ��N��ʱ�̱���һ������
//		int N = 50;
//		if ((GlobalTime%N) == 0)
//			mainBackup(CAR, CROSS, ROAD, GlobalTime);
//
//		resetRoadCarNumber();
//
//		++GlobalTime;
//
//		computeRANUM(GlobalTime,CAR[0]);
//
//		if (GlobalTime > bestTime)
//			return 2 * BADTIME;
//	}
//	cout << "total dieCount is " << dieCount << endl;
//	return GlobalTime - 1;
//}

//�����������������
int Dispatch::dispathMAIN_withDeal3(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bestTime, const Graph_DG &OriginalCarGraph, vector<int> &CROSSID)
{
	//int waitNumber;
	int num, j, dieCount = 0, nowTime, pos, COUNT = 0, tempCount = 0;
	vector<int> roadIDS, dir, deadCar;
	vector<float> futureCrowing;
	vector<vector<int>> CarDeadRoadIds;
	vector<int> deadRoadId;
	for (int i = 0; i < (int)(CAR.size()); i++) {
		CarDeadRoadIds.push_back(deadRoadId);
	}
	vector<int> canBeChangedDeadCarIDs;

	//T1ʱ�̳�ʼ��
	dispathINIT(CAR, CROSS, ROAD, GlobalTime, TT);
	++GlobalTime;
	//cout << "Inition OVER!" << endl;

	while (!isAllTerminate(CAR)) //δ�����г������յ㳵��
	{
		//cout << endl << endl;
		cout << "GlobalTime is " << GlobalTime << endl;

		//if (GlobalTime > 20) 
		dynamicPlanSet(CAR, CROSS, ROAD, OriginalCarGraph);

		//ֱ�Ӵ���ɴ��յ�״̬�ĳ���
		setState(CAR, CROSS, ROAD, GlobalTime);

		//���ȳ�������ȳ���
		for (num = 0; num < crossSize; num++)
			moveCarportPriorityCar(num, CAR, ROAD, CROSS, GlobalTime);

		//�������е�·�ϵȴ�״̬�ĳ�������ֹ״̬
		while (!isAllEnd(CAR))
		{
			//gain waitNumber
			//waitNumber = gainWaitNum(CAR);
			isDeadlock = true;
			for (num = 0; num < crossSize; num++)
			{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���			
				roadIDS.clear();
				roadIDS.push_back(CROSS[num].road1);
				roadIDS.push_back(CROSS[num].road2);
				roadIDS.push_back(CROSS[num].road3);
				roadIDS.push_back(CROSS[num].road4);
				sort(roadIDS.begin(), roadIDS.end());

				//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
				dir.clear();
				for (int q = 0; q < 4; q++)
				{
					if (roadIDS[q] == -1) //û��·
					{
						dir.push_back(-1);
						continue;
					}
					if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
						dir.push_back(0);
					else
						dir.push_back(1);
				}

				//���������·�ĵ�һ���ȼ�����
				for (int q = 0; q < 4; q++)
				{
					//��ǰ��·�ϵĳ�δ��������
					while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
					{
						//��ȡ��һ���ȼ��ĳ�
						int carID = getCar(roadIDS[q], dir[q], ROAD, CAR);

						if (carID == -1)
							break;

						//���ã���ֹ���¶�ʧ
						int oldRoadID = roadIDS[q] - road0;
						int oldChannel = CAR[carID - car0].location[1];
						int oldPosition = CAR[carID - car0].location[2];

						/*int tempRoad = CAR[carID - car0].nextRoad;
						int tempDir = CAR[carID - car0].nextReverse;*/

						if (isConflict(q, carID, roadIDS, dir, ROAD, CAR)) //�����ͻ���ͻ���һ��·����
						{
							break;
						}

						//���ȳ���
						//bool isEndInNextRoad = false;
						moveToNextRoad(carID, CAR, ROAD, CROSS, GlobalTime);

						if (CAR[carID - car0].state == 0) //����ʧ�ܣ�Ҫȥ��·���еȴ��ĳ����赲
						{
							break;
						}

						//***********setdeadlock*************
						isDeadlock = false;

						if (CAR[carID - car0].state == 1)	//���ȳɹ�
						{
							if (oldPosition == 1)
								break;

							for (j = oldPosition - 2; j >= 0; j--)
							{
								if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] == -1)
									continue;
								int newCar = ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] - car0;
								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 1) //�ȴ��´α���
								{
									//ɨ�赱ǰ�����Ƿ�����ֹ���赲
									int count = 0;
									for (int n = j + 1; n < ROAD[oldRoadID].length; n++)
									{
										if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][n] != -1)
										{
											++count;
											break;
										}
									}
									//�ܵ��赲��ֱ����ֹ
									if (count == 1)
										moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
									//�����赲����������ɨ�豾��·�����ȼ�
									if (count == 0)
										break;
								}
								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 0)
									moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
							}
							//��·��ͨ������Ҫ����·�����ȳ�
							moveCarportCarPriorityToRoad(roadIDS[q], dir[q], CAR, ROAD, CROSS, GlobalTime);
						}

					}
				}
			}
			if (isDeadlock == true)
				break;
		}
		//deadlock happen
		if (isDeadlock == true)
		{
			cout << "deadlock happen at GlobalTime in " << GlobalTime << endl;
			//this->getFreeBusyRoads(ROAD);	//��ȡfreeRoads��busyRoads.
			canBeChangedDeadCarIDs.clear();
			canBeChangedDeadCarIDs = this->setFlagDeadCar2(CAR, CROSS, ROAD, CarDeadRoadIds);//��������������־λ����������ʱ�ĵ�·����������ʱ����һ����·
			//this->dealDeadLock_back(CAR, CROSS, ROAD, OriginalCarGraph, freeRoads, busyRoads, CROSSID);//��������������ʵû�õ��ˣ�����ɾ��

			//��ȡ������
			deadCar.clear();
			deadCar = getDeadCarID(CAR, CROSS, ROAD);
			//deadCar=getDeadCarFirstAll(CAR, CROSS, ROAD);
			cout << "deadCar size is " << (int)(deadCar.size()) << endl;

			//��ȡ�޸ĵ�·��				
			nowTime = GlobalTime;
			//���ݻع�������ʱ��
			++dieCount;

			//���ݻع�
			pos = (int)(BackupData.size()) - 1;
			if (abs(nowTime - lastLockTime) < 70)
				++tempCount;
			else
				tempCount = 0;
			int limitCount = 6;
			if (nowTime == lastLockTime)
				++COUNT;
			else
				COUNT = 0;
			cout << "tempCount is " << tempCount << "COUNT is " << COUNT << endl;
			if (tempCount > 10)
			{
				tempCount = 0;
				pos = (int)(BackupData.size()) - 3;
			}
			else
			{
				if (nowTime <= lastLockTime && (int)(BackupData.size()) > 1)  //�����ǰ����������������ݵ�ǰһ�����ݴ��ָ�����
				{
					int order = ceil((double)(COUNT) / (double)(limitCount));
					if (COUNT == 0)
						order = 1;
					pos = (int)(BackupData.size()) - order;
				}
				if (nowTime > lastLockTime || (int)(BackupData.size()) == 1) //�����������������������ݵı��ݴ��ָ�����
					pos = (int)(BackupData.size()) - 1;
			}
			

			GlobalTime = BackupData[pos].backupTime;
			CAR.clear();
			CAR.insert(CAR.begin(), BackupData[pos].backup_CAR.begin(), BackupData[pos].backup_CAR.end());
			CROSS.clear();
			CROSS.insert(CROSS.begin(), BackupData[pos].backup_CROSS.begin(), BackupData[pos].backup_CROSS.end());
			ROAD.clear();
			ROAD.insert(ROAD.begin(), BackupData[pos].backup_ROAD.begin(), BackupData[pos].backup_ROAD.end());

			//����ɾ��
			BackupData.erase(BackupData.begin() + pos, BackupData.end());
			if(pos-8>0)
				BackupData.erase(BackupData.begin(), BackupData.begin() + pos-8);

			cout << "rollback time is " << GlobalTime << endl;
			cout << "dieCount is " << dieCount << endl;
			this->delayCarPT2(CAR, CROSS, ROAD, nowTime, deadCar);

			for (int i = 0; i < (int)(canBeChangedDeadCarIDs.size()); i++) {
				CAR[canBeChangedDeadCarIDs[i]].computeNEXT(ROAD, CROSS);
				this->changeDeadCarRoute2(CAR[canBeChangedDeadCarIDs[i]], CROSS, ROAD, OriginalCarGraph, CarDeadRoadIds[canBeChangedDeadCarIDs[i]]);
			}
			lastLockTime = nowTime;
		}
		
		if (isDeadlock == false)
		{
			//���Ʒ�������
			modifyPlantime(CAR, CROSS, ROAD, GlobalTime);
			//���ȳ���ĳ���
			for (num = 0; num < crossSize; num++)
				moveCarport(num, CAR, ROAD, CROSS, GlobalTime);
		}
		//����ӵ����
		computeRoadCrowding(ROAD);

		//ÿ��N��ʱ�̱���һ������
		int N = 50;
		if ((GlobalTime % N) == 0)
		{
			if ((int)(BackupData.size()) > 8)
				BackupData.erase(BackupData.begin(), BackupData.begin() + (int)(BackupData.size()) - 8);
			Backup_data backup_data;
			backup_data.init(CAR, CROSS, ROAD, GlobalTime);
			BackupData.push_back(backup_data);
		}

		resetRoadCarNumber();

		++GlobalTime;

		computeRANUM(GlobalTime,CAR[0]);

		if (GlobalTime > bestTime)
			return 2 * BADTIME;
	}
	cout << "total dieCount is " << dieCount << endl;
	return GlobalTime - 1;
}

int Dispatch::dispathMAIN(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bestTime)
{
	//int waitNumber;
	int num,j, k;
	vector<int> roadIDS,dir;

	//T1ʱ�̳�ʼ��
	dispathINIT(CAR, CROSS, ROAD, GlobalTime,TT);
	++GlobalTime;
	//cout << "Inition OVER!" << endl;

	while (!isAllTerminate(CAR)) //δ�����г������յ㳵��
	{
		//cout << endl << endl;
		cout<< "GlobalTime is " << GlobalTime<< endl;
		//ֱ�Ӵ���ɴ��յ�״̬�ĳ���
		setState(CAR, CROSS, ROAD, GlobalTime);
		
		//���ȳ�������ȳ���
		for (num = 0; num < crossSize; num++)
			moveCarportPriorityCar(num, CAR, ROAD, CROSS, GlobalTime);

		//�������е�·�ϵȴ�״̬�ĳ�������ֹ״̬
		while (!isAllEnd(CAR))
		{
			//gain waitNumber
			//waitNumber = gainWaitNum(CAR);
			isDeadlock = true;
			for (num = 0; num < crossSize; num++)
			{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���			
				roadIDS.clear();
				roadIDS.push_back(CROSS[num].road1);
				roadIDS.push_back(CROSS[num].road2);
				roadIDS.push_back(CROSS[num].road3);
				roadIDS.push_back(CROSS[num].road4);
				sort(roadIDS.begin(), roadIDS.end());

				//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
				dir.clear();
				for (int q = 0; q < 4; q++)
				{
					if (roadIDS[q] == -1) //û��·
					{
						dir.push_back(-1);
						continue;
					}
					if ((num + cross0) == ROAD[roadIDS[q] - road0].to)
						dir.push_back(0);
					else
						dir.push_back(1);
				}

				//���������·�ĵ�һ���ȼ�����
				for (int q = 0; q < 4; q++)
				{
					//��ǰ��·�ϵĳ�δ��������
					while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
					{
						//��ȡ��һ���ȼ��ĳ�
						int carID = getCar(roadIDS[q], dir[q], ROAD, CAR);

						if (carID == -1)
							break;

						//���ã���ֹ���¶�ʧ
						int oldRoadID = roadIDS[q] - road0;
						int oldChannel = CAR[carID - car0].location[1];
						int oldPosition = CAR[carID - car0].location[2];

						/*int tempRoad = CAR[carID - car0].nextRoad;
						int tempDir = CAR[carID - car0].nextReverse;*/

						if (isConflict(q, carID, roadIDS, dir, ROAD, CAR)) //�����ͻ���ͻ���һ��·����
						{
							break;
						}

						//���ȳ���
						//bool isEndInNextRoad = false;
						moveToNextRoad(carID, CAR, ROAD, CROSS, GlobalTime);

						if (CAR[carID - car0].state == 0) //����ʧ�ܣ�Ҫȥ��·���еȴ��ĳ����赲
						{
							break;
						}

						//***********setdeadlock*************
						isDeadlock = false;

						if (CAR[carID - car0].state == 1)	//���ȳɹ�
						{
							if (oldPosition ==1)
								break;

							for (j = oldPosition - 2; j >= 0; j--)
							{
								if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] == -1)
									continue;
								int newCar = ROAD[oldRoadID].roadCar[dir[q]][oldChannel][j] - car0;
								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 1) //�ȴ��´α���
								{
									//ɨ�赱ǰ�����Ƿ�����ֹ���赲
									int count = 0;
									for (int n = j + 1; n < ROAD[oldRoadID].length; n++)
									{
										if (ROAD[oldRoadID].roadCar[dir[q]][oldChannel][n] != -1)
										{
											++count;
											break;
										}
									}
									//�ܵ��赲��ֱ����ֹ
									if (count == 1)
										moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
									//�����赲����������ɨ�豾��·�����ȼ�
									if (count == 0)
										break;
								}
								if (CAR[newCar].state == 0 && CAR[newCar].toNextRoad == 0)
									moveOnTheRoad(newCar, CAR, ROAD, CROSS, GlobalTime);
							}
							//��·��ͨ������Ҫ����·�����ȳ�
							moveCarportCarPriorityToRoad(roadIDS[q], dir[q], CAR, ROAD, CROSS, GlobalTime);
						}
						
					}
				}
			}			
			//deadlock happen
			if (isDeadlock == true)
			{
				cout << "deadlock happen at GlobalTime in " << GlobalTime << endl;
				return BADTIME;
			}
			/*int nowWaitNumber = gainWaitNum(CAR);
			if (waitNumber == nowWaitNumber)
					return BADTIME;*/			

		}

		//���Ʒ�������
		//modifyPlantime(CAR, CROSS, ROAD, GlobalTime);

		//���ȳ���ĳ���
		for(num=0;num<crossSize;num++)
			moveCarport2(num, CAR, ROAD, CROSS, GlobalTime);

		//��ѯ��·��ǰ������Ŀ������Ŀ
		computeRoadCrowding(ROAD);

		//�����г�state����Ϊ-1
		for (k = 0; k < carSize; k++)
		{
			CAR[k].toNextRoad = 0;
			CAR[k].setState(-1);
		}
		resetRoadCarNumber();

		++GlobalTime;

		//computeRANUM(GlobalTime);

		if (GlobalTime > bestTime)
			return 2*BADTIME;
	}

	return GlobalTime-1;
}

void Dispatch::computeRANUM(int nowTime, Car &FirstCar)
{
	if (FirstCar.from == 139) {
		//if (nowTime > 0 && nowTime < 300)
		//	RANUM = 6500;
		if (nowTime > 400 && nowTime < 900)
			RANUM = 6000;
		////if (nowTime > 800 && nowTime < 1000)
		////	RANUM = 5000;
		if (nowTime > 900 && nowTime < 1400)
			RANUM = 6500;
		//if (nowTime > 1200)
		//	RANUM = 5500;
	}
	else if (FirstCar.from == 146) {
		//if (nowTime > 0 && nowTime < 300)
	//	RANUM = 6500;
		if (nowTime > 600 && nowTime < 900)
			RANUM = 6300;
		////if (nowTime > 800 && nowTime < 1000)
		////	RANUM = 5000;
		if (nowTime > 900 && nowTime < 1400)
			RANUM = 6500;
		//if (nowTime > 1200)
		//	RANUM = 5500;
	}

	//else
	//{
	//	double x = PI / 3.0 + (PI / 3.0 / 500.0)*(double)(nowTime-500);
	//	double y = 6500.0 - 2500.0 * sin(x);
	//	RANUM = (int)(y);
	//}
}

void Dispatch::dynamicPlanSet(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph) {
	int lastRoadID;
	int newRoadID;

	/*���������ص㣬���¹滮·��*/
	Graph_DG dynamicGraph(OriginalCarGraph);
	dynamicGraph.initRoute_Dynamic(CAR, CROSS, ROAD);
	/*���������ص㣬���¹滮·��*/

	//����maxSP�Լ�reverse
	for (int num = 0; num < carSize; num++) {

		if (CAR[num].preset == 1) {//Ԥ�ó��������޸�
			continue;
		}
		else if (CAR[num].isTerminate == 1) {//�����յ�ĳ���Ҳ�����޸�
			continue;
		}

		CAR[num].maxSP.clear();
		CAR[num].reverse.clear();

		for (int i = 0; i < (int)CAR[num].route.size(); i++) {
			if (i == 0) {//��һ��·
				int roadID = CAR[num].route[i] - road0;
				if (CAR[num].from == ROAD[roadID].from) {
					CAR[num].addRverse(0);
					//CAR[num].isRVER(0);
				}
				else if (CAR[num].from == ROAD[roadID].to) {
					CAR[num].addRverse(1);
					//CAR[num].isRVER(1);
				}
			}
			else {
				newRoadID = CAR[num].route[i] - road0;
				if (CAR[num].reverse[i - 1] == 0) //��һ��·��from-to���ǳ����н�����
				{
					lastRoadID = CAR[num].route[i - 1] - road0;
					if (ROAD[lastRoadID].to == ROAD[newRoadID].from)
						CAR[num].addRverse(0);
					else
						CAR[num].addRverse(1);
				}
				if (CAR[num].reverse[i - 1] == 1) //��һ��·��to-from���ǳ����н�����
				{
					lastRoadID = CAR[num].route[i - 1] - road0;
					if (ROAD[lastRoadID].from == ROAD[newRoadID].from)
						CAR[num].addRverse(0);
					else
						CAR[num].addRverse(1);
				}
			}
			if (CAR[num].speed < ROAD[CAR[num].route[i] - road0].speed)
				CAR[num].addMaxSpeed(CAR[num].speed);
			else
				CAR[num].addMaxSpeed(ROAD[CAR[num].route[i] - road0].speed);
		}
	}
}


void Dispatch::getFreeBusyRoads(vector<Road> &ROAD) {

	freeRoads.clear();
	busyRoads.clear();

	//����·�ϳ�������ƽ��ֵ���ǵõ��»���ӵ���ȵ�
	int ave_allCarNum = 0;
	for (int i = 0; i < (int)(ROAD.size()); i++) {
		ave_allCarNum += ROAD[i].allCarNum;
	}
	ave_allCarNum = ave_allCarNum / (int)(ROAD.size());

	//ʶ����������ٵ�·
	//cout << "���е�·�ĳ���������� " << endl;
	for (int i = 0; i < (int)(ROAD.size()); i++) {
		//cout << "��·id�� " << ROAD[i].id << "������: " << ROAD[i].allCarNum << endl;
		if (ROAD[i].allCarNum < 0.2 * ave_allCarNum) {
			freeRoads.push_back(ROAD[i].id);
		}
		if (ROAD[i].allCarNum > 2.5 * ave_allCarNum) {
			busyRoads.push_back(ROAD[i].id);
		}
		else {
			//cout << "��·id�� " << ROAD[i].id << "������: " << ROAD[i].allCarNum << endl;
			//cout << "��·id�� " << ROAD[i].id << "��·Ȩ��Ϊ: " << ROAD[i].allCarNum << endl;
		}
	}
}

vector<int> Dispatch::setFlagDeadCar(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<vector<int>> &CarDeadRoadId) {
	vector<int> carIDs;
	vector<int> canBeChangedDeadCarIDs;
	//canBeChangedDeadCarIDs.clear();
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		//cout << ", cross num is " << num;
		int roadIDS[4] = { CROSS[num].road1,CROSS[num].road2, CROSS[num].road3, CROSS[num].road4 };
		sort(roadIDS, roadIDS + 4); //��С��������

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		int dir[4];
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
				continue;
			if (ROAD[roadIDS[q] - road0].to == num + cross0)
				dir[q] = 0;
			else
				dir[q] = 1;
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��һ���ȼ��ĳ�...
				carIDs.clear();
				carIDs = getCar3(roadIDS[q], dir[q], ROAD, CAR, 15);
				if (carIDs.size() == 0)
					break;
				for (int i = 0; i < (int)carIDs.size(); i++) {

					if (CAR[carIDs[i] - car0].preset == 1) {
						continue;
					}
					if (CAR[carIDs[i] - car0].nextCrossDistance < CAR[carIDs[i] - car0].maxSpeed) {//��ǰʱ��Ҫ��·�ڵĳ�����Ҫ�޸ģ����̫�࣬��bug
						continue;
					}
					if (CAR[carIDs[i] - car0].passRoadNumber == (int)(CAR[carIDs[i] - car0].route.size()) - 1) {//Ŀǰ����·�Ǹó������һ��·��Ҳ��Ҫ��������
						continue;
					}
					else if (CAR[carIDs[i] - car0].passRoadNumber ==(int)(CAR[carIDs[i] - car0].route.size()) - 2) {//�ó�����һ��·��Ҫ���յ㣬Ҳ��Ҫ��������
						continue;
					}
					else if (CAR[carIDs[i] - car0].passRoadNumber == (int)(CAR[carIDs[i] - car0].route.size()) - 3) {//�ó�������һ��·��Ҫ���յ㣬Ҳ��Ҫ��������
						continue;
					}
					//CAR[carIDs[i] - car0].usedToBeDeadCar = true;//����ȥ�����������־�ģ����ﲻ��Ҫ
					CAR[carIDs[i] - car0].changeDeadFlag = true;//ע��
					CAR[carIDs[i] - car0].deadInRoadId = CAR[carIDs[i] - car0].location[0];
					CarDeadRoadId[carIDs[i] - car0].push_back(CAR[carIDs[i] - car0].location[0]);
					CAR[carIDs[i] - car0].deadRoadId.push_back(CAR[carIDs[i] - car0].location[0]);
					CAR[carIDs[i] - car0].deadInRoadId_next = CAR[carIDs[i] - car0].nextRoad;
					canBeChangedDeadCarIDs.push_back(carIDs[i] - car0);
				}
				break;
			}
		}
	}
	return canBeChangedDeadCarIDs;
}

//�ӱ���ʱ�̿�ʼ�ģ��Ȳ���Ŀǰ�Ƿ�Ҫ��·��
vector<int> Dispatch::setFlagDeadCar2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<vector<int>> &CarDeadRoadId) {
	vector<int> carIDs;
	vector<int> canBeChangedDeadCarIDs;
	//canBeChangedDeadCarIDs.clear();
	for (int num = 0; num < crossSize; num++)
	{//��·��ID������е��ȸ���·�ڣ�·���ڸ���·����·ID������е��ȵȴ��ĳ���
		//cout << ", cross num is " << num;
		int roadIDS[4] = { CROSS[num].road1,CROSS[num].road2, CROSS[num].road3, CROSS[num].road4 };
		sort(roadIDS, roadIDS + 4); //��С��������

		//��ȡ���Ӵ�·�ڵ��ĸ�����ڷ����·��������
		int dir[4];
		for (int q = 0; q < 4; q++)
		{
			if (roadIDS[q] == -1) //û��·
				continue;
			if (ROAD[roadIDS[q] - road0].to == num + cross0)
				dir[q] = 0;
			else
				dir[q] = 1;
		}

		//���������·�ĵ�һ���ȼ�����
		for (int q = 0; q < 4; q++)
		{
			//��ǰ��·�ϵĳ�δ��������
			while (!isRoadOver(roadIDS[q], dir[q], ROAD, CAR))
			{
				//��ȡ��һ���ȼ��ĳ�...
				carIDs.clear();
				carIDs = getCar3(roadIDS[q], dir[q], ROAD, CAR, 15);
				if (carIDs.size() == 0)
					break;
				for (int i = 0; i < (int)carIDs.size(); i++) {

					if (CAR[carIDs[i] - car0].preset == 1) {
						continue;
					}
					//if (CAR[carIDs[i] - car0].nextCrossDistance < CAR[carIDs[i] - car0].maxSpeed) {//��ǰʱ��Ҫ��·�ڵĳ�����Ҫ�޸ģ����̫�࣬��bug
					//	continue;
					//}
					//if (CAR[carIDs[i] - car0].passRoadNumber == CAR[carIDs[i] - car0].route.size() - 1) {//Ŀǰ����·�Ǹó������һ��·��Ҳ��Ҫ��������
					//	continue;
					//}
					//else if (CAR[carIDs[i] - car0].passRoadNumber == CAR[carIDs[i] - car0].route.size() - 2) {//�ó�����һ��·��Ҫ���յ㣬Ҳ��Ҫ��������
					//	continue;
					//}
					//else if (CAR[carIDs[i] - car0].passRoadNumber == CAR[carIDs[i] - car0].route.size() - 3) {//�ó�������һ��·��Ҫ���յ㣬Ҳ��Ҫ��������
					//	continue;
					//}
					//CAR[carIDs[i] - car0].usedToBeDeadCar = true;//����ȥ�����������־�ģ����ﲻ��Ҫ
					CAR[carIDs[i] - car0].changeDeadFlag = true;//ע��
					//CAR[carIDs[i] - car0].deadInRoadId = CAR[carIDs[i] - car0].location[0];
					CarDeadRoadId[carIDs[i] - car0].push_back(CAR[carIDs[i] - car0].location[0]);
					//CAR[carIDs[i] - car0].deadRoadId.push_back(CAR[carIDs[i] - car0].location[0]);
					//CAR[carIDs[i] - car0].deadInRoadId_next = CAR[carIDs[i] - car0].nextRoad;
					canBeChangedDeadCarIDs.push_back(carIDs[i] - car0);
				}
				break;
			}
		}
	}
	return canBeChangedDeadCarIDs;
}

void Dispatch::changeDeadCarRoute(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph) {

	if (CAR.preset != 1 && CAR.ATD!=-1 && CAR.nextCrossDistance >= CAR.maxSpeed && CAR.passRoadNumber < (int)(CAR.route.size()) - 2) {//��·�ڡ�Ԥ�ó����������·�ģ�������
		Graph_DG deadCarGraph(OriginalCarGraph);
		deadCarGraph.initRoute_DealLock_back2(CAR, CROSS, ROAD);
		//����Ҫ���ɸĸó�����һ��·�����¼����ĸ�vector
		//����maxSP��reverse
		CAR.maxSP.clear();
		CAR.reverse.clear();
		int roadID = CAR.route[0] - road0;
		if (CAR.from == ROAD[roadID].from) //����
		{
			CAR.addRverse(0);
		}
		if (CAR.from == ROAD[roadID].to) //����
		{
			CAR.addRverse(1);
		}
		for (int i = 0; i < (int)(CAR.route.size()); i++)
		{
			int newRoadID = CAR.route[i] - road0;
			if (i > 0)
			{
				if (CAR.reverse[i - 1] == 0) //��һ��·��from-to���ǳ����н�����
				{
					int lastRoad = CAR.route[i - 1] - road0;
					if (ROAD[lastRoad].to == ROAD[newRoadID].from)
						CAR.addRverse(0);
					else
						CAR.addRverse(1);
				}
				if (CAR.reverse[i - 1] == 1) //��һ��·��to-from���ǳ����н�����
				{
					int lastRoad = CAR.route[i - 1] - road0;
					if (ROAD[lastRoad].from == ROAD[newRoadID].from)
						CAR.addRverse(0);
					else
						CAR.addRverse(1);
				}
			}

			if (CAR.speed < ROAD[CAR.route[i] - road0].speed)
				CAR.addMaxSpeed(CAR.speed);
			else
				CAR.addMaxSpeed(ROAD[CAR.route[i] - road0].speed);
		}
	}
}

void Dispatch::changeDeadCarRoute2(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph, vector<int> &CarDeadRoadId) {

	if (CAR.preset != 1 && CAR.ATD != -1 && CAR.nextCrossDistance >= CAR.maxSpeed && CAR.passRoadNumber < (int)(CAR.route.size()) - 2) {//��·�ڡ�Ԥ�ó����������·�ģ�������
		Graph_DG deadCarGraph(OriginalCarGraph);
		deadCarGraph.initRoute_DealLock_back3(CAR, CROSS, ROAD, CarDeadRoadId);
		//����Ҫ���ɸĸó�����һ��·�����¼����ĸ�vector
		//����maxSP��reverse
		CAR.maxSP.clear();
		CAR.reverse.clear();
		int roadID = CAR.route[0] - road0;
		if (CAR.from == ROAD[roadID].from) //����
		{
			CAR.addRverse(0);
		}
		if (CAR.from == ROAD[roadID].to) //����
		{
			CAR.addRverse(1);
		}
		for (int i = 0; i < (int)(CAR.route.size()); i++)
		{
			int newRoadID = CAR.route[i] - road0;
			if (i > 0)
			{
				if (CAR.reverse[i - 1] == 0) //��һ��·��from-to���ǳ����н�����
				{
					int lastRoad = CAR.route[i - 1] - road0;
					if (ROAD[lastRoad].to == ROAD[newRoadID].from)
						CAR.addRverse(0);
					else
						CAR.addRverse(1);
				}
				if (CAR.reverse[i - 1] == 1) //��һ��·��to-from���ǳ����н�����
				{
					int lastRoad = CAR.route[i - 1] - road0;
					if (ROAD[lastRoad].from == ROAD[newRoadID].from)
						CAR.addRverse(0);
					else
						CAR.addRverse(1);
				}
			}

			if (CAR.speed < ROAD[CAR.route[i] - road0].speed)
				CAR.addMaxSpeed(CAR.speed);
			else
				CAR.addMaxSpeed(ROAD[CAR.route[i] - road0].speed);
		}
	}
}


void Dispatch::printOUT(vector<Car> &CAR)
{
	int i, j;
	cout << "The routes are:" << endl;
	for (i = 0; i < (int)(CAR.size()); i++)
	{
		cout << "(" << CAR[i].id << ", " << CAR[i].ATD << ", ";
		for (j = 0; j < (int)(CAR[i].route.size())-1; j++)
		{
			cout << CAR[i].route[j] << ", ";
		}
		cout << CAR[i].route[j] << ")" << endl;
	}
}
