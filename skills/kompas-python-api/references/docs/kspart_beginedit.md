# BeginEdit - Запустить режим редактирования на месте для данного компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_bodycollection.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

IDispatch * BeginEdit();

Синтаксис COM:

LPDOCUMENT3D BeginEdit();

Возвращаемое значение:

| \- указатель на интерфейс документа [ksDocument3D](ksdocument3d.html) или [IDocument3D](ksdocument3d.html).  
---|---  
  
Примечание:

1\. Данный метод работает только для компонента, вставленного в сборку. Для детали и для "верхнего" компонента сборки возвращает NULL.

2\. Метод работает только для визуального документа.

Подразделы:

(отсутствуют)
