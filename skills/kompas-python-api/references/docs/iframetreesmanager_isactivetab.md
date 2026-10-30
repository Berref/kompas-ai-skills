# IsActiveTab - Активная закладка

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IFrameTreesManager ](iframetreesmanager.html) > [IFrameTreesManager - свойства ](iframetreesmanager_props.html) |  Scroll [ [ [ ](iframetreesmanager_tabvisible.html "К следующему разделу")](iframetreesmanager_props.html "На уровень выше")](iframetreesmanager_activetab.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iframetreesmanager.html)

Тип данных: BOOL

Синтаксис Automation:

IsActiveTab = Object.IsActiveTab( Ocx ) | Получить свойство ([* ](1.html))  
---|---  
Object.IsActiveTab( Ocx ) = IsActiveTab | Установить свойство ([* ](1.html))  
IsActiveTab = Object.GetIsActiveTab( Ocx ) | Получить свойство ([**](2.html))  
Object.SetIsActiveTab( Ocx, IsActiveTab ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_IsActiveTab( Ocx, &IsActiveTab ) | Получить свойство  
---|---  
Object.put_IsActiveTab( Ocx, IsActiveTab ) | Установить свойство  
  
Входные параметры:

IDispatch * Ocx  | \- интерфейс AxtiveX элемента.  
---|---  
  
Примечание:

1.Позволяет получить и установить активность пользовательской панели в окне документа.

2.Для активизации закладки ActiveX библиотеки нужно передать указатель на ActiveX интерфейс созданный функцией [IFrameTreesManager::AddTab](iframetreesmanager_addtab.html) или [IFrameTreesManager::AddTabEx](iframetreesmanager_addtabex.html).

Версия Компас v23

Подразделы:

(отсутствуют)
