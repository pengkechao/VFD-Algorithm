#include <stdio.h>
#include <io.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#include "argraph.h"

#include "vf2_state.h"
#include "argloader.h"
#include "match.h"

#define MAXNODES 3000
#define DEBUG

using namespace std;

unsigned int count1=0;    // 全局变量，记录回归调用的次数
double count2=0;         // 全局变量，记录整个程序判断两点是否匹配所需要的总时间

// 测试判定条件改变后的VF2效果
void testVF2(string fileNameA, string fileNameB, string path, string timefile){
	LARGE_INTEGER start, end, fre;

	int num_edges = 0;
	bool flag;
	
	ifstream fileA(fileNameA);
	ifstream fileB(fileNameB);
	ofstream filetime(timefile);
	cout<<fileNameA<<" "<<fileNameB<<" "<<timefile<<endl;
    if(!(fileA.is_open())&&fileB.is_open()&&filetime.is_open()){
        cerr<<"open error!"<<endl;
		system("pause");
        exit(1);
    }

    int c = 0;
    string A_file, B_file, graphA, graphB;
	node_id *ni1, *ni2;
	ni1 = new node_id[MAXNODES];
	ni2 = new node_id[MAXNODES];

    while(fileA>>graphA&& fileB>>graphB){

		A_file = path+graphA;
		B_file = path+graphB;
		cout<<"----------------"<<path<<": "<<c++<<"th------------"<<endl;
		cout<<A_file<<" "<<B_file<<endl;

        // create two graphs
        ifstream in_A(A_file, ios::in | ios::binary);
        if(!(in_A.is_open())){
            cerr<<"open error!"<<endl;
            exit(1);
        }

        BinaryGraphLoader loader_A(in_A);
        in_A.close();
        Graph g_A(&loader_A);

        ifstream in_B(B_file, ios::in | ios::binary);
        if(!(in_B.is_open())){
            cerr<<"open error!"<<endl;
            exit(1);
        }
        BinaryGraphLoader loader_B(in_B);
        in_B.close();
        Graph g_B(&loader_B);

        int n;
		
		for(int i=0; i<g_A.NodeCount(); i++)
			num_edges += g_A.EdgeCount(i);
		filetime<<g_A.NodeCount()<<" "<<num_edges<<" ";

        count1=0;
		count2=0;
		QueryPerformanceFrequency(&fre);
		QueryPerformanceCounter(&start);
		VF2State s0(&g_A, &g_B);
		flag=match(&s0, &n, ni1, ni2);
		QueryPerformanceCounter(&end);
		//cout<<start<<" "<<end<<endl;
		//cout<<(end-start)<<" "<<count1<<" "<<count2<<endl;
		filetime<<(end.QuadPart-start.QuadPart)*1000/fre.QuadPart<<" "<<count1<<" "<<count2*1000/fre.QuadPart<<" ";
		if(!flag){
			printf("VF2State: No matching found!\n");
			filetime<<1<<endl;
		}
		else{
			printf("VF2State: Found a matching with %d nodes in %dth pair of graphs: \n", n, c);
			filetime<<0<<endl;
		}
	}
    fileA.close();
    fileB.close();
	filetime.close();
	delete [] ni1;
	delete [] ni2;
}


int main(){
	string dataA, dataB, path, time;
	
	dataA = "data/iso/rand/r001A.txt";
	dataB = "data/iso/rand/r001B.txt";
	path = "data/iso/rand/r001/";
	time = "data/iso/output/r001-VF2.txt";
	testVF2(dataA, dataB, path, time);
	dataA = "data/iso/rand/r005A.txt";
	dataB = "data/iso/rand/r005B.txt";
	path = "data/iso/rand/r005/";
	time = "data/iso/output/r005-VF2.txt";
	testVF2(dataA, dataB, path, time);
	dataA = "data/iso/rand/r01A.txt";
	dataB = "data/iso/rand/r01B.txt";
	path = "data/iso/rand/r01/";
	time = "data/iso/output/r01-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m2D/m2DA.txt";
	dataB = "data/iso/m2D/m2DB.txt";
	path = "data/iso/m2D/m2D/";
	time = "data/iso/output/m2D-VF2.txt";
	testVF2(dataA, dataB, path, time);
	
	dataA = "data/iso/m2D/m2Dr2A.txt";
	dataB = "data/iso/m2D/m2Dr2B.txt";
	path = "data/iso/m2D/m2Dr2/";
	time = "data/iso/output/m2Dr2-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m2D/m2Dr4A.txt";
	dataB = "data/iso/m2D/m2Dr4B.txt";
	path = "data/iso/m2D/m2Dr4/";
	time = "data/iso/output/m2Dr4-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m2D/m2Dr6A.txt";
	dataB = "data/iso/m2D/m2Dr6B.txt";
	path = "data/iso/m2D/m2Dr6/";
	time = "data/iso/output/m2Dr6-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m3D/m3DA.txt";
	dataB = "data/iso/m3D/m3DB.txt";
	path = "data/iso/m3D/m3D/";
	time = "data/iso/output/m3D-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m3D/m3Dr2A.txt";
	dataB = "data/iso/m3D/m3Dr2B.txt";
	path = "data/iso/m3D/m3Dr2/";
	time = "data/iso/output/m3Dr2-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m3D/m3Dr4A.txt";
	dataB = "data/iso/m3D/m3Dr4B.txt";
	path = "data/iso/m3D/m3Dr4/";
	time = "data/iso/output/m3Dr4-VF2.txt";
	testVF2(dataA, dataB, path, time);
	
	dataA = "data/iso/m3D/m3Dr6A.txt";
	dataB = "data/iso/m3D/m3Dr6B.txt";
	path = "data/iso/m3D/m3Dr6/";
	time = "data/iso/output/m3Dr6-VF2.txt";
	testVF2(dataA, dataB, path, time);
	
	dataA = "data/iso/m4D/m4DA.txt";
	dataB = "data/iso/m4D/m4DB.txt";
	path = "data/iso/m4D/m4D/";
	time = "data/iso/output/m4D-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m4D/m4Dr2A.txt";
	dataB = "data/iso/m4D/m4Dr2B.txt";
	path = "data/iso/m4D/m4Dr2/";
	time = "data/iso/output/m4Dr2-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m4D/m4Dr4A.txt";
	dataB = "data/iso/m4D/m4Dr4B.txt";
	path = "data/iso/m4D/m4Dr4/";
	time = "data/iso/output/m4Dr4-VF2.txt";
	testVF2(dataA, dataB, path, time);

	dataA = "data/iso/m4D/m4Dr6A.txt";
	dataB = "data/iso/m4D/m4Dr6B.txt";
	path = "data/iso/m4D/m4Dr6/";
	time = "data/iso/output/m4Dr6-VF2.txt";
	testVF2(dataA, dataB, path, time);
	
	
	system("pause");
	return 0;
	
}