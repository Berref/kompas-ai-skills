# DoubleMark - Признак марки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNode ](imarknode.html) > [IMarkNode - свойства ](imarknode_props.html) |  Scroll [ [ [ ](imarknode_marknodes.html "К следующему разделу")](imarknode_props.html "На уровень выше")](imarknode_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknode.html)

Тип данных: BOOL

Синтаксис Automation:

DoubleMark = iObject.DoubleMark | Получить свойство([* ](1.html))  
---|---  
iObject.DoubleMark = DoubleMark | Установить свойство ([* ](1.html))  
DoubleMark = iObject.GetDoubleMark() | Получить свойство ([**](2.html))  
iObject.SetDoubleMark( DoubleMark ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DoubleMark(&DoubleMark) | Получить свойство  
---|---  
iObject->put_DoubleMark( DoubleMark) | Установить свойство  
  
Значения свойства:

TRUE | \- двойная окружность,  
---|---  
FALSE | \- одинарная.  
  
Примечание:

Свойство используется для узлов типов ksMarkCirle и ksMarkRefCirle из перечисления [ksMarkNodeEnum](ksmarknodeenum.html).

Подразделы:

(отсутствуют)
