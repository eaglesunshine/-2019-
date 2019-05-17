#pragma once
#ifndef __CAR_H__
#define __CAR_H__

#include <vector>
#include "Road.h"
#include "Cross.h"
using namespace std;

class Car
{
public:
	int id;					//����id
	int idReal;				//��id
	int from;				//ʼ����
	int to;					//Ŀ�ĵ�
	int speed;				//����ٶ�
	int planTime;			//����ʱ��
	int priority;			//�Ƿ�����
	int preset;				//�Ƿ�Ԥ��

	int PT;                 //���޸ĵĳ���ʱ��
	int ATD = -1;			//ʵ�ʳ���ʱ��
	int EndTime;			//�Ѿ���ʻ��ʱ��
	int nowSpeed;			//��ǰ�ٶ�
	int maxSpeed;           //����ʹ����ٶ�
	int location[3];		//��ǰλ�ã���������·�������������ĸ�λ����
	int nextRoad;			//��һ����·id
	int nextCross=-1;			//��һ��·��
	int nextRoadSpeed;		//��һ����·���ٶ�
	int nextCrossDirection;	//��һ��·��ת��
	int nextCrossDistance;	//��ǰλ������һ��·�ڵľ���
	int state = -1;			//������ʻ״̬��0Ϊ�ȴ���ʻ������1Ϊ��ֹ״̬��-1�ǻ��ڳ���
	int blockDistance;		//��ǰ���赲���ľ���
	int isReverse = 0;		//�Ƿ�λ�ڵ�·��to-from����
	int toNextRoad = 0;		//�Ƿ������ʻ������һ��·��
	int isTerminate = 0;    //�Ƿ񵽴��յ�
	int nextReverse;
	int passRoadNumber = 0;
	//int dieCount[150] = { 0 };	//��һ��ʱ����ÿ��·�ϵĳ�ͻ+����ʧ�ܼ���
	int isReset = 0;
	int LastRoad = -1;
	bool usedToBeDeadCar = false;
	bool changeDeadFlag = false;//�����ع���־λ�������ĳ����޸���·�����ع�ʱ���޸���·����
	int deadInRoadId = -1;
	int deadInRoadId_next = -1;
	vector<int> deadRoadId;

	vector<int> maxSP;
	vector<int> reverse;    //�ڶ�Ӧ��·�ϵ���/����
	vector<int> direction;	//����·��ʱ��Ӧ��·�ķ���(ֱ0����1����2)���б�ʾ·�ڣ��б�ʾ��·��ֵΪת��
	vector<int> route;		//�г�·������·1����·2��...����·N

	////����
	//int backup_PT;                 //���޸ĵĳ���ʱ��
	//int backup_ATD = -1;			//ʵ�ʳ���ʱ��
	//int backup_EndTime;			//�Ѿ���ʻ��ʱ��
	//int backup_nowSpeed;			//��ǰ�ٶ�
	//int backup_maxSpeed;           //����ʹ����ٶ�
	//int backup_location[3];		//��ǰλ�ã���������·�������������ĸ�λ����
	//int backup_nextRoad;			//��һ����·id
	//int backup_nextCross = -1;			//��һ��·��
	//int backup_nextRoadSpeed;		//��һ����·���ٶ�
	//int backup_nextCrossDirection;	//��һ��·��ת��
	//int backup_nextCrossDistance;	//��ǰλ������һ��·�ڵľ���
	//int backup_state = -1;			//������ʻ״̬��0Ϊ�ȴ���ʻ������1Ϊ��ֹ״̬��-1�ǻ��ڳ���
	//int backup_blockDistance;		//��ǰ���赲���ľ���
	//int backup_isReverse = 0;		//�Ƿ�λ�ڵ�·��to-from����
	//int backup_toNextRoad = 0;		//�Ƿ������ʻ������һ��·��
	//int backup_isTerminate = 0;    //�Ƿ񵽴��յ�
	//int backup_nextReverse;
	//int backup_passRoadNumber = 0;
	//int backup_isReset = 0;
	//int backup_LastRoad = -1;
	//bool backup_usedToBeDeadCar = false;
	//vector<int> backup_maxSP;
	//vector<int> backup_reverse;    //�ڶ�Ӧ��·�ϵ���/����
	//vector<int> backup_direction;	//����·��ʱ��Ӧ��·�ķ���(ֱ0����1����2)���б�ʾ·�ڣ��б�ʾ��·��ֵΪת��
	//vector<int> backup_route;		//�г�·������·1����·2��...����·N

	////����
	//int backup_PT2;                 //���޸ĵĳ���ʱ��
	//int backup_ATD2 = -1;			//ʵ�ʳ���ʱ��
	//int backup_EndTime2;			//�Ѿ���ʻ��ʱ��
	//int backup_nowSpeed2;			//��ǰ�ٶ�
	//int backup_maxSpeed2;           //����ʹ����ٶ�
	//int backup_location2[3];		//��ǰλ�ã���������·�������������ĸ�λ����
	//int backup_nextRoad2;			//��һ����·id
	//int backup_nextCross2 = -1;			//��һ��·��
	//int backup_nextRoadSpeed2;		//��һ����·���ٶ�
	//int backup_nextCrossDirection2;	//��һ��·��ת��
	//int backup_nextCrossDistance2;	//��ǰλ������һ��·�ڵľ���
	//int backup_state2 = -1;			//������ʻ״̬��0Ϊ�ȴ���ʻ������1Ϊ��ֹ״̬��-1�ǻ��ڳ���
	//int backup_blockDistance2;		//��ǰ���赲���ľ���
	//int backup_isReverse2 = 0;		//�Ƿ�λ�ڵ�·��to-from����
	//int backup_toNextRoad2 = 0;		//�Ƿ������ʻ������һ��·��
	//int backup_isTerminate2 = 0;    //�Ƿ񵽴��յ�
	//int backup_nextReverse2;
	//int backup_passRoadNumber2 = 0;
	//int backup_isReset2 = 0;
	//int backup_LastRoad2 = -1;
	//bool backup_usedToBeDeadCar2 = false;
	//vector<int> backup_maxSP2;
	//vector<int> backup_reverse2;    //�ڶ�Ӧ��·�ϵ���/����
	//vector<int> backup_direction2;	//����·��ʱ��Ӧ��·�ķ���(ֱ0����1����2)���б�ʾ·�ڣ��б�ʾ��·��ֵΪת��
	//vector<int> backup_route2;		//�г�·������·1����·2��...����·N



	bool init(vector<int> carData);	//������Ϣ��ʼ��
	vector<int> setRoute(vector<int> routeData);	//������ʻ·��
	void setEndTime(int Time);	//���ó�������ʻ��ʱ��
	void setNowSpeed(int speed);	//���õ�ǰ�ٶ�

	void updateRoute(int num, int roadId);	//���ĵ�num����·��Ϣ
	void updateLocation(int road, int channel, int position);
	void setATD(int time);
	void setState(int STD);
	void setBlockDistance(int distance);
	bool computeNEXT(vector<Road> &ROAD, vector<Cross> &CROSS);//����nextRoad,nextRoadSpeed,nextCrossDirection,nextCrossDistance
	void setReverse(int Is);
	void setToNextRoad(int Is);
	void setIsTerminate(int Is);
	void addRverse(int ISR);
	void addMaxSpeed(int SP);
	void isRVER(int ISR);
	void addDieCount(int roadID);
	void addPlanTime();
	void addPlanTime1();
	void addPT(int T);
	void subPT(int T);
	void setPT(int T);
	void renew();
	void dieToZero();
	void setReset(int IS);
	void maxSPClear();
	void reverseClear();
};

#endif 
