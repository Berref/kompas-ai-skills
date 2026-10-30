# FileValue - Признак - выбранный узел является файлом

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyLibExplorer ](ipropertylibexplorer.html) > [IPropertyLibExplorer - свойства ](ipropertylibexplorer_props.html) |  Scroll [ [ [ ](ipropertylibexplorer_rootname.html "К следующему разделу")](ipropertylibexplorer_props.html "На уровень выше")](ipropertylibexplorer_filename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylibexplorer.html)

Тип данных: BOOL.

Значения свойства:

TRUE | \- выбранный узел является файлом,  
---|---  
FALSE | \- выбранный узел не является файлом.  
  
Синтаксис Automation:

FileValue = iObject.FileValue | Получить свойство ([* ](1.html))  
---|---  
FileValue = iObject.GetFileValue( ) | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_FileValue ( &FileValue ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В дереве библиотеки документов могут быть папки и файлы. Путь к выбранному элементу можно получить, используя свойство [IPropertyControl::Value](ipropertycontrol_value.html).

Подразделы:

(отсутствуют)
