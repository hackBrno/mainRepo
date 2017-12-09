int pTrig = 2;
int pEcho = 3;
int pTrig2 = 4;
int pEcho2 = 5;
int buzz = 12;

int releMotor=8;

int buttonMod=9;
int buttonPlus=10;
int buttonMinus=11;
int buttonGPS=6;

int posunVzdalenosti=5;

long minVzdalenost=20;
long maxVzdalenost=200;

int maxMod=3;

int aktButton=0;

long buttonDelay=500;
long lastButtonPressed=0;

int mod=0;

long odezva;
long odezva2;
long vzdalenost;
long vzdalenost2; 
int minimal;

long currentTime = 0;
long lastBeep = 0;

long minimalniVzdalenost=100;

int freguency = 392;
void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  pinMode(pTrig2, OUTPUT);
  pinMode(pEcho2, INPUT);

  pinMode(buttonMod, INPUT);
  pinMode(buttonPlus, INPUT);
  pinMode(buttonMinus, INPUT);
  pinMode(buttonGPS, INPUT);

  pinMode(releMotor, OUTPUT);
  digitalWrite(releMotor, HIGH);
  
  Serial.begin(9600);
}

void loop(){
  getDistance();
  currentTime = millis();
  parseButtons();
    if(vzdalenost<minimalniVzdalenost || vzdalenost2<minimalniVzdalenost){
      if(mod==0){
        soundDistance();
      }else if (mod==1){
        vibrationDistance();
      }else if (mod==2){
        soundDistance();
        vibrationDistance();        
      }
  }
  else{
    digitalWrite(releMotor, HIGH);
  }
}

void parseButtons(){
  if(aktButton==0){
    if(digitalRead(buttonMod)==1){
      aktButton=1;
    }
    else if(digitalRead(buttonPlus)==1){
      aktButton=2;
    }
    else if(digitalRead(buttonMinus)==1){
      aktButton=3;
    }
    else if(digitalRead(buttonGPS)==1){
      aktButton=4;
    }
  }
      
  if(millis()-lastButtonPressed>buttonDelay){
    //Serial.println(9);
    bool smaz=true;
    if(aktButton==1){
      if(mod==maxMod){
        mod=0;
      }
      else{
        mod++;
      }
      Serial.println(mod);
    }
    else if(aktButton==2){
      if(minimalniVzdalenost<maxVzdalenost){
        minimalniVzdalenost+=posunVzdalenosti;
        Serial.println(minimalniVzdalenost);
      }
    }
    else if(aktButton==3){
      if(minimalniVzdalenost>minVzdalenost){
        minimalniVzdalenost-=posunVzdalenosti;
        Serial.println(minimalniVzdalenost);
      }
    }
    else if(aktButton==4){
      vypisGPS();
    }
    else{
      smaz=false;
    }

    if(smaz==true){
      aktButton=0;
    }

    lastButtonPressed=millis();
  }
}

void vypisGPS(){
  Serial.println("GPS poloha: Brno Vozovna komín 666 - 69 - 420 bitch!");
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
  if((odezva2 / 58.31)<1500){
    vzdalenost2 = odezva2 / 58.31;
    }
}

void vibrationDistance(){
  digitalWrite(releMotor, LOW);
}

void soundDistance(){
  if(vzdalenost > vzdalenost2){
    
      minimal = vzdalenost2;
   
   }else{
     minimal = vzdalenost;
       
    }
    //Serial.println(minimal);
  if((millis()-lastBeep)> minimal*3 ){
     tone(12, 440, 10);
     lastBeep = millis();
    }
  }
