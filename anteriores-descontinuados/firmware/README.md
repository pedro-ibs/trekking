# **Firmware**


1. [**`NANO_BLE_33S`**](./NANO_BLE_33S): Auxiliar na aquisição de dados dos sensores.

2. [**`RPI_PICO_SDK`**](./RPI_PICO_SDK/): Controle dos motores e possível modulo de expansão. Tem acesso aos drivers dos motores portando responsável pelo controle dos mesmos.



## **Componentes**

O Trekking é composto por alguns dispositivo dentre sensores e computador e microcontroladores:


 * [Raspberry Pi 3 Model B](https://www.raspberrypi.com/products/raspberry-pi-3-model-b/)
 * [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/)
 * [Arduino Nano 33 BLE Sense](https://docs.arduino.cc/hardware/nano-33-ble-sense)
   * [IMU 9 Eixos LSM9DS1](https://content.arduino.cc/assets/Nano_BLE_Sense_lsm9ds1.pdf)
   * [Barometro LPS22HB](https://content.arduino.cc/assets/Nano_BLE_Sense_lps22hb.pdf)
   * [Sensor de Temperaura e Umidade HTS221](https://content.arduino.cc/assets/Nano_BLE_Sense_HTS221.pdf)
   * [Sensor de Gestos APDS-9960](https://content.arduino.cc/assets/Nano_BLE_Sense_av02-4191en_ds_apds-9960.pdf)
   * [Microfone MP34DT05](https://content.arduino.cc/assets/Nano_BLE_Sense_mp34dt05-a.pdf)
 * [GPRS GT-U7](https://manuals.plus/goouuu/goouuu-tech-gt-u7-gps-modules.pdf)
 * [Sensor de distância CJVL53L0XV2 / VL53L0X](https://www.st.com/resource/en/datasheet/vl53l0x.pdf)
 
 
 
 
 Esses dispositivo estão interconectados através das comunicações serias *usart*, *i2c* e *swd* como mostra o diagrama abaixo:
 
 
  ![Rede de conexão entre os sensores e dispositivos do trekking](conexao.drawio.png)
