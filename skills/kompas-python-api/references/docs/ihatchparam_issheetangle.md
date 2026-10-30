# IsSheetAngle - Угол наклона штриховки относительно листа или границ

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс IHatchParam ](ihatchparam.html) > [IHatchParam - свойства ](ihatchparam_props.html) |  Scroll [ [ [ ](ihatchparam_librarystylenumber.html "К следующему разделу")](ihatchparam_props.html "На уровень выше")](ihatchparam_hatchtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ihatchparam.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- обычная штриховка (угол штриховки - постоянный),  
---|---  
FALSE | \- угол штриховки относительно ее границ сохраняется при повороте границ (используется при изображении накатки на деталях).  
  
Синтаксис Automation:

IsSheetAngle = Object.IsSheetAngle | Получить свойство([* ](1.html))  
---|---  
Object.IsSheetAngle = IsSheetAngle | Установить свойство ([* ](1.html))  
IsSheetAngle = Object.GetIsSheetAngle() | Получить свойство ([**](2.html))  
Object.SetIsSheetAngle( IsSheetAngle ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_IsSheetAngle( &IsSheetAngle ) | Получить свойство  
---|---  
Object.put_IsSheetAngle( IsSheetAngle ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать признак, является ли угол наклона штриховки листовым.

Подразделы:

(отсутствуют)
