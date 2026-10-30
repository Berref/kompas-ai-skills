# Array - Получить указатель на интерфейс массива скругляемых объектов (граней и ребер)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Скругление (Интерфейсы ksFilletDefinition, IFilletDefinition) ](ksfilletdefinition.html) > [IFilletDefinition - методы ](ksfilletdefinition_methods.html) |  Scroll [ [ [ ](kschamferdefinition.html "К следующему разделу")](ksfilletdefinition_methods.html "На уровень выше")](ksfilletdefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfilletdefinition.html)

Синтаксис Automation:

LPDISPATCH Array();

Синтаксис COM:

LPENTITYCOLLECTION Array();

Возвращаемое значение:

| \- указатель на интерфейс массива объектов [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечание:

В возвращаемом массиве включен контроль, не позволяющий добавить в массив нулевые указатели на элементы.

Подразделы:

(отсутствуют)
