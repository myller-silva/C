from os import system
from time import sleep

def preencher(a):
    for c in range (0, 9):
        a[c] = '_'

def exibir(a):
    for c in range(0, 9):
        if c%3==0:
            print('\n')
        print(f'{a[c]}\t', end='')
    print('\n\n')

def win(j):
    for c in range(0, 9, 3):
        if (j[c] != '_' ) and (j[c]==j[c+1]==j[c+2]) :
            return 1
    for c in range(0, 3):
        if (j[c] != '_' ) and (j[c]==j[c+3]==j[c+6]) :
            return 1
    if (j[0] != '_') and (j[0]==j[4]==j[8]):
        return 1
    elif ((j[2] != '_') and (j[2]==j[4]==j[6])):
        return 1
    return 0
j = {}
vencedor = -1
preencher(j)

c = 0
while c<9:
    system('cls')
    exibir(j)
    esc = int(input(f"Jogador N{(c%2)+1}: "))
    if esc>8 or esc<0 or j[esc] == None:
        print("Posicao invalida, tente novamente.")
        sleep(2)
        continue
    if (c%2==0):
        j[esc] = 'X'
    else:
        j[esc] = '0'
    if(win(j)):
        vencedor = (c%2)+1
        break
    c += 1

system('cls')
exibir(j)
if(vencedor == -1):
    print("Empate")
else:
    print(f"Vencedor: Jogador N{vencedor}\n\n")
