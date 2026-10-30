# OpenStampEx - Открыть составной объект "штамп" по номеру листа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](setstampcolumntext.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](openstamp.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int OpenStampEx (int sheetNumb);

Входные параметры:

sheetNumb | \- номер листа, начиная с 1.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Операторы [ColumnNumber](columnnumber.html) и [TextLine](textline.html), вводимые между операторами [OpenStampEx](openstampex.html) и [CloseStamp](closestamp.html), принадлежат штампу листа с номером sheetNumb.

2\. [ColumnNumber](columnnumber.html) определяет номер ячейки, куда помещать текcт.

3\. Номера определены в соответствии с ГОСТ на данный штамп.

4\. [CloseStamp](closestamp.html) возвращает указатель на штамп.

Подразделы:

(отсутствуют)
