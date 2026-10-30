# SetByIndex - Заменить объект с указанным индексом в массиве на присланный объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Массив объектов модели (Интерфейсы ksEntityCollection и IEntityCollection) ](ksentitycollection.html) > [ksEntityCollection - методы ](ksentitycollection_methods.html) |  Scroll [ [ [ ](ksentitycollection_selectbypoint.html "К следующему разделу")](ksentitycollection_methods.html "На уровень выше")](ksentitycollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentitycollection.html)

Синтаксис Automation:

BOOL SetByIndex (LPDISPATCH entity,

long index);

Синтаксис COM:

BOOL SetByIndex (LPENTITY entity,

long index);

Входные параметры:

entity | \- указатель на интерфейс присоединяемого элемента [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
index | \- индекс элемента в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
