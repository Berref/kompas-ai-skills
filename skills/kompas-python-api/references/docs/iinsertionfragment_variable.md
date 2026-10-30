# Variable - Получить параметрическую переменную по имени, индексу или указателю на размер

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionObject ](iinsertionobject.html) > [Интерфейс IInsertionFragment ](iinsertionfragment.html) > [IInsertionFragment - свойства ](iinsertionfragment_props.html) |  Scroll [ [ [ ](iinsertionfragment_variables.html "К следующему разделу")](iinsertionfragment_props.html "На уровень выше")](iinsertionfragment_scale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionfragment.html)

Тип данных: указатель на интерфейс параметрической переменной [IVariable7](ivariable7.html)

Синтаксис Automation:

Variable = Object.Variable ( VARIANT Index ) | Получить свойство ([* ](1.html))  
---|---  
Variable = Object.GetVariable( VARIANT Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Variable( VARIANT Index, &Variable ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- индекс, имя или указатель на размер параметрической переменной.  
---|---  
  
Примечание:

1\. Свойство позволяет получать интерфейс параметрической переменной.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
