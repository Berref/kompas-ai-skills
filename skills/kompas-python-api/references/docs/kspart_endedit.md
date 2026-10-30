# EndEdit - Закрыть режим редактирования на месте для данного компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_entitycollection.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_curveintersection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

VARIANT_BOOL EndEdit (VARIANT_BOOL rebuild);

Синтаксис COM:

BOOL EndEdit (BOOL rebuild);

Входные параметры:

rebuild | \- перестроить компонент.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Данный метод работает только для компонента, вставленного в сборку.

Подразделы:

(отсутствуют)
