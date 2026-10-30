# EntityCollection - Формирует массив объектов и возвращает указатель на его интерфейс

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getadvancedcolor.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_endedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH EntityCollection (short objType);

Синтаксис COM:

LPENTITYCOLLECTION EntityCollection (short objType);

Входной параметр:

objType | \- тип объектов, содержащихся в массиве.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечания:

1\. При создании массив заполняется объектами указанного типа, содержащимися в компоненте.

2\. В возвращаемом массиве включен контроль, не позволяющий добавить в него нулевой указатель.

3\. Параметр objType необходим для создания массива и для правильной работы метода [Refresh](ksentitycollection_refresh.html).

[Типы объектов...](obj3dtype.html)

Подразделы:

(отсутствуют)
