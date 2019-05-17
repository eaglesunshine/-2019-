/************************************************************/
/*                �������ߣ�Willam                          */
/*                �������ʱ�䣺2017/3/11                   */
/*                ���κ���������ϵ��2930526477@qq.com       */
/************************************************************/
//@����д�������ĳ���

#pragma once
//#pragma once��һ���Ƚϳ��õ�C/C++��ע��
//ֻҪ��ͷ�ļ����ʼ����������ע��
//���ܹ���֤ͷ�ļ�ֻ������һ�Ρ�

/*
�����Ϳ�ʼ��Floyd�㷨��ʹ���ڽӾ���ʵ�ֵ�
*/

#include<iostream>
#include<string>
#include "Road.h"
#include "Car.h"
#include "Cross.h"
using namespace std;

class Graph_DG {
private:
	int vexnum;   //ͼ�Ķ������
	int edge;     //ͼ�ı���
	int **arc;   //�ڽӾ���
	int ** dis;   //��¼�����������·������Ϣ
	int ** path;  //��¼�������·������Ϣ
	int ** map;   //��¼ԭʼ��ͼ����ÿ����·��֮��������·
public:
	//���캯��
	Graph_DG(int vexnum, vector<Road>& ROAD);
	Graph_DG(const Graph_DG &DeadCarGraph);
	//��������
	~Graph_DG();
	// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
	//�����1��ʼ���
	//bool check_edge_value(int start, int end, int weight);
	//����ͼ
	void createGraph(int, vector<Road>& ROAD, int num_road);
	//��ӡ�ڽӾ���
	void print();
	//�����·��
	void Floyd();
	//��ӡ���·��
	void print_path();
	//��·��
	void set_path(vector<Car>& CAR, vector<Cross>& CROSS, vector<Road> &ROAD, int num_car);
	void set_path_DealLock(Car &CAR, vector<Cross>& CROSS);
	void set_path_Dynamic(vector<Car>& CAR, vector<Cross>& CROSS, vector<Road> &ROAD);
	void set_out_road(vector<Car>& CAR, vector<Cross>& CROSS);
	void set_out_road_DealLock(Car &CAR, vector<Cross>& CROSS);
	void set_path_DealLock_back(Car &CAR, vector<Cross>& CROSS, vector<Road> &ROAD);
	int findDirection(Cross &CROSS, int now_road_id, int next_road_id);

	void initRoute(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);
	void initRoute_DealLock(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<int> &freeRoads, vector<int> &busyRoads,vector<int> &CROSSID);
	void initRoute_DealLock_back(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<int> &freeRoads, vector<int> &busyRoads, vector<int> &CROSSID);
	void initRoute_DealLock_back2(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);
	void initRoute_DealLock_back3(Car &CAR, vector<Cross> &CROSS, vector<Road> &ROAD, vector<int> &CarDeadRoadId);
	void initRoute_Dynamic(vector<Car> &CAR, vector<Cross> &CROSS, vector<Road> &ROAD);
	vector<int> getLinkCross(Cross &CROSS, vector<Road> &ROAD);
};
