# DisabledObjects - Игнорируемые объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Поиск объектов ](bb2838772.html) > [Интерфейс IFindObjectParameters ](ifindobjectparameters.html) > [IFindObjectParameters - свойства ](ifindobjectparameters_propers.html) |  Scroll [ [ [ ](ifindobjectparameters_disabledviews.html "К следующему разделу")](ifindobjectparameters_propers.html "На уровень выше")](ifindobjectparameters_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifindobjectparameters.html)

Тип данных: VARIANT

Синтаксис Automation:

DisabledObjects = Object.DisabledObjects | Получить свойство ([* ](1.html))  
---|---  
Object.DisabledObjects = DisabledObjects | Установить свойство ([**](2.html))  
DisabledObjects = Object.GetDisabledObjects() | Получить свойство ([**](2.html))  
Object.SetDisabledObjects( DisabledObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DisabledObjects( &DisabledObjects ) | Получить свойство  
---|---  
Object.put_DisabledObjects( DisabledObjects ) | Установить свойство  
  
Примечание.

1\. Позволяет получать и устанавливать объект или список объектов, игнорируемые при поиске.

2\. Массив возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
