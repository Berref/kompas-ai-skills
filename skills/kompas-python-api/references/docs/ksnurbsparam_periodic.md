# periodic - Признак периодичности сплайна

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров графических примитивов ](cd1743949.html) > [NURBS ](cd1751192.html) > [Кривая NURBS (Интерфейс ksNurbsParam) ](ksnurbsparam.html) > [ksNurbsParam - свойства ](ksnurbsparam_props.html) |  Scroll [ [ [ ](ksnurbsparam_style.html "К следующему разделу")](ksnurbsparam_props.html "На уровень выше")](ksnurbsparam_degree.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbsparam.html)

Тип данных:BOOL.

Значения свойства:

FALSE | \- непериодический сплайн,  
---|---  
TRUE | \- периодический сплайн.  
  
Синтаксис Automation:

periodic = iNurbsParam.periodic | Получить свойство ([* ](1.html))  
---|---  
periodic = iNurbsParam.GetPeriodic() | Получить свойство ([**](2.html))  
  
Примечания:

1\. Свойство используется только для функции ksGetObjParam.

2\. Свойство используется только для чтения.

Подразделы:

(отсутствуют)
