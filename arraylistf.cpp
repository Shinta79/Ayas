#include <bits/stdc++.h>
using namespace std;

struct data{
	string nama;
	int id, umur, lanjut; 
	};
	
data binatang[100];

string target;
int listt, kosong, akhirlist, akhirkosong;

int listkosong();

void buat();
void sipdat(string namamasuk, int umurmasuk, int idmasuk);
void hapus(string target);
void tampil();

void buat(){
	listt = 6;
	kosong = 5;
	akhirlist = 9; 
	akhirkosong = 9;
	
	binatang[1].nama = "kudanil";		binatang[1].lanjut = 7;		binatang[1].id = 141;
	binatang[2].nama = "kancil";		binatang[2].lanjut = 3;		binatang[2].id = 0;
	binatang[3].nama = "rusa";			binatang[3].lanjut = 6;		binatang[3].id = 0;
	binatang[4].nama = "panda";			binatang[4].lanjut = 10;	binatang[4].id = 164;
	binatang[5].nama = "beruang";		binatang[5].lanjut = 8;		binatang[5].id = 0;
	binatang[6].nama = "harimau";		binatang[6].lanjut = 1;		binatang[6].id = 112;
	binatang[7].nama = "singa";			binatang[7].lanjut = 4;		binatang[7].id = 190;
	binatang[8].nama = "monyet";		binatang[8].lanjut = 2;		binatang[8].id = 0;
	binatang[9].nama = "paus";			binatang[9].lanjut = 0;		binatang[9].id = 123;
	binatang[10].nama = "penyu";		binatang[10].lanjut = 9;	binatang[10].id = 172;
	}

int listkosong() {
	if(listt == 0)
		return 1;
	else
		return 0;	} 
	
void sipdat(string namamasuk, int umurmasuk, int idmasuk){
	int listbaru, n, curr, prev;
	
	if(listkosong()){
		buat();	}
		
	if(idmasuk < binatang[listt].id || listkosong()){ //depan
		listbaru = kosong;
		kosong = binatang[kosong].lanjut;
		binatang[listbaru].nama = namamasuk;
		binatang[listbaru].umur = umurmasuk;
		binatang[listbaru].id = idmasuk;
		
		if(listkosong()){
			binatang[listbaru].lanjut = 0;
			listt = listbaru;
			akhirlist = listbaru;
			}	
		else {
			binatang[listbaru].lanjut = listt;
			listt = listbaru;
			}
		}
	else if (idmasuk > binatang[akhirlist].id){ //belakang
		listbaru = kosong;
		kosong = binatang[kosong].lanjut;
		binatang[listbaru].nama = namamasuk;
		binatang[listbaru].umur = umurmasuk;
		binatang[listbaru].id = idmasuk;
		binatang[akhirlist].lanjut = listbaru;
		akhirlist = listbaru;
		binatang[akhirlist].lanjut = 0;
		}
	else {									//tengah
		n = listt;
		curr = binatang[n].id;
		while(idmasuk > curr){
			prev = n;
			n = binatang[n].lanjut;
			curr = binatang[n].lanjut;
		}
		listbaru = kosong;
		kosong = binatang[kosong].lanjut;
		binatang[prev].lanjut = listbaru;
		binatang[listbaru].nama = namamasuk;
		binatang[listbaru].umur = umurmasuk;
		binatang[listbaru].id = idmasuk;
		binatang[listbaru].lanjut = n;
		}
	
	
	cout << "\nData berhasil disimpan." << endl << endl;
	}

void tampil(){
	int a = listt;
	if(listkosong()) 	
		cout << "list masih kosong." << endl;
		
	else {
		do{
			cout << binatang[a].id << "\t";
			cout << binatang[a].nama;
			cout << " (" << binatang[a].umur << " tahun)" << endl;
			a = binatang[a].lanjut;
			}while(a != 0);
		}
	}
	
void hapus(){
	string target;
	int listbaru ,n, k, prev;
	if(listkosong()) 
		cout << "list masih kosong." << endl;
	
	else {
		cout << "Nama binatang yang akan dihapus : ";
		cin.ignore();
		getline(cin, target);
	
		if(target == binatang[listt].nama){		//depan
			listbaru = binatang[listt].lanjut;
			k = kosong;
			kosong = listt;
			listt = listbaru;
			binatang[kosong].lanjut = k;
			return;
			}
			
		n = listt;
		while(binatang[n].lanjut != 0) {			//akhir
			prev = n; 
			n = binatang[n].lanjut; }
		if(target == binatang[n].nama){
			binatang[prev].lanjut = 0;
			k = kosong;
			kosong = n;
			binatang[kosong].lanjut = k;
			return;
			}
		
		n = listt;								//tengah
		while(n != 0 && binatang[n].nama != target) {
			prev = n; 
			n = binatang[n].lanjut; }
		if(n != 0){
			listbaru = kosong;
			kosong = n;
			binatang[prev].lanjut = binatang[n].lanjut;
			binatang[kosong].lanjut = listbaru;
			return;
			}
				
		cout << endl << "Data tidak ada"<<endl;
			} 
		}
	
int main(){
	
	string namamasuk, ulang;
	int menuA, umurmasuk, idmasuk;
	buat();
	
	do{
	system("CLS");
	cout << "+" << string (34, '=') << "+" << endl;
	cout << "|" << string (11, ' ') << " MENU UTAMA " << string (11, ' ') << "|" << endl;
	cout << "+" << string (34, '=') << "+" << endl;
	
	cout<<"1. TAMBAH DATA"<<endl;
	cout<<"2. HAPUS DATA"<<endl;
	cout<<"3. TAMPILAN DATA"<<endl;
	cout<<"4. EXIT"<<endl;
	cout<< endl << "Masukkan pilihan anda (1-4) : "; cin>>menuA;
	cout << endl;
	
	switch(menuA)
	{
		case 1:
			cout << "+" << string (34, '=') << "+" << endl;
			cout << "|" << string (11, ' ') << " TAMBAH DATA " << string (10, ' ') << "|" << endl;
			cout << "+" << string (34, '=') << "+" << endl << endl;
		
			cout << "Nama Binatang\t" << ": ";
			cin.ignore();
			getline(cin, namamasuk);
			cout << "Umur Binatang\t" << ": ";
			cin >> umurmasuk;
			cout << "ID Binatang (3 angka)\t" << ": ";
			cin >> idmasuk; 
			cout << endl;
	
			sipdat(namamasuk, umurmasuk, idmasuk);	
			break; 
			
		case 2:
			cout << "+" << string (34, '=') << "+" << endl;
			cout << "|" << string (11, ' ') << " HAPUS DATA " << string (11, ' ') << "|" << endl;
			cout << "+" << string (34, '=') << "+" << endl << endl;
			hapus();
			cout << endl << "Data terbaru : " << endl << endl;
			tampil();	
			cout << endl << "+" << string (34, '=') << "+" << endl << endl;
			break;
		
		case 3:
			cout << "+" << string (34, '=') << "+" << endl;
			cout << "|" << string (10, ' ') << " TAMPILAN DATA " << string (9, ' ') << "|" << endl;
			cout << "+" << string (34, '=') << "+" << endl << endl;
			tampil();
			cout << endl << "+" << string (34, '=') << "+" << endl << endl;
			break;
		
		case 4 :
			cout << "+" << string (34, '=') << "+" << endl;
			cout << "| Program selesai, selamat tinggal |" << endl;
			cout << "+" << string (34, '=') << "+" << endl;
			return 0; 
			break;
		
		default :
			cout << "+" << string (34, '=') << "+" << endl << endl;
			cout << "Maaf pilihan tidak tersedia" << endl <<endl;
			cout << "+" << string (34, '=') << "+" << endl << endl;
			break;	}
		
	cout << "Ingin mencoba menu lain? (y/n) : "; cin >> ulang; cin.ignore(); cout << endl;} 
	//menginput pilihan untuk mengulang program
	while (ulang=="y" || ulang == "Y");	
	}
