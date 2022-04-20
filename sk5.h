using namespace std;

int total_harga(int harga, int jumlah) {
  if(jumlah == 0) {
    return 0;
  } else {
    return harga + total_harga(harga, jumlah-1);
  }
}

class studi_kasus {
  public :
    void program() {
      cout<<"Masukkan Nama : ";
      getline(cin,nama);
      cout<<"Masukkan NIM  : ";
      getline(cin,nim);
      cout<<"Daftar Matakuliah         SKS:"<<endl;
      cout<<"1. Algoritma Pemrograman   3"<<endl;
      cout<<"2. Matematika Diskrit      3"<<endl;
      cout<<"3. Bahasa Indonesia        2"<<endl;
    
      for(int i = 1; i <= 3; i++) {
        cout<<"Masukan Matakuliah : "; 
        getline(cin, matkul[i]);
      }
      for(int i = 1; i <= 3; i++) {
    	  cout<<"Masukan Jumlah SKS : ";
        cin>>sks[i]; 
      }
      for(int i = 1; i<=3; i++) {
        jml_sks = jml_sks + sks[i];
      }
      total = total_harga(120000,jml_sks);
      
      diskon10 = total * 10/100;
      diskon = total - diskon10;
      diskon5 = diskon * 5/100;
      total_pembayaran = diskon - diskon5;
      
      file.open("out_sk5.txt");
      file<<"Nama : "<<nama<<endl;
      file<<"NIM  : "<<nim<<endl;
      file<<"Mata Kuliah\t\t\t\t SKS"<<endl;
      for(int i = 1; i <= 3; i++) {
        file<<matkul[i]<<"\t\t "<<sks[i]<<endl;
      }
        
      file<<"Jumlah SKS\t\t\t\t\t "<<jml_sks<<endl;
      file<<"Total Pembayaran\t\t"<<total_pembayaran;
    }

  private :
    ofstream file;
    string nama, nim;
    string matkul[30];
    int sks[30];
    int jml_sks = 0;
    int total, diskon, total_pembayaran;
    float diskon10, diskon5;
};