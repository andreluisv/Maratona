// OPERATIONS

__builtin_popcount(int mask) // retorna a quantidade de bits setados em "mask"
(valor << qtd) // shift left
(valor >> qtd) // shift right
(valor1 & valor2) // and bit-a-bit
(valor1 | valor2) // or bit-a-bit
(valor1 ^ valor2) // xor bit-a-bit
valor = ~valor // not

//Para valores maiores que 109, usar (ll(valor) << qtd)



// TECNICAS

//Marcar um array estado de moedas coletadas. São 15 moeda.

int mask = 0;//inicial nenhuma moeda coletada

//para pegar uma moeda com índice i
mask = mask|(1<<i);

//para saber se um moeda com índice i foi coletada
return (mask&(1<<i));

//trocar o valor de todo mundo
for (int i = 0; i < 15; i++)
	mask = mask^(1<<i);
