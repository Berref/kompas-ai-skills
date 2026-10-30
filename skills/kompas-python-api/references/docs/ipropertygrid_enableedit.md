# EnableEdit - Запрет редактирования ячеек

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyGrid ](ipropertygrid.html) > [IPropertyGrid - свойства ](ipropertygrid_props.html) |  Scroll [ [ [ ](ipropertygrid_fixedcolumncount.html "К следующему разделу")](ipropertygrid_props.html "На уровень выше")](ipropertygrid_enabledeleterows.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertygrid.html)

Тип данных: BOOL.

Синтаксис Automation:

EnableEdit = Object.EnableEdit( NRow, NCol ) | Получить свойство ([* ](1.html))  
---|---  
Object.EnableEdit( NRow, NCol ) = EnableEdit | Установить свойство ([* ](1.html))  
EnableEdit = Object.GetEnableEdit( NRow, NCol ) | Получить свойство([**](2.html))  
Object.SetEnableEdit( NRow, NCol, EnableEdit ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_EnableEdit( NRow, NCol, &EnableEdit ) | Получить свойство  
---|---  
Object.put_EnableEdit( NRow, NCol, EnableEdit ) | Установить свойство  
  
Входные параметры:

long NRow | \- номер строки  
---|---  
long NCol | \- номер столбца  
  
Подразделы:

(отсутствуют)
