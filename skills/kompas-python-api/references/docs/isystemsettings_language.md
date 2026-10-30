# Language - Марка. Текст префикса

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ISystemSettings ](isystemsettings.html) > [ISystemSettings - свойства ](isystemsettings_props.html) |  Scroll [ [ [ ](isystemsettings_modellocalcscreateinabsolutecs.html "К следующему разделу")](isystemsettings_props.html "На уровень выше")](isystemsettings_modelinverseindynamicselect.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isystemsettings.html)

Тип данных: BSTR

Синтаксис Automation:

Language = Object.Language | Получить свойство ([* ](1.html))  
---|---  
Language = Object.GetLanguage() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Language( &Language ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Список возможных значений свойства см. https://msdn.microsoft.com/ru-ru/library/ee825488(v=cs.20).aspx

В зависимости от текущего языка выбирается словарь (текстовый UNICOD-ный документ с расширением .dic). Имя файла для приложений формируется как имя файла приложения - подчеркивание - имя текущего языка.

Пример:

komlib_ru_RU.dic - словарь для русского языка

komlib_ru_EN.dic - словарь для английского языка.

Подразделы:

(отсутствуют)
