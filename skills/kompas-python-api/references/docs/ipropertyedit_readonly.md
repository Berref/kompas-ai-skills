# ReadOnly - Запрет редактирования значения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyEdit ](ipropertyedit.html) > [IPropertyEdit - свойства ](ipropertyedit_props.html) |  Scroll [ [ [ ](ipropertyedit_width.html "К следующему разделу")](ipropertyedit_props.html "На уровень выше")](ipropertyedit_minvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyedit.html)

Тип данных: BOOL.

Синтаксис Automation:

ReadOnly = iObject.ReadOnly | Получить свойство ([* ](1.html))  
---|---  
iObject.ReadOnly = ReadOnly | Установить свойство ([* ](1.html))  
ReadOnly = iObject.GetReadOnly() | Получить свойство([**](2.html))  
iObject.SetReadOnly (ReadOnly) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ReadOnly (&ReadOnly) | Получить свойство  
---|---  
iObject->put_ReadOnly (ReadOnly) | Установить свойство  
  
Значение свойства:

TRUE | \- ввод нового значения с клавиатуры в поле запрещен,  
---|---  
FALSE | \- ввод нового значения с клавиатуры в раскрывающийся список разрешен.  
  
Подразделы:

(отсутствуют)
