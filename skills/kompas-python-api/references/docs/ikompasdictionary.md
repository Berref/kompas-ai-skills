# Интерфейс IKompasDictionary

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) |  Scroll [ [ [ ](ikompasdictionary_methods.html "К следующему разделу")](adjstment.html "На уровень выше")](ilibitemsettings_setitems.html "К предыдущему разделу")  
---|---  
  
Интерфейс Словарь.

Иерархия:

IDispatch

[IKompasDictionary](ikompasdictionary.html)

Примечание:

Интерфейс можно получить с помощью свойств [IApplication::Dictionary](iapplication_dictionary.html) и [IProceduresLibrary::Dictionary](iprocedureslibrary_dictionary.html)

Словарь сохраняется в файле с расширением .dic.

В зависимости от текущего языка выбирается словарь (текстовый UNICOD-ный документ с расширением .dic).

Имя файла для приложений формируется как имя файла приложения - подчеркивание - имя текущего языка.

•komlib_ru_RU.dic - словарь для русского языка,

•komlib_ru_EN.dic - словарь для английского языка.

Строки файла должны иметь следующий формат:

"Вращение"="Rotation"

"Параметры"="Parameters"

...

...

"Перемещение"="Moving"

Версия Компас v23

Подразделы:

[IKompasDictionary - методы](ikompasdictionary_methods.html)
