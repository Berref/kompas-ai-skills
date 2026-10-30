# ZoomPrevNextOrAll - Отобразить предыдущий/следующий масштаб или показать весь документ

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_unconvertcoordinates.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_zoom.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

void ZoomPrevNextOrAll (long Type);

Синтаксис COM:

HRESULT ZoomPrevNextOrAll ([in]ZoomTypeEnum type);

Входные параметры:

type | \- тип изменения масштаба из перечисления [ZoomTypeEnum.](zoomtypeenum.html)  
---|---  
  
Примечание:

1\. Установка следующего масштаба возможно только после отката к предыдущему масштабу.

2\. Метод работает в полном объеме только для графических документов. Для документов-моделей работает только режим ksZoomAll (Показать весь документ).

3\. В текстовом документе и в спецификации метод не работает.

Подразделы:

(отсутствуют)
