# o que é um ficheiro .a

como sabido o compliador gera objetos de cada ficheiro c/c++
Um ficheiro .a é uma static librariy ou seja ele (normalmente) contem vários objetos *.o; quando você usá-lo na linkage, apenas os objetos necessários serão adicionado ao executável da biblioteca.

no momento do linkage, rhexlib colecta os *.o atraves de das static libs: <br>
    hardware/virtual/libvirtualhw.a  <br>
	hardware/common/libcommonhw.a    <br>
	hardware/SimSect/libsimsecthw.a  <br>

# symbolic link

Em computação, uma ligação simbólica (em inglês: symbolic link, soft link ou symlink) é um tipo especial de arquivo que contém uma referência a outro arquivo ou diretório na forma de um caminho absoluto ou relativo e que afeta a resolução do nome de caminho (pathname)

Um link simbólico contém o nome do arquivo ao qual está associado. Caso o arquivo original seja excluído a ligação passará a referir a um arquivo inexistente, resultando em um erro. Uma ligação rígida (hard link) por sua vez, contém uma referência ao conteúdo do antigo caminho, comportando-se, exceto pela data de criação e texto, indistinguível do nome original do arquivo. Mesmo que o arquivo seja excluído pelo nome original do arquivo a ligação rígida permaneceria ligada ao arquivo original

o comando `@$(LN) ../$(@) lib` no makefile, cria uma simbolic link das lib geradas 

# curiosidades sobre mk


`$(@D)`
A parte do diretório do nome do arquivo de destino, com a barra final removida. Se o valor de `"$@"` for dir/foo.o, então `"$(@D)"` será dir. Este valor é . se $@ não contiver uma barra.


`;`
O ponto e vírgula simplesmente permite escrever a primeira linha da receita na mesma linha da lista de pré-requisitos.
Desta forma (dado que suas receitas cabem em uma única linha) você pode escrever um Makefile sem nenhuma tabulação maligna. Não há muito uso nisso de outra forma.

`$(@F)`
A parte do arquivo dentro do diretório do nome do arquivo de destino. Se o valor de `"$@"` for dir/foo.o, então `"$(@F)"` será foo.o. `"$(@F)"` é equivalente a `$(notdir $@)`.

`wc` 
counts the number of lines in each of the source files, headers

`$?`
is used to find the return value of the last executed command. Try the following in the shell:

`$$`
Make precisa distinguir se você quer usar um `"$"` como introdução de uma referência de variável make, como `"${FOOBAR}"` ou como um `"$"`simples passado para o shell. A especificação make (Section Macros) diz que para fazer o último, você deve usar `"$$"` que é substituído por um único `"$"` e passado para o shell.