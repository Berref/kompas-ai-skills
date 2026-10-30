# SetPartSelected - Установить для части тела с индексом признак включения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс частей тела (Интерфейсы ksBodyParts, IBodyParts) ](ksbodyparts.html) > [IBodyParts - методы ](ksbodyparts_methods.html) |  Scroll [ [ [ ](ksbodyparts_userbodypartschoice.html "К следующему разделу")](ksbodyparts_methods.html "На уровень выше")](ksbodyparts_setgreatpartsselected.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodyparts.html)

Синтаксис Automation:

BOOL SetPartSelected( long Index, BOOL Select );

Синтаксис COM:

BOOL SetPartSelected( long Index, BOOL Select );

Входные параметры:

Index | \- индекс выбираемой части,  
---|---  
Select | \- признак включения в расчет; TRUE - включить, FALSE - выключить часть из расчета.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет изменить признак включения части тела с индексом.

Подразделы:

(отсутствуют)
