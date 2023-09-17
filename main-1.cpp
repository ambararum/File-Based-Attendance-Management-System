#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include <ctime>
#include <algorithm>

using namespace std;

struct mahasiswa{
	string nama;
	string nim;
	string alamat;
	int tahun_masuk;
};

struct presensi{
	string nim;
	string nama;
	string matakuliah;
	char waktu[26];
};

presensi p;
mahasiswa m;

int a;

void AddMahasiswa(){
	fstream sdata;
	sdata.open("Mahasiswa.txt", ios::app);
	sdata << m.nama << "\t";
	sdata << m.nim  << "\t";
	sdata << m.alamat << "\t";
	sdata << m.tahun_masuk << "\t";

	sdata.close();
}

void LihatMahasiswa(){
	ifstream tdata;
	tdata.open("Mahasiswa.txt");
	tdata >> m.nama;
	tdata >> m.nim;
	tdata >> m.alamat;
	tdata >> m.tahun_masuk;
    if (!tdata)
    {
        cout << "\n\t\t\t\t\tNo Data is Present..";
        cout << endl;
        tdata.close();
    }
    else{
	while(!tdata.eof()){
		cout << "\t\t\t\t\tNama           : " << m.nama << endl;
		cout << "\t\t\t\t\tNim            : " << m.nim<<endl;
		cout << "\t\t\t\t\tAlamat         : " << m.alamat<<endl;
		cout << "\t\t\t\t\tTahun Masuk    : " << m.tahun_masuk<<endl;
        cout<<"\t\t\t\t\t========================================="<<endl;

		tdata >> m.nama;
		tdata >> m.nim;
		tdata >> m.alamat;
		tdata >> m.tahun_masuk;
	}
	tdata.close();
	}
}

void EditMahasiswa(){
	system("cls");
	string cari;
    int found = 0;
    fstream file, file1;
    cout<<"\t\t\t\t\t========================================="<<endl;
    cout<<"\t\t\t\t\t=======   Update Data Mahasiswa   ======="<<endl;
    cout<<"\t\t\t\t\t========================================="<<endl;
    file.open("Mahasiswa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\n\t\t\t\t\tMasukkan Nama Yang Di Update : ";
        cin >> cari;
        file1.open("temp.txt", ios::app | ios::out);
        file >> m.nama >> m.nim >> m.alamat >> m.tahun_masuk;
        while (!file.eof())
        {
            if (cari==m.nama)
            {
                cout << "\n\t\t\t\t\t **  Silahkan Masukan Data Baru  ** ";
                cout <<endl;
                cout << "\n\t\t\t\t\t Masukkan Nama Mahasiswa : ";
                cin >> m.nama;
                cout << "\n\t\t\t\t\t Masukkan Nim Mahasiswa  : ";
                cin >> m.nim;
                cout << "\n\t\t\t\t\t Masukkan Alamat         : ";
                cin >> m.alamat;
                cout << "\n\t\t\t\t\t Masukkan Tahun Masuk    : ";
                cin >> m.tahun_masuk;
                file1 << " " << m.nama << " " << m.nim << " " << m.alamat << " " << m.tahun_masuk << "\n";
                found++;
            }
            else
            {
                file1 << " " << m.nama << " " << m.nim << " " << m.alamat << " " << m.tahun_masuk << "\n";
            }
            file >> m.nama >> m.nim >> m.alamat >> m.tahun_masuk;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t\tNama Mahasiswa Not Found.. Please Try Again";
            cout << endl;
        }
        file1.close();
        file.close();
        remove("Mahasiswa.txt");
        rename("temp.txt", "Mahasiswa.txt");
    }

}

void HapusMahasiswa(){
	system("cls");
	string cari;
    int found = 0;
    fstream file, file1;
    cout<<"\t\t\t\t\t=========================================="<<endl;
    cout<<"\t\t\t\t\t=======    Hapus Data Mahasiswa    ======="<<endl;
    cout<<"\t\t\t\t\t=========================================="<<endl;
    file.open("Mahasiswa.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\n\t\t\t\t\tMasukkan Nama Yang Di Hapus : ";
        cin >> cari;
        file1.open("temp.txt", ios::app | ios::out);
        file >> m.nama >> m.nim >> m.alamat >> m.tahun_masuk;
        while (!file.eof())
        {
            if (cari!=m.nama)
            {
                file1 << " " << m.nama << " " << m.nim << " " << m.alamat << " " << m.tahun_masuk << "\n";
            }
            else
            {
            	found++;
                cout << "\n\t\t\t\t\tSuccessfully Delete Data";
                cout << endl;
            }
            file >> m.nama >> m.nim >> m.alamat >> m.tahun_masuk;
        }
        if (found == 0)
        {
            cout << endl;
            cout << "\t\t\t\t\tNama Mahasiswa Not Found.. Please Try Again";
            cout << endl;
        }
        file1.close();
        file.close();
        remove("Mahasiswa.txt");
        rename("temp.txt", "Mahasiswa.txt");
    }
}

void CariMahasiswa(){
	int total = 1;
	system("cls");
    fstream file;
    string cari;
    cout<<"\t\t\t\t\t========================================"<<endl;
    cout<<"\t\t\t\t\t======   Mencari Data Mahasiswa   ======"<<endl;
    cout<<"\t\t\t\t\t========================================"<<endl;
    file.open("Mahasiswa.txt", ios::in);
    cout << endl;
    cout << "\t\t\t\t\tMasukkan Nama Yang Ingin Dicari : ";
    cin >> cari;
    if (!file)
    {
        cout << "\n\t\t\t\tTidak Ada Data... ";
        file.close();
    }
    else
    {
        file >> m.nama >> m.nim >> m.alamat >> m.tahun_masuk;
        cout << endl;
        cout << "\t\t                                  Mahasiswa Yang Dicari                                         ";
        cout << "\n\t\t --------------------------------------------------------------------------------------------------";
    	cout << "\n\t\t  ||\tNO\t||\tNAMA\t||\tNIM\t||\tALAMAT   \t||\tTAHUN MASUK\t||";
        cout << "\n\t\t --------------------------------------------------------------------------------------------------\n";
        while (!file.eof())
        {
            if (cari==m.nama)
            {
        cout <<"\t\t\t"<< total++ << ".\t       " << m.nama << "\t\t" << m.nim << "\t" << m.alamat << "\t\t" << m.tahun_masuk<<"\t";
        cout << "\n\t\t --------------------------------------------------------------------------------------------------";
        cout<<endl;
            }
            file >> m.nama >> m.nim >> m.alamat >> m.tahun_masuk;
        }
    }
    file.close();
}

void AddPresensiMahasiswa(){
	system("cls");
    fstream file;
    cout<<"\t\t\t\t\t========================================"<<endl;
    cout<<"\t\t\t\t\t======  Input Presensi Mahasiswa  ======"<<endl;
    cout<<"\t\t\t\t\t========================================"<<endl;
    cout << "\t\t\t\t\tMasukkan Nama        : ";
    cin >> p.nama;
    cout << "\t\t\t\t\tMasukkan Nim         : ";
    cin >> p.nim;
    cout << "\t\t\t\t\tMasukkan Mata Kuliah : ";
    cin >> p.matakuliah;

    time_t timer;
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(p.waktu, 26, "%d-%B-%Y-%H:%M", tm_info);
    file.open("Presensi.txt", ios::app | ios::out);
    file << " " << p.nim << " " << p.nama << " " << p.matakuliah << " "<<p.waktu<< "\n";
    file.close();
}

void LihatSemuaPresensi(){
	int no = 1;
	ifstream tdata;
	tdata.open("Presensi.txt");

	if (!tdata)
    {
        cout << "\n\t\t\t\t\tNo Data is Present..";
        tdata.close();
    }else{
    	tdata >> p.nim;
    	tdata >> p.nama;
		tdata >> p.matakuliah;
		tdata >> p.waktu;
		    cout << "\n";
		    cout << "\t\t                                  Semua Mahasiswa Yang Presensi                                      ";
			cout << "\n\t\t =================================================================================================";
            cout << "\n\t\t ||     NO     ||      NIM      ||      NAMA      ||      Matakuliah      ||      Timestamps     ||";
            cout << "\n\t\t ================================================================================================="<<endl;
		while(!tdata.eof()){
			cout << "\t \t\t "<< no++ <<"\t  "<< p.nim <<"\t  "<< p.nama <<"\t\t  "<< p.matakuliah <<"\t\t  "<< p.waktu <<"\t\t  "<<endl;
			cout << "\t\t -------------------------------------------------------------------------------------------------"<<endl;
            tdata >> p.nim >> p.nama >> p.matakuliah >> p.waktu;
		}
		tdata.close();
	}
}

void LihatPresensiMahasiswa(){
	int total = 1;
	system("cls");
    fstream file;
    string cari;
    cout<<"\t\t\t\t\t=================================================="<<endl;
    cout<<"\t\t\t\t\t=======    Cari Data Presensi Mahasiswa    ======="<<endl;
    cout<<"\t\t\t\t\t=================================================="<<endl;
    file.open("Presensi.txt", ios::in);
    cout << endl;
    cout << "\t\t\t\t\tMasukkan Mata Kuliah : ";
    cin >> cari;
    if (!file)
    {
        cout << "\n\t\t\t\t\tTidak Ada Data... ";
        file.close();
    }
    else
    {
        file >> p.nim >> p.nama >> p.matakuliah >> p.waktu;
            cout << "\n";
		    cout << "\t\t                           Mahasiswa Yang Presensi di Mata Kuliah "<< cari ;
			cout << "\n\t\t =================================================================================================";
            cout << "\n\t\t ||     NO     ||      NIM      ||      NAMA      ||      Matakuliah      ||      Timestamps     ||";
            cout << "\n\t\t ================================================================================================="<<endl;
        while (!file.eof())
        {
            if (cari==p.matakuliah)
            {
                cout <<"\t\t\t"<< total++ << ".\t " << p.nim << "\t  " << p.nama << "\t\t  " << p.matakuliah << "\t\t   " << p.waktu;
            	cout << "\n\t\t ------------------------------------------------------------------------------------------------\n";
            }
            file >> p.nim >> p.nama >> p.matakuliah >> p.waktu;
        }
    }
    file.close();
}

bool compare( presensi p1,presensi p2){
	if(p1.nim < p2.nim)
		return true;
	else
		return false;
}

void sorting(){
	system("cls");
	int no=1;
    int total = 0;
    int i;
    fstream file;

    cout<<"\t\t\t\t\t=================================================="<<endl;
    cout<<"\t\t\t\t\t=======   Mengurutkan Presensi Mahasiswa   ======="<<endl;
    cout<<"\t\t\t\t\t=================================================="<<endl;
    cout<< endl;
    file.open("Presensi.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present ... ";
        file.close();
    }
    else
    {
        file >> p.nim >> p.nama >> p.matakuliah >> p.waktu;
        while (!file.eof())
        {
        	total = total + 1;
            file >> p.nim >> p.nama >> p.matakuliah >> p.waktu;
        }
    	presensi array[total];
    	ifstream presensi("Presensi.txt");

	    for ( i =0 ; i  < total; i ++)
	    {
	        presensi >> array[i].nim;
	        presensi >> array[i].nama;
	        presensi >> array[i].matakuliah;
	        presensi >> array[i].waktu;
	    }

    	sort(array, array+total, compare);

		    cout << "\t\t                        Shorting NIM Mahasiswa Yang Presensi Secara Ascending                       " ;
			cout << "\n\t\t =================================================================================================";
            cout << "\n\t\t ||     NO     ||      NIM      ||      NAMA      ||      Matakuliah      ||      Timestamps     ||";
            cout << "\n\t\t ================================================================================================="<<endl;

    	for(i=0;i<total;i++){
    		file >> array[i].nim >> array[i].nama >> array[i].matakuliah >> array[i].waktu;
			cout <<"\t\t\t"<< no++ << ".\t " << array[i].nim << "\t  " << array[i].nama << "\t\t" << array[i].matakuliah << "\t\t" << array[i].waktu;
			cout << "\n\t\t------------------------------------------------------------------------------------------------\n";
		}
    }
}

int main(){
     char lanjut;

	 menu1:
        system ("cls");
        cout<<"\t\t\t\t\t======================================="<<endl;
        cout<<"\t\t\t\t\t=====         TUGAS BESAR         ====="<<endl;
        cout<<"\t\t\t\t\t=====   ALGORITMA & PEMOGRAMAN    ====="<<endl;
        cout<<"\t\t\t\t\t======================================="<<endl;
        cout<<"\t\t\t\t\t= -Ambar Arum Prameswari              ="<<endl;
        cout<<"\t\t\t\t\t= -Novi Ramadani                      ="<<endl;
        cout<<"\t\t\t\t\t= -Nurhasanah                         ="<<endl;
        cout<<"\t\t\t\t\t= -Rahma Setiani                      ="<<endl;
        cout<<"\t\t\t\t\t= -Sandya Naufal Wardhana             ="<<endl;
        cout<<"\t\t\t\t\t======================================="<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\tTekan [Y] untuk lanjutkan [T] untuk berhenti : ";
        cin>>lanjut;
            if (lanjut=='y'|| lanjut=='Y')
            {
                goto utama;
            }
            else{
                system("cls");
                cout<<"\n\n\t\t\t\t\t==================================="<<endl;
                cout<<"\n\t\t\t\t\tTerima kasih telah mengunjungi kami"<<endl;
                cout<<"\n\t\t\t\t\t==================================="<<endl;
                cout<<"\n";
                exit(0);
            }

    utama :
    system ("cls");
    cout<<"\t\t\t\t========================================================"<<endl;
	cout<<"\t\t\t\t::: Selamat Datang Di Sistem Presensi Mahasiswa Kita :::"<<endl;
	cout<<"\t\t\t\t========================================================"<<endl;
	cout<<"\t\t\t\t1 .Input  Data Mahasiswa"<<endl;
	cout<<"\t\t\t\t2 .Lihat  Data Mahasiswa"<<endl;
	cout<<"\t\t\t\t3 .Update Data Mahasiswa"<<endl;
	cout<<"\t\t\t\t4 .Hapus  Data Mahasiswa"<<endl;
    cout<<"\t\t\t\t5 .Cari   Data Mahasiswa"<<endl;
    cout<<"\t\t\t\t--------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t6 .Input   Presensi Mahasiswa"<<endl;
	cout<<"\t\t\t\t7 .Lihat   Presensi Mahasiswa"<<endl;
    cout<<"\t\t\t\t8 .Lihat   Presensi Mahasiswa Berdasarkan Mata Kuliah"<<endl;
	cout<<"\t\t\t\t9 .Sorting Presensi Mahasiswa Berdasarkan NIM"<<endl;
	cout<<"\t\t\t\t10.Kembali"<<endl;
    cout<<"\t\t\t\t========================================================"<<endl;
    cout<<endl;
	cout<<"\t\t\t\tPilih Menu : ";
	cin>>a;

	switch(a){
		case 1: {
			int masukkan = 1;
			while(masukkan !=0){
				system("cls");
                cout<<"\t\t\t\t\t========================================"<<endl;
				cout<<"\t\t\t\t\t=======   Input Data Mahasiswa   ======="<<endl;
                cout<<"\t\t\t\t\t========================================"<<endl;
				cout << "\t\t\t\t\tMasukkan Nama       : ";
				cin >> m.nama;
				cout << "\t\t\t\t\tMasukkan Nim        : ";
				cin >> m.nim;
				cout << "\t\t\t\t\tMasukkan Alamat     : ";
				cin >> m.alamat;
				cout << "\t\t\t\t\tMasukkan Tahun Masuk: ";
				cin >> m.tahun_masuk;
				AddMahasiswa();
                cout<<"\t\t\t\t\t========================================"<<endl;
                cout<<endl;
				cout<<"\t\t\t\t\tApakah Ingin Input Data Mahasiswa Lagi ? "<<endl;
				cout<<"\t\t\t\t\t[0]Tidak || [1] IYA : ";
				cin>>masukkan;
			}
			system("cls");
			goto utama;
			break;
		}

		case 2:{
			int masukkan = 1;
			while(masukkan !=0){
				system("cls");
                cout<<"\t\t\t\t\t========================================="<<endl;
                cout<<"\t\t\t\t\t=======   Daftar Data Mahasiswa   ======="<<endl;
                cout<<"\t\t\t\t\t========================================="<<endl;
				LihatMahasiswa();
				cout<<endl;
				cout << "\t\t\t\t\t[0] Untuk kembali : ";
				cin >> masukkan;
			}
			system("cls");
			goto utama;
			break;
		}

		case 3:{
			int masukkan = 1;
			while(masukkan !=0){
				system("cls");

				EditMahasiswa();
				cout<<endl;
				cout << "\t\t\t\t\t[0] Untuk kembali : ";
				cin >> masukkan;
			}
			system("cls");
			goto utama;
			break;
		}

		case 4:{
			int masukkan = 1;
			while(masukkan !=0){
				system("cls");
				HapusMahasiswa();
				cout<<endl;
				cout << "\t\t\t\t\t[0] Untuk kembali : ";
				cin >> masukkan;
			}
			system("cls");
			goto utama;
			break;
		}

		case 5:{
            int masukkan = 1;
			while(masukkan !=0){
				system("cls");
			    CariMahasiswa();
			    cout<<endl;
			    cout<<endl;
				cout << "\t\t\t\t\t[0] Untuk kembali : ";
				cin >> masukkan;
            }
            system("cls");
			goto utama;
			break;
		}

		case 6:{
			int masukkan = 1;
			while(masukkan !=0){
				AddPresensiMahasiswa();
                cout<<"\t\t\t\t\t========================================"<<endl;
				cout<<endl;
				cout<<"\t\t\t\t\tApakah Ingin Input Presensi Mahasiswa Lagi ? "<<endl;
				cout<<"\t\t\t\t\t[0]Tidak || [1] IYA : ";
				cin>>masukkan;
			}
			system("cls");
			goto utama;
			break;
		}

		case 7:{
		int masukkan = 1;
		while(masukkan !=0){
			system("cls");
                cout<<"\t\t\t\t\t============================================="<<endl;
                cout<<"\t\t\t\t\t=======   Daftar Presensi Mahasiswa   ======="<<endl;
                cout<<"\t\t\t\t\t============================================="<<endl;
			LihatSemuaPresensi();
			cout<<endl;
			cout << "\t\t\t\t\t[0] Untuk kembali: ";
			cin >> masukkan;
		}
		system("cls");
		goto utama;
		break;
		}

		case 8:{
		int masukkan = 1;
			while(masukkan !=0){
				system("cls");
				LihatPresensiMahasiswa();
				cout << endl;
				cout << "\t\t\t\t\t[0] Untuk kembali : ";
				cin >> masukkan;
			}
			system("cls");
			goto utama;
			break;
		}

        case 9:{
			int masukkan = 1;
			while(masukkan !=0){
				system("cls");
				sorting();
				cout << endl;
				cout << "\t\t\t\t\t[0] Untuk kembali : ";
				cin >> masukkan;
			}
			system("cls");
			goto utama;
			break;
			break;
		}
		default :
            int masukkan = 1;
			while(masukkan !=0){
            if(a!=10){
                cout <<"\n pilihan tidak tersedia"<<endl;
                cout << "[0] Untuk pilih kembali : ";
				cin >> masukkan;

            system("cls");
			goto utama;
			break;
            }else if(a==10){
            system("cls");
			goto menu1;
			break;
            }
            break;
            }

	}
	return 0;
}
