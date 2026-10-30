# DetachByBody - Удалить указанный объект из массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Массив объектов модели (Интерфейсы ksEntityCollection и IEntityCollection) ](ksentitycollection.html) > [ksEntityCollection - методы ](ksentitycollection_methods.html) |  Scroll [ [ [ ](ksentitycollection_detachbyindex.html "К следующему разделу")](ksentitycollection_methods.html "На уровень выше")](ksentitycollection_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentitycollection.html)

Синтаксис Automation:

BOOL DetachByBody(LPDISPATCH entity);

Синтаксис COM:

BOOL DetachByBody(LPENTITY entity);

Входной параметр:

entity | \- указатель на интерфейс удаляемого элемента [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечания:

1\. Указатель на интерфейс удаляемого объекта entity не должен быть 0.

2\. Элемент массива из модели не удаляется.

Подразделы:

(отсутствуют)
