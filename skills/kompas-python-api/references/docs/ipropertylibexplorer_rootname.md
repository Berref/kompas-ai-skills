# RootName - Имя верхнего узла дерева

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyLibExplorer ](ipropertylibexplorer.html) > [IPropertyLibExplorer - свойства ](ipropertylibexplorer_props.html) |  Scroll [ [ [ ](ipropertylist.html "К следующему разделу")](ipropertylibexplorer_props.html "На уровень выше")](ipropertylibexplorer_filevalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylibexplorer.html)

Тип данных: BSTR.

Синтаксис Automation:

RootName = iObject.RootName | Получить свойство ([* ](1.html))  
---|---  
iObject.RootName = RootName | Установить свойство ([* ](1.html))  
FileName = iObject.GetRootName( ) | Получить свойство([**](2.html))  
iObject.SetRootName (RootName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_RootName ( &RootName ) | Получить свойство  
---|---  
iObject->put_RootName (RootName) | Установить свойство  
  
Примечание:

1\. Имя верхнего узла дерева внутренней структуры библиотеки документов. После вызова установки полного пути к библиотеке документов [IPropertyLibExplorer::FileName](ipropertylibexplorer_filename.html) считывается как ее имя.

2\. Задать значение свойства можно только до запуска процесса.

Подразделы:

(отсутствуют)
