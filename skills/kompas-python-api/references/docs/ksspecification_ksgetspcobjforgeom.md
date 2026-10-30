# ksGetSpcObjForGeom - Получить указатель на объект спецификации, подключенный к данному графическому объекту

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcobjforgeomwithlimit.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcdescription.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjForGeom](ksgetspcobjforgeom.html).

Синтаксис Automation:

long ksGetSpcObjForGeom (BSTR nameLib,

long numb,

long obj,

short equal,

short first);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
obj | \- указатель на графический объект или группу объектов (0 - макроэлемент редактирования),  
equal | \- признак вхождения геометрии в состав объекта: 1 - геометрия идентична геометрии объекта спецификации, 0 - геометрия входит в объект спецификации,  
first | \- 1 - первый объект, 0 - следующий объект.  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Примечания:

1\. Данный метод - только для графических документов.

2\. В настоящий момент метод реализован только для equal = 1.

Подразделы:

(отсутствуют)
