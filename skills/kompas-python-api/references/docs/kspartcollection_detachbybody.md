# DetachByBody - отсоединить компонент от массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_detachbyindex.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

BOOL DetachByBody (LPDISPATCH part);

Синтаксис COM:

BOOL DetachByBody (LPPART part);

Входной параметр:

part | \- указатель на интерфейс отсоединяемого компонента [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Элемент массива из модели не удаляется.

Подразделы:

(отсутствуют)
