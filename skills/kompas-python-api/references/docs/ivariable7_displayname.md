# DisplayName - Отображаемое имя переменной

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariable7 ](ivariable7.html) > [IVariable7 - свойства ](ivariable7_props.html) |  Scroll [ [ [ ](ivariable7_expression.html "К следующему разделу")](ivariable7_props.html "На уровень выше")](ivariable7_deviationtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariable7.html)

Тип данных: BSTR

Синтаксис Automation:

DisplayName = Object.DisplayName | Получить свойство ([* ](1.html))  
---|---  
DisplayName = Object.GetDisplayName() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DisplayName( &DisplayName ) | Получить свойство  
---|---  
  
Свойство позволяет получить отображаемое имя переменной.

Примечание:

Свойство доступно только для чтения.

Отображаемое имя переменной может отличаться от имени переменной [IVariable7::Name](ivariable7_name.html) для внешних переменных вставки детали в сборку.

К имени переменной из источника добавляется префикс, равный имени переменной «исключить из расчета».

Подразделы:

(отсутствуют)
