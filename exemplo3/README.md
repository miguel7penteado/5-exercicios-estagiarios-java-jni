# 1 - Exemplo 3

# 2 - Compilando

java 7 e anteriores:
```sh
javac MinhaClasse.java
javah MinhaClasse
g++ -I$JAVA_HOME/include/linux -I$JAVA_HOME/include/ -fPIC -shared MinhaClasse.cpp -o libbiblioteca_padrao.so
java -cp ./ -Djava.library.path=./ MinhaClasse
```

java 8:
```sh
javac -h . MinhaClasse.java
g++ -I$JAVA_HOME/include/linux -I$JAVA_HOME/include/ -fPIC -shared MinhaClasse.cpp -o libbiblioteca_padrao.so
java -cp ./ -Djava.library.path=./ MinhaClasse
```

