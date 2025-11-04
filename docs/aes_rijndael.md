# Advanced Encryption Standard (AES)
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
There are 4 main steps in each round
### SubBytes step

