# GetByIndex - Получить указатель на интерфейс компонента по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_getbyname.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_detachbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

LPDISPATCH GetByIndex (long index);

Синтаксис COM:

LPPART GetByIndex (unsigned long index);

Входной параметр:

index | \- индекс компонента в массиве.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс компонента [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Подразделы:

(отсутствуют)
