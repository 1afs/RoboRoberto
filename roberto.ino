#include "SoftwareSerial.h"

const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
const int pinoLedR = 4; //PINO DIGITAL UTILIZADO PELO LED VERMELHO
const int pinoLedG = 5; //PINO DIGITAL UTILIZADO PELO LED VERDE
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
boolean loopLED = false; //VARIÁVEL BOOLEANA QUE FAZ O CONTROLE DE ATIVAÇÃO DO LOOP DO LED
const int tonePin = 8; //PINO DIGITAL USADO PRO BUZZER
const int intervalo = 500; //TEMPO PARA INTERVALO

SoftwareSerial bluetooth(pinoRX, pinoTX); //INICIALIZAÇÃO DO MODULO BLUETOOTH

void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  pinMode(pinoLedG, OUTPUT);//DEFINE O PINO COMO SAÍDA
  pinMode(pinoLedR, OUTPUT);//DEFINE O PINO COMO SAÍDA
  pinMode(tonePin, OUTPUT);//DEFINE O PINO COMO SAÍDA
}

void loop() {
  if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
       dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH

  switch(dadoBluetooth){
    case 'g':
    loopLED = false;
    resposta(pinoLedG);
    break;
    
    case 'r':
    loopLED = false;
    resposta(pinoLedR);
    break;
    
    case 'm':
    musica();
    break;

    case 's':
    shutdownWindows();
    break;

    case 'l':
    logonWindows();
    break;

    case '1':
    loopLED = true;
    break;

    case '0':
    loopLED = false;
    digitalWrite(pinoLedR, LOW); //DESLIGA O LED
    digitalWrite(pinoLedG, LOW); //DESLIGA O LED
    break;
    
    default:
    break;

  }
 
  }
 
  //MÉTODO RESPONSÁVEL PELO LOOP (LIGA / DESLIGA) DO LED
  if(loopLED){
    digitalWrite(pinoLedR, HIGH); //LIGA O LED
    digitalWrite(pinoLedG, HIGH); //LIGA O LED
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
    digitalWrite(pinoLedR, LOW); //DESLIGA O LED
    digitalWrite(pinoLedG, LOW); //DESLIGA O LED
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
  }
}

//FUNÇÃO PARA ANIMAÇÃO DE LEDS
void resposta(int pino){
  int i;
  digitalWrite(pinoLedR,LOW);
  digitalWrite(pinoLedG,LOW);
  delay(intervalo);
  
  for(i=0;i<2;i++){
    digitalWrite(pinoLedR,HIGH);
    digitalWrite(pinoLedG,LOW);
    delay(intervalo/2);
    digitalWrite(pinoLedR,LOW);
    digitalWrite(pinoLedG,HIGH);
    delay(intervalo/2);
  };
  digitalWrite(pinoLedR,LOW);
  digitalWrite(pinoLedG,LOW);
  delay(intervalo*2);
  digitalWrite(pino,HIGH);
}

//FUNÇÃO P/ TOQUE
void shutdownWindows(){
  tone(tonePin, 830, 225.0);
    delay(250.0);
    tone(tonePin, 622, 225.0);
    delay(250.0);
    tone(tonePin, 415, 225.0);
    delay(250.0);
    tone(tonePin, 466, 225.0);
    delay(250.0);
}

//FUNÇÃO P/ TOQUE
void logonWindows(){
  tone(tonePin, 622, 225.0);
    delay(250.0);
    tone(tonePin, 311, 112.5);
    delay(125.0);
    tone(tonePin, 466, 225.0);
    delay(250.0);
    tone(tonePin, 415, 337.5);
    delay(375.0);
    tone(tonePin, 622, 225.0);
    delay(250.0);
    tone(tonePin, 466, 450.0);
    delay(500.0);
}


//FUNÇÃO P/ TOCAR MUSICA
void musica(){
    tone(tonePin, 246, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 412.325976562);
    ritmo(false);
    delay(458.139973958);
    delay(4.82252604167);
    tone(tonePin, 195, 99.8262890625);
    ritmo(true);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 164, 99.8262890625);
    ritmo(false);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(236.303776042);
    tone(tonePin, 195, 99.8262890625);
    ritmo(true);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 164, 99.8262890625);
    ritmo(false);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(236.303776042);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(236.303776042);
    tone(tonePin, 246, 555.555);
    ritmo(false);
    delay(617.283333333);
    delay(77.1604166667);
    tone(tonePin, 246, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 412.325976562);
    ritmo(false);
    delay(458.139973958);
    delay(4.82252604167);
    tone(tonePin, 195, 99.8262890625);
    ritmo(true);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 164, 99.8262890625);
    ritmo(false);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(236.303776042);
    tone(tonePin, 195, 99.8262890625);
    ritmo(true);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 164, 99.8262890625);
    ritmo(false);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(236.303776042);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(236.303776042);
    tone(tonePin, 246, 555.555);
    ritmo(false);
    delay(617.283333333);
    delay(77.1604166667);
    tone(tonePin, 246, 347.221875);
    ritmo(true);
    delay(385.802083333);
    delay(77.1604166667);
    tone(tonePin, 293, 308.159414062);
    ritmo(false);
    delay(342.399348958);
    delay(4.82252604167);
    tone(tonePin, 293, 99.8262890625);
    ritmo(true);
    delay(110.918098958);
    delay(4.82252604167);
    tone(tonePin, 261, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 246, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 220, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 220, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 724.825664062);
    ritmo(false);
    delay(805.361848958);
    delay(120.563151042);
    tone(tonePin, 195, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 220, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 246, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 220, 555.555);
    ritmo(false);
    delay(617.283333333);
    delay(77.1604166667);
    tone(tonePin, 220, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 195, 412.325976562);
    ritmo(false);
    delay(458.139973958);
    delay(4.82252604167);
    tone(tonePin, 220, 203.992851562);
    ritmo(true);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 246, 203.992851562);
    ritmo(false);
    delay(226.658723958);
    delay(4.82252604167);
    tone(tonePin, 164, 1245.65847656);
    ritmo(true);
    delay(1384.06497396);
    digitalWrite(pinoLedR,LOW);
    digitalWrite(pinoLedG,LOW);
}

void ritmo(boolean ritmo){
  if(ritmo){
    digitalWrite(pinoLedR,HIGH);
    digitalWrite(pinoLedG,LOW);
  }else{
    digitalWrite(pinoLedR,LOW);
    digitalWrite(pinoLedG,HIGH);
  }
}
