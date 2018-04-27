//#include <BitbloqSoftwareSerial.h>

//boolean obtenPresencia(String cv, bqSoftwareSerial & phone){
//  phone.println(String("obtenPresencia-")+String(cv));
//  String data="";
//  boolean result =false;
//  while(data==""){
//    data=phone.readString(); 
//  }
//  if(data.indexOf("true") >= 0){
//    result=true;
//  }else{
//    result=false;
//  }
//  return result;
//}
//
//float obtenBrillo(bqSoftwareSerial & phone){
//  phone.println(String("obtenBrillo-"));
//  String data="";
//  while(data==""){
//    data=phone.readString();
//  }
//  return data.toFloat();
//}
//
//bqSoftwareSerial puerto_serie(0,1,9600);
//bqSoftwareSerial bluetooth_de_la_placa(0, 1, 19400);

#include <Servo.h>

char command;
String string;
boolean ledon = false;
Servo miservo;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
  miservo.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    string = "";}
  
  while(Serial.available() > 0) {
    command = ((byte)Serial.read());
      if(command == ':') {
        break;
      }
      else {
        string += command;
      }
      delay(1);
  }
  
  
  String dato=string.substring(2, 5);
  //Serial.println(dato);
  delay(1000);
  if(string.indexOf("TO")>=0) {
    ledOn();
    ledon = true;
  }
  if(string.indexOf("TF")>=0) {
    ledOff();
    ledon = false;
    //bluetooth_de_la_placa.println(string); //debug
  }
  if(string.indexOf("BR")>=0){
     //String dato = string.substring(2, end_line_index);
    int dato_num = dato.toInt();
    //Serial.println(dato_num);
//    if(dato_num<50){
//       miservo.write(180);
//    }else{
//       miservo.write(90);
//    }
  }
  if(string.indexOf("PR")>=0){
     if(string.indexOf("lib")>0){
        mandaComando("im1");    
     } else {
        mandaComando("im2");
     }
  }
  
  delay(100);
  mandaComando("brillo");
  delay(500);
  mandaComando("acc");
  delay(500);
  mandaComando("pres");
  delay(500);
  //mandaComando("cam");
  //delay(1000);
  //mandaComando("im1");
  //delay(100);
  dato="";   
}

void mandaComando(String comando){
  Serial.print('#');
  Serial.print(comando);
  Serial.print('~');
  Serial.println();
  delay(10);
}

 
void ledOn(){
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(10);
}
  
void ledOff(){
  digitalWrite(LED_BUILTIN, LOW); 
  delay(10);
}

