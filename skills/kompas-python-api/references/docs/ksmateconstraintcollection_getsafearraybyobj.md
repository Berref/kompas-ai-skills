# GetSafeArrayByObj - Сформировать массив SAFEARRAY параметров сопряжений по объекту

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html) > [IMateConstraintCollection - методы ](ksmateconstraintcollection_methods.html) |  Scroll [ [ [ ](ksmateconstraintcollection_findit.html "К следующему разделу")](ksmateconstraintcollection_methods.html "На уровень выше")](ksmateconstraintcollection_getcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmateconstraintcollection.html)

Синтаксис Automation:

BOOL GetSafeArrayByObj( LPDISPATCH obj, VARIANT * pArray );

Синтаксис COM:

BOOL GetSafeArrayByObj( LPUNKNOWN obj, VARIANT * pArray );

Входные параметры:

obj | \- указатель на объект.  
---|---  
  
Выходные параметры:

pArray | \- указатель на массив параметров сопряжений.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Тип выходного массива VT_ARRAY | VT_UNKNOWN. Элемент, лежащий в массиве, IMateConstraint.

2\. Входной объект либо компонент IPart, тогда будет сформирован массив всех сопряжений для этого компонента, либо объект модели, который может фигурировать в сопряжениях.

Подразделы:

(отсутствуют)
