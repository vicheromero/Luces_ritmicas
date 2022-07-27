# Luces_ritmicas
## Descripción general
Luces ritmicas en arduio MEGA 2560 con 8 salidas hacia optoacopladores independientes. La señal de ingreso será el audio que deberá limitarse a 5V para luego proceder con el ADC (0-1023) para encender las 8 salidas dependiendo del nivel regulado a través de un potenciómetro para cada salida.

## Funcionamiento
- Se usa el conversor A/D A0 para leer la señal de audio.

- Conversor A/D A0 de 10bits -> 0 a 1023.

- El tiempo de conversión del A/D A0 hasta 100us.

NOTA: La Frecuencia de salida de los PWM = 490Hz. En Arduino Mega los pines 2-13, 44-46 funcionan a 490Hz (pines 4 y 13: 980Hz).

ES POSIBLE CAMBIAR LA FRECUENCIA DE LOS RELOJES PERO EL CORE DE ARDUINO USA UNA CONFIGURACION PREDETERMINADA DE PRE-ESCALADORES EN LOS RELOJES INTERNOS, ASI QUE SE DEBE TENER MUCHO CUIDADO. POR ESTE MOTIVO SE ESCOGE LOS TIMER 1, 2, 3 Y 4.

## Variables generales
```
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
```
