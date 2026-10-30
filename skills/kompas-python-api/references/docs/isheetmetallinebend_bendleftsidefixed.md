# BendLeftSideFixed - Признак фиксации левой стороны

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBend ](isheetmetallinebend.html) > [ISheetMetalLineBend - свойства ](isheetmetallinebend_props.html) |  Scroll [ [ [ ](isheetmetallinebend_bendreduction.html "К следующему разделу")](isheetmetallinebend_props.html "На уровень выше")](isheetmetallinebend_bendcoefficient.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebend.html)

Тип данных: BOOL

Синтаксис Automation:

BendLeftSideFixed = iObject.BendLeftSideFixed; | Получить свойство ([* ](1.html))  
---|---  
iObject.BendLeftSideFixed = BendLeftSideFixed; | Установить свойство ([* ](1.html))  
BendLeftSideFixed = iObject.GetBendLeftSideFixed; | Получить свойство ([**](2.html))  
iObject.SetBendLeftSideFixed( BendLeftSideFixed ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BendLeftSideFixed( &BendLeftSideFixed ); | Получить свойство  
---|---  
iObject->put_BendLeftSideFixed( BendLeftSideFixed ); | Установить свойство  
  
Значения свойства:

TRUE | \- прямое направление,  
---|---  
FALSE | \- обратное направление.  
  
Примечание.

Позволяет установить и получить признак фиксации левой стороны.

Подразделы:

(отсутствуют)
