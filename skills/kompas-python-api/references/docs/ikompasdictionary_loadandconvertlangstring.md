# LoadAndConvertLangString - Загрузить и конвертировать строку

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IKompasDictionary](ikompasdictionary.html) > [IKompasDictionary - методы](ikompasdictionary_methods.html) |  Scroll [ [ [ ](idocumentsettings.html "К следующему разделу")](ikompasdictionary_methods.html "На уровень выше")](ikompasdictionary_convertlangwindow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdictionary.html)

Синтаксис Automation:

BSTR LoadAndConvertLangString( VARIANT Module, long ResID );

Синтаксис COM:

HRESULT LoadAndConvertLangString( VARIANT Module, long ResID, BSTR * Result );

Возвращаемое значение:

| \- Переведенная строка.  
---|---  
  
Входные параметры:

Module  | \- HINSTANCE модуля, в котором находится переводимая строка,  
---|---  
ResID | \- идентификатор строки.  
  
Подразделы:

(отсутствуют)
