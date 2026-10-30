# GetByIndex - Получить указатель на интерфейс объекта в массиве по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Массив граней (Интерфейсы ksFaceCollection, IFaceCollection) ](ksfacecollection.html) > [IFaceCollection - методы ](ksfacecollection_methods.html) |  Scroll [ [ [ ](ksfacecollection_getbyname.html "К следующему разделу")](ksfacecollection_methods.html "На уровень выше")](ksfacecollection_findit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfacecollection.html)

Синтаксис Automation:

LPDISPATCH GetByIndex (long index);

Синтаксис COM:

LPFACEDEFINITION GetByIndex (long index);

Входной параметр:

index | \- номер объекта в массиве.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksFaceDefinition](ksfacedefinition.html) или [IFaceDefinition](ksfacedefinition.html).  
---|---  
  
Подразделы:

(отсутствуют)
