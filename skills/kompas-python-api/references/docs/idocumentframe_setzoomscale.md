# SetZoomScale - Растянуть изображение окна

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_zoom.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_setgabaritmodifying.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL SetZoomScale( double X, double Y, double Scale, BOOL ViewParam );

Синтаксис COM:

HRESULT SetZoomScale( double X, double Y, double Scale, BOOL ViewParam, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- Координаты точки центра,  
---|---  
Scale | \- Масштаб,  
ViewParam | \- TRUE - координаты заданы в системе координат текущего вида, \- FALSE - координаты заданы в системе координат листа.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
