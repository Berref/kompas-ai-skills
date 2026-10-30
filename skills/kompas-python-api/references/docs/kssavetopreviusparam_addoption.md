# AddOption - Добавить настройку конвертации с возможностью выбора варианта конвертации

[API интерфейсов. Версия 5](ag57940.html) > [Параметры конвертации при сохранении в предыдущую версию (Интерфейсы ISaveToPreviusParam, ksSaveToPreviusParam ) ](isavetopreviusparam.html) > [ksSaveToPreviusParam - методы ](kssavetopreviusparam.html) |  Scroll [ [ [ ](kssavetopreviusparam_addwarning.html "К следующему разделу")](kssavetopreviusparam.html "На уровень выше")](kssavetopreviusparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isavetopreviusparam.html)

Синтаксис:

BOOL AddOption( BSTR uniqueID, BSTR optionName, VARIANT options, BSTR defaultValue );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

uniqueID | \- уникальный идентификатор,  
---|---  
optionName | \- отображаемое имя свойства,  
options. | \- список возможных значений (массив строк SafeArray VT_ARRAY | VTBSTR).  
  
Подразделы:

(отсутствуют)
