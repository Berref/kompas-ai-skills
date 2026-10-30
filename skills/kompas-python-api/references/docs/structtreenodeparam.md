# TreeNodeParam - Структура параметров узла дерева библиотеки документов, библиотеки атрибутов

[Структуры параметров и константы](3d_define.html) > [Структуры параметров библиотек ](bk1803365.html) |  Scroll [ [ [ ](structtreenodeparamw.html "К следующему разделу")](bk1803365.html "На уровень выше")](structlibrarystyleparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTreeNodeParam](kstreenodeparam.html).

long | type | \- тип узла: корень, папка, файл (из [LtNodeType ](ltnodetype.html)),  
---|---|---  
char | name [MAX_TEXT_LENGTH] | \- имя узла,  
reference | comment | \- комментарий - динамический массив CHAR_STR_ARR (динамический массив строк символов),  
reference | nodes | \- динамический массив узлов [TreeNodeParam.](structtreenodeparam.html)  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [TreeNodeParamW](structtreenodeparamw.html).

Подразделы:

(отсутствуют)
