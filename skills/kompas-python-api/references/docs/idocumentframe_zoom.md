# Zoom - Увеличить масштаб окна рамкой

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_zoomprevnextorall.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_setzoomscale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

void Zoom (double x1, double y1, double x2, double y2);

Синтаксис COM:

HRESULT Zoom ([in]double x1, [in]double y1, [in]double x2, [in]double y2);

Входные параметры:

x1, y1 | \- координаты (в СК вида) первой точки диагонали рамки,  
---|---  
x2, y2 | \- координаты (в СК вида) второй точки диагонали рамки.  
  
Примечание:

1\. Метод позволяет растянуть часть документа, заданную рамкой, во все окно.

2\. Метод работает только для графических документов.

Подразделы:

(отсутствуют)
