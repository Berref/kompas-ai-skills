# AddBefore - Добавить объект перед указанным объектом в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Массив объектов модели (Интерфейсы ksEntityCollection и IEntityCollection) ](ksentitycollection.html) > [ksEntityCollection - методы ](ksentitycollection_methods.html) |  Scroll [ [ [ ](ksentitycollection_clear.html "К следующему разделу")](ksentitycollection_methods.html "На уровень выше")](ksentitycollection_addat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentitycollection.html)

Синтаксис Automation:

BOOL AddBefore (LPDISPATCH entity,

LPDISPATCH base);

Синтаксис COM:

BOOL AddBefore (LPENTITY entity,

LPENTITY base);

Входные параметры:

entity | \- интерфейс добавляемого элемента [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
base | \- интерфейс базового объекта ksEntity или IEntity (не должен быть 0).  
  
Возвращаемое значение:

Функция возвращает TRUE в двух случаях:

•Если при работе с динамическим массивом объектов модели (метод [EntityCollection](ksdocument3d_entitycollection.html)) checkEntity - признак проверки для вновь добавляемых объектов на NULL - имеет значение FALSE (т.е. в массив можно добавить NULL).

•Если при работе с динамическим массивом объектов модели checkEntity имеет значение TRUE (т.е. в массив нельзя добавить NULL) и объект - не NULL.

Функция возвращает FALSE, если при работе с динамическим массивом объектов модели checkEntity имеет значение TRUE (т.е. в массив нельзя добавить NULL) и объект - NULL.

Подразделы:

(отсутствуют)
