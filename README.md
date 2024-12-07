# MedTrack

Este projeto utiliza um Arduino para monitorar o uso de um dispenser, detectando movimentos e proximidade de pessoas, e registrando a quantidade de vezes que o dispenser foi utilizado. Ele combina sensores PIR e ultrassônicos com um botão e um buzzer para criar um sistema interativo.

## Funcionalidades

- **Sensor Ultrassônico**: Detecta a proximidade de uma pessoa em até 20 cm.
- **Sensor PIR**: Detecta movimentos próximos ao dispenser.
- **Botão**: Contabiliza o número de utilizações do dispenser.
- **Buzzer**: Emite um som ao registrar uma utilização.
- **Serial Monitor**: Exibe informações em tempo real, como a distância medida, detecção de movimento e total de usos registrados.

## Componentes Utilizados

1. **Microcontrolador**: Arduino (qualquer modelo compatível).
2. **Sensor Ultrassônico**: HC-SR04.
3. **Sensor PIR**: Para detecção de movimento.
4. **Botão**: Para interação física e registro de utilizações.
5. **Buzzer**: Para sinalização sonora.
6. **Jumpers e Protoboard**: Para conexões.

## Esquema de Conexão

| Componente       | Pino no Arduino |
|-------------------|-----------------|
| Buzzer           | 5               |
| Sensor PIR       | 23              |
| Botão            | 14              |
| Trigger (HC-SR04)| 13              |
| Echo (HC-SR04)   | 12              |

## Código

O código utilizado está no arquivo `dispenser_monitor.ino`. Ele realiza as seguintes ações:
1. Mede a distância com o sensor ultrassônico.
2. Verifica a detecção de movimento com o sensor PIR.
3. Registra uma utilização ao pressionar o botão e emite um som com o buzzer.
4. Exibe as informações no Serial Monitor.

## Como Utilizar

1. Monte o circuito de acordo com o esquema de conexão.
2. Carregue o código `dispenser_monitor.ino` na placa Arduino utilizando a IDE Arduino.
3. Abra o Serial Monitor para acompanhar as informações em tempo real.
4. Interaja com o sistema:
   - Aproximando-se do sensor.
   - Pressionando o botão para registrar utilizações.

## Depuração

Para facilitar a depuração, o código exibe no Serial Monitor:
- Distância medida pelo sensor ultrassônico.
- Estado do sensor PIR (detectando ou não movimento).
- Estado do botão (pressionado ou não).
- Ativação e desativação do buzzer.

## Possíveis Melhorias

- Adicionar um display para exibir o número de utilizações diretamente no dispositivo.
- Incorporar conectividade IoT para envio de dados em tempo real para um servidor ou aplicativo.

---

**Autores**: Desenvolvido com base em solicitações e orientações fornecidas.
"""

# Caminho do arquivo a ser salvo
file_path = "/mnt/data/README.md"

# Salvando o arquivo
with open(file_path, "w") as file:
    file.write(readme_content)

file_path
