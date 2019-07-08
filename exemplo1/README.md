# 1 - Exemplo 1


# 2 - Compilando

java 7 e anteriores:
```sh
javac ClassePrincipal.java
havah ClassePrincipal
g++ -I$JAVA_HOME/include/linux -I$JAVA_HOME/include/ -fPIC -shared ClassePrincipal.cpp -o libbiblioteca1.so
java -cp ./ -Djava.library.path=./ ClassePrincipal
```

java 8:
```sh
javac -h . ClassePrincipal.java
g++ -I$JAVA_HOME/include/linux -I$JAVA_HOME/include/ -fPIC -shared ClassePrincipal.cpp -o libbiblioteca1.so
java -cp ./ -Djava.library.path=./ ClassePrincipal
```
