#include "Train.hpp"
#include <algorithm>
#define cnt 8		//���������� �������

using namespace std;

int sort(const void* a, const void* b){
	return 	((Train*)a)->Number() > ((Train*)b)->Number();
}

Train* search(Train *trains, const string& a){
	
			int i = 0;
			for(; i < cnt; ++i){
				if(trains[i].Station() == a){
					return trains + i;
				}
			}
			return nullptr;
}

void read(Train *trains){
	cout << "����� ������� �����\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> trains[i];
				}	  //������������ ����������
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//���������� i ����� ��� ���������� �����
				}
			}
}

int main(){
	setlocale(LC_ALL, "");
	Train trains[cnt];
	int a;
	//����
	while(true){
		cout << "\n1. �����\n2. ������� ������\n3. ������� ����������\n";
		if(!(cin >> a)){//���� ������������ ����, �� ���������� ��
		 continue;
		}
		if(a == 1){
			return 0;
		}
		else if(a == 2){
			//��������� ������ � �������
			 read(trains);
			/*��������� ��������� �� �������*/
			qsort(trains,cnt, sizeof(Train), sort);
			
		}
		else if(a == 3){
			string a;
			cout << "�����: ";
			if(!(cin >> a)){
				cout << "Error";
				continue;
			}
			Train *tmp = search(trains, a);
			if(tmp != nullptr){
				cout << *tmp;
			}
			else{
				cout << "�� �������";
			}
		}
	}

}
