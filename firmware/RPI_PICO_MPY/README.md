# **Firmware**

## Preparando Raspberry pi pico

Siga os paços definidos [aqui](https://www.raspberrypi.com/documentation/microcontrollers/micropython.html) para a gravação do Micro Python na Raspberry Pi Pico, para mais informações veja o [Python SDK](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-python-sdk.pdf).

<br>

### **Protocolo**

Como carácteres especiais São utilizados **`:`** e **`/`** sendo que **`:`** divide os argumentos e **`/`** finaliza o pacote e sinaliza para o driver que o comando pode ser executado. O protocolo carrega o comando a ser executado e os valores dos pwm divididos pelo caractere **`:`** e finalizado pelo caractere **`/`**, a tabela a seguir mostra  possibilidades de comandos:

<br>


**Comando**	| **PWM Polo A/B** 	| **PWM Polo B**	| **Descrição**
:-------------- | :-------------------- | :-------------------- | :---------------
**`x`**		| X			| X 			| Reinicia o Driver	
**`s`**		| X			| X 			| Desliga os motores
**`f`**		| 0 - 65535		| X 			| Robô para frente
**`b`**		| 0 - 65535		| X 			| Robô para traz
**`l`**		| 0 - 65535		| X 			| Robô gira para esquerda
**`L`**		| 0 - 65535		| 0 - 65535 		| Controla conjunto esquerdo
**`r`**		| 0 - 65535		| X 			| Robô gira para direita
**`R`**		| 0 - 65535		| 0 - 65535 		| Controla conjunto direito	

<br>

Os comandos  **`R`** e **`L`** os pares de motores de cada lado, possível controlar não somente a intensidade do giro como também o sentido, Além disso esses comando usados em conjunto pode fazer o bobô ter uma trajetória curva.

<br>

O comando **`x`** simplesmente faz a driver esperar por 3 segundos dando tempo para que o `watchdog` reinicia e placa. E o comando **`s`** desliga os motores escrevendo 0 em todos os polos do motores

<br>

Caso o protocolo tenha algum ruido ou má formação e isso ocasionar na trava do código python o `watchdog` reiniciara a placa.

<br>

**Exemples de comandos:**
```
x:0/
s:0/
f:30000/
b:10000/
l:40000/
L:30000:0/
r:30000/
R:10000:65535/

```

## **Implementações Futuras**
 * Medição das alimentações
 * Medição das velocidades de cada motor





