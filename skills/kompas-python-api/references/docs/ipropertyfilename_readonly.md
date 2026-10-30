# ReadOnly - Запрет редактирования значения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyFileName ](ipropertyfilename.html) > [IPropertyFileName - свойства ](ipropertyfilename_props.html) |  Scroll [ [ [ ](ipropertyfilename_resmodule.html "К следующему разделу")](ipropertyfilename_props.html "На уровень выше")](ipropertyfilename_preview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyfilename.html)

Тип данных: BOOL

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
  
Значения свойства:

TRUE | \- запрещает ввод нового значения с клавиатуры в текстовом поле,  
---|---  
FALSE | \- разрешает ввод нового значения с клавиатуры в текстовом поле.  
  
Подразделы:

(отсутствуют)
