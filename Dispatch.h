#pragma once
#ifndef __DISPATCH_H__
#define __DISPATCH_H__

#include <vector>
#include <set>
#include <map>
#include "Car.h"
#include "Road.h"
#include "Cross.h"
#include "presetAnswer.h"
#include "Floyd.h"
#include "Backup_data.h"
using namespace std;

class Dispatch
{
public:
	int RANUM;
	int car0, carSize;
	int road0, roadSize;
	int cross0, crossSize;
	bool isDeadlock=false;
	int EmptyCarportNumber = 0;
	vector<int> oldPT;
	int roadCarNumber = 0;

	int T = 0;		//ϵͳ����ʱ��
	int Tsum = 0;	//ϵͳ�ܵ���ʱ��
	int Tpri = 0;	//���ȳ�������ʱ��
	int Tsumpri = 0; //���ȳ����ܵ���ʱ��
	int TE = 0;		//���յ���ʱ��
	int TEsum = 0;  //�����ܵ���ʱ��

	//����·��ӵ��·������ʷ����ʶ������ģ������������������Ĵ���ʽ
	vector<int> freeRoads;
	vector<int> busyRoads;

	//������&���ع�
	int lastLockTime = 0;
	vector<Backup_data> BackupData;
	//bool mainBackup(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime);
	//bool mainRollback(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, const Graph_DG &OriginalCarGraph);
	vector<int> setFlagDeadCar(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<vector<int>> &CarDeadRoadId);
	vector<int> setFlagDeadCar2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<vector<int>> &CarDeadRoadId);
	void changeDeadCarRoute(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph);
	void changeDeadCarRoute2(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph, vector<int> &CarDeadRoadId);
	//����&�ع�1
	//int backup_GlobalTime = 0;
	//int backup_roadCarNumber = 0;
	//int backup_EmptyCarportNumber = 0;
	//void Backup(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime);
	//void Rollback(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, const Graph_DG &OriginalCarGraph);
	void givePT(vector<Car> &CAR);
	void recoveryPT(vector<Car> &CAR);
	//����&�ع�2
	//int backup_GlobalTime2 = 0;
	//int backup_roadCarNumber2 = 0;
	//int backup_EmptyCarportNumber2 = 0;
	//void Backup2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime);
	//void Rollback2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, const Graph_DG &OriginalCarGraph);

	//������
	void dispathINIT(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT);  //T0ʱ�̵���
	void setState(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime);
	int dispathMAIN(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bsetTime);
	bool isAllEnd(vector<Car> &CAR);
	bool isAllTerminate(vector<Car> &CAR);
	void printOUT(vector<Car> &CAR);
	bool isRoadOver(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR);
	bool isConflict(int nowOrder, int carID, vector<int> &roadAll, vector<int> &dir, vector<Road> &ROAD, vector<Car> &CAR);	
	void resetRoadCarNumber();
	void addRoadCarNumber();
	void subRoadCarNumber();	
	bool subEndCarPT(vector<Car> &CAR, int count);
	int gainWaitNum(vector<Car> &CAR);
	bool clearSF(vector<Car> &tempCar);

	//��������
	bool moveToNextRoad(int roadNum, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime);
	bool moveOnTheRoad(int num, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime);
	bool moveCarportPriorityCar(int num, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime);
	bool moveCarport(int num, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime); //·�ϳ����Ƚ�������ʼ���ȳ����ڵȴ��ĳ�
	bool moveCarportCarPriorityToRoad(int roadId, int dir, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime);
	bool moveCarport2(int crossNum, vector<Car> &CAR, vector<Road> &ROAD, vector<Cross> &CROSS, int &GlobalTime);

	//����
	void Batch1(vector<Car> &CAR, int batchNum,int t);
	void Batch2(vector<Car> &CAR, int batchNum, int t);
	vector<int> bathSort(vector<Car> &CAR, vector<int> &bath);
	vector<int> bathSort2(vector<Car> &CAR, vector<int> &bath);

	//����
	bool controlInitCar(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime);
	bool modifyPlantime(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime);

	//�����·ӵ����
	void setRoadCarNUm(int Num);
	void computeRoadCrowding(vector<Road> &ROAD);

	//����ʱ��
	int priorityCarSize=0;
	vector<int> allCarSpeed, priorityCarSpeed;
	vector<int> allCarPlanTime, allCarEndTime, priorityCarPlanTime, priorityCarEndTime;
	set<int> allCarFrom, priorityCarFrom;
	set<int> allCarTo, priorityCarTo;
	double a1, a2, a3, a4, a5;
	void clearData();
	void computeData(vector<Car> &CAR);
	int computeT();		//�������ʱ��
	int computeTpri();	//�������ȳ�������ʱ��
	int computeTE(vector<Car> &CAR);	//�������յ���ʱ��
	int computeTEsum(vector<Car> &CAR);	//���������ܵ���ʱ��

	//��������
	int searchBestBatchNum(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int batchNum,int t, int limitNum);
	int searchBestLimitNum(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int batchNum, int limitNum);
	int mainLoop1(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bsetTime);
	int mainLoop2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bsetTime);
	//int searchBestTime1(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);
	int searchBestTime2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);
	//int computeRoadCarNUm(vector<Road> &ROAD);


	//����������
	void dealDeadLock(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph, vector<int> &freeRoads, vector<int> &busyRoads, vector<int> &CROSSID);
	void dealDeadLock_back(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph, vector<int> &freeRoads, vector<int> &busyRoads, vector<int> &CROSSID);
	int dispathMAIN_withDeal(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bsetTime, const Graph_DG &OriginalCarGraph, vector<int> &CROSSID);
	int dispathMAIN_withDeal2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bestTime, const Graph_DG &OriginalCarGraph, vector<int> &CROSSID);
	int dispathMAIN_withDeal3(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &GlobalTime, int TT, int bestTime, const Graph_DG &OriginalCarGraph, vector<int> &CROSSID);
	bool delayCarPT(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &nowTime,vector<int> &deadCar);
	bool delayCarPT2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, int &nowTime, vector<int> &deadCar);
	//void setDeadLockCarRoute(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<vector<int>> &CarDeadRoadId, const Graph_DG &OriginalCarGraph);
	int getCar(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR);						//��ȡ��·�ϵ�һ���ȼ��ĳ�
	vector<int> getCar2(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT);  //��ȡ��·�Ϲ��¸�·�ڵĳ�
	vector<int> getCar3(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT);  //��ȡ��·�ϵȴ��ĳ�
	vector<int> getCar4(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT); //��ȡ�ȴ��Ҳ�����һ·�ڵ�
	vector<int> getCar5(int roadID, int dir, vector<Road> &ROAD, vector<Car> &CAR, int COUNT);  //��ȡ��·�ϵ����г�
	vector<int> getDeadCarFirstAll(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);  //��ȡ��������·�ϵ�һ���ȼ��ĳ�
	vector<int> getDeadCarID(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);		//��ȡ��������ID
	void deadLockProcess1(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);		//�ѵȴ�������ԭ�ش�ɢ
	void deadLockProcess2(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);		//�ѵȴ�������ȫ�����������
	void deadLockProcess3(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);		//�ѵȴ�����·�ڵĳ�ԭ�ش�ɢ���ѹ�·�ڵĳ�ȫ�����������
	void setLimitNum(int limitNum);
	void computeRANUM(int nowTime, Car &FirstCar);
	void getFreeBusyRoads(vector<Road> &ROAD);

	//�滮
	void dynamicPlanSet(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, const Graph_DG &OriginalCarGraph);

};

#endif 


