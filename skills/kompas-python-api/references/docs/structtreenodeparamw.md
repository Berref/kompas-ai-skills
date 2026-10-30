# TreeNodeParamW - Структура параметров узла дерева библиотеки документов, библиотеки атрибутов (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров библиотек ](bk1803365.html) |  Scroll [ [ [ ](bk1803366.html "К следующему разделу")](bk1803365.html "На уровень выше")](structtreenodeparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTreeNodeParam](kstreenodeparam.html).

long | type | \- тип узла: корень, папка, файл (из [LtNodeType](ltnodetype.html)),  
---|---|---  
wchar_t | name [MAX_TEXT_LENGTH] | \- имя узла,  
reference | comment | \- комментарий - динамический массив CHAR_STR_ARR (динамический массив строк символов),  
reference | nodes | \- динамический массив узлов.  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [TreeNodeParam](structtreenodeparam.html).

Подразделы:

(отсутствуют)
