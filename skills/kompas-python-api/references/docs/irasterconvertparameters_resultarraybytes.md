# ResultArrayBytes - Результат сохранения в растр в виде массива байт

[API интерфейсов. Версия 7](applicate.html) > [Конвертер файлов КОМПАС ](conv.html) > [Интерфейс IRasterConvertParameters ](irasterconvertparameters.html) > [IRasterConvertParameters - свойства ](irasterconvertparameters_propers.html) |  Scroll [ [ [ ](irasterconvertparameters_returnresultasarraybytes.html "К следующему разделу")](irasterconvertparameters_propers.html "На уровень выше")](irasterconvertparameters_resolution.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irasterconvertparameters.html)

Тип данных: VARIANT

Синтаксис Automation:

ResultArrayBytes = Object.ResultArrayBytes | Получить свойство ([* ](1.html))  
---|---  
Object.ResultArrayBytes = ResultArrayBytes | Установить свойство ([* ](1.html))  
ResultArrayBytes = Object.GetResultArrayBytes() | Получить свойство ([**](2.html))  
Object.SetResultArrayBytes( ResultArrayBytes ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ResultArrayBytes( &ResultArrayBytes ) | Получить свойство,  
---|---  
Object.put_ResultArrayBytes( ResultArrayBytes ) | Установить свойство  
  
Примечание:

Для одностраничного растра возвращается массив байт VT_ARRAY | VT_UI1.

Для многостраничного растра возвращается массив VT_ARRAY | VT_VARIANT - каждая страница добавляется отдельным элементом в массив в виде массива байт VT_ARRAY | VT_UI1.

Подразделы:

(отсутствуют)
