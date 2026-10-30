# Variable - Получить параметрическую переменную по имени, индексу или указателю на размер

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_variables.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_scale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: указатель на интерфейс параметрической переменной [IVariable7](ivariable7.html)

Синтаксис Automation:

Variable = Object.Variable (VARIANT Index) | Получить свойство ([* ](1.html))  
---|---  
Variable = Object.GetVariable (VARIANT Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Variable(VARIANT Index, &Variable) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- индекс, имя или указатель на размер параметрической переменной.  
---|---  
  
Свойство позволяет получать интерфейс параметрической переменной.

Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
