# GetMathematic3D - Получить интерфейс математических измерений

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getmeasurer.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getmateconstraintobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис COM:

LPUNKNOWN GetMathematic3D( int type );

Входные параметры:

type | \- тип запрашиваемого интерфейса, допустимыми значениями являются следующие: \- o3d_sTrackingPointsMeasurer, \- o3d_measurer.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс IUnknown | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Метод позволяет получать интерфейс математических измерений по типу [Obj3dType](obj3dtype.html) в виде интерфейса IUnknown. Полученный интерфейс необходимо привести к интерфейсу, соответствующему типу type с помощью функции IUnknown::QeryInterface.

Подразделы:

(отсутствуют)
