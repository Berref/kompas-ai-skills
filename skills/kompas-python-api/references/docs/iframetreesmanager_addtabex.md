# AddTabEx - Добавить закладку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IFrameTreesManager ](iframetreesmanager.html) > [IFrameTreesManager - методы ](iframetreesmanager_methods.html) |  Scroll [ [ [ ](iframetreesmanager_removetab.html "К следующему разделу")](iframetreesmanager_methods.html "На уровень выше")](iframetreesmanager_addtab.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iframetreesmanager.html)

Синтаксис Automation:

LPDISPATCH AddTabEx( BSTR TabCaption, BSTR TreeCaption, BSTR OcxClassID, BOOL Active, PropertyManagerLayout Layout );

Синтаксис COM:

HRESULT AddTabEx( BSTR TabCaption, BSTR TreeCaption, BSTR OcxClassID, BOOL Active, PropertyManagerLayout Layout, IDispatch* * Result );

Возвращаемое значение:

| \- Указатель на интерфейс созданного ActiveX элемента.  
---|---  
  
Входные параметры:

tabCaption | \- имя закладки,  
---|---  
TreeCaption | \- заголовок дерева,  
ocxProgID | \- ProgID - ActiveX элемента (ActiveX дерева); Например, «VCTree.VCTreeCtrl.1» - для создания дерева, из примеров SDK. см SDK\lib\VCTree.ocx, проект SDK\OCX\VCTree. Пример использования SDK\C++\Visualc\TestVCTree,  
Active | \- активизировать закладку при создании,  
Layout | \- умолчательное расположение.  
  
Примечание:

При повторном создании закладки она будет создана в том же положении, где ее разместил пользователь.

Подразделы:

(отсутствуют)
