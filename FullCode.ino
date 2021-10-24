#include <Servo.h>                  //Pemanggilan library servo
#include <Wire.h>                   //Pemanggilan library LCD
#include <LiquidCrystal_I2C.h>      //Pemanggilan library I2C
LiquidCrystal_I2C lcd(0x27, 20, 4); //Inisiasi data LCD yaitu 0x27 alamat, 20x4 jenis Lcd
Servo myservo1;                     //Inisiasi penamaan servo 1
Servo myservo2;                     //Inisiasi penamaan servo 2
Servo myservo3;                     //Inisiasi penamaan servo 3
#define potpin1 PA0                 //Pin Potensio 1 - PA0
#define potpin2 PA1                 //Pin Potensio 2 - PA1
#define potpin3 PA2                 //Pin Potensio 3 - PA2
#define BUTTON_PIN PB12             //Pin PB Relay   - PB12
#define RELAY_PIN PB13              //Pin Relay      - PB13
#define Manual PA6                  //Pin PB Manual  - PA6
#define Auto PA7                    //Pin PB Auto    - PA7
int nilaipot1,nilaiserv1;           //Inisiasi angka pot dan servo 1
int nilaipot2,nilaiserv2;           //Inisiasi angka pot dan servo 2
int nilaipot3,nilaiserv3;           //Inisiasi angka pot dan servo 3
int pos3 = 170;                      //Inisiasi posisi awal servo 3
int pos2 = 93;                     //Inisiasi posisi awal servo 2
int pos1 = 57;                      //Inisiasi posisi awal servo 1

void setup() {                    //yaitu menginisiasi setup program
pinMode(potpin1, INPUT);          //Potentiometer 1 sebagai Input Analog
pinMode(potpin2, INPUT);          //Potentiometer 2 sebagai Input Analog
pinMode(potpin3, INPUT);          //Potentiometer 3 sebagai Input Analog
myservo1.attach(PA8);             //Inisiasi Pin Servo 1
myservo2.attach(PA9);             //Inisiasi Pin Servo 2
myservo3.attach(PA10);            //Inisiasi Pin Servo 3
pinMode(BUTTON_PIN, INPUT_PULLUP); //PB Relay sebagai Input Digital Self Lock
pinMode(RELAY_PIN, OUTPUT);        //Relay sebagai Output
pinMode(Manual, INPUT_PULLUP);     //PB Manual sebagai Input Digital Self Lock
pinMode(Auto, INPUT_PULLUP);       //PB Otomatis sebagai Input Digital Self Lock
lcd.begin();                       //Menginisiasi LCD
lcd.backlight();
}

void loop(){                            //Void utama pada program
int tombolmanual = digitalRead(Manual); //Pembacaan PB Manual di inisiasi berupa angka 0/1
 if (tombolmanual == LOW)               //Jika PB Manual ditekan
 { servo1();                            //Memainkan kontrol knob servo1
   servo2();                            //Memainkan kontrol knob servo2
servo3();                               //Memainkan kontrol knob servo3
controlbutton();                        //Memainkan kontrol PB Relay terhadap Relay
displaylcd(); }                         //Menampilkan kondisi kontrol manual

int tombolotomatis = digitalRead(Auto); //Pembacaan PB Otomatis di inisiasi berupa angka 0/1
 if (tombolotomatis == LOW)             //Jika PB Otomatis ditekan
 { lcdotomatis();                       //Menampilkan kondisi kontrol otomatis
  otomatis(); }                         //Memainkan kontrol otomatis
 
 else if(tombolotomatis == HIGH && tombolmanual == HIGH){ //Jika PB Otomatis maupun PB Manual tidak ditekan
  startlcd(); }                                      //Menampilkan tampilan menu
                                        
}
