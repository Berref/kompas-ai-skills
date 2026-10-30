# GetZoomScale - Получить масштаб и центр окна документа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_iskompascommandcheck.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_getworkarearect.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

void GetZoomScale (double* x, double* y, double* scale);

Синтаксис COM:

HRESULT GetZoomScale ([out]double* x, [out]double* y, [out]double* scale);

Выходные параметры:

x, y | \- координаты (в СК вида) точки центра изменения масштаба,  
---|---  
scale | \- коэффициент изменения масштаба изображения.  
  
Примечание:

1\. Метод позволяет получить текущий масштаб отображения документа в окне с центром в точке х, у (точка х, у в центре окна).

2\. Метод работает только для графических документов.

Подразделы:

(отсутствуют)
