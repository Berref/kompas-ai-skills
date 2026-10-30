# DetachByIndex - Отсоединить от массива компонент с указанным индексом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_getbyindex.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_detachbybody.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

BOOL DetachByIndex (long index);

Синтаксис COM:

BOOL DetachByIndex (unsigned long index);

Входной параметр:

index | \- индекс отсоединяемого компонента в массиве.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Элемент массива из модели не удаляется.

Подразделы:

(отсутствуют)
