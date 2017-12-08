
int pTrig = 2;
int pEcho = 3;
int pTrig2 = 4;
int pEcho2 = 5;
int buzz = 12;
int mod=0;

long odezva;
long odezva2;
long vzdalenost;
long vzdalenost2; 

long currentTime = 0;
long lastBeep = 0;

int freguency = 392;
void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  pinMode(pTrig2, OUTPUT);
  pinMode(pEcho2, INPUT);
  
  Serial.begin(9600);
  
}

void loop(){
  getDistance();
  writeDistance();
  currentTime = millis();
    if(vzdalenost<100 || vzdalenost2<100){
      if(mod==0){
        
        soundDistance();
      }else if (mod==1){
          
      }else if (mod==2){
        
      }
  }
}
void getDistance(){
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig, LOW);
  
  odezva = pulseIn(pEcho, HIGH);
  
  digitalWrite(pTrig2, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig2, LOW);

  odezva2 = pulseIn(pEcho2, HIGH);
  if((odezva / 58.31)<1500){
    vzdalenost = odezva / 58.31;
    }
  if((odezva / 58.31)<1500){
    vzdalenost2 = odezva2 / 58.31;
    }
}
void writeDistance(){
  }
void soundDistance(){
  int minimal;
  if(vzdalenost > vzdalenost2){
    minimal = vzdalenost2;
   }else{
    minimal = vzdalenost;
    }
  if((millis()-lastBeep)> vzdalenost*4 ){
     tone(12, 440, 50);
     lastBeep = millis();
    }
  
  }
