# UnConvertCoordinates - Преобразовать координаты документа в логические координаты экрана

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_zoomscale.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_zoomprevnextorall.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL UnConvertCoordinates( ConvertCoordTypeEnum Type, double X, double Y, double Z, long * LX, long * LY );

Синтаксис COM:

HRESULT UnConvertCoordinates( ConvertCoordTypeEnum Type, double X, double Y, double Z, long * LX, long * LY, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Type | \- тип СК, в которой передаются координаты,  
---|---  
X, Y, Z | \- координаты в мм в СК, согласно [ConvertCoordTypeEnum](convertcoordtypeenum.html).  
  
Выходные параметры:

LX, LY | \- координаты в экранных пикселах.  
---|---  
  
Подразделы:

(отсутствуют)
