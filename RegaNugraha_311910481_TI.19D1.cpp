#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int maxim=50;
string data[50];
int penunjuk=-1;

//membuat fungsi IsEmpty untuk mengecek queue kosong atau tidak
bool IsEmpty()
{
 if(penunjuk == -1)
  return true;
 else
  return false;
}

//membuat fungsi IsFull untuk mengecek queue isi atau tidak
bool IsFull()
{
 if(penunjuk == maxim-1)
  return true;
 else
  return false;
}

//membuat fungsi enqueue untuk memasukkan nilai kedalam queue yang sebelumnya dicek terlebih dahulu apakah penuh atau belum
void enqueue()
{
 if(IsFull())
 {
  cout<<"Antrian Sudah Penuh!";
  getch();
 }
 else
 {
  penunjuk++;
  cout<<"Data Yang Akan Dimasukkan Kedalam Antrian= ";
  cin>>data[penunjuk];
  cin.ignore();
 }

}

//membuat fungsi dequeue untuk mengambil nilai dari queue yang sebelumya dicek terlebih dahulu apakah kosong atau belum
void dequeue()
{
 if (IsEmpty())
 {
  cout<<"Antrian kosong!";
  getch();
 }
 else
 {
  cout<<"Data yang diambil adalah : "<<data[0];
  penunjuk--;
  for(int x=0;x<=penunjuk;x++)
  {
   data[x]=data[x+1];
  }
 
  getch();
 }
}

//membuat fungsi Clear untuk menghapus data dalam queue
void clear()
{
 penunjuk = -1;
 cout<<"Antrian Sudah Dikosongkan!";
 getch();
}

//membuat fungsi untuk menampilkan isi dari antrian
void view()
{
 if (!IsEmpty())
 {
  for(int a=penunjuk;a>=0;a--)
  {
   cout<<"Data Antrian Pada Tumpukan ke-"<<a<<": "<<data[a]<<endl;
  }
 }
 else
 {
  cout<<"- QUEUE KOSONG -";
 }
 
}

//fungsi utama
main()
{
 int jawab;
  
 do
 {
  system ("cls");
  cout<<endl;
  cout<<"Isi QUEUE Saat Ini:"<<endl<<endl;
   view();
  cout<<endl<<endl<<endl<<endl;
  
  
  cout<<"================ P R O G R A M  Q U E U E ===============\n";
  cout<<"*********************************************************\n";
  cout<<"|       |\n";
  cout<<"| 1. Enqueue      |"<<endl;
  cout<<"| 2. Dequeue       |"<<endl;
  cout<<"| 3. Clear     |"<<endl;
  cout<<"| 4. Exit      |"<<endl;
  cout<<"|       |\n";
  cout<<"*********************************************************\n";
  cout<<"Masukkan pilihan Anda [ 1/2/3/4 ]= ";
  cin>>jawab;
 
  
  
  switch(jawab)
  {
  case 1:
   
   int limit;
   cout<<"Masukkan Jumlah Data = ";
   cin>>limit;
   
   for(int a=1; a<=limit; a++)
   {
    enqueue();
   }
   break;

  case 2:
   dequeue();   
   break;
   
  case 3:
   clear();
   break;
  }
 }
 while (jawab !=4);
}
