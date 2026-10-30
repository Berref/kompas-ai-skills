# ActiveTab - Активная закладка

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IFrameTreesManager ](iframetreesmanager.html) > [IFrameTreesManager - свойства ](iframetreesmanager_props.html) |  Scroll [ [ [ ](iframetreesmanager_isactivetab.html "К следующему разделу")](iframetreesmanager_props.html "На уровень выше")](iframetreesmanager_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iframetreesmanager.html)

Тип данных: IDispatch

Синтаксис Automation:

ActiveTab = Object.ActiveTab | Получить свойство ([* ](1.html))  
---|---  
Object.ActiveTab = ActiveTab | Установить свойство ([* ](1.html))  
ActiveTab = Object.GetActiveTab() | Получить свойство ([**](2.html))  
Object.SetActiveTab( ActiveTab ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ActiveTab( &ActiveTab ) | Получить свойство  
---|---  
Object.put_ActiveTab( ActiveTab ) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить активность вкладки окна дерева документа.

2\. Для активизации закладки дерева документа системы КОМПАС нужно передать NULL.

3\. Для активизации закладки ActiveX библиотеки нужно передать указатель на интерфейс созданного функцией [AddTab](iframetreesmanager_addtab.html) ActiveX.

Подразделы:

(отсутствуют)
