# 1 - Exemplo 2

Neste exemplo, fazemos o java evocar uma biblioteca C++ para fazer a soma ordinária de 2 números.

# 2 - Compilando

java 7 e anteriores:
```sh
javac Matematica.java
javah Matematica
g++ -I$JAVA_HOME/include/linux -I$JAVA_HOME/include/ -fPIC -shared Matematica.cpp -o libbiblioteca_soma.so
java -cp ./ -Djava.library.path=./ Matematica
```

java 8:
```sh
javac -h . Matematica.java
g++ -I$JAVA_HOME/include/linux -I$JAVA_HOME/include/ -fPIC -shared Matematica.cpp -o libbiblioteca_soma.so
java -cp ./ -Djava.library.path=./ Matematica
```

