# CopyObjectParam - Структура параметров копирования объекта графического документа

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structdocumentparam.html "К следующему разделу")](bk1829760.html "На уровень выше")](structassociationviewparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksCopyObjectParam](kscopyobjectparam.html).

reference | p | указатель на объект, группу, вид, слой  
---|---|---  
double | xOld | координаты базовой точки объекта  
double | yOld  
double | xNew | координаты точки вставки  
double | yNew  
double | scale | масштаб  
double | angle | угол поворота в градусах  
unsigned char | attrCopy | признак копирования атрибутов  
unsigned char | dimLineScale | признак масштабирования выносных линий  
| spcObjCopy | копировать объекты спецификации  
unsigned char | storagesCopy | копировать пользовательские данные и свойства  
unsigned char | hyperLinksCopy | копировать ссылки  
  
Подразделы:

(отсутствуют)
