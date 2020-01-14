#include <header.h>

/*
 * servo depan (betis): 6,5,9,13,7,12
 * servo pangkal (paha): 11,2,4,3,10,8
 * liat di robotnya aja :v
*/

//--- ada 6 kaki. perkaki 2 DOF
const int leg[6][2] = { {12,11},{7,2},{13,4},{9,3},{5,10},{6,8} };
/*
    leg[][] ada 6 elemen (6 kaki)
    keterangan untuk method maju(),mundur(),ke_kanan(),ke_kiri()
    0 = depan kiri      3 = depan kanan
    1 = tengah kiri     4 = tengah kanan
    2 = belakang kiri   5 = belakang kanan
*/

//--- leg biar ga bingung
const int paha=0; // indeks paha
const int betis=1; // indeks betis

//--- leg constant (posisi default)
const int pos_paha=500;  //525
const int pos_betis=500; //500

//--- delay
int  del=12; // delay dorong12
int  del2=25; // delay angkat 25
int  del3=20;

//---  posisi awal
void init_bot() {
  for(int i=2;i<14;i++){
      ax12a.move(i,500); // set ke 500 semua
      delay(100);
  }
}

//--- 3 kaki betisnya diangkat (depan, tengah, belakang)
void walk_angkat(int depan,int tengah,int belakang){
    ax12a.move(leg[depan][betis],pos_betis+100);
    delay(del2);
    ax12a.move(leg[tengah][betis],pos_betis+100 );
    delay(del2);
    ax12a.move(leg[belakang][betis],pos_betis+100 );
    delay(del2);
}

//--- 3 kaki betisnya turun (depan,tengah,belakang)
void walk_turun(int depan,int tengah,int belakang){
    ax12a.move(leg[depan][betis],pos_betis-100 );
    delay(del2);
    ax12a.move(leg[tengah][betis],pos_betis-100 );
    delay(del2);
    ax12a.move(leg[belakang][betis],pos_betis-100 );
    delay(del2);
}

//--- 3 kaki pahanya didorong (depan,tengah,belakang)
void walk_dorong(int depan,int tengah,int belakang,int posisi) {
    //-- beda nilai var posisi, beda arah gerak bodynya
    if(posisi==1) {
        ax12a.move(leg[depan][paha],pos_paha+65 );
        delay(del);
        ax12a.move(leg[tengah][paha],pos_paha-65 );
        delay(del);
        ax12a.move(leg[belakang][paha],pos_paha+65 );
        delay(del);
    }
    else if(posisi==2) {
        ax12a.move(leg[depan][paha],pos_paha-65 );
        delay(del);
        ax12a.move(leg[tengah][paha],pos_paha+65 );
        delay(del);
        ax12a.move(leg[belakang][paha],pos_paha-65 );
        delay(del);
    }
    else if (posisi==3) {
        ax12a.move(leg[depan][paha],pos_paha-65 );
        delay(del);
        ax12a.move(leg[tengah][paha],pos_paha-65 );
        delay(del);
        ax12a.move(leg[belakang][paha],pos_paha-65 );
        delay(del);
    }
    else if(posisi==4) {
        ax12a.move(leg[depan][paha],pos_paha+65 );
        delay(del);
        ax12a.move(leg[tengah][paha],pos_paha+65 );
        delay(del);
        ax12a.move(leg[belakang][paha],pos_paha+65);
        delay(del);
    }
}

//--- maju 1 kali
void maju()
{
    walk_angkat(0,4,2); // angkat kaki 0 dan 4
    walk_dorong(3,1,5,2); // dorong kaki 3, 1, 5
    walk_turun(0,4,2); // kaki 0 dan 4 turun
    walk_angkat(3,1,5); // angkat kaki 3, 1, 5
    walk_dorong(3,1,5,1); // dorong kaki 3, 1, 5
    //-- gantian
    walk_angkat(3,1,5);
    walk_dorong(0,4,2,1);
    walk_turun(3,1,5);
    walk_angkat(0,4,2);
    walk_dorong(0,4,2,2);
}

//--- mundur 1 kali
void mundur() {
    walk_angkat(0,4,2); // angkat kaki 0 dan 4
    walk_dorong(3,1,5,1); // dorong kaki 3,1,5
    walk_turun(0,4,2); // kaki 0 dan 4 turun
    walk_angkat(3,1,5); // angkat kaki 3,1,5
    walk_dorong(3,1,5,2); // dorong kaki 3,1,5
    //gantian
    walk_angkat(3,1,5);
    walk_dorong(0,4,2,2);
    walk_turun(3,1,5);
    walk_angkat(0,4,2);
    walk_dorong(0,4,2,1);
}

//--- muter ke kanan 30 derajat
void ke_kanan() {
    walk_angkat(0,4,2); // angkat kaki 0 dan 4
    walk_dorong(3,1,5,3); // dorong kaki 3,1,5
    walk_turun(0,4,2); // kaki 0 dan 4 turun
    walk_angkat(3,1,5); // angkat kaki 3,1,5
    walk_dorong(3,1,5,4); // dorong kaki 3,1,5
    //gantian
    walk_angkat(3,1,5);
    walk_dorong(0,4,2,3);
    walk_turun(3,1,5);
    walk_angkat(0,4,2);
    walk_dorong(0,4,2,4);
}

//--- muter ke kiri 30 derajat
void ke_kiri() {
    walk_angkat(0,4,2); // angkat kaki 0 dan 4
    walk_dorong(3,1,5,4); // dorong kaki 3,1,5
    walk_turun(0,4,2); // kaki 0 dan 4 turun
    walk_angkat(3,1,5); // angkat kaki 3,1,5
    walk_dorong(3,1,5,3); // dorong kaki 3,1,5
    //gantian
    walk_angkat(3,1,5);
    walk_dorong(0,4,2,4);
    walk_turun(3,1,5);
    walk_angkat(0,4,2);
    walk_dorong(0,4,2,3);
}

//--- belok kanan
void belok_kanan() {
  for(int i=0;i<3;i++) //belok kanan butuh panggil ke_kanan() 3 kali
    ke_kanan();
}

//--- belok kiri
void belok_kiri() {
  for(int i=0;i<3;i++) //belok kiri butuh panggil ke_kiri() 3 kali
    ke_kiri();
}

//--- geser kanan
void geser_kanan(int depankanan,int depankiri,int belakangkanan,int belakangkiri,int tengahkanan,int tengahkiri) {
    //-- depan kiri dan belakang kanan diangkat, dorong, turun
    ax12a.move(leg[depankiri][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[belakangkanan][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[depankiri][paha], pos_paha+65); // dorong
    delay(del);
    ax12a.move(leg[belakangkanan][paha], pos_paha-65); // dorong
    delay(del);
    ax12a.move(leg[depankiri][betis], pos_betis-100); // turun
    delay(del2);
    ax12a.move(leg[belakangkanan][betis], pos_betis-100); // turun
    delay(del2);
    //-- depan kanan dan belakang kiri diangkat, dorong, turun
    ax12a.move(leg[depankanan][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[belakangkiri][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[depankanan][paha], pos_paha+65); // dorong
    delay(del);
    ax12a.move(leg[belakangkiri][paha], pos_paha-65); // dorong
    delay(del);
    ax12a.move(leg[depankanan][betis], pos_betis-100); // turun
    delay(del2);
    ax12a.move(leg[belakangkiri][betis], pos_betis-100); // turun
    delay(del2);
    //-- kedua kaki tengah diangkat dulu
    ax12a.move(leg[tengahkanan][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[tengahkiri][betis], pos_betis+100); // angkat
    delay(del2);
    //-- dorong 4 kakinya biar bodynya geser
    ax12a.move(leg[depankiri][paha], pos_paha-65); // dorong
    delay(del);
    ax12a.move(leg[belakangkanan][paha], pos_paha+65); // dorong
    delay(del);
    ax12a.move(leg[depankanan][paha], pos_paha-65); // dorong
    delay(del);
    ax12a.move(leg[belakangkiri][paha], pos_paha+65); // dorong
    delay(del);
    //-- kedua kaki tengah diturunin
    ax12a.move(leg[tengahkanan][betis], pos_betis-100); // turun
    delay(del2);
    ax12a.move(leg[tengahkiri][betis], pos_betis-100); // turun
    delay(del2);
}

//--- geser kiri
void geser_kiri(int depankanan,int depankiri,int belakangkanan,int belakangkiri,int tengahkanan,int tengahkiri) {
    //-- depan kiri dan belakang kanan diangkat, dorong, turun
    ax12a.move(leg[depankiri][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[belakangkanan][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[depankiri][paha], pos_paha-55); // dorong
    delay(del);
    ax12a.move(leg[belakangkanan][paha], pos_paha+55); // dorong
    delay(del);
    ax12a.move(leg[depankiri][betis], pos_betis-100); // turun
    delay(del2);
    ax12a.move(leg[belakangkanan][betis], pos_betis-100); // turun
    delay(del2);
    //-- depan kanan dan belakang kiri diangkat, dorong, turun
    ax12a.move(leg[depankanan][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[belakangkiri][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[depankanan][paha], pos_paha-55); // dorong
    delay(del);
    ax12a.move(leg[belakangkiri][paha], pos_paha+55); // dorong
    delay(del);
    ax12a.move(leg[depankanan][betis], pos_betis-100); // turun
    delay(del2);
    ax12a.move(leg[belakangkiri][betis], pos_betis-100); // turun
    delay(del2);
    //-- kedua kaki tengah diangkat dulu
    ax12a.move(leg[tengahkanan][betis], pos_betis+100); // angkat
    delay(del2);
    ax12a.move(leg[tengahkiri][betis], pos_betis+100); // angkat
    delay(del2);
    //-- dorong 4 kakinya biar bodynya geser
    ax12a.move(leg[depankiri][paha], pos_paha+55); // dorong
    delay(del);
    ax12a.move(leg[belakangkanan][paha], pos_paha-55); // dorong
    delay(del);
    ax12a.move(leg[depankanan][paha], pos_paha+55); // dorong
    delay(del);
    ax12a.move(leg[belakangkiri][paha], pos_paha-55); // dorong
    delay(del);
    //-- kedua kaki tengah diturunin
    ax12a.move(leg[tengahkanan][betis], pos_betis-100); // turun
    delay(del2);
    ax12a.move(leg[tengahkiri][betis], pos_betis-100); // turun
    delay(del2);
}