#pragma once
#ifndef __CROSS_H__
#define __CROSS_H__

#include <vector>
using namespace std;

class Cross
{
public:
	int id;				//·��id
	int idReal;			//��id
	int road1;			//��·id��-1��ʾû��·
	int road2;			//��·id
	int road3;			//��·id
	int road4;			//��·id
	vector<int> StartCar;

	////����
	//vector<int> backup_StartCar;

	////����
	//vector<int> backup_StartCar2;

	bool init(vector<int> crossData);	//��·��Ϣ��ʼ��
	void addStartCar(int carId);
	void subStartCar(vector<int> carCut);
	void renew();
};

#endif 