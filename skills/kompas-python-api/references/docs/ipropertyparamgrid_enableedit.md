# EnableEdit - Разрешить редактирование ячейки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - свойства](ipropertyparamgrid_propers.html) |  Scroll [ [ [ ](ipropertyparamgrid_readonly.html "К следующему разделу")](ipropertyparamgrid_propers.html "На уровень выше")](ipropertyparamgrid_currentrow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Тип данных: BOOL

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

long NRow | \- номер строки,  
---|---  
long NCol | \- номер столбца.  
  
Подразделы:

(отсутствуют)
