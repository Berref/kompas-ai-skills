# Variable - Получить параметрическую переменную по имени, индексу или указателю на размер

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - свойства ](ikompasdocument2d1_props.html) |  Scroll [ [ [ ](ikompasdocument2d1_variables.html "К следующему разделу")](ikompasdocument2d1_props.html "На уровень выше")](ikompasdocument2d1_selectionmanager.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Тип данных: указатель на интерфейс параметрической переменной [IVariable7](ivariable7.html)

Синтаксис Automation:

Variable = Object.Variable (VARIANT Index ) | Получить свойство ([* ](1.html))  
---|---  
Variable = Object.GetVariable (VARIANT Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Variable (VARIANT Index, &Variable ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- индекс, имя или указатель на размер параметрической переменной.  
---|---  
  
Свойство позволяет получать интерфейс параметрической переменной.

Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
