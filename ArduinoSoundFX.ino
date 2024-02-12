/*
 *  SoudFX
 *  Daniel Chagas
 *  
 *  Faz efeitos sonoros. Ao clicar no botão muda o padrão de som.
 *  O botão pushButton deve ser conectado entre o ground (GND) e o pino 3.
 *  
 */

int piezoPin = 11;
int pushButton = 3; // declara o push button na porta 2
int x = 0;

void setup(){
  pinMode(piezoPin,OUTPUT);
  pinMode(pushButton, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(pushButton)==LOW){
    x = x+1; //incrementa o valor de Xis
    if(x>5) x=0; //zera o valor de Xis caso passe de cinco
    delay(500); //forma de debounce simples
  }
  escolheEfeito();
}

void soundFX(float num,float period) {
  int fxdelay=num+num*sin(millis()/period);
  for(int i=0;i<5;i++){
      digitalWrite(piezoPin,HIGH);
      delayMicroseconds(fxdelay);
      digitalWrite(piezoPin,LOW);
      delayMicroseconds(fxdelay);
    }
}

void escolheEfeito(){
  switch(x){
    case 0:
      soundFX(50,50);
      break;
    case 1:
      soundFX(1000,100);
      break;
    case 2:
      soundFX(200,29);
      break;
    case 3:
      soundFX(700,1000);
      break;
    case 4:
      soundFX(50,10);
      break;
    case 5:
      soundFX(300,100);
      break;
    default:
      digitalWrite(piezoPin,LOW);
      break;
  }
}
