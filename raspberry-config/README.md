# **CONFIGURAÇÕES**


1. Instale es dependências:

```
sudo apt update -y
sudo apt upgrade -y
sudo apt install python3-pip evdev -y


pip3 install evdev 
pip3 install pyserial 
```

2. copie o arquivo `gameped.py` para o diretório:

```
mkdir -p ~/trekking
cp gameped.py ~/trekking/gameped.py
```

3. Terne o arquivo executável:

```
sudo chmod +x ~/trekking/gameped.py
```

4. edite o arquivo `/etc/rc.local` antes da linha com o comando `exit` e insira o seguinte comando:
```
sudo python3  ~/trekking/gameped.py &
```

5. Reinicie a raspberry e logo após um tempo insira o adaptador do controle ela irá reconhecer automaticamente 


### **NOTA:**
Foi utilizado o controle `Ipega 9076` para esse programa.