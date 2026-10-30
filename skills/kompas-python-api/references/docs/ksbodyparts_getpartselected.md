# GetPartSelected - Получить для части тела с индексом признак включения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс частей тела (Интерфейсы ksBodyParts, IBodyParts) ](ksbodyparts.html) > [IBodyParts - методы ](ksbodyparts_methods.html) |  Scroll [ [ [ ](ksbodyparts_setgreatpartsselected.html "К следующему разделу")](ksbodyparts_methods.html "На уровень выше")](ksbodyparts_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodyparts.html)

Синтаксис Automation:

BOOL GetPartSelected( long Index );

Синтаксис COM:

BOOL GetPartSelected( long Index );

Входные параметры:

Index | \- индекс выбираемой части.  
---|---  
  
Возвращаемое значение:

TRUE | \- часть тела включена,  
---|---  
FALSE | \- часть тела выключена.  
  
Примечание:

Метод позволяет получить для части тела с индексом признак включения.

Подразделы:

(отсутствуют)
