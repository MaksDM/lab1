#include "Train.hpp"
#include <algorithm>
#define cnt 8		//количество поездов

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
	cout << "Номер станция время\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> trains[i];
				}	  //обрабатываем исключение
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//откатываем i назад для повторного ввода
				}
			}
}

int main(){
	setlocale(LC_ALL, "");
	Train trains[cnt];
	int a;
	//меню
	while(true){
		cout << "\n1. Выход\n2. Считать поезда\n3. Вывести информацию\n";
		if(!(cin >> a)){//если некорректный ввод, то пропускаем всё
		 continue;
		}
		if(a == 1){
			return 0;
		}
		else if(a == 2){
			//считываем данные о поездах
			 read(trains);
			/*сортируем пузырьком по номерам*/
			qsort(trains,cnt, sizeof(Train), sort);
			
		}
		else if(a == 3){
			string a;
			cout << "Пункт: ";
			if(!(cin >> a)){
				cout << "Error";
				continue;
			}
			Train *tmp = search(trains, a);
			if(tmp != nullptr){
				cout << *tmp;
			}
			else{
				cout << "Не найдено";
			}
		}
	}

}
