#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*
Naufal Fawwazi
A11.2020.12764
A11.43UG
*/

struct Node {
	char nama[30];
	Node *next, *prev;
};

Node *head=NULL, *tail=NULL;

bool isExist(char cari[30]) {
	Node *bantu = head;
	bool found = false;
	while(bantu!=NULL) {
		if(strcmp(bantu->nama,cari)==0)
			found = true;
		bantu = bantu->next;
	} return found;
}

void cariData() {
	char nama[30];
	cout<<"Cari siapa : "; cin>>nama;
	if(isExist(nama))
		cout<<nama<<" ada di list.\n";
	else
		cout<<nama<<" tidak ada di list!\n";
}

void tambahDepan() {
	char namaorg[30];
	cout<<"Nama : "; cin>>namaorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);

	baru->prev = NULL;
	baru->next = head;
	if(head==NULL)
		tail = baru;
	else
		head->prev = baru;
	head = baru;
	
	cout<<namaorg<<" berhasil masuk list.\n";
}

void tambahBelakang() {
	char namaorg[30];
	cout<<"Nama : "; cin>>namaorg;
	
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	
	baru->prev = tail;
	baru->next = NULL;
	if(head==NULL)
		head = baru;
	else
		tail->next = baru;
	tail = baru;
	
	cout<<namaorg<<" berhasil masuk list.\n";
}

void tambahSetelah(char namaorg[30], char cari[30]) {
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);

	if(isExist(cari)) {
		Node *bantu = head;
		while(bantu!=NULL) {
			if(strcmp(cari,bantu->nama)==0) {
				baru->next = bantu->next;
				baru->prev = bantu;
				if(bantu==tail)
					tail = baru;
				else
					bantu->next->prev = baru;
				bantu->next = baru;
				break;
			}
			bantu = bantu->next;
		} cout<<namaorg<<" berhasil masuk list.\n";
	} else
		cout<<cari<<" tidak ada di list!\n";
}

void tambahSebelum(char namaorg[30], char cari[30]) {
	Node *baru = new Node;
	strcpy(baru->nama, namaorg);
	
	if(isExist(cari)) {
		Node *bantu = head;
		while(bantu!=NULL) {
			if(strcmp(cari,bantu->nama)==0) {
				baru->prev = bantu->prev;
				baru->next = bantu;
				if(bantu==head) 
					head = baru;
				else
					bantu->prev->next = baru;
				bantu->prev = baru;
				break;
			}
			bantu = bantu->next;
		} cout<<namaorg<<" berhasil masuk list.\n";
	} else
		cout<<cari<<" tidak ada di list!\n";
}

void tambahTengah() {
	char namaorg[30];
	cout<<"Nama : "; cin>>namaorg;

	Node *baru = new Node;
	strcpy(baru->nama, namaorg);

	if(head==NULL) {
		baru->prev = NULL;
		baru->next = NULL;
		head = baru;
		tail = baru;
		cout<<namaorg<<" berhasil masuk list.\n";
	}	else {
		char cari[30];
		int pilih;
		cout<<"\nTambahkan "<<namaorg<<" dimana?\n";
		cout<<"1. Setelah suatu data\n";
		cout<<"2. Sebelum suatu data\n";
		cout<<"Pilih : "; cin>>pilih;
		if(pilih==1) {
			cout<<"\nTambahkan setelah siapa : "; cin>>cari;
			tambahSetelah(namaorg, cari);
		} else if(pilih==2) {
			cout<<"\nTambahkan sebelum siapa : "; cin>>cari;
			tambahSebelum(namaorg, cari);
		}
	}
}

void hapusDepan() {
	if(head!=NULL) {
		Node *bantu = head->next;
		if(head==tail)
			tail = NULL;
		else
			bantu->prev = NULL;
		cout<<head->nama<<" dihapus dari list.\n";
		delete head;
		head = bantu;
	} else 
		cout<<"List masih kosong!\n";
}

void hapusBelakang() {
	if(head!=NULL) {
		Node *bantu = tail->prev;
		if(head==tail)
			head = NULL;
		else
			bantu->next = NULL;
		cout<<tail->nama<<" dihapus dari list.\n";
		delete tail;
		tail = bantu;
	} else
		cout<<"List masih kosong!\n";
}

void hapusTengah() {
	if(head!=NULL) {
		if(head==tail) {
			cout<<head->nama<<" dihapus dari list.\n";
			delete head;
			head = NULL;
			tail = NULL;
		} else {
			char cari[30];
			cout<<"Hapus siapa : "; cin>>cari;
			
			if(isExist(cari)) {
				Node *bantu = head;
				while(bantu!=NULL) {
					if(strcmp(bantu->nama,cari)==0) {
						Node *hapus = bantu;
						if(bantu==head) {
							head = head->next;
							head->prev = NULL;
						} else if(bantu==tail) {
							tail = tail->prev;
							tail->next = NULL;	
						}	else {
							bantu->next->prev = bantu->prev;
							bantu->prev->next = bantu->next;
						}
						cout<<bantu->nama<<" dihapus dari list.\n";
						delete hapus;
						break;
					}
					bantu = bantu->next;
				}
			} else
				cout<<cari<<" tidak ada di list!\n";
		}
	} else
		cout<<"List masih kosong!\n";
}

void tampilMaju() {
	if(head!=NULL) {
		Node *bantu = head;
		cout<<"[head.prev] NULL -> ";
		while(bantu!=NULL) {
			cout<<bantu->nama<<" -> ";
			bantu = bantu->next;
		} cout<<"NULL [tail.next]\n";
	} else
		cout<<"List masih kosong!\n";
}

void tampilMundur() {
	if(head!=NULL) {
		Node *bantu = tail;
		cout<<"[tail.next] NULL <- ";
		while(bantu!=NULL) {
			cout<<bantu->nama<<" <- ";
			bantu = bantu->prev;
		} cout<<"NULL [head.prev]\n";
	} else
		cout<<"List masih kosong!\n";
}

int main() {
	int pilih;

	do {
		system("cls");
		cout<<"Operasi - operasi pada Double Linked List :\n";
		cout<<"1. Tambah Depan\n";
		cout<<"2. Tambah Belakang\n";
		cout<<"3. Tambah Tengah\n";
		cout<<"4. Hapus Depan\n";
		cout<<"5. Hapus Belakang\n";
		cout<<"6. Hapus Tengah\n";
		cout<<"7. Tampil Maju\n";
		cout<<"8. Tampil Mundur\n";
		cout<<"9. Cari Data\n";
		cout<<"10. Keluar\n";
		cout<<">>> Pilih operasi : "; cin>>pilih;
		cout<<"\n";

		if(pilih==1) tambahDepan();
		if(pilih==2) tambahBelakang();
		if(pilih==3) tambahTengah();
		if(pilih==4) hapusDepan();
		if(pilih==5) hapusBelakang();
		if(pilih==6) hapusTengah();
		if(pilih==7) tampilMaju();
		if(pilih==8) tampilMundur();
		if(pilih==9) cariData();
		if(pilih<1 or pilih>10) cout<<"Pilihan salah!\n";

		cout<<"\nTekan apapun untuk lanjut..."; getch();
	} while(pilih!=10);
	
	return 0;
}
