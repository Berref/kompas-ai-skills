# ZoomPrevNextOrAll - Показать модель в активном окне полностью или установить предыдущий или последующий масштаб изображения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](kspartcollection.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_userselectentityex2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL ZoomPrevNextOrAll (short type);

Синтаксис COM:

BOOL ZoomPrevNextOrAll (short type);

Входные параметры:

type | \- признак устанавливаемого масштаба (0 - следующий масштаб изображения, 1 - предыдущий масштаб изображения, 2 - показать модель полностью).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

В настоящий момент метод работает только при type=2.

Подразделы:

(отсутствуют)
