# SetPlacement - Установить новое местоположение компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_setsourcevariables.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_setobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL SetPlacement (LPDISPATCH placement);

Синтаксис COM:

BOOL SetPlacement (LPPLACEMENT placement);

Входной параметр:

placement | \- указатель на интерфейс [ksPlacement](ksplacement.html) или [IPlacement](ksplacement.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Данный метод вступает в силу после вызова метода [UpdatePlacement](kspart_updateplacement.html).

Подразделы:

(отсутствуют)
