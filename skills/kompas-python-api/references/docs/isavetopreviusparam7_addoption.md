# AddOption - Добавить настройку конвертации с возможностью выбора варианта конвертации

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс ISaveToPreviusParam7 ](isavetopreviusparam7.html) > [ISaveToPreviusParam7- методы ](isavetopreviusparam7_methods.html) |  Scroll [ [ [ ](isavetopreviusparam7_addwarning.html "К следующему разделу")](isavetopreviusparam7_methods.html "На уровень выше")](isavetopreviusparam7_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isavetopreviusparam7.html)

Синтаксис Automation:

BOOL AddOption( BSTR UniqueId, BSTR OptionName, VARIANT Options, BSTR DefaultValue );

Синтаксис COM:

HRESULT AddOption( BSTR UniqueId, BSTR OptionName, VARIANT Options, BSTR DefaultValue, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

UniqueId | \- уникальный идентификатор,  
---|---  
OptionName | \- отображаемое имя свойства,  
Options | \- список возможных значений (массив строк SafeArray VT_ARRAY | VT_BSTR),  
DefaultValue | \- базовое значение.  
  
Подразделы:

(отсутствуют)
