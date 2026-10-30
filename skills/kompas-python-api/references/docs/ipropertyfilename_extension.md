# Extension - Расширение имени файла

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyFileName ](ipropertyfilename.html) > [IPropertyFileName - свойства ](ipropertyfilename_props.html) |  Scroll [ [ [ ](ipropertyfilename_filter.html "К следующему разделу")](ipropertyfilename_props.html "На уровень выше")](ipropertyfilename_defaultvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyfilename.html)

Тип данных: BSTR (строка).

Синтаксис Automation:

Extension = iObject.Extension | Получить свойство ([* ](1.html))  
---|---  
iObject.Extension = Extension | Установить свойство ([* ](1.html))  
Extension = iObject.GetExtension() | Получить свойство([**](2.html))  
iObject.SetExtension (Extension) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Extension (&Extension) | Получить свойство  
---|---  
iObject->put_Extension (Extension) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить/задать расширение имени файла для диалога открытия файла, используемое по умолчанию.

2\. Если пользователь при задании имени файла не укажет расширение, автоматически для открытия будут предлагаться файлы с заданным расширением имени.

3\. Если присвоить свойству значение NULL, то расширение файлов должно задаваться пользователем явно.

Подразделы:

(отсутствуют)
