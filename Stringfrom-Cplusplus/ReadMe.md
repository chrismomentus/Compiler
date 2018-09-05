Usando strings do C++

Podemos usar as strings do C++. Para isso, basta incluir o arquivo <string> (sem o ".h") e acrescentar o comando "using namespace std;". Os operadores de atribuição e adição estão definidos para string, assim como os operadores relacionais <, >, <=, >=, == e !=.


Se for necessário obter um "char *" de uma string, use o método c_str(). Mas tenha em mente que se a string for alterada esse ponteiro pode se invalidado. Uma forma de prevenir isso é usar esse método apenas como parâmetro de função.
