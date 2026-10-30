# CreateOpenButton - Отображение кнопки выбора файла

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyFileName ](ipropertyfilename.html) > [IPropertyFileName - свойства ](ipropertyfilename_props.html) |  Scroll [ [ [ ](ipropertyfilename_defaultvalue.html "К следующему разделу")](ipropertyfilename_props.html "На уровень выше")](ipropertyfilename_bitmap.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyfilename.html)

Тип данных: BOOL.

Синтаксис Automation:

CreateOpenButton = iObject.CreateOpenButton | Получить свойство ([* ](1.html))  
---|---  
iObject.CreateOpenButton = CreateOpenButton | Установить свойство ([* ](1.html))  
CreateOpenButton = iObject.GetCreateOpenButton() | Получить свойство([**](2.html))  
iObject.SetCreateOpenButton (CreateOpenButton) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CreateOpenButton (&CreateOpenButton) | Получить свойство  
---|---  
iObject->put_CreateOpenButton (CreateOpenButton) | Установить свойство  
  
Значения свойства:

TRUE | \- справа от текстового поля будет находится кнопка вызова диалога открытия файла,  
---|---  
FALSE | \- элемент управления будет состоять только из текстового поля (без кнопки).  
  
Подразделы:

(отсутствуют)
