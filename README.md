# Embarcatech_Interrupcoes_LedMatrix
Repositório criado para a Tarefa 2 - Aula Síncrona 29/01 - Atividade 1 - Temporizador Periódico

Aluno: Melk Silva Braga

# Instruções de compilação para o simulador

Para compilar e rodar o código, são necessárias as seguintes extensões: 

*Raspberry Pi Pico*

*Cmake*

*Cmake Tools*

*Wokwi simulator*

Após a compilação, clicar no arquivo "diagram.json" e iniciar a simulação no wokwi.
No terminal poderá ser possível observar uma mensagem a cada segundo (1.000 ms).

# Instruções de compilação para a BitDogLab

Alternativamente, foi adicionado ao repositório o arquivo "codigo_semaforo_bitdoglab.txt" com um código modificado 
para que o programa funcione na placa BitDogLab, visto que o mapeamento GPIO do LED RGB da placa é diferente da 
configuração exigida no wokwi para a atividade, além de que a placa não possui leds de cores independentes (amarelo, 
por exemplo).

Substitua o código do arquivo principal "semaforo" pelo do arquivo .txt, faça a compilação e para
rodar na placa, é necessário conectá-la via cabo usb em modo bootsel e ter instalado o driver 
WinUSB (v6.1.7600.16385) na interface 1. Só então clicar em "Run Project", na extensão Raspberry Pi Pico.

No Serial Monitor do VSCode, selecionar a porta correta e clicar em "Start Monitoring" para observar uma mensagem 
a cada segundo (1.000 ms).

# Vídeo demonstrativo do semáforo funcionando na BitDogLab
https://youtube.com/shorts/B1xFO1oaVs8?feature=share