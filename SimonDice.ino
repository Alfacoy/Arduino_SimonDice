//VARIABLES
int luces[] = {2,3,4,5};
int buzz = 6;
int dice[99];
int turno = 0;
int turnoJugador = 0; 
int numRandom;
int ultimoNumero = -1;
int cantidadRepeticiones = 0;
bool usuario = true;
bool perdio = false;

int uno = 0;
int dos = 0;
int tres = 0;
int cuatro = 0;

//FUNCIONES
void sonido();
void simon();

//PROGRAMA
void setup() {
  pinMode(luces[0], OUTPUT);
  pinMode(luces[1], OUTPUT);
  pinMode(luces[2], OUTPUT);
  pinMode(luces[3], OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(buzz,OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  
  for(int i = 0; i < 99; i++){
    Serial.println();
    Serial.println();
    Serial.print("================================================");
    Serial.println(); 
    Serial.print("RONDA N°");
    Serial.print(i);
    Serial.println();
    Serial.print("================================================");
    Serial.println(); 
    
    //AGREGAMOS LUCES NUEVAS AL "DICE" VALIDANDO QUE NO SE REPITA MÁS DE 4 VECES EL ÚLTIMO NÚMERO
    while(cantidadRepeticiones < 5){
      numRandom = random(4);
      Serial.print("Número Actual: ");
      Serial.print(numRandom);
      Serial.println();
      Serial.print("Ultimo:");
      Serial.print(ultimoNumero);
      Serial.println();
      if(numRandom == ultimoNumero){
        cantidadRepeticiones++;
        Serial.print("Repeticiones: ");
        Serial.print(cantidadRepeticiones);
        Serial.println();
        if(cantidadRepeticiones >= 3){
          continue;          
        }
        break;        
      }else{
        ultimoNumero = numRandom;
        cantidadRepeticiones = 0;
        break;
      }
    }
  
    //AGREGAMOS EL NÚMERO RANDOM AL ARRAY
    dice[i] = numRandom;  
    Serial.print("================================================");
    Serial.println();
    Serial.print("INICIO NUMEROS DEL ARRAY --> Turno n°: ");
    Serial.print(turno);
    Serial.println();
    Serial.print("================================================");    
    Serial.println();  

    for(int x = 0; x <= turno; x++){
      //MOSTRAR LAS LUCES QUE TIENE EL DICE
      digitalWrite(luces[dice[x]],HIGH);
      delay(500);
      digitalWrite(luces[dice[x]],LOW);
      delay(500);
      
      Serial.print("N°");
      Serial.print(x);
      Serial.print(":");
      Serial.print(dice[x]);
      Serial.println();
    }

    Serial.print("================================================");
    Serial.println();
    Serial.print("FIN NUMEROS DEL ARRAY ");
    Serial.println();
    Serial.print("================================================");   
    Serial.println(); 
    
    //USUARIO INGRESA VALORES Y UNA FUNCIÓN SE ENCARGA DE VALIDAR. DE IR BIEN DEJA QUE SIGA RUMBO, DE ERRRAR, ACTIVA UNA FLAG Y LO SACA DEL BUCLE + ACTIVA LA PERDIDA.
    Serial.print("TU TURNO ");
    Serial.println();
    while(usuario) {
      uno = digitalRead(8);
      dos = digitalRead(9);
      tres = digitalRead(10);
      cuatro = digitalRead(11);

      if(turnoJugador <= turno){
          if(uno){
            Serial.print("UNO");
            Serial.println();
            usuario = simon(dice, turnoJugador,0);
          if(!usuario){
            perdio = true;
            Serial.print("PERDISTEEE");
            Serial.println();
          }
          turnoJugador++; 
          Serial.print("TURNO JUGADOR ");
          Serial.print(turnoJugador);
          Serial.println();    
        }
        
        if(dos){
            Serial.print("DOS");
            Serial.println();
            usuario = simon(dice, turnoJugador,1);
          if(!usuario){
            perdio = true;
            Serial.print("PERDISTEEE");
            Serial.println();
          }
          turnoJugador++;
          Serial.print("TURNO JUGADOR ");
          Serial.print(turnoJugador);
          Serial.println();
        }

        if(tres){
            Serial.print("TRES");
            Serial.println();
            usuario = simon(dice, turnoJugador,2);
          if(!usuario){
            perdio = true;
            Serial.print("PERDISTEEE");
            Serial.println();
          }
          turnoJugador++;
          Serial.print("TURNO JUGADOR ");
          Serial.print(turnoJugador);
          Serial.println();
        }
        
        if(cuatro){
            Serial.print("CUATRO");
            Serial.println();
            usuario = simon(dice, turnoJugador,3);
          if(!usuario){
            perdio = true;
            Serial.print("PERDISTEEE");
            Serial.println();
          }
          turnoJugador++;
          Serial.print("TURNO JUGADOR ");
          Serial.print(turnoJugador);
          Serial.println(); 
        }     
      } else {
        usuario = false;
      }
      delay(145);
    }

    if(perdio) {
      perdio = false;
      tone(buzz,269);
      delay(1000);
      noTone(buzz);
      break;
    }

    //FINALIZAR EL TURNO
    turno++;
    usuario = true;
    turnoJugador = 0;
    tone(buzz,269);
    delay(250);
    noTone(buzz);
  }

  ultimoNumero = -1;
  turno = 0;  
  turnoJugador = 0;
  usuario = true;
}

//FUNCIONES DEL SISTEMA
bool simon(int arr[], int num, int sel){
  bool status;
  Serial.println();
  Serial.print("SIMON DIJO: ");
  Serial.print(dice[num]);  
  Serial.println();
  Serial.print("USUARIO SELECCIONO: ");
  Serial.print(sel);  
  Serial.println();
  digitalWrite(luces[sel],HIGH);
  delay(500);
  digitalWrite(luces[sel],LOW);

  if(dice[num] == sel){
    return status = true;
  } else  {
    return status = false;    
  }
}

/* void mensaje(char const *text, int num) {
  if(!num) {
    Serial.print(text);   
    Serial.println();      
  }else{
    Serial.print(text + " " +  String(num));   
    Serial.println();  
  }
}  */

//SI SALE MAS DE 3 VECES UN MISMO NÚ  MERO PIDO QUE SE VUELVA A TIRAR LOS DADOS.

/*

  if(randi == 3) {
      //sonido();
      delay(1000);
    }


  for(int i = 0; i <= 3; i++){
    digitalWrite(Luces[i],HIGH);
    delay(500);
    digitalWrite(Luces[i],LOW);
    delay(500);
    if(i == 3){
      i = -1;
    }
  }
*/





/*void sonido() {
   tone(8,249); 
  delay(165);
  noTone(8);

  delay(95);
  
  tone(8,249); 
  delay(80);
  noTone(8);

  tone(8,369); 
  delay(350);
  noTone(8);

  delay(1000);
}
*/


/*
TONO GANADOR
 /*if(uno){
        digitalWrite(luces[0],uno); 
        uno = LOW; 
        tone(6,259); 
      }  

      if(dos){
        digitalWrite(luces[1],dos); 
        dos = LOW; 
        tone(6,259); 
      }  

      if(tres){
        digitalWrite(luces[2],tres); 
        tres = LOW; 
        tone(6,259); 
      }  

      if(cuatro){
        digitalWrite(luces[3],cuatro); 
        cuatro = LOW; 
        tone(6,259); 
      }  

      delay(250);
      noTone(6);

      digitalWrite(luces[0],uno);
      digitalWrite(luces[1],dos); 
      digitalWrite(luces[2],tres);
      digitalWrite(luces[3],cuatro);*/
