# ksGetSpcObjForGeomWithLimit - Получить указатель на объект спецификации, подключенный к данному графическому объекту с ограничениями по номеру раздела и типу атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcobjgeometry.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcobjforgeom.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjForGeomWithLimit](ksgetspcobjforgeomwithlimit.html).

Синтаксис Automation:

long ksGetSpcObjForGeomWithLimit (BSTR nameLib,

long numb,

long obj,

short equal,

short first,

long section,

double attrTypeNumb);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
obj | \- указатель на графический объект или группу объектов (0 - макроэлемент редактирования),  
equal | \- признак вхождения геометрии в состав объекта: 1 - геометрия идентична геометрии объекта спецификации, 0 - геометрия входит в объект спецификации,  
first | \- 1 - первый объект, 0 - следующий объект,  
section | \- номер раздела, в котором нужно найти объект (0 - номер не ограничивается),  
attrTypeNumb | \- номер типа атрибута, для которого нужно найти объект (0 - номер не ограничивается).  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Примечания:

1\. Данный метод - только для графических документов.

2\. В настоящий момент метод реализован только для equal = 1.

Подразделы:

(отсутствуют)
