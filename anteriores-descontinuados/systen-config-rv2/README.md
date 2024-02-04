
# **NOTA:** 

<br>


Pode haver incoerências no processo e ou incompatibilidade nos funcionamentos pois esses arquivos retratam uma versão antiga e descontinuada do robô, eles estão aqui por uma questão de histórico. 

<br><br><br>

# **systen-config-rv2**

<br>

1. Instale es dependências:

```
sudo apt update -y
sudo apt upgrade -y
sudo apt install python3-pip evdev -y


pip3 install evdev 
pip3 install pyserial 
```

2. Com o arquivo `gameped-rv2.py` e `gamepad-rv2-server.service` crie um no sistema por meio do systemctl.

3. Intale o node-red seguindo esses [paços](https://nodered.org/docs/getting-started/raspberrypi).

4. Importe o [flows-JETSON_NANO.json](./flows-JETSON_NANO.json) para o node-red.

### **NOTA:**
Foi utilizado o controle `Ipega 9076` para esse programa.