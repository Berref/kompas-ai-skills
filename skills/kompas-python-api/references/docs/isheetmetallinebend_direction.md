# Direction - Направление построения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBend ](isheetmetallinebend.html) > [ISheetMetalLineBend - свойства ](isheetmetallinebend_props.html) |  Scroll [ [ [ ](isheetmetallinebend_dismissalangletype.html "К следующему разделу")](isheetmetallinebend_props.html "На уровень выше")](isheetmetallinebend_bendvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebend.html)

Тип данных: BOOL

Синтаксис Automation:

Direction = iObject.Direction; | Получить свойство ([* ](1.html))  
---|---  
iObject.Direction = Direction; | Установить свойство ([* ](1.html))  
Direction = iObject.GetDirection; | Получить свойство ([**](2.html))  
iObject.SetDirection( Direction ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Direction( &Direction ); | Получить свойство  
---|---  
iObject->put_Direction( Direction ); | Установить свойство  
  
Значения свойства:

TRUE | \- прямое направление,  
---|---  
FALSE | \- обратное направление.  
  
Примечание.

Позволяет установить и получить направление построения сгиба.

Подразделы:

(отсутствуют)
