#pragma once
#ifndef __ROAD_H__
#define __ROAD_H__

#include <vector>
using namespace std;

class Road
{
public:
	int id;				//��·id
	int idReal;			//��id
	int length;			//��·����
	int speed;			//�������
	int channel;		//������Ŀ
	int from;			//��ʼ·��id
	int to;				//�յ�·��id
	int isDuplex;		//�Ƿ�˫��1��˫��0������
	vector<vector<vector<int>>> WaitCar; //�ĸ������ĸ�ת�����ĵڼ�������id	

	int roadCar[2][10][100];//from-to����/to-from�ϵĳ���λ�ã����ĸ��������ĸ�λ��
	
	//��·ӵ�����
	int nowCarNum=0;		//��ǰʱ��·�ϵĳ�����Ŀ
	int allCarNum = 0;		//�ӿ�ʼ����ǰʱ�̵ĳ�����Ŀ
	int nowNum[2] = {0};		//��ǰʱ��·����/����ĳ�����Ŀ
	int allNum[2] = {0};		//�ӿ�ʼ����ǰʱ����/����ĳ�����Ŀ
	float crowding[2] = {0};		//��ǰʱ�̵�·����/�����ӵ����

	////����
	//int backup_roadCar[2][10][100];//from-to����/to-from�ϵĳ���λ�ã����ĸ��������ĸ�λ��
	//int backup_nowCarNum = 0;		//��ǰʱ��·�ϵĳ�����Ŀ
	//int backup_allCarNum = 0;		//�ӿ�ʼ����ǰʱ�̵ĳ�����Ŀ
	//int backup_nowNum[2] = { 0 };		//��ǰʱ��·����/����ĳ�����Ŀ
	//int backup_allNum[2] = { 0 };		//�ӿ�ʼ����ǰʱ����/����ĳ�����Ŀ
	//float backup_crowding[2] = { 0 };		//��ǰʱ�̵�·����/�����ӵ����

	////����
	//int backup_roadCar2[2][10][100];//from-to����/to-from�ϵĳ���λ�ã����ĸ��������ĸ�λ��
	//int backup_nowCarNum2 = 0;		//��ǰʱ��·�ϵĳ�����Ŀ
	//int backup_allCarNum2 = 0;		//�ӿ�ʼ����ǰʱ�̵ĳ�����Ŀ
	//int backup_nowNum2[2] = { 0 };		//��ǰʱ��·����/����ĳ�����Ŀ
	//int backup_allNum2[2] = { 0 };		//�ӿ�ʼ����ǰʱ����/����ĳ�����Ŀ
	//float backup_crowding2[2] = { 0 };		//��ǰʱ�̵�·����/�����ӵ����

	bool init(vector<int> roadData);			//��·��Ϣ��ʼ��
	void addWaitCar(int way, int direction, int carId);
	void subWaitCar(int way, int direction, vector<int> carCut);
	void clearWaitCar(int way);

	void addRoadCar(int direction, int lane, int position, int carId);
	void subRoadCar(int direction, int lane, int carId);
	void renew();
	int getNowCarNum();    //��ȡ��ǰ·�ϳ�����
};

#endif 