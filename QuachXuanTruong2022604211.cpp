//chen 1 sinh vien truoc sinh vien co ma 123
// sap xep sinh vien theo diem trung binh
#include<iostream>
#include <iomanip>
using namespace std;
struct sinhvien{
	string id;
	string hoten;
	double diemtb;
};
struct Node{
	sinhvien infor;
	Node *next = NULL;
};
typedef Node *tro;
//khoi tao danh sach rong
void create(tro &L){
	L = NULL;
}
void nhapsv(sinhvien &x){
	cout << "Nhap ID: ";
	cin >> x.id;
	fflush(stdin);
	cout << "Nhap ho ten : ";
	getline(cin, x.hoten);
	cout << "Nhap diem tb: ";
	cin >> x.diemtb;
}
void input(tro &L){
	tro P, Q;
	int d = 0;
	sinhvien x;
	int result;
	L = NULL;
	do{
		nhapsv(x);
		P = new Node;
		P->infor = x;
		P->next = NULL;
		if(L == NULL) L = P;
		else{
			Q->next = P;
		}
		Q = P;
		d++;
		cout << "Nhap 0 neu ban muon dung lai ";
		cin >> result;
	}
	while (result !=  0);
}
void hienthi(tro &L){
	cout << "***********Danh sach sinh vien ************\n";
	cout << setw(6) << "ID";
	cout << setw(15) << "Ho va ten";
	cout << setw(12) << "Diem TB\n";
	if(L == NULL){
		cout << "Danh sach rong";
	}
	tro Q = L;
	while(Q != NULL){
		sinhvien x = Q->infor;
		cout << setw(6) << x.id;
		cout << setw(15) << x.hoten;
		cout << setw(12) << x.diemtb << endl;
		Q = Q->next;
	}
}
void sapxep(tro &L){
	if (L == NULL){
		cout << "Danh sach rong";
	}
	else{
		tro Q = L;
		sinhvien x;
		while ( Q != NULL){
			tro P  = Q->next;
			while(P != NULL){
				if(Q->infor.diemtb > P->infor.diemtb){
					x = Q->infor;
					Q->infor = P->infor;
					P->infor = x;
				}
				P = P->next;
			}
			Q = Q->next;
		}
	}
}// chen 1 sinh vien vao truoc sinh vien co ma 123
tro timvt(tro &L){
	// tra ve con tro tai vi tri ma = 123
	tro P, Q;
	P = L;
	if(L == NULL){
		cout << "Danh sach rong";
		return 0;
	}
	else{
		while(P != NULL){
			Q = P->next;
			if(Q->infor.id == "123"){
				return Q;
			}
			P = P->next;
		}
	}	
}
void chends(tro &L){
	sinhvien x;
	cout << "Nhap thong tin sinh vien ban muon chen: \n";
	nhapsv(x);
	tro P = timvt(L);
	tro Q = new Node;
	Q->infor = x;
	Q->next = P->next;
	P->next = Q;
}
// dem so luong sinh vien co diem la max
tro timkiem(tro L){
    //tim kiem con tro tro toi diem max
    tro P;
    tro Q = L;
    if(L == NULL) cout << "Danh sach rong";
    else{
        P = Q;
        while (Q!= NULL){
            if(Q->infor.diemtb > P->infor.diemtb){
                P = Q;
            } 
            Q = Q->next;
        }
    }
    return P;
}

// dem so luong
void demsl(tro L){
	tro Q = L;
	int d = 0;
	while(Q != NULL){
		if(Q->infor.diemtb == timkiem(L)->infor.diemtb){
			d++;
		}
		Q = Q->next;
	}
	cout << "So luong sinh vien co diem = max la: " << d;
}
int main(){
	sinhvien x;
	tro L;
	input(L);
	hienthi(L);
//	sapxep(L);
//	cout << "Sap xep sinh vien theo diem tb tang dan la: \n";
//	hienthi(L);
//	cout << "Chen vao sau sinh vien co ma 123\n";
//	chends(L);
//	hienthi(L);
	cout << "*********";
	demsl(timkiem(L));
	return 0;
}