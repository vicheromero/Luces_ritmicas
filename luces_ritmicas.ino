/*
 * Luces rítmicas con arduino
 * 
 * Se usa el conversor A/D A0 para leer la señal de audio
 * Conversor A/D de 10bits -> 0 a 1023
 * Tiempo de conversión hasta 100us
 * 
 * NOTA: Frecuencia PWM = 490Hz
 * En Arduino Mega 2-13, 44-46 (pines 4 y 13: 980Hz)
 * NO ES POSIBLE CAMBIAR LA FRECUENCIA PORQUE 
 * EL CORE DE ARDUINO USA UNA CONFIGURACION PREDETERMINADA
 * DE PRE-ESCALADORES EN LOS RELOJES INTERNOS
 */
int leer_audio = A0; //Conversor de ingreso del audio
int salida1 = 2; //Pin salida hacia el optoacoplador
int salida2 = 3; //Pin salida hacia el optoacoplador
int salida3 = 5; //Pin salida hacia el optoacoplador
int salida4 = 6; //Pin salida hacia el optoacoplador
int salida5 = 7; //Pin salida hacia el optoacoplador
int salida6 = 8; //Pin salida hacia el optoacoplador
int salida7 = 9; //Pin salida hacia el optoacoplador
int salida8 = 10; //Pin salida hacia el optoacoplador
int tiempo_entre_muestreo = 10; //Tiempo de separación entre cada muestreo de audio
int analogo_audio_1023 = 0;
int analogo_audio_255 = 0;

void setup() 
{ 
pinMode(salida1, OUTPUT);
pinMode(salida2, OUTPUT); 
pinMode(salida3, OUTPUT); 
pinMode(salida4, OUTPUT); 
pinMode(salida5, OUTPUT); 
pinMode(salida6, OUTPUT); 
pinMode(salida7, OUTPUT); 
pinMode(salida8, OUTPUT);

// Set PWM frequency for D11 & D12 -----------------------------
//TCCR1B = TCCR1B & B11111000 | B00000001;    // set timer 1 divisor to     1 for PWM frequency of 31372.55 Hz
//TCCR1B = TCCR1B & B11111000 | B00000010;    // set timer 1 divisor to     8 for PWM frequency of  3921.16 Hz
//TCCR1B = TCCR1B & B11111000 | B00000011;    // set timer 1 divisor to    64 for PWM frequency of   490.20 Hz
//TCCR1B = TCCR1B & B11111000 | B00000100;    // set timer 1 divisor to   256 for PWM frequency of   122.55 Hz
//TCCR1B = TCCR1B & B11111000 | B00000101;    // set timer 1 divisor to  1024 for PWM frequency of    30.64 Hz
//Set PWM frequency for D9  D10 ------------------------------
//TCCR2B = TCCR2B & B11111000 | B00000001;    // set timer 2 divisor to     1 for PWM frequency of 31372.55 Hz
//TCCR2B = TCCR2B & B11111000 | B00000010;    // set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz
//TCCR2B = TCCR2B & B11111000 | B00000011;    // set timer 2 divisor to    32 for PWM frequency of   980.39 Hz
//TCCR2B = TCCR2B & B11111000 | B00000100;    // set timer 2 divisor to    64 for PWM frequency of   490.20 Hz
//TCCR2B = TCCR2B & B11111000 | B00000101;    // set timer 2 divisor to   128 for PWM frequency of   245.10 Hz
//TCCR2B = TCCR2B & B11111000 | B00000110;    // set timer 2 divisor to   256 for PWM frequency of   122.55 Hz
//TCCR2B = TCCR2B & B11111000 | B00000111;    // set timer 2 divisor to  1024 for PWM frequency of    30.64 Hz
// Set PWM frequency for D2, D3 & D5 ---------------------------
//TCCR3B = TCCR3B & B11111000 | B00000001;    // set timer 3 divisor to     1 for PWM frequency of 31372.55 Hz
//TCCR3B = TCCR3B & B11111000 | B00000010;    // set timer 3 divisor to     8 for PWM frequency of  3921.16 Hz
//TCCR3B = TCCR3B & B11111000 | B00000011;    // set timer 3 divisor to    64 for PWM frequency of   490.20 Hz
//TCCR3B = TCCR3B & B11111000 | B00000100;    // set timer 3 divisor to   256 for PWM frequency of   122.55 Hz
//TCCR3B = TCCR3B & B11111000 | B00000101;    // set timer 3 divisor to  1024 for PWM frequency of    30.64 Hz
// Set PWM frequency for D6, D7 & D8 ---------------------------
//TCCR4B = TCCR4B & B11111000 | B00000001;    // set timer 4 divisor to     1 for PWM frequency of 31372.55 Hz
//TCCR4B = TCCR4B & B11111000 | B00000010;    // set timer 4 divisor to     8 for PWM frequency of  3921.16 Hz
//TCCR4B = TCCR4B & B11111000 | B00000011;    // set timer 4 divisor to    64 for PWM frequency of   490.20 Hz
//TCCR4B = TCCR4B & B11111000 | B00000100;    // set timer 4 divisor to   256 for PWM frequency of   122.55 Hz
//TCCR4B = TCCR4B & B11111000 | B00000101;    // set timer 4 divisor to  1024 for PWM frequency of    30.64 Hz
} 

void loop() {
  // put your main code here, to run repeatedly:
  analogo_audio_1023 = analogRead(leer_audio);
  analogo_audio_255 = map (analogo_audio_1023, 0, 1023, 0, 255);
  analogWrite(salida1, analogo_audio_255);
  delay(10000);
  
}
