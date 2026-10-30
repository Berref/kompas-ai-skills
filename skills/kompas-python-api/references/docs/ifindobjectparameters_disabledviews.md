# DisabledViews - Игнорируемые виды

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Поиск объектов ](bb2838772.html) > [Интерфейс IFindObjectParameters ](ifindobjectparameters.html) > [IFindObjectParameters - свойства ](ifindobjectparameters_propers.html) |  Scroll [ [ [ ](ifindobjectparameters_drawingobjecttype.html "К следующему разделу")](ifindobjectparameters_propers.html "На уровень выше")](ifindobjectparameters_disabledobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifindobjectparameters.html)

Тип данных: VARIANT

Синтаксис Automation:

DisabledViews = Object.DisabledViews | Получить свойство ([* ](1.html))  
---|---  
Object.DisabledViews = DisabledViews | Установить свойство ([**](2.html))  
DisabledViews = Object.GetDisabledViews() | Получить свойство ([**](2.html))  
Object.SetDisabledViews( DisabledViews ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DisabledViews( &DisabledViews ) | Получить свойство  
---|---  
Object.put_DisabledViews( DisabledViews ) | Установить свойство  
  
Примечание.

1\. Позволяет получать и устанавливать вид или список видов, игнорируемые при поиске.

2\. Массив возвращается в виде массива SAFEARRAY видов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
