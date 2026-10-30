# ZoomScale - Изменить масштаб изображения окна

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframes.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_unconvertcoordinates.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

void ZoomScale (double x, double y, double scale);

Синтаксис COM:

HRESULT ZoomScale ([in]double x, [in]double y, [in]double scale);

Входные параметры:

x, y | \- координаты (в СК вида) точки центра изменения масштаба,  
---|---  
scale | \- коэффициент изменения масштаба изображения.  
  
Примечание:

1\. Метод позволяет установить новый масштаб отображения документа в окне с центром в точке х,у.

2\. Метод работает только для графических документов.

Подразделы:

(отсутствуют)
