# Advanced Encryption Standard (AES)
(based on [wikipedia](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard#The_SubBytes_step) )
## Description
AES has a fixed block size : 128, 192 or 256 bits. 
In AES, we work with 4x4 matrices : 
```math
\begin{pmatrix}
b_0 & b_4 & b_8 & b_12 \\
b_1 & b_5 & b_9 & b_13 \\
b_2 & b_6 & b_10 & b_14 \\
b_3 & b_7 & b_11 & b_15
\end{pmatrix}
```
The number of rounds depends on the block size : 
* 128 -> 10 rounds
* 192 -> 12 rounds
* 256 -> 14 rounds
There are 4 main steps in each round
### SubBytes step
Each byte in the state array becomes a new byte using a subsistution box. 
-> Provides non linearity in cipher
To perform decryption : InvSubBytes step
### ShiftRows step
It cyclically shifts the bytes in each row by a certain offset. 
* First row : 0
* Second row : 1 (to the left)
* Third row : 2 (to the left)
* Fourth row : 3 (to the left)
-> Avoids the column being encrypted independently
### MixColumns step
The four bytes of each column are combined using an invertible linear transformation
Input : 4 bytes
Output : 4 bytes
-> Each input byte affects all output bytes. 
-> Provides diffusion in cipher (with ShiftRows)
Each column is transformed using a fixed matrix
```math
\begin{pmatrix}
b_{0j} \\
b_{1j} \\
b_{2j} \\
b_{3j} \\
\end{pmatrix}
=
\begin{pmatrix}
2 & 3 & 1 & 1 \\
1 & 2 & 3 & 1 \\
1 & 1 & 2 & 3 \\
3 & 1 & 1 & 2 \\
\end{pmatrix}
\begin{pmatrix}
a_{0j} \\
a_{1j} \\
a_{2j} \\
a_{3j} \\
\end{pmatrix}
\qquad 0 \leq j \leq 3
```
Addition is simply XOR and multiplication is modulo x^8 + x^4 + x^3 + x + 1
### AddRoundKey step
the subkey is combined with the state. It is added by combining with XOR. 
