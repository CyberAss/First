#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

void input(float **&A, int &cnt, int &Realn){
	char c = ' ';
	fstream f;
	int icolumns = 0, ilines = 0;
	f.open("input.txt", ios::in);
	if(!f.is_open()) cout << "Файл не найден";
	else{
		f >> cnt;
		Realn = cnt;
		if(cnt > 0){
			A = new float*[cnt];
			for (int i=0; i < cnt; i++)
				A[i] = new float[2];
			while(!f.eof() && ilines < cnt){
				while((c < '0' || c > '9') && c != '+' && c != '-' && c != '\n' && !f.eof()){
					f >> c >> noskipws;
				}
				if(c != '\n'){
					if(icolumns < 2){
						f.unget();
						f >> A[ilines][icolumns];
						icolumns++;
					}
					c = ' ';
				}
				else{
					if(ilines < cnt && icolumns > 1) ilines++;
					icolumns = 0;
					c = ' ';
				}
			}
			if(ilines + 1 < cnt) cnt = ilines + 1;
		}
	}
	f.close();
}

void control(float **A, int cnt){
	fstream f;
	f.open("output.txt", ios::out);
	f << "Контрольный вывод:\n" << cnt << endl;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < 2; j++) f << A[i][j] << " ";
		f << endl;
	}
	f.close();		
}
void find(float **A, float**&RectMas, int cnt){
	for(int i = 0; i < cnt; i++){
		for(int j = i + 1; j < cnt; j++){
			for(int k = j + 1; k < cnt; k++){
				for(int l = k + 1; l < cnt; l++){
					//Првоерка 4 точек на составление прямоугольника
				}
			}
		}
	}
}

int main(){
	setlocale(LC_ALL, "rus");
	int cnt = 0, Realn = 0;
	float **A;
	float **RectMas;
	RectMas = (float**) realloc(RectMas, 2);
	A = NULL;
	RectMas = NULL;
	input(A, cnt, Realn);
	cout << A[0][1] << endl << cnt;
	control(A, cnt);
	for(int i = 0; i < Realn; i++) delete A[i];
	delete []A;
		return 0;
}