# type - Способ задания надписи в обозначении базы

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Обозначение базы (Интерфейс ksBaseParam) ](ksbaseparam.html) > [ksBaseParam - свойства ](ksbaseparam_props.html) |  Scroll [ [ [ ](ksbaseparam_x1.html "К следующему разделу")](ksbaseparam_props.html "На уровень выше")](ksbaseparam_style.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbaseparam.html)

Тип данных: BOOL

Значения свойства:

FALSE | \- текст в виде строки (текст определяется свойством [ksBaseParam::str](ksbaseparam_str.html)),  
---|---  
TRUE | \- динамический массив компонент текстов (текст определяется массивом pTextItem (смотрите методы [ksBaseParam::GetPTextItem](ksbaseparam_getptextitem.html) и [ksBaseParam::SetPTextItem](ksbaseparam_setptextitem.html)).  
  
Синтаксис Automation:

type = iBaseParam.type | Получить свойство ([* ](1.html))  
---|---  
iBaseParam.type = type | Установить свойство ([* ](1.html))  
type = iBaseParam.GetType() | Получить свойство ([**](2.html))  
iBaseParam.SetType( type ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
