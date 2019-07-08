# 1 - Exemplo 3

Aqui o JAVA chama um método nativo em C++, porém, o método c++ chama de volta métodos JAVA (Callback), demonstrando que é possível chamar métodos existentes nas 2 plataformas pelas duas plataformas durante a execução.

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

